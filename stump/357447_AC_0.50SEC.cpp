#include <iostream> 
using namespace std; 
  
int main() { 
    int arr[50001]; 
    int r[50001]={0,}; 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    r[0]=1; 
    for(int i=1;i<n;i++) { 
        //cout<<i<<endl; 
        if(arr[i] > arr[i-1]) { 
            r[i] = r[i-1]+1; 
            r[i-1]=0; 
        } 
        if(arr[i] > arr[i+1] && arr[i] >= arr[i-1]) { 
            int j; 
            for(j=i+1;;j++) { 
                if(arr[j-1] <= arr[j] || j>n-1) { 
                    break; 
                } else r[i]++; 
            } 
            i=j-1; 
        } 
    } 
  
    for(int i=0;i<n;i++) if(r[i] != 0) cout<<i+1<<endl; 
    //cin>>n; 
} 
 
