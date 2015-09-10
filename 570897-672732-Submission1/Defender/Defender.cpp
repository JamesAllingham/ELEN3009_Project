#include "Defender.h"

Defender::Defender () : _window(VideoMode(800, 600), "Defender"), _kestrel(), _textures(), _camera(), _background() {
	
	try 
	{
		_textures.load(TextureID::Landscape,"resources/space_backdrop.png");
	}
	catch (const runtime_error& error)
	{
		cerr << error.what();
		// maybe quit the application
	}	
	
	// The camera object will allow the implementation of scrolling
	_camera.reset(FloatRect(0.f,0.f,800.f,600.f)); //the camera is a 800x600 rectangle located at (0,0)
	_window.setView(_camera);
	_textures.get(TextureID::Landscape).setRepeated(true);
	_background.setTexture(_textures.get(TextureID::Landscape));
	_background.setTextureRect(IntRect(0,0,4800,600));
	
}


void Defender::run() {

	//sf::RenderWindow::setVerticalSyncEnabled(true);
	//_window.setFramerateLimit(_fps_limit);
	Clock clock;
	Time time_since_last_update = Time::Zero;
	Time time_per_frame = sf::seconds (1.0f / _FPS_LIMIT); //time per frame in seconds
	
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

	auto oldX = _kestrel.get_Character().getPosition().x;
	_kestrel.move_The_Ship(deltaTime);
	
	auto deltaX = _kestrel.get_Character().getPosition().x - oldX;
	// re-center the view on the ship in the x-direction
	_camera.move(deltaX,0.f);
	_window.setView(_camera);
}

void Defender::render() {

	_window.clear();
	
	_window.draw(_background);
	_window.draw(_kestrel.get_Character());
	
	_window.display();

}