#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[101]; 
    int arr2[101]={0,}; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i];; 
  
for(int c=1;;c++) { 
  
    for(int i=0;i<n;i++) { 
        if(i == n-1) { 
            arr2[0]+=arr[i]/2; 
            arr[i]-=arr[i]/2; 
        } else { 
            arr2[i+1]+= arr[i]/2; 
            arr[i]-=arr[i]/2; 
        } 
    } 
  
    for(int i=0;i<n;i++)  { 
        arr[i]+=arr2[i]; 
        arr2[i]=0; 
    } 
  
    for(int i=0;i<n;i++) { 
        if(arr[i] % 2 == 1) arr[i]++; 
    } 
  
    int a=arr[0]; 
    bool b = true; 
    for(int i=0;i<n;i++) { 
        if(arr[i] != a) { 
            b = false; 
            break; 
        } 
    } 
  
    if(b) { 
        cout<<c<<" "<<arr[0]; 
        break; 
    } 
} 
  
} 
 
