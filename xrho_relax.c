//periodic 1d channel with moving defect
//random sequential update, v=L/k, tmax=k*100
//density profile with rho+- measured
//L(500)k(500)tmax(50000)ens(10000)=

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "ran2.c"

# define L       512
# define k       4096
# define ens     100

int main()
{

int            x,y,z,i,b,e,dt;
long int       tmax,t1,w=0;
double         a[L]={},rho[L]={},d=0.5,p,q,r,s,t;
long double    rhom,rhop;
//rhom=(double *)calloc(tmax,sizeof(double));
long   sd      =-96711;

FILE   *fq;

p=1.0; q=0.0; t=0.0;
fq=fopen("relax100v.125","w");

r=q; s=q;

for(dt=1;dt<=100000;dt*=2){ rhom=0; rhop=0;

tmax=k*dt ;

for(e=0;e<ens;e++){

for(z=0;z<L;z++){a[z]=0; rho[z]=0;}
i=0; while (i<L*d){ z=ran2(&sd)*L ; if(!a[z]) {a[z]=1; i++ ;  }  }

x=0;
w=k-1;

for(t1=0;t1<tmax;t1++){
//-------------------------------------------------------------------
b=ran2(&sd)*L;

if(b==x){ if (a[x] && a[(x-1+L)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){ 
                                                             if(ran2(&sd)<p){a[x]=0;a[(x+1)%L]=1; } } 
                                                             else a[x]=1; }
          else if (a[x] && !a[(x-1+L)%L] && a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                             if(ran2(&sd)<p){a[x]=0;a[(x-1+L)%L]=1; } }
                                                             else a[x]=1; } 
          else if (a[x] && !a[(x-1+L)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                             if(ran2(&sd)<p){a[x]=0;a[(x+1)%L]=1; } } 
                                                          else if(ran2(&sd)<p){a[x]=0;a[(x-1+L)%L]=1; } 
                                                        }        
        }

else
if(b==(x-1+L)%L){ if (a[(x-1+L)%L] && a[(x-2+L)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<t){a[(x-1+L)%L]=0;a[x]=1; } }
                                                       else a[(x-1+L)%L]=1; }
                  else if (a[(x-1+L)%L] && !a[(x-2+L)%L] && a[x]){ if(ran2(&sd)<0.5){ 
                                                       if(ran2(&sd)<s){a[(x-1+L)%L]=0; a[(x-2+L)%L]=1; } }
                                                       else a[(x-1+L)%L]=1; } 
                  else if (a[(x-1+L)%L] && !a[(x-2+L)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<t){a[(x-1+L)%L]=0;a[x]=1; } } 
                                                  else if(ran2(&sd)<s){a[(x-1+L)%L]=0;a[(x-2+L)%L]=1;}
                                                                  }        
                }

else
if(b==(x-2+L)%L){ if (a[(x-2+L)%L] && a[(x-3+L)%L] && !a[(x-1+L)%L]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<r){a[(x-2+L)%L]=0;a[(x-1+L)%L]=1; } }
                                                       else a[(x-2+L)%L]=1; }
                  else if (a[(x-2+L)%L] && !a[(x-3+L)%L] && a[(x-1+L)%L]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<q){a[(x-2+L)%L]=0; a[(x-3+L)%L]=1; } }
                                                       else a[(x-2+L)%L]=1; } 
                  else if (a[(x-2+L)%L] && !a[(x-3+L)%L] && !a[(x-1+L)%L]){ if(ran2(&sd)<0.5){
                                                                           if(ran2(&sd)<r){a[(x-2+L)%L]=0;a[(x-1+L)%L]=1; } } 
                                                                    else if(ran2(&sd)<q){a[(x-2+L)%L]=0;a[(x-3+L)%L]=1;}
                                                                  }        
                }

else
if(b==(x+1)%L){ if (a[(x+1)%L] && a[(x+2)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                          if(ran2(&sd)<t){a[(x+1)%L]=0;a[x]=1; } }
                                          else a[(x+1)%L]=1; }
                else if (a[(x+1)%L] && !a[(x+2)%L] && a[x]){ if(ran2(&sd)<0.5){
                                          if(ran2(&sd)<s){a[(x+1)%L]=0; a[(x+2)%L]=1; } }
                                          else a[(x+1)%L]=1; }
                else if (a[(x+1)%L] && !a[(x+2)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                                                    if(ran2(&sd)<t){a[(x+1)%L]=0;a[x]=1; } } 
                                                              else if(ran2(&sd)<s){a[(x+1)%L]=0;a[(x+2)%L]=1; } 
                                                            }        
              }

else
if(b==(x+2)%L){ if (a[(x+2)%L] && a[(x+3)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                   if(ran2(&sd)<r){a[(x+2)%L]=0;a[(x+1)%L]=1; } }
                                                   else a[(x+2)%L]=1; }
                  else if (a[(x+2)%L] && !a[(x+3)%L] && a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                   if(ran2(&sd)<q){a[(x+2)%L]=0; a[(x+3)%L]=1; } }
                                                   else a[(x+2)%L]=1; }
                  else if (a[(x+2)%L] && !a[(x+3)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                                           if(ran2(&sd)<r){a[(x+2)%L]=0;a[(x+1)%L]=1; } } 
                                                                    else if(ran2(&sd)<q){a[(x+2)%L]=0;a[(x+3)%L]=1;}
                                                                  }        
              }

else {                 
if (a[b] && !a[(b+1)%L] && a[(b-1+L)%L]){if(ran2(&sd)<0.5){
                                                if(ran2(&sd)<q){a[b]=0;a[(b+1)%L]=1;} }
                                                else a[b]=1; }
else if (a[b] && a[(b+1)%L] && !a[(b-1+L)%L]){if(ran2(&sd)<0.5){
                                                if(ran2(&sd)<q){a[b]=0;a[(b-1+L)%L]=1;} }
                                                else a[b]=1; }
else if (a[b] && !a[(b+1)%L] && !a[(b-1+L)%L]){if(ran2(&sd)<0.5){
                                                         if(ran2(&sd)<q){a[b]=0;a[(b+1)%L]=1;} } 
                                               else if(ran2(&sd)<q){a[b]=0;a[(b-1+L)%L]=1;} }
     }
//-------------------------------------------------------------------------

if(t1==w){x=(x+1)%L; w=t1+k;
rhom += a[(x-1+L)%L]; rhop += a[x];
         }

          }//tmax ends

//printf("%lf %lf\n",rhom*1.0/dt,rhop*1.0/dt);

//for(z=0;z<L;z++){rho[z] += a[z] ;}

     }//ens ends

fprintf(fq,"%d  %Lf  %Lf\n",dt,rhom*1.0/ens/dt,rhop*1.0/ens/dt);

 }//dt loop ends
//for(z=0;z<L;z++){fprintf(fq,"%d  %lf\n",z,rho[z]/ens); }

fclose(fq);
}//main ends
