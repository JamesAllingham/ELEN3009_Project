#include "Defender.h"

Defender::Defender () : _Window(VideoMode(640, 480), "Defender")
, mPlayer() {
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
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
	_Window.draw(mPlayer);
	//end test
	
	_Window.display();

}