#pragma once
#include "basicShapes.h"

namespace sushiEngine {
	namespace objects {
		class objectSystem {
		private:
			std::string* objectTable[10000];
			void* objectClass[10000]; // Supposed to be cast to whatever class an object is
		public:
			objectSystem();
			void writeToObjectTable(int id, std::string objectType);
			void writeToObjectClass(int id, void* object);
			std::string readFromObjectTable(int id);
			void* readFromObjectClass(int id);
		};
		
		
	}
}