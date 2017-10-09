#include <iostream> 
using namespace std; 
int main() { 
    int arr[10001]; 
    int n; 
    int count=0; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
  
    for(int i=0;i<n-1;i++) { 
        int min=i; 
        for(int j=i+1;j<n;j++) { 
            if(arr[j] < arr[min]) min = j; 
        } 
  
        int temp=arr[i]; 
        arr[i]  = arr[min]; 
        arr[min] = temp; 
        if(min != i) 
        count++; 
    } 
  
    cout<<count; 
} 
 
