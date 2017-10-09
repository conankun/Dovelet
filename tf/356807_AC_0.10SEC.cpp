#include <iostream> 
#include <cmath> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int j=0; 
    int a,b; 
    for(int i=1;i<=n;i*=2,j++) { 
        if(n%i == 0) { 
            a = n/i; 
            b = j; 
        } 
    } 
      
    cout<<a<<" "<<b; 
    return 0; 
} 
 
