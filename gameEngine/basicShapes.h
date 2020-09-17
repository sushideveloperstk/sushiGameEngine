#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace sushiEngine {
	namespace objects {
		class square {
		private:
			float m_scale;
			float m_x_pos;
			float m_y_pos;
			bool  m_hasCollision;
		public:
			square(float scale, float x_pos, float y_pos, bool hasCollision);
			void render();
			void translate(float x, float y);
			void setScale(float scale);
			void setCollision(bool hasCollision);
		};
	}
}