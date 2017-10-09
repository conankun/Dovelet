#include <iostream> 
#include <cmath> 
using namespace std; 
int main() { 
    int n; 
    int arr[501]; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    int min=999999999; 
    int mini; 
    for(int i=0;i<n;i++) { 
        int sum=0; 
        for(int j=0;j<n;j++) { 
            if(i != j) { 
                sum+=abs((double)(arr[i]-arr[j])); 
            } 
        } 
        if(sum < min) {  
            min = sum; 
            mini=arr[i]; 
        } 
    }    
      
    cout<<min; 
    return 0; 
} 
 
