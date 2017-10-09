#include <iostream> 
using namespace std; 
int main () { 
    int max=0; 
    for(int i=0;i<7;i++) { 
        int n; 
        cin>>n; 
        if(n > max) max = n; 
    } 
      
    cout<<max; 
    return 0; 
} 
 
