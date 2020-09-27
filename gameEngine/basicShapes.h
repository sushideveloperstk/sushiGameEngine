#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace sushiEngine {
	namespace objects {
		class square {
		private:
			int m_id;
			float m_scale;
			float m_x_pos;
			float m_y_pos;
			bool  m_hasCollision;
		public:
			square(int id, float scale, float x_pos, float y_pos, bool hasCollision);
			void render();
			void translate(float x, float y);
			void setScale(float scale);
			void setCollision(bool hasCollision);
		};
	}
}