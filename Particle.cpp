

#include "Particle.h"

Particle::Particle()
{
    
}

Particle::Particle (const Vector3d &p)
{
    Position = p;
}

Particle::Particle (const Vector3d &p,const Vector3d &v, const float &t)
{
    Position = p;
    Velocity = v;
    temperature = t;
}

Particle::Particle( const Vector3d &p, const Vector3d &v, const Vector3d &a, const float l, const int age)
{
    setParticlev(v);
    setParticlep(p);
    setParticlea(a);
    setParticlel(l);
    setParticleage(age);
}

Particle::~Particle()
{
    
}

void Particle::setParticlev(const Vector3d &v)
{
    Particle::Velocity = v;
}

void Particle::setParticlep(const Vector3d &p)
{
    Particle::Position = p;
}

void Particle::setParticlea(const Vector3d &a)
{
    Particle::Acceleration = a;
}

void Particle::setParticlel(const float l)
{
    Particle::lifespan = l;
}

void Particle::setParticleage(const int age)
{
    Age  = age;
}

void Particle::simulate(const double timestep)
{
    update(timestep);
}

void Particle::update(const double timestep)
{
    Position.x = Position.x + (Velocity.x * timestep);
    Position.y = Position.y + (Velocity.y * timestep);
    Position.z = Position.z + (Velocity.z * timestep);
}


void Particle::DrawParticle (float x, float y, float z, GLfloat sphere_diffuseX, GLfloat sphere_diffuseY, GLfloat sphere_diffuseZ, GLfloat sphere_diffuseA )
{
    GLfloat sphere_diffuse[] = { sphere_diffuseX, sphere_diffuseY, sphere_diffuseZ, sphere_diffuseA};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, sphere_diffuse);
    
    glPushMatrix();
    glTranslatef (x,y,z);
    glutSolidSphere(0.05,40,40);
    glPopMatrix ();

}




