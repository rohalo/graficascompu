#include "balon.h"

balon::balon(GLMmodel* modelo)
{
	balonOriginalX = -0.9f;
	balonOriginalY = -0.65f;
	balonX = -0.9f;
	balonY = -0.65;
	objeto = modelo;


	GLfloat* light0_position = new GLfloat[4];
	light0_position[0] = 3;
	light0_position[1] = 3;
	light0_position[2] = 0;
	light0_position[3] = 1;

	GLfloat* mat0_diffuse = new GLfloat[4];
	mat0_diffuse[0] = 0.8f;
	mat0_diffuse[1] = 0.7f;
	mat0_diffuse[2] = 0.6f;
	mat0_diffuse[3] = 1.0f;

	GLfloat* mat0_specular = new GLfloat[4];
	mat0_specular[0] = 1.0f;
	mat0_specular[1] = 1.0f;
	mat0_specular[2] = 1.0f;
	mat0_specular[3] = 1.0f;

	GLfloat* mat0_shininess = new GLfloat[1];
	mat0_shininess[0] = 100.0f;


	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	glmUnitize(objeto);
	glmScale(objeto, 0.5f);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glTranslatef(balonOriginalX , balonOriginalY , 0.0f);

	glmDraw(objeto, GLM_SMOOTH);
	glPopMatrix();

	glutSwapBuffers();
}

void balon::posesion()
{
	
}

void balon::render(float x, float y)
{
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	glmUnitize(objeto);
	glmScale(objeto, 0.15f);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	if (gol()==1) {
		glTranslatef(balonOriginalX, balonOriginalY, 0.0f);
		posicion = 0;
	}

	else {
		glTranslatef( balonX=+x, balonY=+y, 0.0f);
	}

	glmDraw(objeto, GLM_SMOOTH);
	glPopMatrix();

	glutSwapBuffers();

}

bool balon::gol()
{
	return posicion = 1;
}