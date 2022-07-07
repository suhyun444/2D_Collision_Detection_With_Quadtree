#include "GL/glut.h"
#include "Box.h"
Box box[4];
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f,1.0f);
	glLoadIdentity();
	glScaled(0.01f, 0.01f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(box[i].position.x - box[i].scale.x, box[i].position.y - box[i].scale.y);
		glVertex2f(box[i].position.x - box[i].scale.x, box[i].position.y + box[i].scale.y);
		glVertex2f(box[i].position.x + box[i].scale.x, box[i].position.y + box[i].scale.y);
		glVertex2f(box[i].position.x + box[i].scale.x, box[i].position.y - box[i].scale.y);
	}
	glEnd();
	glFinish();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("2D Collision Detection");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	
	for (int i = 0; i < 4; i++)
	{
		box[i].position = Vector3(i * 3, 0, 0);
	}

	glutMainLoop();
	return 0;
}
