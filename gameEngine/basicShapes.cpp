#include "basicShapes.h"

namespace sushiEngine {
	namespace objects {
		square::square(int id, float scale, float x_pos, float y_pos, bool hasCollision) {
			m_id = id;
			m_scale = scale; m_x_pos = x_pos;
			m_y_pos = y_pos;
			m_hasCollision = hasCollision;
			printf("Object 'square' has been created. (%i)\n", m_id);
		}
		void square::render() {
			glTranslatef(m_x_pos, m_y_pos, 0.0f);

			glBegin(GL_QUADS);
			glVertex3f((-1.0f * m_scale), (-1.0f * m_scale), 0.0f); // The bottom left corner  
			glVertex3f((-1.0f * m_scale), ( 1.0f * m_scale), 0.0f); // The top left corner  
			glVertex3f(( 1.0f * m_scale), ( 1.0f * m_scale), 0.0f); // The top right corner  
			glVertex3f(( 1.0f * m_scale), (-1.0f * m_scale), 0.0f); // The bottom right corner 
			glEnd();

			glTranslatef(0.0f, 0.0f, 0.0f);
		}
		void square::translate(float x, float y) {
			m_x_pos = x; m_y_pos = y;
		}
		void square::setScale(float scale) {
			m_scale = scale;
		}
		void square::setCollision(bool hasCollision) {
			m_hasCollision = hasCollision;
		}
	}
}