#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int j=0; 
    cin>>n; 
    for(int i=1;i<=n;i++)  { 
        if( n % i == 0 ) { 
            j++; 
        } 
    } 
    cout<<j; 
    return 0; 
} 
 
