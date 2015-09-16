#include "UserInterface.h"

UserInterface::UserInterface() : _game_window(VideoMode(800, 600), "Attacker"), _camera(), _textures(), _background() {
	
	try 
	{
		_textures.load(TextureID::Landscape,"resources/space_backdrop.png");
		_textures.load(TextureID::Ship,"resources/player_ship.png");
		_textures.load(TextureID::Flyer,"resources/flyer_ship.png");
	}
	catch (const runtime_error& error)
	{
		cerr << error.what();
		// maybe quit the application
	}	
	
	// The camera object will allow the implementation of scrolling
	_camera.reset(FloatRect(0.f,0.f,800.f,600.f)); //the camera is a 800x600 rectangle located at (0,0)
	_game_window.setView(_camera);
	_textures.get(TextureID::Landscape).setRepeated(true);
	_background.setTexture(_textures.get(TextureID::Landscape));
	_background.setTextureRect(IntRect(0,0,4800,600));
	
}

void UserInterface::processEvents() {

	_events.clear();
	Event event;
	while (_game_window.pollEvent(event)) {
		
		//poll all event types
		//convert from SFML
		switch (event.type) {
			case Event::KeyPressed:
				switch (event.key.code){
					case Keyboard::W:
						_events.push_back(Events::W_Pressed);
						break;
					case Keyboard::S:
						_events.push_back(Events::S_Pressed);
						break;
					case Keyboard::A:
						_events.push_back(Events::A_Pressed);
						break;
					case Keyboard::D:
						_events.push_back(Events::D_Pressed);
						break;
					default:
						break;
				}
				break;
			case Event::KeyReleased:
				switch (event.key.code){
					case Keyboard::W:
						_events.push_back(Events::W_Released);
						break;
					case Keyboard::S:
						_events.push_back(Events::S_Released);
						break;
					case Keyboard::A:
						_events.push_back(Events::A_Released);
						break;
					case Keyboard::D:
						_events.push_back(Events::D_Released);
						break;
					default:
						break;
				}
				break;
			case Event::Closed:
				_events.push_back(Events::Window_Close);
				break;
			default:
				break;
		}
	}
}

void UserInterface::closeWindow() {
	_game_window.close();
}

void UserInterface::render(list<Character>& characters) {

	_game_window.clear();
	
	//draw background before characters so that it appears behind them
	_game_window.draw(_background);
	processTextures(characters);
	
	_game_window.display();

}

void UserInterface::processTextures(list<Character>& characters) {
	
	for (auto character_iter : characters){
		Sprite _character;
		_character.setTexture(_textures.get(character_iter.texture_ID));
		_character.setPosition(character_iter.x,character_iter.y);
		
		//if (static_cast<int> (character_iter.texture_ID) == 3) {
		//	std::cout << "going to draw" << std::endl;
		//	_game_window.draw(_character);
		//}
		_game_window.draw(_character);
		//std::cout << "drawn" << std::endl;
	}
	
}

void UserInterface::moveWindow(float delta_x){
	_camera.move(delta_x,0.f);
	_game_window.setView(_camera);
}