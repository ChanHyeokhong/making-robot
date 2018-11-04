#include <GL/glut.h>
#include <math.h>

#define BASE_HEIGHT 4.0/2
#define BASE_RADIUS 1.0/2
#define HEIGHT1 1.25/2
#define HEIGHT2 3.0/2
#define WIDTH1 0.5/2
#define TRANSLATION 0.22/2
static GLfloat theta[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,5.3,1.25};
GLfloat Y[] = {0.0,0.0};
GLUquadricObj *p;
GLfloat ambient[3];
GLfloat diffuse[3];
GLfloat specular[3];
GLfloat shiness[] = {50.0f};
void base(void);
void sehyang(void);
void gondhak(void);
void init(void);
void display(void);
void reshape (int, int);
void keyboard(unsigned char, int, int);
void road(void);


void base (void) {
double angle, angleInc;
int i;
angle = 3.14159265 / 180;
angleInc = angle;
glPushMatrix();
ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 0.0;
diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glRotatef (90.0, 3.0, 0.0, 0.0);
gluQuadricDrawStyle(p, GLU_FILL);
gluSphere (p, 2,2, 30);
glPopMatrix();
}



void road(void)
{
	    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); 
    glVertex2f(-1.5f, -1.5f);    
    glVertex2f(15.5f, -1.5f);
    glVertex2f(15.5f, 1.5f);
    glVertex2f(-15.5f, 1.5f);
    glEnd();
}


void sehyang(void) {
glPushMatrix();
ambient[0] = 0.0; ambient[1] = 1.0; ambient[2] = 0.0;
diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glTranslatef(0.0, 0.5 * HEIGHT2, TRANSLATION);
glScalef(WIDTH1, HEIGHT2, WIDTH1);
glutSolidCube(1.0);
glPopMatrix();
}

void gondhak(void) {
glPushMatrix();
ambient[0] = 0.0; ambient[1] = 1.0; ambient[2] = 0.0;
diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
glTranslatef(0.0, 0.5 * HEIGHT2, -TRANSLATION);
glScalef(WIDTH1, HEIGHT2, WIDTH1);
glutSolidCube(1.0);
glPopMatrix();
}

void display(void) {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(0.3, 5.3, 13.0+Y[0], 0.0, 1.25, -15.0, 0.0, 1.0, -10.0);
glPopMatrix();
glPushMatrix();
glTranslatef(BASE_RADIUS+0.5, BASE_HEIGHT - BASE_RADIUS / 2-1, 6.0);
glRotatef(180.0, 0.0, 0.0, 1.0);
glRotatef(270.0, 0.0, 1.0, 0.0);
glRotatef(theta[4], 0.0, 0.0, 1.0);
base();
glTranslatef(0.0, HEIGHT2, 0.0);
glRotatef(0.0, 0.0, 0.0, 180.0);
glRotatef(theta[6], 0.0, 0.0, 1.0);
glPopMatrix();
glPushMatrix();
glTranslatef(-BASE_RADIUS, 1.0, 0.0);
glRotatef(180.0, 0.0, 0.0, 1.0);
glRotatef(270.0, 0.0, 1.0, 0.0);
glRotatef(theta[3]+555.0, 0.0, 0.0, 1.0);
sehyang();
glTranslatef(0.0, HEIGHT2, 0.0);
glRotatef(0.0, 0.0, 0.0, 180.0);
glRotatef(theta[5], 0.0, 0.0, 1.0);
glPopMatrix();
glPushMatrix();
glTranslatef(BASE_RADIUS+6, BASE_HEIGHT + HEIGHT1/1, -3.0);
glRotatef(theta[2]+20, 1.0, 0.0, 0.0);
gondhak();
glPushMatrix();
glTranslatef(BASE_RADIUS-9, BASE_HEIGHT + HEIGHT1/1, -3.0);
glRotatef(180.0, 0.0, 0.0, 100.0);
glRotatef(270.0, 0.0, 1.0, 0.0);
glRotatef(theta[3], 20.0, 90.0, 0.0);
road();
glFlush();
glutSwapBuffers();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void keyboard (unsigned char key, int x, int y) 
{switch(key){
	case 'w':
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		Y[0]+=1.0;
		gluLookAt(0.3, 5.3, 13.0+Y[0], 0.0, 1.25, -15.0, 0.0, 1.0, -10.0);
		glutPostRedisplay( );
		break;
	case 's':
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		Y[0]-=1.0;
		gluLookAt(0.3, 5.3, 13.0+Y[0], 0.0, 1.25, -15.0, 0.0, 1.0, -10.0);
		glutPostRedisplay( );
		break;
	default :
		break;
	}
	glutPostRedisplay( );
}
void reshape(int w, int h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(80.0, (GLfloat) w / (GLfloat) h, 0.5, 100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void init (void) { 
glEnable(GL_LIGHTING); 
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
p = gluNewQuadric();
}

int main(int argc, char **argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize(500, 500);   
glutInitWindowPosition(100, 100); 
glutCreateWindow("ÇÐ±³");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}

