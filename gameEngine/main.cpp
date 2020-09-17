#include <stdlib.h>

#include "window.h"

// Namespace for testing functions that have not been put into its class yet
namespace mainFunctions {
	// Simple triangle renderer
	void renderTriangle(float offsetX, float offsetY) {
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f + offsetX, -0.5f + offsetY);
		glVertex2f( 0.0f + offsetX,  0.5f + offsetY);
		glVertex2f( 0.5f + offsetX, -0.5f + offsetY);
		glEnd();
	}
	void dormantFunction() {} // Placeholder function representing actions when the core game engine shuts down
}

int main() {
	printf("Sushi Game engine Start:\n\n");
	
	// Inits the window, and sets the initial resoulution
	sushiEngine::graphics::Window window("Sushi Engine", 800, 600);

	// Game loop
	while (!window.closed()) {
		// Creates black background (other colors will be implemented in renderer)
		window.clear();
		// Remders a triangle in buffer
		mainFunctions::renderTriangle(0.0f, 0.0f);

		// Resizes window [Currently not working]
		window.resize(NULL, NULL, NULL); // Will be removed once resize callback is implemented
	
		// Updates the window with the buffer
		window.update();
	}
	// Destroyes window
	window.~Window();

	printf("The core engine has shut down successfully.\n\n");

	// Dormant function when core engine is down (for something like a idle game)
	mainFunctions::dormantFunction();

	system("pause"); // DEBUG
	return 0;
}
