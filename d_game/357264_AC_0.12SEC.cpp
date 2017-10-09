#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    int arr[3]; 
    int max=0; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        int sum=0; 
        cin>>arr[0]>>arr[1]>>arr[2]; 
        if(arr[0] == arr[1] && arr[1] == arr[2]) { 
            sum=10000+arr[0]*1000; 
        } else if(arr[0] == arr[1] || arr[0] == arr[2]) { 
            sum=1000+arr[0]*100; 
        } else if(arr[1] == arr[2]) { 
            sum=1000+arr[1]*100; 
        } else { 
            int max2=0; 
            for(int a=0;a<3;a++) { 
                if(arr[a] > max2) max2 = arr[a]; 
            } 
              
            sum=max2*100; 
        } 
          
        if(sum > max) max = sum; 
          
        sum=0; 
    } 
      
    cout<<max; 
    return 0; 
} 
 
