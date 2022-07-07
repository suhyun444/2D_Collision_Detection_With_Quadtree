#include "GL/glut.h"
#include "Box.h"
Box box[4];
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f,1.0f);
	glLoadIdentity();
	glScaled(0.01f, 0.01f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (int i = 0; i < 4; i++)
	{
		box[i].Update();
		glBegin(GL_LINE_LOOP);
		box[i].Display();
		glEnd();
	}
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
