#include <stdio.h> 

int main() 
{ 
    int a,i,min=-99; 
    for(i=1;i<=7;i++){ 
    scanf("%d",&a); 
    if(a<min)          min=a; 
    } 
    printf("%d\n",min); 
    return 0; 
} 