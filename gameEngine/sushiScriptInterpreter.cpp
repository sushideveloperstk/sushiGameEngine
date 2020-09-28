#include "sushiScriptInterpreter.h"
#include "basicShapes.h"
#include "main.h"

namespace sushiEngine {
	namespace filesystem {
		scriptInterpreter::scriptInterpreter(){
			m_isFinished = false;
			m_firstLoop = true;
			std::cout << "Sushi Script initialized." << std::endl;
		}
		int scriptInterpreter::execScript(std::string file) {
			/* Return codes:
			0 = Success
			1 = Failed to read file
			2 = invalid object
			3 = invalid argument
			*/
			std::cout << "Loading script file: " << file << std::endl;

			std::ifstream inFile;
			inFile.open(file);

			if (inFile.fail()) {
				return 1;
			}

			std::string buffer;


			int objID;
			std::string command;

			// NOTICE: Argument checking has not been implemented
			while (!inFile.eof()) {
				inFile >> objID >> command;

				if (command == "renderSquare") {
					sushiEngine::objects::square* workingObject = (sushiEngine::objects::square*)*getObjectClass(objID);
					workingObject->render();
				}
			}

			inFile.close();
		}
		int scriptInterpreter::loopScript(std::string file) {
			/* Return codes:
			0 = Success
			1 = Failed to read file
			2 = invalid object
			3 = invalid argument
			*/
			
			if (m_firstLoop == true) {
				std::cout << "Looping script file: " << file << std::endl;
			}

			m_firstLoop = false;

			std::ifstream inFile;
			inFile.open(file);

			if (inFile.fail()) {
				return 1;
			}

			int objID;
			std::string command;

			// NOTICE: Argument checking has not been implemented
			while (!inFile.eof()) {
				inFile >> objID >> command;

				if (command == "renderSquare") {
					sushiEngine::objects::square* workingObject = (sushiEngine::objects::square*)*getObjectClass(objID);
					workingObject->render();
				}
			}

			inFile.close();
		}
	}
}