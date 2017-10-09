#include<stdio.h>
int main() {
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
if(b/a == d/c && b-(b/a*a) == d-(d/c*c)) {
printf("%d %d",b/a,b-(b/a*a));
} else {
printf("%d %d",d/c,d-(d/c*c));
}
}