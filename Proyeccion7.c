#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <FreeImage.h>
#define PI 3.141592
int texID[13];
int luzx,luzy,luzz;
char* textureFileNames[13] = {
"textures/Piso.jpg",
"textures/ParedRoja.jpg",
"textures/ParedCrema.jpg",
"textures/grass.jpg",
"textures/stucco.jpg",
"textures/Madera.jpg",
"textures/Negro.png",
"textures/Mural.jpg",
"textures/Mural1.jpg",
"textures/Mural2.jpg",
"textures/Mural3.jpg",
"textures/Mural4.jpg",
"textures/Ventana.jpg"
};
float pos[3];
float at[3];
float up[3];
float dir[3];
int angH;
int angV;
float mod;
int FC[100][40][200];
GLfloat SpecRef[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLubyte Shine =	128;
void Draw2(float x,float y,float z){
	glPushMatrix();
		glTranslatef(x+0.5,y+0.5,z+0.5);
	glutWireCube(1.0);
	glPopMatrix();
}
void textura(float x, float y, float z){
	if(pos[1]>y){
		if( pos[0]<=x && pos[2]<=z ){//1
			glBegin(GL_QUADS);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			glEnd();
		}else if( pos[0]<=x && pos[2]>=z ){//2
			glBegin(GL_QUADS);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			glEnd();
		}else if( pos[0]>=x && pos[2]<=z ){//3
			glBegin(GL_QUADS);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			glEnd();
		}else if( pos[0]>=x && pos[2]>=z ){//4
			glBegin(GL_QUADS);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			glEnd();
		}
	}else if(pos[1]<=y){
		if( pos[0]<=x && pos[2]<=z ){//1
			glBegin(GL_QUADS);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			glEnd();
		}else if( pos[0]<=x && pos[2]>=z ){//2
			glBegin(GL_QUADS);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			glEnd();
		}else if( pos[0]>=x && pos[2]<=z ){//3
			glBegin(GL_QUADS);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			glEnd();
		}else if( pos[0]>=x && pos[2]>=z ){//4
			glBegin(GL_QUADS);
			//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y+1,z);
			//2
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z);
			//1
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			//3
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z+1);
			//4
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x+1,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x+1,y+1,z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y+1,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z+1);
			//6
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z+1);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x+1,y,z+1);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x+1,y,z);
			glEnd();
		}
	}
}
void SeleccionColores(int i,int j, int k){
	if(FC[i][j][k]==1){
		glBindTexture(GL_TEXTURE_2D, texID[1]);
		textura(i,j,k);
	}else if(FC[i][j][k]==2){
		glBindTexture(GL_TEXTURE_2D, texID[2]);
		textura(i,j,k);
	}else if(FC[i][j][k]==3){
		glBindTexture(GL_TEXTURE_2D, texID[5]);
		textura(i,j,k);
	}else if(FC[i][j][k]==4){
		glBindTexture(GL_TEXTURE_2D, texID[0]);
		textura(i,j,k);
	}else if(FC[i][j][k]==5){
		glBindTexture(GL_TEXTURE_2D, texID[4]);
		textura(i,j,k);
	}else if(FC[i][j][k]==6){
		glBindTexture(GL_TEXTURE_2D, texID[3]);
		textura(i,j,k);
	}else if(FC[i][j][k]==7){
		glBindTexture(GL_TEXTURE_2D, texID[6]);
		Draw2(i,j,k);
	}
}

static float spotAngle = 15.0; // Spotlight cone half-angle.
static float spotExponent = 2.0; // Spotlight exponent = attenuation.

void setup(void)
{
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glEnable(GL_DEPTH_TEST); // Enable depth testing.

   // Turn on OpenGL lighting.
   glEnable(GL_LIGHTING);

   // Light property vectors.
   float lightAmb[] = { 0.5, 0.5, 0.5, 1.0 };
   float lightDifAndSpec[] = { 0.7, 0.7, 0.7, 1.0 };// Intensidad de la luz
   float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };// Luz del ambiente

   // Light properties.
   glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
   glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);

   glEnable(GL_LIGHT0); // Enable particular light source.
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.
   glEnable(GL_LIGHT0); // Enable particular light source.

   // Cull back faces.
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
   
   glEnable(GL_COLOR_MATERIAL);  
}

// Drawing routine.
void drawScene()
{
	//if(pos[0] > 40 && pos[1] > 20 && pos[2] < 60){
	//	luzx = 70.0; luzy = 50.0; luzz = 30.0;}
	//else{
		//luzx = ((int)pos[0]/20) * 20 + 10;
		//luzy = 50.0;
		//luzz = ((int)pos[2]/20) * 20 + 10;
		luzx = pos[0];
		luzy = pos[1];
		luzz = pos[2];
	//}

   float lightPos[] = { luzx, luzy, luzz, 1.0 }; // Spotlight position.
   //float spotDirection[] = {0.0, -1.0, 0.0}; // Spotlight direction.   
   float spotDirection[] = {dir[0],0.0,dir[2]};
   // Spotlight properties including position.
   glLightfv(GL_LIGHT0, GL_POSITION, lightPos);  
   glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotAngle);
   glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);  
   
     
  // glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExponent);
	  glEnable(GL_COLOR_MATERIAL); 
   glutSwapBuffers();
}

void init(){
	//glClearColor(0.0,0.0,0.0,1.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
	glMateriali(GL_FRONT, GL_SHININESS, Shine);
	// Posicion de la camara
	pos[0] = 30.0;
	pos[1] = 10;
	pos[2] = 0.0;
	// Para voltear a la izquierda o derecha
	angH = 90;
	// Para voltear a arriba o abajo
	angV = 0;
	// Direccion ortogonal a donde esta viendo
	up[0] = 0.0;
	up[1] = 1.0;
	up[2] = 0.0;
	glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    setup();
}
void camara(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0,1.0,1.0,200.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(pos[0],pos[1],pos[2],at[0],at[1],at[2],up[0],up[1],up[2]);
}
void pintacasa(){
	mod = sqrt(dir[0]*dir[0] + dir[2]*dir[2]);
	dir[0] = cos(PI*angH/180.0)/2.0;
	dir[2] = sin(PI*angH/180.0)/2.0;
	at[0] = pos[0]+dir[0];
	at[2] = pos[2]+dir[2];
	// Para agachar o levantar
	at[1] = pos[1]+mod*sin(PI*angV/180.0);

	drawScene();
	camara();

	glEnable(GL_TEXTURE_2D);
	int i,j,k;
	for(i=99;i>=pos[0];i--){
		for(k=199;k>=pos[2];k--){
			for(j=39;j>=pos[1];j--){
				SeleccionColores(i,j,k);
			}
			for(j=0;j<=pos[1];j++){
				SeleccionColores(i,j,k);
			}
		}
		for(k=0;k<=pos[2];k++){
			for(j=39;j>=pos[1];j--){
				SeleccionColores(i,j,k);
			}
			for(j=0;j<=pos[1];j++){
				SeleccionColores(i,j,k);
			}
		}
	}
	for(i=0;i<=pos[0];i++){
		for(k=199;k>=pos[2];k--){
			for(j=39;j>=pos[1];j--){
				SeleccionColores(i,j,k);
			}
			for(j=0;j<=pos[1];j++){
				SeleccionColores(i,j,k);
			}
		}
		for(k=0;k<=pos[2];k++){
			for(j=39;j>=pos[1];j--){
				SeleccionColores(i,j,k);
			}
			for(j=0;j<=pos[1];j++){
				SeleccionColores(i,j,k);
			}
		}
	}
	glutSwapBuffers();
}
void teclado1(unsigned char key, int x,int y){
	int i,j,k;
	switch(key){
		case 'w':
			i = (int)(pos[0]+dir[0]/2.0);
			j = (int)(pos[1]+mod*sin(PI*angV/180.0));
			k = (int)(pos[2]+dir[2]/2.0);
			if(FC[i][j][k]==0){
				pos[0]+=dir[0];
				pos[2]+=dir[2];
			}
			break; 
		case 's':
			i = (int)(pos[0]-dir[0]/2.0);
			j = (int)(pos[1]+mod*sin(PI*angV/180.0));
			k = (int)(pos[2]-dir[2]/2.0);
			if(FC[i][j][k]==0){
				pos[0]-=dir[0];
				pos[2]-=dir[2];
			}
			break;
		case 'd':
			if(pos[1]<37)
				pos[1]+=1;
			break;
		case 'a':
			if(pos[1] > 3)
				pos[1]-=1;
			break;
		case '+':
			spotAngle+=0.5;
			break;
		case '-':
			spotAngle-=0.5;
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
	glutPostRedisplay();
}
void teclado2(int key, int x,int y){
	switch(key){
		case GLUT_KEY_UP:
			angV+=2;
			break; 
		case GLUT_KEY_DOWN:
			angV-=2;
			break; 
		case GLUT_KEY_LEFT:
			angH-=2;
			if(angH<0){
				angH+=360;
			}
			break; 
		case GLUT_KEY_RIGHT:
			angH = (angH + 2)%360;
			break; 
		default:
			break;
	}
	glutPostRedisplay();
}
//Cargando Texturas
void loadTextures() {
  int i;
  glGenTextures(13, texID);  // Obtener el Id textura .
  for (i = 0; i < 13; i++) {
     void* imgData;      // Puntero a data del Archivo.
     int imgWidth;   // Ancho de Imagen
     int imgHeight;  // Alto.
     FREE_IMAGE_FORMAT format = FreeImage_GetFIFFromFilename(textureFileNames[i]);
     if (format == FIF_UNKNOWN) {
        printf("Archivo de Imagen desconocido %s\n", textureFileNames[i]);
            continue;
        }
     FIBITMAP* bitmap = FreeImage_Load(format, textureFileNames[i], 0);  //Leer Imagen.
     if (!bitmap) {
        printf("Fallo la carga de image %s\n", textureFileNames[i]);
        continue;
     }
     FIBITMAP* bitmap2 = FreeImage_ConvertTo24Bits(bitmap);  // Convierte a RGB
     FreeImage_Unload(bitmap);
     imgData = FreeImage_GetBits(bitmap2);
     imgWidth = FreeImage_GetWidth(bitmap2);
     imgHeight = FreeImage_GetHeight(bitmap2);
     if (imgData) {
         printf("Texture cargada %s, tamanio %dx%d\n", 
                                     textureFileNames[i], imgWidth, imgHeight);
         int format; // Formato del color.
         if ( FI_RGBA_RED == 0 )
            format = GL_RGB;
         else
            format = GL_BGR;
            glBindTexture( GL_TEXTURE_2D, texID[i] );  // Cargando textura
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, format,GL_UNSIGNED_BYTE, imgData);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        } else {
            printf("Fallo la carga de textura %s\n", textureFileNames[i]);
        }
    }
}
void timer(int n){
	int i,j,k;
	i = pos[0]+dir[0]/2.0;
	j = pos[1];
	k = pos[2]+dir[2]/2.0;
	if(FC[i][j][k]==0){
		pos[0]+=dir[0]/2.0;
		pos[2]+=dir[2]/2.0;
	}
	glutPostRedisplay();
	glutTimerFunc(250,timer,rand()%2);
}
int main(int argc, char** argv){
	int i,j,k;
	FILE *fp;
	fp = fopen ("j0.txt","rt");
	for(j=0;j<40;j++)
		for (i=0;i<100;i++)
			for(k=0;k<200;k++)
				fscanf(fp,"%d\n",&FC[i][j][k]);
	fclose ( fp );
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(695,695);
	glutCreateWindow("Proyeccion Del Primer Piso");
	init();
	loadTextures();
	glutDisplayFunc(pintacasa);
	glutKeyboardFunc(teclado1);
	glutSpecialFunc(teclado2);
	glutTimerFunc(250,timer,0);
	glutMainLoop();
}