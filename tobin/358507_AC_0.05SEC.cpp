#include <stdio.h> 
void t(int n) {if(n != 1) t(n/2);printf("%d",n%2);}int main(){int n;scanf("%d",&n);t(n);} 
 
