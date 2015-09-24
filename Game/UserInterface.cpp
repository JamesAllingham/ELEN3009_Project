#include "UserInterface.h"

UserInterface::UserInterface() : _game_window(VideoMode(800, 720), "Attacker"), _camera(), _mini_map(), _textures(), _background(), _focusWindow(Vector2f(800, 600)) 
{
	//std::cout << "User interface constructor" << std::endl;
	
	try 
	{
		_textures.load(TextureID::Landscape,"resources/space_backdrop.png");
		_textures.load(TextureID::Ship,"resources/ship.png");
		_textures.load(TextureID::Flyer,"resources/flyer.png");				
		_textures.load(TextureID::Laser,"resources/laser.png");
		_textures.load(TextureID::Powerup,"resources/power_up.png");
		_textures.load(TextureID::Missile,"resources/missile.png");
		_textures.load(TextureID::Homing_Missile,"resources/homing_missile.png");
	}
	catch (const runtime_error& error)
	{
		cerr << error.what();
		// maybe quit the application
	}	
	
	// The camera object will allow the implementation of scrolling
	_game_window.setView(_camera);	
	_camera.reset(FloatRect(2000.f,0.f,800.f,600.f)); 	
	_camera.setViewport(FloatRect(0.f,0.2f,1.f,0.833f));
	_mini_map.reset(FloatRect(0.f,0.f,4800.f,600.f));
	_mini_map.setViewport(FloatRect(0.1f,0.0f,0.8f,0.167f));
	_textures.get(TextureID::Landscape).setRepeated(true);
	_background.setTexture(_textures.get(TextureID::Landscape));
	_background.setTextureRect(IntRect(0,0,4800,600));
	
	_focusWindow.setFillColor(Color(255, 255, 255, 0));
	_focusWindow.setOutlineThickness(-25);
	_focusWindow.setOutlineColor(Color(250, 150, 100));
	_focusWindow.setPosition(2000.f,0.f);
	
	_game_window.setKeyRepeatEnabled(false);
	
}

void UserInterface::processEvents() 
{

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
					case Keyboard::E:
						_events.push_back(Events::E_Pressed);
						break;
					case Keyboard::Space:
						_events.push_back(Events::Space_Pressed);
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
					case Keyboard::E:
						_events.push_back(Events::D_Released);
						break;
					case Keyboard::Space:
						_events.push_back(Events::Space_Released);
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

void UserInterface::closeWindow() 
{
	_game_window.close();
}

void UserInterface::render(list<Character>& characters) 
{

	_game_window.clear();	
	
	_game_window.setView(_camera);
	_background.setColor(sf::Color(255, 255, 255, 255));
	_game_window.draw(_background);
	_game_window.setView(_mini_map);
	_background.setColor(sf::Color(255, 255, 255, 50));
	_game_window.draw(_background);
	_game_window.draw(_focusWindow);
	processTextures(characters);
	
	_game_window.display();

}

void UserInterface::processTextures(list<Character>& characters) 
{
	
	for (auto character : characters){
		Sprite character_sprite;
		character_sprite.setTexture(_textures.get(character.texture_ID));
		character_sprite.setPosition(character.position);				
		drawSprite(character_sprite);
	}
	
}

void UserInterface::moveWindow(float delta_x)
{
	_camera.move(delta_x,0.f);
	_focusWindow.move(delta_x,0.f);
	_game_window.setView(_camera);
}

void UserInterface::drawSprite(const Sprite& texture)
{
	_game_window.setView(_mini_map);
	_game_window.draw(texture);
	_game_window.setView(_camera);
	_game_window.draw(texture);
}