#include<iostream> 
#include<algorithm> 
using namespace std; 
int datas; 
int n; 
int main() { 
        cin>>n; 
        int arr[1000]; 
        int sortarr[1000]={0}; 
        for(int i=0;i<n;i++) { 
            cin>>arr[i]; 
            sortarr[i] = arr[i]; 
        } 
        sort(sortarr,sortarr+n); 
        int sum=0; 
        int f=99999999,s,in=-1; 
        bool t=false; 
        for(int i=n-1;i>=0;i--) { 
            if(sortarr[i] != arr[i]) { 
                if(in == -1) { 
                 f = sortarr[i]; 
                 s = arr[i]; 
                 in=i; 
                 sum=arr[i]; 
                } 
                if(arr[i] < arr[in]) { 
                 f = sortarr[i]; 
                 s = arr[i]; 
                 in=i; 
                 sum=arr[i]; 
                } 
            } 
        } 
        do { 
            t=false; 
            for(int k=0;k<n;k++) { 
                if(arr[k] == f) { 
                    t= true; 
                    sum+=arr[k]; 
                    arr[in]=arr[k]; 
                    f = sortarr[k]; 
                    in = k; 
                    arr[k]=0; 
                    break; 
                } 
            } 
            if(!t) { 
                for(int k=0;k<n;k++) { 
                    if(arr[k] == 0) { 
                        arr[k]=s; 
                        sum+=s; 
                    } 
                } 
                int f2=999999; 
                for(int k=0;k<n;k++) { 
                    if(arr[k] != sortarr[k] && arr[k] != 0 && arr[k] < f2) { 
                        f=sortarr[k]; 
                        in = k; 
                        f2 = arr[k]; 
                        t=true; 
                    } 
                } 
                if(t) { 
                    s=arr[in]; 
                    sum+=arr[in]; 
                    arr[in]=0; 
                } 
            } 
  
        }while(t); 
        cout<<sum; 
    } 
 
