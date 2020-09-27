#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include "basicShapes.h"

namespace sushiEngine {
	namespace filesystem {
		class mapFileHandler {
		private:
			std::string m_fileName;
			std::string m_mapName;
			void* objClass;
		public:
			mapFileHandler(std::string fileName, void* objClass[], void* objTable[]);
			int loadMap();
			void destroy();
			std::string getMapName();

		};
	}
}