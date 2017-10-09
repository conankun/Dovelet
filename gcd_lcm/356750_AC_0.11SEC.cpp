#include <iostream> 
using namespace std; 
int main () { 
    // insert code here... 
    int a,b; 
    int gob; 
    int x; 
    cin>>a>>b; 
      
    if(a %b == 0) { 
        if(a >= b) cout<<b<<" "<<b*(a/b); 
        else cout<<a<<" "<<a*(b/a); 
        return 0; 
    } 
      
    gob = a*b; 
    do { 
        x = a%b; 
        a = b; 
        b = x; 
    } while(x!=0); 
      
    cout<<a<<" "<<gob/a; 
      
    return 0; 
} 
 
