#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int fs=2; 
    int ls; 
    for(int i=0;i<n;i++) { 
        if(i == 0) ls=3; 
        else { 
            int fsls = fs+ls; 
            fs = ls; 
            ls = fsls; 
        } 
    } 
  
    cout<<fs; 
} 
 
