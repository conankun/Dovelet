#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    cin>>n; 
    int arr[1001]; 
    int sum=0; 
    int sumh=0; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        sum+=arr[i]; 
    } 
    sum/=n; 
      
    for(int i=0;i<n;i++) { 
        if(arr[i] > sum) { 
            sumh++; 
        } 
    } 
      
    printf("%.3f%%",((float)sumh/(float)n)*100); 
      
    return 0; 
} 
 
