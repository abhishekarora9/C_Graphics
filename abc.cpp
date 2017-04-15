#include <stdio.h>
#include <math.h>

#include <GLUT/glut.h>

#define RDim 44  /* number of raster rows and columns */
#define RasterSize 1.0  /* scaled size of raster within window */
#define PSize 25 /* relative size of my pixels */
#define GridSize 2 /* relative width of pixel border grid */
#define Incr ((2 * RasterSize) / ((PSize + GridSize) * RDim + GridSize))
/* relative increment for window-pixels */

int theRaster[RDim][RDim];

void lineDraw(float x0, float y0, float x1, float y1);
void lineBresenham(int x0, int y0, int x1, int y1);

void display()
{
	int i, j;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (i = 0; i < RDim; i++)
		for (j = 0; j < RDim; j++) {
			glBegin(GL_POLYGON);
            if (theRaster[i][j] == 1)
				glColor3f(0.7, 0.3, 0.5);
				//glColor3f(1.0, 1.0, 0.0);
            else
				glColor3f(1.0, 1.0, 1.0);
			glVertex2f(-RasterSize
					   + (i + 1) * GridSize * Incr + i * PSize * Incr,
					   -RasterSize
					   + (j + 1) * GridSize * Incr + j * PSize * Incr);
            glVertex2f(-RasterSize
					   + (i + 1) * GridSize * Incr
					   + (i + 1) * PSize * Incr,
					   -RasterSize
					   + (j + 1) * GridSize * Incr
					   + j * PSize * Incr);
			
            glVertex2f(-RasterSize
					   + (i + 1) * GridSize * Incr
					   + (i + 1) * PSize * Incr,
					   -RasterSize
					   + (j + 1) * GridSize * Incr
					   + (j + 1) * PSize * Incr);
			
            glVertex2f(-RasterSize
					   + (i + 1) * GridSize * Incr + i * PSize * Incr,
					   -RasterSize
					   + (j + 1) * GridSize * Incr
					   + (j + 1)  * PSize * Incr);
			glEnd();
			glFlush();
		}
			
			
}

int main(int argc, char ** argv)
{
	int i, j;
	
	for (i = 0; i < RDim; i++)
		for (j = 0; j < RDim; j++)
			theRaster[i][j] = 0;
	
	lineDraw(-0.9, -0.75, 0.9, -0.25);
	lineDraw(-0.9, -0.75, 0.9, 0.60);
	lineDraw(-0.9, -0.75, -0.25, 0.90);
	lineDraw(-1.9, 0.75, 0.9, -1.25);
	
	glutInit(&argc, argv);
	if (1)
	glutInitWindowSize(600, 600);
	else
		glutInitWindowSize(300, 300);
	glutCreateWindow("MyRaster");
	glutDisplayFunc(display);
	glutMainLoop();
	   
	return (1);
	
}

void lineDraw(float x0, float y0, float x1, float y1)
{
	int px0, py0, px1, py1;
	
	px0 = (int) ((1 + x0) * RDim / 2);
	py0 = (int) ((1 + y0) * RDim / 2);
	px1 = (int) ((1 + x1) * RDim / 2);
	py1 = (int) ((1 + y1) * RDim / 2);
	
	lineBresenham(px0, py0, px1, py1);
}

void lineBresenham(int x0, int y0, int x1, int y1)
{
    int dx, dy;
    int stepx, stepy;
	
    dx = x1 - x0;
    dy = y1 - y0;
	
    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;                            /* dy is now 2*dy */
    dx <<= 1;                            /* dx is now 2*dx */
    if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
		theRaster[x0][y0] = 1;
	if (dx > dy) {
			int fraction = dy - (dx >> 1);   /* same as 2*dy - dx */
			while (x0 != x1) {
				if (fraction >= 0) {
					y0 += stepy;
					fraction -= dx;           /* same as fraction -= 2*dx */
				}
				x0 += stepx;
				fraction += dy;               /* same as fraction -= 2*dy */
				if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
					theRaster[x0][y0] = 1;
			}
		} else {
			int fraction = dx - (dy >> 1);
			while (y0 != y1) {
				if (fraction >= 0) {
					x0 += stepx;
					fraction -= dy;
				}
				y0 += stepy;
				fraction += dx;
				if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
					theRaster[x0][y0] = 1;
			}
		}
}
