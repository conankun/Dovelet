#include <stdio.h> 
#include <math.h> 
  
int main() { 
    int n; 
unsigned long long i; 
    scanf("%d",&n); 
      
    unsigned long long n2=(unsigned long long)n*n; 
    for(i=1;i<n;i++) { 
        unsigned long long n2m=n2-(i*i); 
        unsigned long long n2msqrt=sqrt(n2m); 
          
        unsigned long long i2 = i*i; 
        unsigned long long n2msqrt2 = n2msqrt * n2msqrt; 
          
        unsigned long long i2n2 = n2-i2; 
          
        if(i2n2 == n2msqrt2) { 
            if(i > n2msqrt) { 
                printf("%llu %llu",n2msqrt,i); 
            } else { 
                printf("%llu %llu",i,n2msqrt); 
            } 
            return 0; 
        } 
    } 
      
    printf("impossible"); 
      
    return 0; 
} 
 
