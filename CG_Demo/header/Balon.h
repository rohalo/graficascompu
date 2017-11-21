#pragma once
#include "glm.h"

class balon
{
public:
	balon();
	balon(GLMmodel* modelo);
	~balon();

	

	void posesion();
	void render(float x, float y);

	bool gol();

	float balonX;
	float balonY;
	GLMmodel* objeto;

	float balonOriginalX;
	float balonOriginalY;

	bool posicion;

	GLfloat* light0_position;
	GLfloat* mat0_diffuse;
	GLfloat* mat0_specular;
	GLfloat* mat0_shininess;
	

};