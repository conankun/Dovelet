#include <iostream> 
#include <cmath> 
using namespace std; 
int main() { 
    int n; 
    int arr[3001]; 
    int arr2[3001]={0,}; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
  
    bool a = true; 
    for(int i=0;i<n-1;i++) { 
        int x,y; 
        if(arr[i] > arr[i+1]) { 
            x = arr[i];y=arr[i+1]; 
        } else { 
            x = arr[i+1];y=arr[i]; 
        } 
        if(x-y >= 1 && x-y <=n-1) { 
                if(arr2[x-y] > 0) { 
                    cout<<"Not jolly"; 
                    a=false; 
                    break; 
                } else arr2[x-y]++; 
              
        } else { 
            cout<<"Not jolly"; 
            a=false; 
            break; 
        } 
    } 
  
    if(a) cout<<"Jolly"; 
} 
 
