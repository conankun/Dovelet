#include <iostream> 
#include <stdlib.h> 
using namespace std; 
  
int main() { 
    int n; 
    cin>>n; 
      
    int ia[1000001]; 
    int ic[100001]; 
    int max=0; 
    for(int i=0;i<n;i++) {  
        cin>>ia[i]; 
        if(ia[i] > max) max = ia[i]; 
    } 
      
    int *ib = (int *)malloc(sizeof(int) * (max+1)); 
      
    for(int i=0;i<n;i++) { 
        ib[ia[i]]++; 
    } 
      
    int *iib = (int *)malloc(sizeof(int) * (max+1)); 
      
    for(int i=1;i<=max;i++) { 
            iib[i]=ib[i]; 
          
        for(int j=1;j<i;j++) { 
            ib[i]+=iib[j]; 
        } 
          
    } 
          
      
    for(int i=0;i<=n;i++) { 
        ic[ib[ia[i]]] = ia[i]; 
        ib[ia[i]]--; 
    } 
      
    for(int i=1;i<=n;i++) { 
        cout<<ic[i]<<" "; 
    } 
        return 0; 
} 
 
