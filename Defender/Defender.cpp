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
	//_window.setFramerateLimit(_fps_limit);
	Clock clock;
	Time time_since_last_update = Time::Zero;
	Time time_per_frame = sf::seconds (1.0f / _fps_limit); //time per frame in seconds
	
	while (_window.isOpen()) {
	
		time_since_last_update += clock.restart();
		
		while (time_since_last_update > time_per_frame ) {
		
			process_events();
			update(time_per_frame);
		
			time_since_last_update -= time_per_frame;
			
		}
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

void Defender::update(Time deltaTime) {

	_kestrel.move_The_Ship(deltaTime);

}

void Defender::render() {

	_window.clear();
	//add functionality
	
	_window.draw(_kestrel.get_Character());
	_window.draw(_testSprite);
	
	_window.display();

}