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
			std::ifstream* m_inFile;
			int m_id;
			void* objClass;
		public:
			mapFileHandler(std::string fileName);
			int loadMap();
			void closeMap();
			void destroy();
			std::string getMapName();

		};
	}
}