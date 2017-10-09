#include <iostream> 
using namespace std; 
int main () { 
    int x,m; 
    int max=0; 
    cin>>x>>m; 
    for(int i=0;i<m;i++) { 
          
        if((x * i) % m == 1) { 
            max = i; 
        } 
    } 
      
    if(max !=0)  
    cout<<max; 
    else { 
        cout<<"No such integer exists."; 
    } 
  
    return 0; 
} 
 
