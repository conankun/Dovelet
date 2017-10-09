#include<iostream> 
#include<cmath> 
#include<algorithm> 
using namespace std; 
int a,b; 
int palin[10000000]={0}; 
int index=0; 
void makePalin(int n) { 
    int m=n; 
    int mlog=log10((double)n); 
    int g = pow(10,(double)(int)log10((double)n) ); 
    int sum=0; 
    while(n > 0) { 
        sum+=g*(n%10); 
        n/=10; 
        g/=10; 
    } 
    palin[index++]=sum+(pow(10,(double)mlog+1) * m); 
    for(int i=0;i<=9;i++) { 
        palin[index++]=sum+(pow(10,(double)mlog+2) * m)+(pow(10,(double)mlog+1) * i); 
    } 
} 
int main() { 
    cin>>a>>b; 
    for(int i=a;i<=9;i++) palin[index++] = i; 
    for(int i=1;i<=9999;i++) { 
        makePalin(i); 
    } 
    sort(palin,palin+index); 
    for(int i=0;i<index;i++) { 
        bool t=true; 
        if(palin[i] > b) break; 
        for(int j=2;j*j<=palin[i];j++) { 
            if(palin[i] % j == 0) { 
                t=false; 
                break; 
            } 
        } 
        if(t && palin[i] >= a) cout<<palin[i]<<endl; 
    } 
} 
 
