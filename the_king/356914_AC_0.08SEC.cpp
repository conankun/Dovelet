#include <iostream> 
#include <stdlib.h> 
using namespace std; 
int main () { 
    int n; 
    int j; 
    int sum=0; 
    cin>>n>>j; 
    int *arr = (int *)malloc(sizeof(int) * n); 
    for(int i=0;i<n;i++) { 
        int gob=1; 
        cin>>arr[i]; 
      
        for(int a=0;a<j;a++) gob*=arr[i]; 
          
        if(gob > 0) sum+=gob; 
      
    } 
      
    cout<<sum; 
    return 0; 
} 
 
