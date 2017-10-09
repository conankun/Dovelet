#include <iostream> 
using namespace std; 
int main () { 
    int m,n; 
    cin>>m>>n; 
    if(n < m) { 
        int temp = n; 
        n = m; 
        m = temp; 
    } 
    for(int i=m;i<=n;i++) { 
        if(i!=m)cout<<" "; 
        cout<<i; 
    } 
    return 0; 
} 
 
