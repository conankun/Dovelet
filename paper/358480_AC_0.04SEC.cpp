#include<iostream> 
#include<algorithm> 
using namespace std; 
int tx,ty; 
int n; 
int x[1000]={0}; 
int y[1000]={0}; 
int xin=1; 
int yin=1; 
int cx[1000]={0}; 
int cy[1000]={0}; 
int main() { 
    cin>>y[0]>>x[0]; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        int a,b; 
        cin>>a>>b; 
        if(a == 0) { 
            x[xin++]=b; 
        } else { 
            y[yin++]=b; 
        } 
    } 
    sort(x,x+xin+1); 
    sort(y,y+yin+1); 
    for(int i=1;i<=xin;i++) { 
        cx[i] = x[i]-x[i-1]; 
    } 
    for(int i=1;i<=yin;i++) { 
        cy[i] = y[i]-y[i-1]; 
    } 
    int mx=0; 
    for(int i=1;i<=xin;i++) { 
        for(int j=1;j<=yin;j++) { 
            if(cx[i]*cy[j] > mx) mx = cx[i]*cy[j]; 
        } 
    } 
    cout<<mx; 
} 
 
