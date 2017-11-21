#pragma once
#include "glm.h"

class jugador
{
public:
	jugador();
	jugador(GLMmodel* modelo);
	~jugador();


	float jugadorX;
	float jugadorY;
	float jugadorOriginalX;
	float jugadorOriginalY;


	void posicionJugador();

	void patada();

	void posicionOriginal();

	void draw();


};
