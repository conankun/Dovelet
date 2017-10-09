#include<stdio.h> 
int cd; 
  
int main() { 
    scanf("%d",&cd); 
    int n=0; 
    int i; 
    for(i=1;;i++) { 
        if(n >= cd) break; 
    n++; 
    if(i%3 ==0)  {  
        n++;     
    } 
    if(i%4 == 0) {  
        n++; 
    } 
  
    } 
  
    printf("%d",i-1); 
} 
 
