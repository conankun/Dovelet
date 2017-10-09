#include <iostream> 
  
using namespace std; 
  
int main() { 
    int n; 
    int gob; 
    int index=0; 
    cin>>n; 
    gob=n; 
    for(;gob>0;gob/=2,index++) { 
        if(gob % 2 == 1) { 
            cout<<index<<" "; 
        } 
    } 
    return 0; 
} 
 
