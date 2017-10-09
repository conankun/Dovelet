#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=n;;) { 
        cout<<i<<" "; 
          
        if(i == 1) break; 
          
        if(i%2 == 1) 
        { 
            i=(i*3)+1; 
        } else if(i % 2 == 0) { 
            i/=2; 
        } 
    } 
    return 0; 
} 
 
