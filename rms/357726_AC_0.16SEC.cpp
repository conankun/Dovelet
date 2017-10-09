#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
  
    int jari=1; 
    for(;;) { 
        int a=n%2; 
        if(a == 1) { 
            cout<<jari; 
            break; 
        } 
        else 
        jari*=2; 
        n/=2; 
    } 
  
      
} 
 
