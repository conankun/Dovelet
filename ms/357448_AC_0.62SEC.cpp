#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[100001]; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    int max=0; 
    int inputarr[100001]; 
    int index=0; 
    for(int i=0;i<n;i++) { //오름차순 검사. 
          
        if(index == 0) { 
            inputarr[index]=arr[i]; 
            index++; 
            if(index > max) max = index; 
        } else { 
            if(inputarr[index-1] <= arr[i]) { 
                inputarr[index]=arr[i]; 
                index++; 
                if(index > max) max = index; 
            } else { 
                index=0; 
                inputarr[index]=arr[i]; 
            index++; 
            if(index > max) max = index; 
            } 
        } 
  
    } 
          
        index=0; 
        for(int i=0;i<n;i++) { 
            if(index == 0) { 
                inputarr[index]=arr[i]; 
                index++; 
                if(index > max) max = index; 
            } else { 
                if(inputarr[index-1] >= arr[i]) { 
                    inputarr[index]=arr[i]; 
                    index++; 
                    if(index > max) max = index; 
                } else { 
                    index=0; 
                    inputarr[index]=arr[i]; 
                    index++; 
                    if(index > max) max = index; 
                } 
            } 
        } 
  
  
  
        cout<<max; 
} 
 
