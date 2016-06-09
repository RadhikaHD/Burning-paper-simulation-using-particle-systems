
#ifndef Paper_h
#define Paper_h

#include <stdio.h>
#include "Particle.h"
#include "Matrix.h"
#include <vector>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif



class Paper
{
public:
    
    float width;
    float height;
    int rows;
    int columns;
    int particleCount;
    float density;
    bool burnt;
    
    
    
    std::vector<Particle> paperParticles;
    
    Paper();
    ~Paper();
    
    void createPaper(const int &nrow, const int &ncol, const float &density);
    void drawPaper ();
    void drawMesh();
    
    
};
#endif /* Paper_h */
