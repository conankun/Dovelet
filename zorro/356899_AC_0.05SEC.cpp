#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    cin>>n; 
    int space = n-2; 
    for(int i=0;i<n;i++) { 
        if(i==0 || i == n-1) { 
            for(int j=0;j<n;j++) cout<<"*"; 
        } else { 
            for(int j=0;j<=space;j++) cout<<" "; 
            cout<<"*"; 
        } 
          
        cout<<endl; 
        space-=1; 
    } 
    return 0; 
} 
 
