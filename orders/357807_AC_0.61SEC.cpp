#include<iostream> 
#include<algorithm> 
using namespace std; 
char a[301]={0}; 
int vis[301]={0}; 
char ar[301]={0}; 
int cnt=0; 
void bt(int n) { 
    char arr[301]={0}; 
    int in=0; 
    if(n == cnt+1) { 
        for(int i=1;i<=n-1;i++) cout<<ar[i]; 
        cout<<endl; 
    } else { 
    for(int i=0;i<cnt;i++) { 
        bool b=true; 
        for(int j=0;j<10;j++) { 
            if(arr[j] == a[i]) b=false; 
        } 
        if(b && vis[i] != 1) { 
            arr[in]=a[i]; 
            in++; 
            ar[n]=a[i]; 
            vis[i] = 1; 
            bt(n+1); 
            ar[n]=' '; 
            vis[i]=0; 
        } 
    } 
    } 
} 
int main() { 
    cin>>a; 
    for(int i=0;i<301;i++) { 
        if(a[i] == NULL) break; 
        else cnt++; 
    } 
    sort(a,a+cnt); 
    bt(1); 
      
} 
 
