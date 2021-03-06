/*
	TC3022. Computer Graphics
	Sergio Ruiz
	External geometry loader example.
*/

#include <stdio.h>
#include <math.h>
#include "glm.h"
#include "Jugador.h"
#include "balon.h"

// NATE ROBINS' OBJ MODEL LOADER (http://devernay.free.fr/hacks/glm/)
 /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define DO_ROTATION_X

GLfloat		rotationY = 0.0f;
GLfloat		rotationX = 0.0f;

GLfloat*	mat0_specular;
GLfloat*	mat0_diffuse;
GLfloat*	mat0_shininess;
GLfloat*	light0_position;

GLMmodel*	modelo1;
GLMmodel*	modelo2;
GLMmodel*	scene;
GLMmodel*	balon1;

balon* balonJuego;



void init(void)
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glClearColor(0.2, 0.2, 0.2, 1.0);


	modelo1 = glmReadOBJ("assets/Jugador1.obj");
	modelo2 = glmReadOBJ("assets/Jugador2.obj");
	scene = glmReadOBJ("assets/cancha.obj");
	balon1 = glmReadOBJ("assets/ball.obj");

	jugador* jugador1 = new jugador(modelo1);
	jugador* jugador2 = new jugador(modelo2);
	balonJuego = new balon(balon1);
	





	//model = glmReadOBJ("assets/mystery2.obj");

	// When the model is too big make it fit inside a 1x1x1 cube:
	glmUnitize(modelo1);
	glmUnitize(modelo2);
	glmUnitize(balon1);
	// You can also scale it later:
	glmScale(scene, 0.2f);
	glmScale(balon1, 0.3f);
	glmScale(modelo1, 0.5f);
	glmScale(modelo2, 0.5f);
	//glmScale(model2, 0.2f);

	// When the model doesn't have normals, glm can add them:
	//glmVertexNormals(model, 45.0f, false); // first per vertex
	//glmFacetNormals(model); // and then per face

	light0_position = new GLfloat[4];
	light0_position[0] = 3;
	light0_position[1] = 3;
	light0_position[2] = 0;
	light0_position[3] = 1; // POINT LIGHT
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	mat0_specular = new GLfloat[4];
	mat0_specular[0] = 1.0f;
	mat0_specular[1] = 1.0f;
	mat0_specular[2] = 1.0f;
	mat0_specular[3] = 1.0f;

	mat0_diffuse = new GLfloat[4];
	mat0_diffuse[0] = 0.8f;
	mat0_diffuse[1] = 0.7f;
	mat0_diffuse[2] = 0.6f;
	mat0_diffuse[3] = 1.0f;

	mat0_shininess = new GLfloat[1];
	mat0_shininess[0] = 100.0f;

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void display(void)
{
	

	// Limpiar los buffers de color y de profundidad:
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Dibujar los polígonos:
	glPushMatrix();

	// Indicar propiedades del material con el que vamos a dibujar:
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);
	
	glPushMatrix();
	
	glTranslatef(1.0f, 0.0f, 0.0f);
	glmDraw(modelo1, GLM_SMOOTH);
	glPopMatrix();

	glPushMatrix();
	// Indicar propiedades del material con el que vamos a dibujar:
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);
	
	glPushMatrix();
	
	glmDraw(modelo2, GLM_SMOOTH);
	glPopMatrix();

	glPushMatrix();
	// Indicar propiedades del material con el que vamos a dibujar:
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	//glPushMatrix();
	//glTranslatef(-0.9, -0.65, 0);
	
	//glmDraw(balon1, GLM_SMOOTH);
	//glPopMatrix();

	glPushMatrix();
	// Indicar propiedades del material con el que vamos a dibujar:
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	glPushMatrix();
	glTranslatef(0.5, -0.65, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(270, 1, 0, 0);
	glmDraw(scene, GLM_SMOOTH);
	glPopMatrix();
	
	// Intercambiar el buffer visible por el oculto:
	glutSwapBuffers();
	//glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	//glPushMatrix();
	//{
	//	glTranslatef(-0.5f, 0, 0);
	//	//glRotatef(rotationX, 1, 0, 0);
	//	glRotatef(rotationY, 0, 1, 0);
	//	glmDraw(model1, GLM_SMOOTH);

	//	
	//}
	//glPopMatrix();

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	//glPushMatrix();
	//{
	//	glTranslatef(0.5f, 0, 0);
	//	glScalef(0.2f, 0.2f, 0.2f);
	//	//glRotatef(rotationX, 1, 0, 0);
	//	glRotatef(rotationY, 0, 1, 0);
	//	glmDraw(model2, GLM_SMOOTH);
	//}
	//glPopMatrix();
	//glutSwapBuffers();


}

void idle (void)
{
	rotationY += 0.08f;
	if (rotationY > 360)
	{
		rotationY = 0;
	}

#ifdef DO_ROTATION_X
	rotationX += 0.02f;
	if (rotationX > 360)
	{
		rotationX = 0;
	}
#endif

	glutPostRedisplay ();	
}



void reshape (int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 10, 
		0, 0, 0, 
		0, 1, 0);
	display();
}


void keys(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'w':

		break;
	}
}


	int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 800); 
	glutInitWindowPosition (100, 50);
	glutCreateWindow ("Pateando por un sueño!");
	glutReshapeFunc (reshape);
	glutKeyboardFunc(keys);
	init ();
	glutDisplayFunc(display); 
	glutIdleFunc (idle);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
