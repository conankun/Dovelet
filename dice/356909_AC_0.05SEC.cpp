#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
      
    for(int i=1;i<n;i++) { 
        if(i <= 6 && n-i <= 6) { 
            cout<<i<<" "<<n-i; 
            cout<<endl; 
        } 
    } 
} 
 
