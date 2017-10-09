#include <iostream> 
  
using namespace std; 
bool isPrime(int n) { 
    int i; 
    if(n == 2) return true; 
    if(n%2 == 0) return false; 
    for(i=3;i*i<=n;i+=2) { 
        if(n%i ==0) break; 
    } 
      
    if(i*i > n) return true; 
    else return false; 
} 
  
int main() { 
    int n; 
    cin>>n; 
    cout<<2<<" "; 
    for(int i=3;i<=n;i+=2) { 
        if(isPrime(i) == true) cout<<i<<" "; 
    } 
    return 0; 
} 
 
