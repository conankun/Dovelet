#include <iostream> 
#include <algorithm> 
using namespace std; 
int main() { 
    int n; 
    int arr[21]; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    sort(arr,arr+n); 
    int a=arr[0]; 
    int sum=0; 
    for(int i=1;i<n;i++) { 
        sum+=arr[i]-a; 
        a = arr[i]; 
    } 
    cout<<sum*2; 
} 
 
