#include <iostream> 
using namespace std; 
int main () { 
    int r,e,c; 
    cin>>r>>e>>c; 
    //e-c > r 
    if(e-c > r) cout<<"advertise"; 
    else if(e-c < r) cout<<"do not advertise"; 
    else cout<<"does not matter"; 
    return 0; 
} 
 
