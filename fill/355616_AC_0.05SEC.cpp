#include <iostream> 
using namespace std; 
int main () { 
    float a,b,c; 
    int n=0; 
    cin>>a>>b>>c; 
      
    if(a<=4.5 && b >= 150.0 && c >= 200.00) { 
    if(n > 0) cout<<" "; 
    cout<<"Wide Receiver"; 
        n++; 
    } 
      
    if(a<=6.0 && b >= 300.0 && c>= 500.0) { 
    if(n > 0) cout<<" "; 
    cout<<"Lineman"; 
        n++; 
    } 
      
    if(a<=5.0 && b >=200.0 && c>= 300.0) { 
        if(n > 0) cout<<" "; 
        cout<<"Quarterback"; 
        n++; 
    }  
      
    if(n == 0) cout<<"No positions"; 
      
    return 0; 
} 
 
