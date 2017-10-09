#include <iostream> 
  
using namespace std; 
int main() { 
    int n,k; 
    cin>>n>>k; 
    int index=1; 
    int su=0; 
    for(int i=1;i<=n;i++) { 
        if(n % i == 0) { 
            if(index++ == k)  
            { 
                su = i; 
                break; 
            } 
        } 
    } 
    cout<<su; 
    return 0; 
} 
 
