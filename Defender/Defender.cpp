#include "Defender.h"

Defender::Defender () : _Window(VideoMode(640, 480), "Defender"), _Kestrel() {
	
	//Ship Kestrel;
	
	//test
	//_Player.setRadius(40.f);
	//_Player.setPosition(100.f, 100.f);
	//_Player.setFillColor(sf::Color::Cyan);
	//end test
}


void Defender::run() {
	while (_Window.isOpen()) {
		
		process_events();
		update();
		render();
	
	}
}

void Defender::process_events() {

	Event event;
	while (_Window.pollEvent(event)) {
		
		//Check if close command has been given
		if (event.type == Event::Closed) _Window.close();
		
	}
}

void Defender::update() {

}

void Defender::render() {

	_Window.clear();
	//add functionality
	
	//test
	_Window.draw(_Kestrel.get_character());
	//end test
	
	_Window.display();

}