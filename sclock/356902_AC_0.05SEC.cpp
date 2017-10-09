#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int i,j=0; 
      
    for(i=0;i<n/2+1;i++) { 
        for(int z=0;z<(n-(n-(i*2)-1))/2;z++) cout<<" "; 
        for(j=0;j<n-(i*2)-1;j++) cout<<"*"; 
        cout<<"$"; 
        cout<<endl; 
    } 
  
    for(i=n/2-1;i>=0;i--) { 
        for(int z=0;z<(n-(n-(i*2)-1))/2;z++) cout<<" "; 
        cout<<"$"; 
        for(j=0;j<n-(i*2)-1;j++) cout<<"*"; 
        cout<<endl; 
    } 
  
    return 0; 
} 
 
