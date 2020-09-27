#include "mapFileHandler.h"
#include "objects.h"

namespace sushiEngine {
	namespace filesystem {
		mapFileHandler::mapFileHandler(std::string fileName, void* objClass, void* objTable[]) {
			m_fileName = fileName;
		}

		int mapFileHandler::loadMap() {
			/* Return codes:
				0 = Success
				1 = Failed to read file
				2 = invalid object
				3 = invalid argument
			*/
			std::cout << "Loading map file: " << m_fileName << std::endl;

			std::ifstream inFile;
			inFile.open(m_fileName);

			if (inFile.fail()) {
				return 1;
			}

			std::string inObject;
			float inX, inY;
			double inScale;
			int id = 0;

			

			// NOTICE: Argument checking has not been implemented
			while (!inFile.eof()) {
				inFile >> inObject >> inX >> inY >> inScale;

				if (inObject == "square") {
					
					(sushiEngine::objects::square*)*objClass = new sushiEngine::objects::square(id, inScale, inX, inY, 1);
				}
				else {
					return 2;
				}
				id++;
			}

			inFile.close();
		}
	}
}