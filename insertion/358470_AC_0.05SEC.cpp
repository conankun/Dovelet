#include <iostream> 
using namespace std; 
int main() { 
    int n,s; 
    int arr[1001]; 
    cin>>n>>s; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    for(int i=0;i<s;i++) { 
        int imsi=i; 
        if(i == 0) continue; 
        for(int j=i-1;j>=0;j--) { 
            if(arr[j] <= arr[imsi]) { 
                break; 
            } else { 
                int temp=arr[imsi]; 
                arr[imsi]=arr[j]; 
                arr[j]=temp; 
                imsi = j; 
            } 
        }    
    } 
  
    for(int i=0;i<n;i++) cout<<arr[i]<<" "; 
  
} 
 
