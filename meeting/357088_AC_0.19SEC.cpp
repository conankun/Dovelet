#include <iostream> 
using namespace std; 
int max(int a,int b) { 
    if(a > b) return a; 
    return b; 
} 
int main() { 
    int arr[25]={0,}; 
    int n; 
    int a,b; 
    cin>>n; 
    for(int i=0;i<n;i++) {  
        cin>>a>>b; 
        if(arr[b] <= arr[a]+1 && arr[b-1] >= arr[b]) arr[b] = max(arr[a]+1,arr[b-1]); 
        for(int j=b+1;j<=24;j++) arr[j]=arr[j-1]; 
    } 
      
    cout<<arr[b]; 
} 
 
