#include "Defender.h"

Defender::Defender () : _window(VideoMode(640, 480), "Defender"), _kestrel(), _testSprite(), _textures() {
	
	try 
	{
		_textures.load(TextureID::Ship,"resources/test.jpg");	
	}
	catch (const runtime_error& error)
	{
		cerr << error.what();
		// maybe quit the application
	}
	
	_testSprite.setTexture(_textures.get(TextureID::Ship));	
}


void Defender::run() {
	while (_window.isOpen()) {
		
		process_events();
		update();
		render();
	
	}
}

void Defender::process_events() {

	Event event;
	while (_window.pollEvent(event)) {
		
		//Check if close command has been given
		if (event.type == Event::Closed) _window.close();
		
	}
}

void Defender::update() {

}

void Defender::render() {

	_window.clear();
	//add functionality
	
	//test
	_window.draw(_kestrel.get_character());
	_window.draw(_testSprite);
	//end test
	
	_window.display();

}