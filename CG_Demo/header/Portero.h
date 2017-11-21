#pragma once
#include "glm.h"

class portero
{
public:
	portero();
	portero(GLMmodel* modelo,float posicionX, float posicionY);
	~portero();

	void draw();

	void movimiento();

	float posicionX;
	float posicionY;

	float posicionOriginalX;
	float posicionOriginalY;
};