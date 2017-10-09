#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int gazi=1; 
      
    for(int i=1;i<=n/2+1;i++) { 
        int sum=i; 
        for(int j=i+1;j<=n/2+1;j++) { 
            sum+=j; 
            if(sum >= n) break; 
        } 
          
        if(sum == n) gazi++; 
          
    } 
      
    cout<<gazi; 
} 
 
