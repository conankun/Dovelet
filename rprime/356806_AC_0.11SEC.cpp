#include <iostream> 
using namespace std; 
  
int main() { 
    int a,b; 
    cin>>a>>b; 
    int c; 
    do { 
        c = a%b; 
        a = b; 
        b = c; 
    }while (c!=0); 
      
      
    if(a == 1) cout<<"yes"; 
        else cout<<"no"; 
      
    return 0; 
} 
 
