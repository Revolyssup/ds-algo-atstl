#pragma once
#include<cmath>
namespace atstl{
    namespace calculas{
        //Differential calculas stuff

    //Using the phase space of theta-thetaDot to solve the problem with initial conditions
    class pendulum{
        double g=9.81; //Acceleration due to gravity
        double len; //length in metres
        double theta;
        double mu; //coefficient of air friction
        double theta_dot;
        double getThetadoubleDot(double theta_temp,double theta_dot_temp){
            return -((mu*theta_dot_temp) + ((g/len)*std::sin(theta_temp)));
        }
        public:
        //With no initial angular velocity.

        //With no air friction.Give angle in degrees.
        pendulum(double l,double theta_init,double thetaDot):len(l),theta(theta_init*(3.14159/180)),mu(0),theta_dot(thetaDot){}
        //With air friction
        pendulum(double l,double theta_init,double thetaDot,double m):len(l),theta(theta_init*(3.14159/180)),mu(m),theta_dot(thetaDot){}
        double getThetaT(double t){
             double delta_t=0.001;
             double time=0;
             double theta_new=theta;
             double theta_dot_temp=theta_dot;
             while(time<t){
                 time+=delta_t;
                 theta_new+=theta_dot_temp*delta_t;
                 theta_dot_temp+=(getThetadoubleDot(theta_new,theta_dot_temp)*delta_t);
             }
             return (theta_new*(180/3.14159));
        }

        double timePeriod(){
            return 2*3.14159*std::sqrt((len/g));
        }
    };
    }
    
   
}