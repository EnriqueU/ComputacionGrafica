#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
int aux1,aux2,aux3;
int timer=0;
int matriz[15][15]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,1,1,1,0,1,1,1,0,1,0,0},
					{0,1,0,0,1,0,0,0,1,0,0,0,0,1,0},
					{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
					{0,1,0,0,1,0,0,0,1,0,0,0,0,1,0},
					{0,0,1,0,1,1,1,0,1,1,1,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,1,1,1,1,0,1,0,0,1,1,0,1,1,0},
					{0,1,0,0,1,0,1,0,0,1,1,0,1,1,0},
					{0,1,0,0,1,0,1,1,1,1,1,0,1,1,0},
					{0,1,0,0,1,0,1,1,0,0,1,0,1,1,0},
					{0,1,0,0,1,0,1,1,0,0,1,0,1,1,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,1,1,1,1,1,0,1,0,1,1,1,1,1,0},
					{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}};
void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,600,0.0,600);
}
//-------------------------CLASE DE GHOST-----------------------------
class Ghost{
	public:
	int posX, posY, posZ;
	int s1,s2,s3,S;
	int v,act;
	int X,Y;
	Ghost(int x,int y);
	void drawGhost(int r);
	void moveGhost();
	void TimerGhost(int value);
	void activo();
};
Ghost::Ghost(int x,int y){
	this->X = x;
	this->Y = y;
	this->posX = 0;
	this->posY = 0;
	this->posZ = 0;
	this->s1 = 1;
	this->s2 = 0;
	this->s3 = 0;
	this->v = 5;
	this->act = 1;
}
void Ghost::drawGhost(int r){
	GLfloat angulo;
	int i;
	glLineWidth(2);
	// CUerpo
	glBegin(GL_LINES);
	for(i=0;i<360;i+=1){
		angulo = (GLfloat)i*3.14159f/180.0f;
		glColor3f(1.0, 0.0, 0.0);
		r=20;
		glVertex2i(X,Y);
		glVertex2i(X+r*cos(angulo),Y+r*sin(angulo));
	}
	for(i=0;i<360;i+=1){
		r=5;
		angulo = (GLfloat)i*3.14159f/180.0f;
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(X+14.14,Y+14.14);
		glVertex2i(X+14.14+r*cos(angulo),Y+14.14+r*sin(angulo));
		glVertex2i(X+14.14,Y-14.14);
		glVertex2i(X+14.14+r*cos(angulo),Y-14.14+r*sin(angulo));
		glVertex2i(X-14.14,Y+14.14);
		glVertex2i(X-14.14+r*cos(angulo),Y+14.14+r*sin(angulo));
		glVertex2i(X-14.14,Y-14.14);
		glVertex2i(X-14.14+r*cos(angulo),Y-14.14+r*sin(angulo));
	}
	glEnd();
	// OJO
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	for(i=0;i<360;i+=1){
		angulo = (GLfloat)i*3.14159f/180.0f;
		glVertex2i(X-7,Y+10);
		glVertex2i(X-7+3*cos(angulo),Y+10+3*sin(angulo));
	}
	for(i=0;i<360;i+=1){
		angulo = (GLfloat)i*3.14159f/180.0f;
		glVertex2i(X+7,Y+10);
		glVertex2i(X+7+3*cos(angulo),Y+10+3*sin(angulo));
	}
	glEnd();
}
void Ghost::moveGhost(){
	glPushMatrix();
    glTranslatef(posX, posY, posZ);
	if(s1==2){
    	glTranslatef(X,Y,0);
		glRotatef(180,0,1,0);
    	glTranslatef(-X,-Y,0);
    }else if(s1==3){
    	glTranslatef(X,Y,0);
    	if(s2==1){
			glRotatef(90,0,0,1);
    	}else if(s2==2){
    		glRotatef(180,0,1,0);
    		glRotatef(90,0,0,1);
    	}else if(s2==4 && s3==1){
    		glRotatef(180,0,1,0);
    		glRotatef(90,0,0,1);
    	}else if(s2==4 && s3==2){
    		glRotatef(90,0,0,1);
    	}
    	glTranslatef(-X,-Y,0);
    }else if(s1==4){
    	glTranslatef(X,Y,0);
    	if(s2==1){
			glRotatef(-90,0,0,1);
    	}else if(s2==2){
    		glRotatef(180,0,1,0);
    		glRotatef(-90,0,0,1);
    	}else if(s2==3 && s3==1){
    		glRotatef(-90,0,0,1);
    		glRotatef(180,1,0,0);
    	}else if(s2==3 && s3==2){
    		glRotatef(180,0,1,0);
    		glRotatef(-90,0,0,1);
    		glRotatef(180,1,0,0);
    	}
    	glTranslatef(-X,-Y,0);
    }
	drawGhost(20);
	glPopMatrix();
}
void Ghost::activo(){
	switch(act){
	case 1:
	aux1 = (X+19+(int)posX+v)/40;
	aux2 = (Y+19+(int)posY)/40;
	aux3 = (Y-19+(int)posY)/40;
	if(posX+v<=560-(X-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)posY)%40==0 ){
		posX += v;
		act = 1;
		if(s1!=1){
			s3=s2;
			s2=s1;
			s1=1;
		}
	}
	break;
	case 2:
	aux1 = (X-19+(int)posX-v)/40;
	aux2 = (Y+19+(int)posY)/40;
	aux3 = (Y-19+(int)posY)/40;
	if(posX-v>=(20-X) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)posY)%40==0 ){
		posX -= v;
		act = 2;
		if(s1!=2){
			s3=s2;
			s2=s1;
			s1=2;
		}
	}
	break;
	case 3:
	aux1 = (X+19+(int)posX)/40;
	aux2 = (Y+19+(int)posY+v)/40;
	aux3 = (X-19+(int)posX)/40;
	if(posY+v<=560-(Y-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)posX)%40==0 ){
		posY += v;
		act = 3;
		if(s1==4 && s2==3){
			s1=3;
			s2=4;	
		}else if(s1!=3){
			s3=s2;
			s2=s1;
			s1=3;
		}
	}
	break;
	case 4:
	aux1 = (X+19+(int)posX)/40;
	aux2 = (Y-19+(int)posY-v)/40;
	aux3 = (X-19+(int)posX)/40;
	if(posY-v>=(20-Y) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)posX)%40==0 ){
		posY -= v;
		act = 4;
		if(s1==3 && s2==4){
			s1=4;
			s2=3;
		}else if(s1!=4){
			s3=s2;
			s2=s1;
			s1=4;
		}
	}
	break;
	}
}
void Ghost::TimerGhost(int value){
	if( (value+s1)==3 || (value+s1)==7 ){
		value++;
	}
	switch(value){
	case 1:
	aux1 = (X+19+(int)posX+v)/40;
	aux2 = (Y+19+(int)posY)/40;
	aux3 = (Y-19+(int)posY)/40;
	if(posX+v<=560-(X-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)posY)%40==0 ){
		posX += v;
		act = 1;
		if(s1!=1){
			s3=s2;
			s2=s1;
			s1=1;
		}
		act = value;
	}else{ activo();}
	break;
	case 2:
	aux1 = (X-19+(int)posX-v)/40;
	aux2 = (Y+19+(int)posY)/40;
	aux3 = (Y-19+(int)posY)/40;
	if(posX-v>=(20-X) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)posY)%40==0 ){
		posX -= v;
		act = 2;
		if(s1!=2){
			s3=s2;
			s2=s1;
			s1=2;
		}
		act = value;
	}else{ activo();}
	break;
	case 3:
	aux1 = (X+19+(int)posX)/40;
	aux2 = (Y+19+(int)posY+v)/40;
	aux3 = (X-19+(int)posX)/40;
	if(posY+v<=560-(Y-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)posX)%40==0 ){
		posY += v;
		act = 3;
		if(s1==4 && s2==3){
			s1=3;
			s2=4;	
		}else if(s1!=3){
			s3=s2;
			s2=s1;
			s1=3;
		}
		act = value;
	}else{ activo();}
	break;
	case 4:
	aux1 = (X+19+(int)posX)/40;
	aux2 = (Y-19+(int)posY-v)/40;
	aux3 = (X-19+(int)posX)/40;
	if(posY-v>=(20-Y) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)posX)%40==0 ){
		posY -= v;
		act = 4;
		if(s1==3 && s2==4){
			s1=4;
			s2=3;
		}else if(s1!=4){
			s3=s2;
			s2=s1;
			s1=4;
		}
		act = value;
	}else{ activo();}
	break;
	}
}
//----------------------------CLASE PACMAN----------------------------
class Pacman{
	public:
	int posX, posY, posZ;
	int s1,s2,s3,S;
	int v,act;
	int X,Y;
	int numBol;
	Pacman(int x,int y);
	void drawPacman(int r);
	void movePacman();
	void colision(Ghost g);
	void bolitas();
};
Pacman::Pacman(int x,int y){
	this->X = x;
	this->Y = y;
	this->posX = 0;
	this->posY = 0;
	this->posZ = 0;
	this->s1 = 1;
	this->s2 = 0;
	this->s3 = 0;
	this->v = 5;
	this->act = 1;
	this->S = 1;
	this->numBol=0;
}
void Pacman::bolitas(){
	if(posX%40==0 && posY%40==0 
	&& matriz[(posY+Y)/40][(posX+X)/40] ==0 ){
		matriz[(posY+Y)/40][(posX+X)/40] = 3;
		numBol++;
	}
}
void Pacman::colision(Ghost g){
if( abs((g.X+g.posX)-(X+posX))<40 && (g.Y+g.posY)==(Y+posY)){
	exit(0);
	
}else if( abs((g.Y+g.posY)-(Y+posY))<40 && (g.X+g.posX)==(X+posX)){
	exit(0);
}
}
void Pacman::drawPacman(int r){
	GLfloat angulo;
	int i;
	glLineWidth(2);
	// CUerpo
	glBegin(GL_LINES);
	for(i=40;i<360;i+=1){
		angulo = (GLfloat)i*3.14159f/180.0f;
		glColor3f(1.0, 1.0, 0.0);
		glVertex2i(X,Y);
		glColor3f(0.5, 0.5, 0.0);
		glVertex2i(X+r*cos(angulo),Y+r*sin(angulo));
	}
	glEnd();
	// OJO
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for(i=0;i<360;i+=1){
		angulo = (GLfloat)i*3.14159f/180.0f;
		glVertex2i(X-3,Y+10);
		glVertex2i(X-3+5*cos(angulo),Y+10+5*sin(angulo));
	}
	glEnd();
}
// Mueve al pacman
void Pacman::movePacman(){
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
	if(s1==2){
    	glTranslatef(X,Y,0);
		glRotatef(180,0,1,0);
    	glTranslatef(-X,-Y,0);
    }else if(s1==3){
    	glTranslatef(X,Y,0);
    	if(s2==1){
			glRotatef(90,0,0,1);
    	}else if(s2==2){
    		glRotatef(180,0,1,0);
    		glRotatef(90,0,0,1);
    	}else if(s2==4 && s3==1){
    		glRotatef(180,0,1,0);
    		glRotatef(90,0,0,1);
    	}else if(s2==4 && s3==2){
    		glRotatef(90,0,0,1);
    	}
    	glTranslatef(-X,-Y,0);
    }else if(s1==4){
    	glTranslatef(X,Y,0);
    	if(s2==1){
			glRotatef(-90,0,0,1);
    	}else if(s2==2){
    		glRotatef(180,0,1,0);
    		glRotatef(-90,0,0,1);
    	}else if(s2==3 && s3==1){
    		glRotatef(-90,0,0,1);
    		glRotatef(180,1,0,0);
    	}else if(s2==3 && s3==2){
    		glRotatef(180,0,1,0);
    		glRotatef(-90,0,0,1);
    		glRotatef(180,1,0,0);
    	}
    	glTranslatef(-X,-Y,0);
    }
	drawPacman(20);
	glPopMatrix();
}
//----------------------------DIBUJA EL JUEGO-------------------------
Pacman p1(20,20);
Ghost g1(340,340);
Ghost g2(340,340);
Ghost g3(340,340);
Ghost g4(340,340);
Ghost g5(340,340);
void cuadrados(int X, int Y){
	glBegin(GL_POINTS);
	int i,j;
	for(i=-20;i<=20;i++){
		for(j=20;j>=-20;j--){
			if((i+j)%2==0){
				glColor3f(0.0,1.0,0.0);
			}else if((i+j)%3==0){
				glColor3f(0.0,0.0,1.0);
			}else if((i+j)%5==0){
				glColor3f(0.0,0.0,0.0);
			}
			glVertex2i(X+i,Y+j);
		}
	}
	glEnd();
}
void pintacasa(){
	glClear(GL_COLOR_BUFFER_BIT);
	// Dibujando el mapa
	p1.bolitas();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	int i,j,k,aux1,aux2;
	// Dibujos de cuadrados y bolitas
	for(i=20;i<=580;i=i+40){
		for(j=20;j<=580;j=j+40){
			aux1 = i/40;
			aux2 = j/40;
			if(matriz[aux2][aux1]==1){
				cuadrados(i,j);
			}else if(matriz[aux2][aux1]==0){
				GLfloat angulo;
				glLineWidth(1);
				glBegin(GL_LINES);
				for(k=0;k<360;k+=1){
					angulo = (GLfloat)k*3.14159f/180.0f;
					glColor3f(1.0, 1.0, 0.0);
					glVertex2i(i,j);
					glVertex2i(i+5*cos(angulo),j+5*sin(angulo));
				}
				glEnd();
			}
		}
	}
	p1.movePacman();
	if(timer<5000){
		g1.moveGhost();
	}else if(timer<10000){
		g1.moveGhost();
		g2.moveGhost();
	}else if(timer<15000){
		g1.moveGhost();
		g2.moveGhost();
		g3.moveGhost();
	}else if(timer<20000){
		g1.moveGhost();
		g2.moveGhost();
		g3.moveGhost();
		g4.moveGhost();
	}else if(timer>=20000){
		g1.moveGhost();
		g2.moveGhost();
		g3.moveGhost();
		g4.moveGhost();
		g5.moveGhost();
	}
	glColor3f(1.0, 1.0, 1.0);// Fondo
	glutSwapBuffers();
}
//------------------------------------------------------------
// Manejo con flechas
void eventosteclado(int key,int x, int y) {
    switch (key) {
	case GLUT_KEY_RIGHT:
	aux1 = (p1.X+19+(int)p1.posX+p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX+p1.v<=560-(p1.X-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)p1.posY)%40==0 ){
		p1.posX += p1.v;
		p1.act = 1;
		p1.S = 1;
		if(p1.s1!=1){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=1;
		}
	}else p1.S=1;
	break;
	case GLUT_KEY_LEFT:
	aux1 = (p1.X-19+(int)p1.posX-p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX-p1.v>=(20-p1.X) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)p1.posY)%40==0 ){
		p1.posX -= p1.v;
		p1.act = 2;
		p1.S = 2;
		if(p1.s1!=2){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=2;
		}
	}else p1.S=2;
	break;
	case GLUT_KEY_UP:
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y+19+(int)p1.posY+p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY+p1.v<=560-(p1.Y-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)p1.posX)%40==0 ){
		p1.posY += p1.v;
		p1.act = 3;
		p1.S = 3;
		if(p1.s1==4 && p1.s2==3){
			p1.s1=3;
			p1.s2=4;	
		}else if(p1.s1!=3){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=3;
		}
	}else p1.S=3;
	break;
	case GLUT_KEY_DOWN:
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y-19+(int)p1.posY-p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY-p1.v>=(20-p1.Y) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)p1.posX)%40==0 ){
		p1.posY -= p1.v;
		p1.act = 4;
		p1.S = 4;
		if(p1.s1==3 && p1.s2==4){
			p1.s1=4;
			p1.s2=3;
		}else if(p1.s1!=4){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=4;
		}
	}else p1.S=4;
	break;
    }
	glutPostRedisplay();
}
// Manejo con letras
void keyboard(unsigned char key, int x, int y){
	switch (key){
	case 27:
		exit(0);
	break;
	case 'd':
	aux1 = (p1.X+19+(int)p1.posX+p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX+p1.v<=560-(p1.X-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)p1.posY)%40==0 ){
		p1.posX += p1.v;
		p1.act = 1;
		p1.S = 1;
		if(p1.s1!=1){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=1;
		}
	}else p1.S=1;
	break;
	case 'a':
	aux1 = (p1.X-19+(int)p1.posX-p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX-p1.v>=(20-p1.X) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)p1.posY)%40==0 ){
		p1.posX -= p1.v;
		p1.act = 2;
		p1.S = 2;
		if(p1.s1!=2){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=2;
		}
	}else p1.S=2;
	break;
	case 'w':
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y+19+(int)p1.posY+p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY+p1.v<=560-(p1.Y-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)p1.posX)%40==0 ){
		p1.posY += p1.v;
		p1.act = 3;
		p1.S = 3;
		if(p1.s1==4 && p1.s2==3){
			p1.s1=3;
			p1.s2=4;	
		}else if(p1.s1!=3){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=3;
		}
	}else p1.S=3;
	break;
	case 's':
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y-19+(int)p1.posY-p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY-p1.v>=(20-p1.Y) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)p1.posX)%40==0 ){
		p1.posY -= p1.v;
		p1.act = 4;
		p1.S = 4;
		if(p1.s1==3 && p1.s2==4){
			p1.s1=4;
			p1.s2=3;
		}else if(p1.s1!=4){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=4;
		}
	}else p1.S=4;
	break;
	}
	glutPostRedisplay();
}
void activo(){
	switch(p1.act){
	case 1:
	aux1 = (p1.X+19+(int)p1.posX+p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX+p1.v<=560-(p1.X-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1){
		p1.posX += p1.v;
		p1.act = 1;
		if(p1.s1!=1){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=1;
		}
	}
	break;
	case 2:
	aux1 = (p1.X-19+(int)p1.posX-p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX-p1.v>=(20-p1.X) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1){
		p1.posX -= p1.v;
		p1.act = 2;
		if(p1.s1!=2){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=2;
		}
	}
	break;
	case 3:
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y+19+(int)p1.posY+p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY+p1.v<=560-(p1.Y-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1){
		p1.posY += p1.v;
		p1.act = 3;
		if(p1.s1==4 && p1.s2==3){
			p1.s1=3;
			p1.s2=4;	
		}else if(p1.s1!=3){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=3;
		}
	}
	break;
	case 4:
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y-19+(int)p1.posY-p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY-p1.v>=(20-p1.Y) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1){
		p1.posY -= p1.v;
		p1.act = 4;
		if(p1.s1==3 && p1.s2==4){
			p1.s1=4;
			p1.s2=3;
		}else if(p1.s1!=4){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=4;
		}
	}
	break;
	}
}
// Para que el pacman se siga moviendo
void Timer(int value){
	switch(p1.S){
	case 1:
	aux1 = (p1.X+19+(int)p1.posX+p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX+p1.v<=560-(p1.X-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)p1.posY)%40==0 ){
		p1.posX += p1.v;
		p1.act = 1;
		if(p1.s1!=1){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=1;
		}
		p1.act = p1.S;
	}else{ activo();}
	break;
	case 2:
	aux1 = (p1.X-19+(int)p1.posX-p1.v)/40;
	aux2 = (p1.Y+19+(int)p1.posY)/40;
	aux3 = (p1.Y-19+(int)p1.posY)/40;
	if(p1.posX-p1.v>=(20-p1.X) && matriz[aux2][aux1]!=1 
	&& matriz[aux3][aux1]!=1 && ((int)p1.posY)%40==0 ){
		p1.posX -= p1.v;
		p1.act = 2;
		if(p1.s1!=2){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=2;
		}
		p1.act = p1.S;
	}else{ activo();}
	break;
	case 3:
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y+19+(int)p1.posY+p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY+p1.v<=560-(p1.Y-20) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)p1.posX)%40==0 ){
		p1.posY += p1.v;
		p1.act = 3;
		if(p1.s1==4 && p1.s2==3){
			p1.s1=3;
			p1.s2=4;	
		}else if(p1.s1!=3){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=3;
		}
		p1.act = p1.S;
	}else{ activo();}
	break;
	case 4:
	aux1 = (p1.X+19+(int)p1.posX)/40;
	aux2 = (p1.Y-19+(int)p1.posY-p1.v)/40;
	aux3 = (p1.X-19+(int)p1.posX)/40;
	if(p1.posY-p1.v>=(20-p1.Y) && matriz[aux2][aux1]!=1 
	&& matriz[aux2][aux3]!=1 && ((int)p1.posX)%40==0 ){
		p1.posY -= p1.v;
		p1.act = 4;
		if(p1.s1==3 && p1.s2==4){
			p1.s1=4;
			p1.s2=3;
		}else if(p1.s1!=4){
			p1.s3=p1.s2;
			p1.s2=p1.s1;
			p1.s1=4;
		}
		p1.act = p1.S;
	}else{ activo();}
	break;
	}
	timer+=35;
	if(timer<5000){
		g1.TimerGhost(rand()%4+1);
		p1.colision(g1);
	}else if(timer<10000){
		g1.TimerGhost(rand()%4+1);
		g2.TimerGhost(rand()%4+1);
		p1.colision(g1);
		p1.colision(g2);
	}else if(timer<15000){
		g1.TimerGhost(rand()%4+1);
		g2.TimerGhost(rand()%4+1);
		g3.TimerGhost(rand()%4+1);
		p1.colision(g1);
		p1.colision(g2);
		p1.colision(g3);
	}else if(timer<20000){
		g1.TimerGhost(rand()%4+1);
		g2.TimerGhost(rand()%4+1);
		g3.TimerGhost(rand()%4+1);
		g4.TimerGhost(rand()%4+1);
		p1.colision(g1);
		p1.colision(g2);
		p1.colision(g3);
		p1.colision(g4);
	}else if(timer>=20000){
		g1.TimerGhost(rand()%4+1);
		g2.TimerGhost(rand()%4+1);
		g3.TimerGhost(rand()%4+1);
		g4.TimerGhost(rand()%4+1);
		g5.TimerGhost(rand()%4+1);
		p1.colision(g1);
		p1.colision(g2);
		p1.colision(g3);
		p1.colision(g4);
		p1.colision(g5);
	}
	if(p1.numBol==158){
		exit(0);
	}
	glutPostRedisplay();
	glutTimerFunc(35,Timer,0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow("Pacman");
	init();
	glutDisplayFunc(pintacasa);
	glutSpecialFunc(eventosteclado);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(35,Timer,0);
	glutMainLoop();
}
