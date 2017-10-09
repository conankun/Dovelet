#include <iostream> 
using namespace std; 
   
int c=0; 
   
int maxstair; 
   
void stair(int n) { 
       
    if(n == maxstair) { 
        c++; 
        return; 
    } else if(n> maxstair) { 
        return; 
    } 
        stair(n+1); 
        stair(n+2); 
   
} 
   
int main () { 
    int n; 
    cin>>n; 
       
    maxstair = n; 
       
    stair(0); 
       
    cout<<c; 
return 0; 
}