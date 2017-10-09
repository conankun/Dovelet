#include <iostream> 
using namespace std; 
int main () { 
    int n; 
      
    for(;cin>>n,n!=0;) { 
          
        if(n % 2 == 0) { 
            cout<<"No Solution!"<<endl; 
        } else { 
            cout<<n-1<<endl; 
        } 
          
          
    } 
    return 0; 
} 
 
