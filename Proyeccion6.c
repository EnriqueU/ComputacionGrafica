#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <FreeImage.h>
#define PI 3.141592
int texID[7];
char* textureFileNames[7] = {
"textures/Piso2.jpg",
"textures/ParedRoja2.jpg",
"textures/ParedCrema.jpg",
"textures/grass.jpg",
"textures/stucco.jpg",
"textures/Madera.jpg",
"textures/Negro.png"
};
float pos[3];
float at[3];
float up[3];
float dir[3];
int angH;
int angV;
float mod;
int FC[100][40][200];
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
		//Marron();
		glBindTexture(GL_TEXTURE_2D, texID[5]);
		textura(i,j,k);
	}else if(FC[i][j][k]==4){
		glBindTexture(GL_TEXTURE_2D, texID[0]);
		textura(i,j,k);
	}else if(FC[i][j][k]==5){
		//Plomo();
		glBindTexture(GL_TEXTURE_2D, texID[4]);
		textura(i,j,k);
	}else if(FC[i][j][k]==6){
		//Verde();
		glBindTexture(GL_TEXTURE_2D, texID[3]);
		textura(i,j,k);
	}else if(FC[i][j][k]==7){
		//Negro();
		glBindTexture(GL_TEXTURE_2D, texID[6]);
		Draw2(i,j,k);
	}
}
void init(){
	glClearColor(0.0,0.0,0.0,1.0);
	// Posicion de la camara
	pos[0] = 30.0;
	pos[1] = 30;
	pos[2] = 10.0;
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
	dir[0] = cos(PI*angH/180.0)/100;
	dir[2] = sin(PI*angH/180.0)/100;
	at[0] = pos[0]+dir[0];
	at[1] = pos[1]+mod*sin(PI*angV/180.0);
	at[2] = pos[2]+dir[2];
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
				i = pos[0]+10*20*dir[0];
				j = pos[1];
				k = pos[2]+10*20*dir[2];
				if(FC[i][j][k]==0){
					pos[0]+=20*dir[0];
					pos[2]+=20*dir[2];
				}
			break; 
		case 's':
			i = pos[0]-10*20*dir[0];
			j = pos[1];
			k = pos[2]-10*20*dir[2];
			if(FC[i][j][k]==0){
				pos[0]-=20*dir[0];
				pos[2]-=20*dir[2];
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
  glGenTextures(7, texID);  // Obtener el Id textura .
  for (i = 0; i < 7; i++) {
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
	i = pos[0]+10*20*dir[0];
	j = pos[1];
	k = pos[2]+10*20*dir[2];
	if(FC[i][j][k]==0){
		pos[0]+=100*dir[0];
		pos[2]+=100*dir[2];
	}
	glutPostRedisplay();
	glutTimerFunc(10,timer,rand()%2);
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
	glutInitWindowPosition(0,0);
	glutInitWindowSize(695,695);
	glutCreateWindow("Proyeccion Del Primer Piso");
	init();
	loadTextures();
	glutDisplayFunc(pintacasa);
	glutKeyboardFunc(teclado1);
	glutSpecialFunc(teclado2);
	glutTimerFunc(10,timer,0);
	glutMainLoop();
}
