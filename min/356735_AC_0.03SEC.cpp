#include <iostream> 
using namespace std; 
int main () { 
    int min=2147483647; 
    for(int i=0;i<7;i++) { 
        int n; 
        cin>>n; 
        if(n < min) min = n; 
    } 
      
    cout<<min; 
    return 0; 
} 
 
