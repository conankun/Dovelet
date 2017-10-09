#include <iostream> 
using namespace std; 
int main () { 
    int a,b; 
    scanf("%d:%d",&a,&b); 
      
    if(b == 00) { 
      
    if(a>12) { 
        cout<<a-12; 
    } else if(a == 0) { 
        cout<<"12"; 
    }else { 
        cout<<a+12; 
    } 
          
    } else { 
        cout<<"0"; 
    } 
      
    return 0; 
} 
 
