#include "Simulator.h"

#include <vector>

Simulator::Simulator(const Vector3d &origin, const int noOfParticles, const double timestep)
{
    setSimulatorp(origin);
    setSimulatorSize(noOfParticles);
    setSimulatorts(timestep);
    particles.reserve(noOfParticles);
}

Simulator::~Simulator()
{
    
}

void Simulator::setSimulatorp(const Vector3d &p)
{
    Simulator::Origin = p;
   
}

void Simulator::setSimulatorSize(const int size)
{
    Simulator::noOfParticles = size;
    
}

void Simulator::setSimulatorts(const double timestep)
{
    timeStep = timestep;
    
}

double Simulator::RandomDouble(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

void Simulator::setFire(Paper& pap)
{
    int i = 0;
    pap.paperParticles[i].temperature = 1.0;
}

void Simulator::burn(Paper& p)
{
    int rmin = 0;
    int cmin = 0;
    int rmax = p.rows - 1;
    int cmax = p.columns - 1;
    float k = 0.4;
    float left = 0, right = 0, top = 0, bottom = 0, self = 0, Tnew = 0, rowid = 0, columnid =0;
    
    
    for (int i = 1; i< p.particleCount;i++)
    {
        
        self = p.paperParticles[i].temperature;
        Tnew = p.paperParticles[i].temperature;
        rowid = i%p.rows;
        columnid = i/p.columns;
        if (columnid != cmin)
        {
            left = p.paperParticles[i-(p.rows)].temperature;
            Tnew = Tnew + ((k + RandomDouble(-0.1, 0.1)) * (left -self));
        }
        if (columnid != cmax)
        {
            right = p.paperParticles[i+(p.rows)].temperature;
            Tnew = Tnew + ((k + RandomDouble(-0.1, 0.1)) * (right - self));
            
        }
        if (rowid != rmin)
        {
            top = p.paperParticles[i -1].temperature;
            Tnew = Tnew + ((k + RandomDouble(-0.1, 0.1)) * (top - self));
            
        }
        if (rowid != rmax)
        {
            bottom = p.paperParticles[i +1].temperature;
            Tnew = Tnew + ((k + RandomDouble(-0.1, 0.1)) *(bottom - self));
        }
        
        p.paperParticles[i].temperature = Tnew;
        
    }
    
    p.drawPaper();
    p.drawMesh();
    
}



