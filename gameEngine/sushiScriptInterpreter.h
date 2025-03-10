#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace sushiEngine {
	namespace filesystem {
		class scriptInterpreter {
		private:
			bool m_isFinished;
			bool m_firstLoop;
		public:
			scriptInterpreter();
			int execScript(std::string file);
			int loopScript(std::string file);
		};
	}
}