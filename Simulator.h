#ifndef Simulator_h
#define Simulator_h

#include "Particle.h"
#include "Paper.h"
#include <vector>

class Simulator
{
    
public:
    
    int noOfParticles;
    double timeStep;
    Vector3d Origin;
    std::vector<Particle> particles;
    Paper burningPaper;
    
    Simulator(const Vector3d &origin, const int noOfParticles, const double timestep);
    ~Simulator();
    
    void setSimulatorp(const Vector3d &p);
    void setSimulatorSize(const int size);
    void setSimulatorts(const double timestep);
    
    void setFire(Paper &pap);
    void burn(Paper &pap);
  
    double RandomDouble(double a, double b);
    
};

#endif
