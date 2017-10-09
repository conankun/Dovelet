#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int i,j=0; 
    for(i=1;j!=n;i+=2,j++) { 
        for(int x=0;x<(n*2-1-i)/2;x++) cout<<" "; 
        for(int z=0;z<i;z++) cout<<"*"; 
        cout<<endl; 
    } 
  
    for(i=n*2-3;i>=1;i-=2) { 
        for(int x=0;x<(n*2-1-i)/2;x++) cout<<" "; 
        for(int z=0;z<i;z++) cout<<"*"; 
        cout<<endl; 
    } 
    return 0; 
} 
 
