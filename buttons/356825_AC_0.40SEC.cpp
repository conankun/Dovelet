#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
  
        for(int i=3;;i++) { 
            if(n%i ==0) { 
                cout<<i-1; 
                break; 
            } 
        } 
      
} 
 
