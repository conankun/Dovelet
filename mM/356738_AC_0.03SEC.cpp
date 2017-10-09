#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int max=0,min=2147483647; 
    for(int i=0;i<7;i++) { 
        cin>>n; 
        if(n > max) max = n; 
        if(n < min) min = n; 
    } 
    cout<<max<<" "<<min; 
    return 0; 
} 
 
