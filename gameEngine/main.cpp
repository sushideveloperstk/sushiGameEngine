#include <stdlib.h>

#include "window.h"
#include "basicShapes.h"

// Namespace for testing functions that have not been put into its class yet
namespace mainFunctions {
	void dormantFunction() {} // Placeholder function representing actions when the core game engine shuts down
}

int main() {
	printf("Sushi Game engine Start:\n\n");
	
	// Inits the window, and sets the initial resoulution
	sushiEngine::graphics::Window window("Translating Square Example - Sushi Engine", 800, 600);

	// Creates a square object
	sushiEngine::objects::square square0(0.1f, -1, 0, false);

	// Game loop
	while (!window.closed()) {
		// Creates black background (other colors will be implemented in renderer)
		window.clear();

		// Renders square0
		square0.render();

		// Translates square0
		square0.translate(0.00001f, 0.0f);

		// Resizes window [Currently not working]
		window.resize(NULL, NULL, NULL); // Will be removed once resize callback is implemented
	
		// Updates the window with the buffer
		window.update();
	}
	// Destroyes window
	window.~Window();

	printf("\n");

	printf("The core engine has shut down successfully.\n\n");

	// Dormant function when core engine is down (for something like a idle game)
	mainFunctions::dormantFunction();

	system("pause"); // DEBUG
	return 0;
}
