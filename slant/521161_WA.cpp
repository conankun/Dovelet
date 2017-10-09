#include<stdio.h>
int main() {
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
int x=b/a;
int y=d/c;
if(a==0) {
printf("%d %d",d/c,d-(d/c*c));
} else {
printf("%d %d",b/a,b-(b/a*a));
}

}