#include "mapFileHandler.h"
#include "objects.h"
#include "main.h"

namespace sushiEngine {
	namespace filesystem {
		mapFileHandler::mapFileHandler(std::string fileName) {
			m_fileName = fileName;
			m_inFile = new std::ifstream(fileName);
			std::cout << "Opened map file: " << m_fileName << std::endl;
			m_id = 0;
		}

		int mapFileHandler::loadMap() {
			/* Return codes:
			   -1 = End of file
				0 = Success
				1 = Failed to read file
				2 = invalid object
				3 = invalid argument
			*/



			if (m_inFile->fail()) {
				return 1;
			}
			else if (m_inFile->eof()) {
				return -1;
			}

			std::string inObject;
			float inX, inY;
			double inScale;
			int id = 0;
			

			// NOTICE: Argument checking has not been implemented
			while (!m_inFile->eof()) {
				void** objClass = getObjectClass(id);
				std::string** objTable = getObjectTable(id);

				*m_inFile >> inObject >> inX >> inY >> inScale;

				if (inObject == "square") {
					*objClass = new sushiEngine::objects::square(id, inScale, inX, inY, 1);
				}
				id++;
			}

				m_inFile->close();
				return 0;
		}

		void mapFileHandler::closeMap() {
			m_id = 0;
		}
	}
}