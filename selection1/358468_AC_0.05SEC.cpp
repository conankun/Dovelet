#include <iostream> 
using namespace std; 
int main() { 
    int m,n; 
      
    cin>>m>>n; 
      
    int minindex; 
    int arr[1001]; 
    for(int i=0;i<m;i++) cin>>arr[i]; 
      
    for(int i=0;i<n;i++) { 
        minindex=i; 
        for(int j=i+1;j<m;j++) { 
            if(arr[j] < arr[minindex]) { 
                minindex = j; 
            } 
        } 
          
        int temp=arr[i]; 
        arr[i]=arr[minindex]; 
        arr[minindex]=temp; 
    } 
      
    for(int i=0;i<m;i++) cout<<arr[i]<<" "; 
      
    return 0; 
} 
 
