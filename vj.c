//L(512)trelax(100000)tmax(1000000)ens(1) = 818"


# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "ran2.c"

# define L         512
# define trelax    100000
# define tmax      1000000
# define ens       100

int main()
{

int    x,i,j,z,t1,e,b,y,yy,k,c1,w;
double a[L]={},c[L]={},d=0.5,crl=0,cl,cr,p,q,r,s,t;
long   sd =-96744;
FILE   *fp,*fq;

p=1.0;q=0.0;r=0.0;s=0.0;t=0;
fq=fopen("05vj100t","w");
//fq=fopen("vj150_l512_04","w");

//fp = fopen("input","r");
fp = fopen("input_vj_l512","r");
j=0; while (fscanf(fp,"%d\n",&c1) !=EOF){ k=c1;

crl=0;

for(z=0;z<L;z++){a[z]=0; c[z]=0;}
i=0; while (i<L*d){ z=ran2(&sd)*L ; if(!a[z]) {a[z]=1; i++ ;  }  }
x=20; y=36; w=k-1;

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
//-------------------------------------------------------------------relaxation ends

for(e=0;e<ens;e++){

cl=0;cr=0;

for(z=0;z<L;z++){a[z] = 0;}
for(z=0;z<L;z++){a[z] = c[z];} x=yy; w=k-1;

for(t1=0;t1<tmax*L;t1++){
//---------------------------- 
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
//----------------------------
          }//tmax ends

crl += cr-cl ;

     }//ens ends
  
//printf("%d   %lf  %lf\n",k,L*1.0/k,crl/tmax/ens);
fprintf(fq,"%lf  %lf\n",L*1.0/k,crl*L/tmax/ens);

j++ ; }//reading datafile ends

fclose(fq); fclose(fp);
}//main ends
