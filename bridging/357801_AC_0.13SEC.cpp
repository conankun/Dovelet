#include<iostream> 
using namespace std; 
int tree[1000000]={0}; 
int brid[1000000]={0}; 
int n; 
int i; 
int size=1; 
int main() { 
    cin>>n; 
    for(i=1;i<=n;i++) cin>>brid[i]; 
    for(;size<n;size*=2); 
    int le=0; 
    for(int i=1;i<=n;i++) { 
        int ld = size, rd = size+brid[i]-2; 
        bool t=true; 
        int mx=0; 
        while(ld <= rd && t) { 
            if(ld == rd) t = false; 
            if(ld%2 == 1) { 
                if(tree[ld] > mx) mx = tree[ld]; 
                ld++; 
            } 
            if(rd%2 == 0) { 
                if(tree[rd] > mx) mx = tree[rd]; 
                rd--; 
            } 
            ld/=2; 
            rd/=2; 
        } 
        mx++; 
        if(mx > le) le = mx; 
        int rw = size+brid[i]-1; 
        while(rw > 0) { 
            if(tree[rw] < mx) tree[rw] = mx; 
            rw/=2; 
        } 
    } 
    cout<<le; 
} 
 
