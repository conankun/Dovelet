#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        int a; 
        cin>>a; 
        int b=1; 
        int plus=4; 
        while(b < a) { 
            b+=plus; 
            plus+=3; 
        } 
  
        if(b == a) cout<<a<<" "<<"Y"<<endl; 
        else cout<<a<<" "<<"N"<<endl; 
    } 
} 
 
