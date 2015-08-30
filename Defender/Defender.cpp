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

	//sf::RenderWindow::setVerticalSyncEnabled(true);
	_window.setFramerateLimit(_fps_limit);
	
	while (_window.isOpen()) {
		
		process_events();
		update();
		render();
	
	}
}

void Defender::process_events() {

	Event event;
	while (_window.pollEvent(event)) {
		
		//poll all event types
		switch (event.type) {
			case Event::KeyPressed:
				if (event.key.code == Keyboard::W || event.key.code == Keyboard::A || event.key.code == Keyboard::S || event.key.code == Keyboard::D) {
					_kestrel.handle_Ship_Movement(event.key.code, true);
				}
				break;
			case Event::KeyReleased:
				if (event.key.code == Keyboard::W || event.key.code == Keyboard::A || event.key.code == Keyboard::S || event.key.code == Keyboard::D) {
					_kestrel.handle_Ship_Movement(event.key.code, false);
				}
				break;
			case Event::Closed:
				_window.close();
				break;
			default:
				break;
		}
	}
}

void Defender::update() {

	_kestrel.move_The_Ship();

}

void Defender::render() {

	_window.clear();
	//add functionality
	
	_window.draw(_kestrel.get_Character());
	_window.draw(_testSprite);
	
	_window.display();

}