#ifndef EVENTS
#define EVENTS

// Define some strongly typed enumerations which will act as the keys for the event logic
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
	E_Released		  
};

#endif