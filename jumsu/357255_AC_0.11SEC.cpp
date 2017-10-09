#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    cin>>n; 
    int arr[101]; 
    int count=0 ; 
    int sum=0; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
      
    for(int a=0;a<n;a++) { 
        if(arr[a] == 1) { 
            count++; 
            sum+=count; 
        } else { 
            count=0; 
        } 
    } 
      
      
    cout<<sum; 
    return 0; 
} 
 
