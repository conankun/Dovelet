#include<iostream> 
#include<algorithm> 
using namespace std; 
int arr[1000000]; 
int arr2[1000000]; 
int main() { 
    int l; 
    int n; 
    cin>>l>>n; 
    for(int i=0;i<n;i++) { 
        int a; 
        cin>>a; 
        arr[i]=l-a; 
        arr2[i]=min(l-a,a); 
    } 
    sort(arr,arr+n); 
    sort(arr2,arr2+n); 
    cout<<arr2[n-1]<<" "<<l-arr2[0]; 
} 
 
