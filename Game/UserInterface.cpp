#include "UserInterface.h"

UserInterface::UserInterface() : _game_window(VideoMode(_CAMERA_WIDTH, _CAMERA_HEIGHT/_CAMERA_HEIGHT_RATIO), "Attacker"), _camera(), _mini_map(), _textures(), _background(), _focusWindow(sf::Vector2f(800, 600)) 
{
	try 
	{
		_textures.load(EntityID::Landscape,"resources/space_backdrop.png");
		_textures.load(EntityID::Ship,"resources/ship.png");
		_textures.load(EntityID::Flyer,"resources/flyer.png");				
		_textures.load(EntityID::Laser,"resources/laser.png");
		_textures.load(EntityID::Power_Up,"resources/power_up.png");
		_textures.load(EntityID::Missile,"resources/missile.png");
		_textures.load(EntityID::Homing_Missile,"resources/homing_missile.png");
		_textures.load(EntityID::Smart_Bomb,"resources/smart_bomb.png");
	}
	catch (const runtime_error& error)
	{
		cerr << error.what();
		// maybe quit the application
	}	
	
	// The camera object will allow the implementation of scrolling
	_game_window.setView(_camera);	
	_camera.reset(FloatRect(_CAMERA_X_OFFSET,_CAMERA_Y_OFFSET,_CAMERA_WIDTH,_CAMERA_HEIGHT)); 	
	_camera.setViewport(FloatRect(_CAMERA_X_POS_RATIO,_CAMERA_Y_POS_RATIO,_CAMERA_WIDTH_RATIO,_CAMERA_HEIGHT_RATIO));
	_mini_map.reset(FloatRect(_MAP_X_OFFSET,_MAP_Y_OFFSET,_MAP_WIDTH,_MAP_HEIGHT));
	_mini_map.setViewport(FloatRect(_MINI_MAP_X_POS_RATIO,_MINI_MAP_Y_POS_RATIO,_MINI_MAP_WIDTH_RATIO,_MINI_MAP_HEIGHT_RATIO));
	_textures.get(EntityID::Landscape).setRepeated(true);
	_background.setTexture(_textures.get(EntityID::Landscape));
	_background.setTextureRect(IntRect(_MAP_X_OFFSET,_MAP_Y_OFFSET,_MAP_WIDTH,_MAP_HEIGHT));
	
	_focusWindow.setFillColor(Color(255, 255, 255, 0));
	_focusWindow.setOutlineThickness(-25);
	_focusWindow.setOutlineColor(Color(250, 150, 100));
	_focusWindow.setPosition(_CAMERA_X_OFFSET,_CAMERA_Y_OFFSET);	
	
}

void UserInterface::processEvents() 
{

	_events.clear();
	Event event;
	while (_game_window.pollEvent(event)) 
	{		
		//poll all event types
		//convert from SFML
		switch (event.type) 
		{
			case Event::KeyPressed:
				switch (event.key.code)
				{
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
					case Keyboard::Q:
						_events.push_back(Events::Q_Pressed);
						break;
					default:
						break;
				}
				break;
			case Event::KeyReleased:
				switch (event.key.code)
				{
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
						_events.push_back(Events::E_Released);
						break;
					case Keyboard::Space:
						_events.push_back(Events::Space_Released);
						break;
					case Keyboard::Q:
						_events.push_back(Events::Q_Released);
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
	
	for (auto character : characters)
	{
		Sprite character_sprite;
		character_sprite.setTexture(_textures.get(character.entityID()));
		character_sprite.setPosition(ConvertToSFMLVector(character.position()));
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