#include <iostream> 
using namespace std; 
  
int main() { 
    int n; 
    cin>>n; 
    int c=0; 
    for(int i=1;i<n/2;i++) { 
        for(int j=i;j<=n/2;j++) { 
            if(n-(i+j) >= j && n-(i+j) < i+j) { 
                c++; 
            } 
        } 
    } 
    cout<<c; 
} 
 
