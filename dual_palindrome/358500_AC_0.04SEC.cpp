#include<iostream> 
using namespace std; 
bool dual_palin(int n) { 
    int cnt=0; 
    int m=n; 
    for(int i=2;i<=10;i++) { 
        m=n; 
        int arr[100]={0},arr2[100]={0}; 
        int in=0; 
        bool t=true; 
        while(m > 0) { 
            arr[in++]=m%i; 
            m/=i; 
        } 
        int ain=0; 
        for(int i=in-1;i>=0;i--) { 
            arr2[i]=arr[ain++]; 
        } 
        for(int i=0;i<in;i++) { 
            if(arr[i] != arr2[i]) t=false; 
        } 
        if(t) cnt++; 
    } 
    if(cnt >=2) return true; 
    return false; 
} 
int main() { 
    int n,s; 
    cin>>n>>s; 
    int t=0; 
    for(int i=s+1;;i++) { 
        if(dual_palin(i)) { 
            t++; 
            cout<<i<<endl; 
        } 
        if(t >= n) break; 
    } 
} 
 
