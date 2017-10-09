#include <iostream> 
using namespace std; 
int main () { 
    int m,n; 
    int m2,n2; 
    int p; 
    cin>>m>>n; 
      
    if(m > 0) { 
        m2 = m; 
    } else { 
        m2 = m*-1; 
    } 
      
    if(n > 0) { 
        n2 = n; 
    } else { 
        n2 = n*-1; 
    } 
      
      
    for(int i=0;i<=n2;i++) { 
        if(m2 * i == n2) p++; 
    } 
      
    if(p > 0 && m!=0) cout<<m<<" | "<<n; 
      
    else cout<<m<<" !| "<<n; 
      
    return 0; 
} 
 
