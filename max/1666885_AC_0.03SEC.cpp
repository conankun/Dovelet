#include <stdio.h> 

int main() 
{ 
    int a,i,max=-99; 
    for(i=1;i<=7;i++){ 
    scanf("%d",&a); 
    if(a>max)          max=a; 
    } 
    printf("%d\n",max); 
    return 0; 
} 