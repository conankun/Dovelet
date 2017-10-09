#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    cin>>n; 
    int space = n/2; 
      
    for(int i=0;i<n/2;i++) { 
        for(int k=1;k<=space;k++) cout<<" "; 
        for(int j=1;j<=(n-(space*2))/2+1;j++) cout<<j; 
        for(int j=(n-(space*2))/2;j>=1;j--) cout<<j; 
        cout<<endl; 
        space-=1; 
    } 
      
    for(int i=1;i<=n/2+1;i++) cout<<i; 
      
    for(int i=n/2;i>=1;i--) cout<<i; 
    cout<<endl; 
      
    space = 1; 
    for(int i=0;i<n/2;i++) { 
        for(int k=1;k<=space;k++) cout<<" "; 
        for(int j=1;j<=(n-(space*2))/2+1;j++) cout<<j; 
          
        for(int j=(n-(space*2))/2;j>=1;j--) cout<<j; 
          
        cout<<endl; 
        space+=1; 
    } 
    return 0; 
} 
 
