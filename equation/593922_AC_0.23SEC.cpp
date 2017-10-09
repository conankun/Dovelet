#include<stdio.h>
int main()
{
 double a,b,c,d;
 scanf ("%lf%lf%lf%lf",&a,&b,&c,&d);
 if(a-c==0&&d-b==0)
 {
  printf ("many\n");
 }
 else if(a-c==0&&d-b!=0)
 {
  printf ("none\n");
 }
 else
 {
  printf("%.3lf\n",(d-b)/(a-c));
 }
 
 return 0;
}