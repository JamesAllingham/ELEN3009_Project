#ifndef EVENTS
#define EVENTS
/**
* Events strongly typed enumeration class - used to enumerate the different events that SFML can generate from user input.
* This decouples SFML from the GameLogic.
*/
enum class Events
{
    Window_Close,
	W_Pressed,
	W_Released,
	A_Pressed,
	A_Released,
	S_Pressed,
	S_Released,
	D_Pressed,
	D_Released,
	Space_Pressed, // If the player presses space a laser should be shot in the direction of movement
	Space_Released,
	E_Pressed, // If the player presses the E key, a Homing Missile should be fired targeting the closest (or maybe random) flyer
	E_Released,
	Q_Pressed, // If the player presses the Q key, a Smart Bomb should be fired destroying all targets on the screen
	Q_Released,
	P_Pressed, // If the player presses the P key, the game should be paused/unpaused
};

#endif