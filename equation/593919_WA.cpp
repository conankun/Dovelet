#include<stdio.h>
int main()
{
 int a,b,c,d;
 scanf ("%d %d %d %d",&a,&b,&c,&d);
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