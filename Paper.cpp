#include "Paper.h"
#include "Spring.h"

Paper::Paper()
{
    
}

Paper::~Paper()
{
    
}

void Paper::createPaper(const int &nrow, const int &ncol, const float &den)
{
    
    int dim = nrow * ncol;
    particleCount = dim;
    paperParticles.reserve(particleCount);
    rows = nrow;
    columns = ncol;
    density = den;
    width = columns * density;
    height = rows * density;
    std::cout<<width<<height;
    
    for ( int i = 0; i< rows; i++)
    {
        for ( int j = 0; j< columns; j++)
        {
            float x = i;
            float y = j;
            Vector3d pos((x*density),(y*density),0);
            Vector3d vel(0,0,0);
            paperParticles.push_back(Particle(pos,vel,0.0));
            
        }
    }
    
    
}

void Paper::drawMesh()
{
    
    
    for (int i = 0; i< particleCount;i++)
    {
        //columns
        std::cout<<"drawing columns";
        
        if (((i+1)%columns) != 0)
        {
            
            glBegin(GL_LINES);
            
            glVertex3f(paperParticles[i].Position.x, paperParticles[i].Position.y, paperParticles[i].Position.z);
            glVertex3f(paperParticles[i+1].Position.x, paperParticles[i+1].Position.y, paperParticles[i+1].Position.z);
            
            glEnd();
        }
        
    }
    
    
     
     for (int i = 0; i< (particleCount-rows);i++)
     {
     //rows
     std::cout<<"drawing columns";
     
     
     glBegin(GL_LINES);
     
     glVertex3f(paperParticles[i].Position.x, paperParticles[i].Position.y, paperParticles[i].Position.z);
     glVertex3f(paperParticles[i+rows].Position.x, paperParticles[i+rows].Position.y, paperParticles[i+rows].Position.z);
     
     glEnd();
    
     
     }
    
     
     for (int i = 0; i< (particleCount-rows-1);i++)
     {
     //diagonals
     std::cout<<"drawing diagonals";
     
     if (((i+1)%rows) != 0)
     {
     
     glBegin(GL_LINES);
     
     glVertex3f(paperParticles[i].Position.x, paperParticles[i].Position.y, paperParticles[i].Position.z);
     glVertex3f(paperParticles[i+rows+1].Position.x, paperParticles[i+rows+1].Position.y, paperParticles[i+rows+1].Position.z);
     
     glEnd();
     }
     
     }
     
     
}

void Paper::drawPaper()
{
    float x,y,z;
    for (unsigned int i = 0; i< particleCount; i++)
    {
        x = paperParticles[i].Position.x;
        y = paperParticles[i].Position.y;
        z = paperParticles[i].Position.z;
        if (paperParticles[i].temperature > 0.44)
        {
            paperParticles[i].color = Vector4d(1.0,0.4,0.0, 1.0);
                if (paperParticles[i].temperature>0.45)
                    {
                        paperParticles[i].color = Vector4d(0.4,0.4,0.4, 1.0);
                        //paperParticles[i].Velocity = Vector3d(-0.09,-0.078,0.0);
                
                            if (paperParticles[i].temperature>0.46)
                                {
                                    paperParticles[i].color = Vector4d(0.4,0.4,0.4, 0.0);

                                }
                    }
        }
        else
            paperParticles[i].color= Vector4d(1.0,1.0,1.0, 1.0);

        paperParticles[i].simulate(0.08);
        paperParticles[i].DrawParticle(x,y,z, paperParticles[i].color.x, paperParticles[i].color.y, paperParticles[i].color.z, paperParticles[i].color.w);
        
       
        

    }

}





