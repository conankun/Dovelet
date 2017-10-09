#include <iostream> 
#include <algorithm> 
using namespace std; 
int main() { 
    int arr[5],arr2[5]; 
    for(int i=0;i<5;i++) cin>>arr[i]; 
  
    int b=5; 
  
    for(int i=0;i<5;i++) { 
        if(arr[i] >= 0) arr2[i]=arr[i]%b; 
        else { 
            int j; 
            for(j=0;j<=b;j++) { 
                if((-1*(arr[i]-j)) % 5 == 0) break; 
            } 
            arr2[i]=j; 
        } 
    } 
    sort(arr2,arr2+5); 
    for(int i=1;i<5;i++) { 
          
        if(arr2[i]-arr2[i-1] != 1)  { 
            cout<<"no"; 
            return 0; 
        } 
    } 
    cout<<"yes"; 
} 
 
