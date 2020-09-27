#include <stdlib.h>
#include <Windows.h>

#include "window.h"
#include "basicShapes.h"
#include "mapFileHandler.h"
#include "objects.h"
#include "sushiScriptInterpreter.h"


// Namespace for testing functions that have not been put into its class yet
namespace mainFunctions {
	void dormantFunction() {} // Placeholder function representing actions when the core game engine shuts down
}

#include "main.h"

int main() {
	printf("Make sure the main map and script file is within C:\SushiEngine\Map.. (main.sem, main.ses)\n");
	system("pause");

	SetCurrentDirectory(L"C:\\SushiEngine\\Map");

	printf("Sushi Game engine Start:\n\n");
	
	// Inits the window, and sets the initial resoulution
	sushiEngine::graphics::Window window("Translating Square Example - Sushi Engine", 800, 600);

	// Loads a map
	sushiEngine::filesystem::mapFileHandler mainMap("main.sem");
	int mainMapReturn = mainMap.loadMap();

	// Inits Sushi Script Interpreter
	sushiEngine::filesystem::scriptInterpreter sushiScript;

	if (mainMapReturn == 1) {
		printf("Error loading the map, file read failed...\n");
	}
	else if (mainMapReturn == 2) {
		printf("Error loading the map, invalid argument...\n");
	}

	// Game loop
	while (!window.closed()) {
		// Creates black background (other colors will be implemented in renderer)
		window.clear();

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
