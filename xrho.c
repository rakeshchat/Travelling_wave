//periodic 1d channel with moving defect with CO-MOVING FRAME, defect site at 1.
//random sequential update, v=L/k, trelax=tmax=k*A, A=number of defects movement
//density profile with rho+- measured
//v vs xi plot: 'xrho150_l512v0.00125' u 1:($2-0.444),0.165*exp(-x/193)
//L(512)k(512)ens(100)A(10000) = 1' 

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "ran2.c"

# define L       512
# define k       512
# define ens     10000
# define A       10000

int main()
{

int    x,y,yy,i,b,z,t1,e,w,trelax,tmax;
double a[L]={},c[L]={},rho[L]={},rhop,rhom,d=0.9,p,q,r,s,t;
long   sd =-96711;
FILE   *fq;

p=1.0;q=0.5;r=0.5;s=0.5;t=0;
fq=fopen("xrho150_l512r0.9","w");

for(z=0;z<L;z++){a[z]=0; c[z]=0; rho[z]=0;}
i=0; while (i<L*d){ z=ran2(&sd)*L ; if(!a[z]) {a[z]=1; i++ ;  }  }

//----------------------------------------------------------------- relaxation
x=0; yy=0; w=k-1; trelax=k*A; tmax=k*A;

for(t1=0;t1<trelax;t1++){
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

if(t1==w){x=(x+1)%L; w=t1+k; }

          }//trelax ends

for(z=0;z<L;z++){c[z] = a[z];} yy=x;
//-------------------------------------------------------------------relaxation ends



for(e=0;e<ens;e++){

for(z=0;z<L;z++){a[z] = 0;}
for(z=0;z<L;z++){a[z] = c[z];} x=yy;

w=k-1;

for(t1=0;t1<tmax;t1++){
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

if(t1==w){x=(x+1)%L; w=t1+k; for(z=0;z<L;z++){rho[z] += a[(x-1+z+L)%L] ;} }

          }//tmax ends

     }//ens ends  
for(z=0;z<L;z++){fprintf(fq,"%d  %lf\n",z,rho[z]/A/ens); }

fclose(fq);
}//main ends
