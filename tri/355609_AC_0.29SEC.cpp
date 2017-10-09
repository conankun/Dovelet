#include <iostream> 
using namespace std; 
int main () { 
    int a,b,c; 
    int max,orderhap; 
    cin>>a>>b>>c; 
      
    if(a > b && a > c) { 
        max = a; 
        orderhap = b+c; 
    } else if(b > a && b > c) { 
        max = b; 
        orderhap = a+c; 
    } else if(c > a && c > b) { 
        max = c; 
        orderhap = a+b; 
    } 
    if(orderhap > max) cout<<"yes"; 
    else cout<<"no"; 
  
      
    return 0; 
} 
 
