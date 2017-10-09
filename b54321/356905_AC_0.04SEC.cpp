#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
      
    for(int i=0;i<n;i++) { 
        for(int z=0;z<i;z++) cout<<" "; 
        for(int j=n-i;j>=1;j--) { 
            cout<<j; 
        } 
        cout<<endl; 
    } 
    return 0; 
} 
 
