#include<iostream> 
#include<algorithm> 
using namespace std; 
int main() { 
    int arr[6]; 
    int c[6]={0}; 
    for(int i=0;i<6;i++) cin>>arr[i]; 
    sort(arr,arr+6); 
    for(int i=0;i<4;i++) { 
        for(int j=i+1;j<5;j++) { 
            for(int k=j+1;k<6;k++) { 
                if(arr[i] == arr[j] && arr[j] == arr[k]) { 
                    if(c[i] == 0 && c[j] == 0 && c[k] == 0) { 
                        c[i]=1; 
                        c[j]=1; 
                        c[k]=1; 
                    } 
                } 
                if(arr[i]+1 == arr[j] && arr[j]+1 == arr[k]) { 
                    if(c[i] == 0 && c[j] == 0 && c[k] == 0) { 
                        c[i]=1; 
                        c[j]=1; 
                        c[k]=1; 
                    } 
                } 
            } 
        } 
    } 
    bool t=true; 
    for(int i=0;i<6;i++) { 
        if(c[i] == 0) t=false; 
    } 
    if(t) cout<<"gin"; 
    else cout<<"lose"; 
} 
 
