#include<iostream> 
#include<algorithm> 
using namespace std; 
struct A { 
    int s,e; 
}; 
A arr[5000]={0}; 
bool cmp(A a,A b) { 
    if(a.s == b.s) return a.e < b.e; 
    return a.s < b.s; 
} 
int es[5000]={0}; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i].s>>arr[i].e; 
    sort(arr,arr+n,cmp); 
    int mx=0; 
    int mx2=0; 
    int s=arr[0].s,e=arr[0].e; 
    for(int i=0;i<n;i++) { 
        int fs=arr[i].s; 
        int fe=arr[i].e; 
        for(int j=i+1;j<n;j++) { 
            if(arr[j].s <= fe) { 
                if(fe < arr[j].e) { 
                    s = arr[i].s; 
                    e = arr[j].s; 
                    fe = arr[j].e; 
                } 
            } 
        } 
        if(fe-fs > mx2) mx2 = fe-fs; 
        es[i]=fe; 
    } 
    for(int i=0;i<n;i++) { 
        bool t=true; 
        for(int j=i-1;j>=0;j--) { 
            if(arr[i].s <= es[j]) { 
                t=false; 
                break; 
            } 
        } 
        int tt=0; 
        for(int j=0;j<n;j++) { 
            if(i == j) continue; 
            else { 
                if(es[j] < arr[i].s) { 
                    tt=max(tt,es[j]); 
                } 
            } 
        } 
        if(arr[i].s > tt && t) { 
            if(tt != 0) 
            mx = max(arr[i].s-tt,mx); 
        } 
    } 
    cout<<mx2<<" "<<mx; 
} 
 
