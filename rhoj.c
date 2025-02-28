//L(512)k(512)trelax(100000)tmax(1000000)ens(1) = 25'

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "ran2.c"

# define L         512
# define k         512
# define trelax    10000
# define tmax      100000
# define ens       1

int main()
{

int    x,i,w,z,t1,e,b,y,yy;
double a[L]={},c[L]={},rho[L]={},d,crl=0,cl,cr,p,q,r,s,t;
long   sd =-98155;
FILE   *fp;

p=1.0;q=0.0;r=0.0;s=0.0;t=0;
//fp=fopen("rhoj100t560","w");
fp=fopen("arhoj100_l512_5a","w");

for(d=0.0;d<1.0;d+=0.02){ 

crl=0;

for(z=0;z<L;z++){a[z]=0; c[z]=0;}
i=0; while (i<L*d){ z=ran2(&sd)*L ; if(!a[z]) {a[z]=1; i++ ;  }  }
x=10; y=27; w=k-1;

for(t1=0;t1<trelax*L;t1++){
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
//----------------------------------------------relaxation ends


for(e=0;e<ens;e++){ 
cl=0;cr=0;
for(z=0;z<L;z++){a[z] = 0;}
for(z=0;z<L;z++){a[z] = c[z];} x=yy; w=k-1;



for(t1=0;t1<tmax*L;t1++){
//-----------------------------------------
b=ran2(&sd)*L;

if(b==x){ if (a[x] && a[(x-1+L)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){ 
                                                             if(ran2(&sd)<p){a[x]=0;a[(x+1)%L]=1; if(x==y)cr++;} } 
                                                             else a[x]=1; }
          else if (a[x] && !a[(x-1+L)%L] && a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                             if(ran2(&sd)<p){a[x]=0;a[(x-1+L)%L]=1; if(x==y+1)cl++;} }
                                                             else a[x]=1; } 
          else if (a[x] && !a[(x-1+L)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                             if(ran2(&sd)<p){a[x]=0;a[(x+1)%L]=1; if(x==y)cr++;} } 
                                                          else if(ran2(&sd)<p){a[x]=0;a[(x-1+L)%L]=1; if(x==y+1)cl++;} 
                                                        }        
        }

else 
if(b==(x-1+L)%L){ if (a[(x-1+L)%L] && a[(x-2+L)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<t){a[(x-1+L)%L]=0;a[x]=1;if((x-1+L)%L==y)cr++; } }
                                                       else a[(x-1+L)%L]=1; }
                  else if (a[(x-1+L)%L] && !a[(x-2+L)%L] && a[x]){ if(ran2(&sd)<0.5){ 
                                                       if(ran2(&sd)<s){a[(x-1+L)%L]=0; a[(x-2+L)%L]=1;if((x-1+L)%L==y+1)cl++; } }
                                                       else a[(x-1+L)%L]=1; } 
                  else if (a[(x-1+L)%L] && !a[(x-2+L)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<t){a[(x-1+L)%L]=0;a[x]=1;if((x-1+L)%L==y)cr++; } } 
                                                  else if(ran2(&sd)<s){a[(x-1+L)%L]=0;a[(x-2+L)%L]=1;if((x-1+L)%L==y+1)cl++;}
                                                                  }        
                }

else 
if(b==(x-2+L)%L){ if (a[(x-2+L)%L] && a[(x-3+L)%L] && !a[(x-1+L)%L]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<r){a[(x-2+L)%L]=0;a[(x-1+L)%L]=1;if((x-2+L)%L==y)cr++; } }
                                                       else a[(x-2+L)%L]=1; }
                  else if (a[(x-2+L)%L] && !a[(x-3+L)%L] && a[(x-1+L)%L]){ if(ran2(&sd)<0.5){
                                                       if(ran2(&sd)<q){a[(x-2+L)%L]=0; a[(x-3+L)%L]=1;if((x-2+L)%L==y+1)cl++; } }
                                                       else a[(x-2+L)%L]=1; } 
                  else if (a[(x-2+L)%L] && !a[(x-3+L)%L] && !a[(x-1+L)%L]){ if(ran2(&sd)<0.5){
                                                                           if(ran2(&sd)<r){a[(x-2+L)%L]=0;a[(x-1+L)%L]=1;if((x-2+L)%L==y)cr++; } } 
                                                                    else if(ran2(&sd)<q){a[(x-2+L)%L]=0;a[(x-3+L)%L]=1;if((x-2+L)%L==y+1)cl++;}
                                                                  }        
                }

else 
if(b==(x+1)%L){ if (a[(x+1)%L] && a[(x+2)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                          if(ran2(&sd)<t){a[(x+1)%L]=0;a[x]=1;if((x+1)%L==y+1)cl++; } }
                                          else a[(x+1)%L]=1; }
                else if (a[(x+1)%L] && !a[(x+2)%L] && a[x]){ if(ran2(&sd)<0.5){
                                          if(ran2(&sd)<s){a[(x+1)%L]=0; a[(x+2)%L]=1;if((x+1)%L==y)cr++; } }
                                          else a[(x+1)%L]=1; }
                else if (a[(x+1)%L] && !a[(x+2)%L] && !a[x]){ if(ran2(&sd)<0.5){
                                                                    if(ran2(&sd)<t){a[(x+1)%L]=0;a[x]=1;if((x+1)%L==y+1)cl++; } } 
                                                              else if(ran2(&sd)<s){a[(x+1)%L]=0;a[(x+2)%L]=1;if((x+1)%L==y)cr++; } 
                                                            }        
              }

else 
if(b==(x+2)%L){ if (a[(x+2)%L] && a[(x+3)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                   if(ran2(&sd)<r){a[(x+2)%L]=0;a[(x+1)%L]=1;if((x+2)%L==y+1)cl++; } }
                                                   else a[(x+2)%L]=1; }
                  else if (a[(x+2)%L] && !a[(x+3)%L] && a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                   if(ran2(&sd)<q){a[(x+2)%L]=0; a[(x+3)%L]=1;if((x+2)%L==y)cr++; } }
                                                   else a[(x+2)%L]=1; }
                  else if (a[(x+2)%L] && !a[(x+3)%L] && !a[(x+1)%L]){ if(ran2(&sd)<0.5){
                                                                           if(ran2(&sd)<r){a[(x+2)%L]=0;a[(x+1)%L]=1;if((x+2)%L==y+1)cl++; } } 
                                                                    else if(ran2(&sd)<q){a[(x+2)%L]=0;a[(x+3)%L]=1;if((x+2)%L==y)cr++;}
                                                                  }        
              }

else {                 
if (a[b] && !a[(b+1)%L] && a[(b-1+L)%L]){if(ran2(&sd)<0.5){
                                                if(ran2(&sd)<q){a[b]=0;a[(b+1)%L]=1;if(b==y)cr++;} }
                                                else a[b]=1; }
else if (a[b] && a[(b+1)%L] && !a[(b-1+L)%L]){if(ran2(&sd)<0.5){
                                                if(ran2(&sd)<q){a[b]=0;a[(b-1+L)%L]=1;if(b==y+1)cl++;} }
                                                else a[b]=1; }
else if (a[b] && !a[(b+1)%L] && !a[(b-1+L)%L]){if(ran2(&sd)<0.5){
                                                         if(ran2(&sd)<q){a[b]=0;a[(b+1)%L]=1;if(b==y)cr++;} } 
                                               else if(ran2(&sd)<q){a[b]=0;a[(b-1+L)%L]=1;if(b==y+1)cl++;} }
     }
           
if(t1==w){x=(x+1)%L; w=t1+k;}  
//-----------------------------------------------
          }//tmax ends

crl += cr-cl ;

     }//ens ends

//printf("%lf  %lf\n",d,crl/tmax/ens);
fprintf(fp,"%lf  %lf\n",d,crl*L/tmax/ens);

  }//d loop ends

fclose(fp);
}//main ends
