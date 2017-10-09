#include <iostream> 
using namespace std; 
int main () { 
    int n,a; 
    int p=0; 
    cin>>n; 
      
    if(n % 2 == 1) a = n/2 + 1; 
    else a = n/2; 
      
    for(int i=a;i<=n;i++) { 
        if(i > 5) break; 
        p++; 
    } 
      
    cout<<p; 
      
    return 0; 
} 
 
