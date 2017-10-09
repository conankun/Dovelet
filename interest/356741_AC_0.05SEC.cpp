#include <iostream> 
  
using namespace std; 
  
int main() { 
    int r,y; 
    double m; 
    cin>>r>>m>>y; 
  
    for(int i=0;i<y;i++) 
    { 
        m += m*((float)r/100); 
    } 
    cout<<(int)m; 
    return 0; 
} 
 
