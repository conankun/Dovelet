#include <iostream> 
using namespace std; 
int main () { 
    int a,b; 
    int x,y; 
    cin>>a>>b; 
    if(a-b >= 0 && (a-b)%2 == 0) { 
        y = (a+b)/2; 
        x = a-y; 
        if(x > y) 
        cout<<x<<" "<<y; 
        else { 
            cout<<y<<" "<<x; 
        } 
  
    } else { 
        cout<<"impossible"; 
    } 
    return 0; 
} 
 
