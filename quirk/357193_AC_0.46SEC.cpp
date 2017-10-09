#include <iostream> 
using namespace std; 
  
int func(int a,int b,int c) { 
    if(a*a + b*b + 2*(a*b) == c) { 
        return 1; 
    } else return 0; 
} 
  
int main() { 
    int n; 
    cin>>n; 
    int a=1; 
    for(int i=0;i<n;i++) a*=10; 
    int b=1; 
    for(int i=0;i<n/2;i++) b*=10; 
      
    for(int i=0;i<=a-1;i++) { 
        if(func(i/b,i-((i/b)*b),i) == 1) 
        printf("%0*d\n",n,i); 
    } 
  
} 
 
