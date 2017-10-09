#include <iostream> 
  
using namespace std; 
  
int main() { 
    int a,b; 
    int last,now; 
    cin>>a>>b; 
    cout<<a<<" "<<b; 
    last = b; 
    now = a-b; 
    for(;now>=0;) { 
        cout<<" "; 
        cout<<now; 
        int temp=now; 
        now = last-now; 
        last = temp; 
    } 
    return 0; 
} 
 
