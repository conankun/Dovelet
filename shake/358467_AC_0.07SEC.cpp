#include<iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[1001]; 
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>arr[i]; 
    int c=0; 
    int low=1,high=n; 
    for(;low<high;c++) { 
        int l=low,h=high; 
        for(int i=l+1;i<=h;i++) { 
            if(arr[i] < arr[i-1]) { 
                high=i; 
                int temp=arr[i]; 
                arr[i]=arr[i-1]; 
                arr[i-1]=temp; 
            } 
        } 
        h = high; 
        for(int i=h;i>l;i--) { 
            if(arr[i] < arr[i-1]) { 
                low=i; 
                int temp=arr[i]; 
                arr[i]=arr[i-1]; 
                arr[i-1]=temp; 
            } 
        } 
        if(l == low && h == high) break; 
    } 
    cout<<c+1; 
} 
 
