#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    bool arr[1000]={true,}; 
    cin>>n; 
      
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            if(j % i == 0) { 
                arr[j] = !arr[j]; 
            } 
        } 
    } 
      
    int c=0; 
    for(int i=1;i<=n;i++) { 
        if(arr[i] == true) c++; 
    } 
      
    cout<<c; 
} 
 
