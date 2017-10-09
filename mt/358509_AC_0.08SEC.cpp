#include <iostream> 
  
using namespace std; 
  
int a; 
int tt=0; 
void mountain(int n,int t) { 
  
    cout<<n; 
    if(n == 1 && t == a*2-1) { 
          
        return; 
    } 
  
    if(a %2 == 0 &&  n == a) tt=1; 
    else if(a % 2 == 1 && n == a) tt=1; 
  
    if(tt == 1) mountain(n-1,++t); 
    else mountain(n+1,++t); 
  
    return; 
  
} 
  
int main() { 
    cin>>a; 
  
    mountain(1,1); 
  
      
  
  
} 
 
