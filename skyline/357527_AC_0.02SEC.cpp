#include<iostream> 
#include<algorithm> 
using namespace std; 
int n; 
int xpos[1000]={0}; 
int xvalue[1000]={0}; 
int xin=1; 
struct A { 
    int x1,x2,h; 
}; 
A arr[1000]={0}; 
bool cmp(A a,A b) { 
    return a.x1 < b.x1; 
} 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i].x1>>arr[i].x2>>arr[i].h; 
        xpos[xin++]=arr[i].x1; 
        xpos[xin++]=arr[i].x2; 
    } 
  
    sort(xpos,xpos+xin); 
    sort(arr,arr+n,cmp); 
    for(int i=0;i<xin-1;i++) { 
        for(int j=0;j<n;j++) { 
            if((xpos[i] >= arr[j].x1 && xpos[i] <= arr[j].x2) && (xpos[i+1] >= arr[j].x1 && xpos[i+1] <= arr[j].x2)) { 
                xvalue[i]=max(xvalue[i],arr[j].h); 
            } 
        } 
    } 
    int s=0; 
    for(;;) { 
        for(int j=s+1;j<xin;j++) { 
            if(xvalue[s] != xvalue[j]) { 
                if(s != 0)cout<<xpos[s]<<" "<<xpos[j]<<" "<<xvalue[s]<<endl; 
                s = j; 
                continue; 
            } 
        } 
        break; 
    } 
      
} 
 
