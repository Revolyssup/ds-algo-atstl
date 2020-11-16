#pragma once
#include<cmath>
#include<complex>
#include<vector>


namespace atstl{
    //type definitions
    typedef std::complex<double> cd;


    /****************************/
    namespace maths{
        std::vector<cd> FFT(std::vector<cd>& a){
            int n=a.size();
            if(n==1) return std::vector<cd>(1,a[0]);
            std::vector<cd> exp(n);
            for(int itr=0;itr<n;itr++){
                double alpha=-2*M_1_PI*itr/n;               //W^(-1)
                exp[itr]=cd(cos(alpha),sin(alpha));        //W*(itrTH root of unity)
                
            }

            std::vector<cd> A0(n/2),A1(n/2);
            for(auto itr=0;itr<n/2;itr++){ 
                A0[itr]=a[itr*2];
                A1[itr]=a[itr*2+1];
            }
            std::vector<cd> y0=FFT(A0); //Calculated y0 for all m's from 0 to n-1 in it
            std::vector<cd> y1=FFT(A1);
            std::vector<cd> y(n);
            for(int i=0;i<n/2;i++){
                y[i]=y0[i]+exp[i]*y1[i];
                y[i+(n/2)]=y0[i]-exp[i]*y1[i];
            }
            return y;
        } 

    


    } // namespace maths
    




    namespace physics{
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
             double delta_t=0.0001;
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