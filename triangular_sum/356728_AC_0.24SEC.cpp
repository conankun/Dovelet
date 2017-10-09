#include <iostream> 
using namespace std; 
  
int sum=0; 
  
int T(int n) { 
    if(n % 2 == 0) { 
        return (n+1)*(n/2); 
    } 
    return (n+1)*(n/2)+(n/2+1); 
} 
  
void w(int n) { 
    sum += n * T(n+1); 
    if(n == 1) return; 
    else
    w(n-1); 
} 
  
int main () { 
    int n; 
    cin>>n; 
      
    w(n); 
      
    cout<<sum; 
    return 0; 
} 
 
