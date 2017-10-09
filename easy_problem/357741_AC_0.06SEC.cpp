#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int count=0; 
    int n2=n; 
    for(;n2>=1;) { 
        if(n2 % 2 == 1) count++; 
        n2/=2; 
    } 
  
    for(int i=n+1;;i++) { 
        int n3=i; 
        int count2=0; 
        for(;n3>=1;) { 
        if(n3 % 2 == 1) count2++; 
        n3/=2; 
    } 
  
        if(count == count2) { 
            cout<<i; 
            break; 
        } 
    } 
  
} 
 
