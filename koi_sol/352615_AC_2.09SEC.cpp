#include<iostream> 
#include<stdlib.h> 
#include<algorithm> 
using namespace std; 
long long arr[5000]; 
int n; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    sort(arr,arr+n); 
    long long ar[3]; 
    long long mn=100000000000LL; 
    for(int i=0;i<=n-3;i++) { 
        int low = i+1; 
        int high = n-1; 
        for(;;) { 
            long long a=100000000000LL; 
            long long b=100000000000LL; 
            long long c=100000000000LL; 
            long long d=100000000000LL; 
            if(low != high) a=abs(arr[low]+arr[high]+arr[i]); 
            if(low+1 != high) b=abs(arr[low+1]+arr[high]+arr[i]); 
            if(low != high-1)c=abs(arr[low]+arr[high-1]+arr[i]); 
            if(low+1 != high-1)d=abs(arr[low+1]+arr[high-1]+arr[i]); 
            if(a < mn) { 
                mn = a; 
                ar[1]=arr[low]; 
                ar[2]=arr[high]; 
                ar[0] =arr[i]; 
            } 
            int low2=low,high2=high; 
            if(b <= c && b <= d) { 
                low2++; 
            } else if(c <= b && c <= d) { 
                high2--; 
            } else if(d <= b && d <= c) { 
                low2++; 
                high2--; 
            } 
            if(abs(low-high) <= 1) break; 
            low=low2; 
            high=high2; 
        } 
    } 
    for(int i=0;i<3;i++) cout<<ar[i]<<" "; 
} 
