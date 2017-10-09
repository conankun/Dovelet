#include<iostream> 
#include<algorithm> 
using namespace std; 
struct A { 
    double w,v; 
}; 
A arr[1000]; 
bool cmp(A a,A b) { 
    return (a.v/a.w) > (b.v/b.w); 
} 
int main() { 
    int n; 
    cin>>n; 
    int t; 
    cin>>t; 
    for(int i=0;i<t;i++) { 
        cin>>arr[i].w>>arr[i].v; 
    } 
    sort(arr,arr+t,cmp); 
    double total=0; 
    for(int i=0;i<t;i++) { 
        if(n >= arr[i].w) { 
            total+=arr[i].v; 
            n-=arr[i].w; 
        } else { 
            double cc=(n/arr[i].w); 
            total+=cc*arr[i].v; 
            break; 
        } 
    } 
    printf("%.2f",total); 
}