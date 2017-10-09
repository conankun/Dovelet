#include<iostream> 
using namespace std; 
int n; 
int arr[100]={0}; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
    for(int i=0;i<n;i++) { 
        for(int j=i+1;j<n;j++) { 
            for(int k=j+1;k<n;k++) { 
                for(int z=k+1;z<n;z++) { 
                    for(int s=z+1;s<n;s++) { 
                        for(int t=s+1;t<n;t++) { 
                            cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[z]<<" "<<arr[s]<<" "<<arr[t]<<endl; 
                        } 
                    } 
                } 
            } 
        } 
    } 
} 
 
