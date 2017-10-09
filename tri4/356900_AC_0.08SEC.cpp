#include <iostream> 
  
using namespace std; 
  
int main() { 
    int n; 
    cin>>n; 
    int space=(n-1)/2; 
    for(int i=0;i<n/2+1;i++) { 
        for(int j=1;j<=space;j++)  
        { 
            cout<<" "; 
        } 
        for(int z=1;z<=i*2+1;z++) cout<<"*"; 
        cout<<endl; 
        space-=1; 
    } 
    return 0; 
} 
 
