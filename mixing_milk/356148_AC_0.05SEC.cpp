#include<iostream> 
#include<algorithm> 
using namespace std; 
struct A { 
    int p; 
    int a; 
}; 
bool cmp(A a,A b) { 
    return a.p < b.p; 
} 
A arr[5000]; 
int main() { 
    int p,a; 
    cin>>p>>a; 
    for(int i=0;i<a;i++) { 
        int c,d; 
        cin>>c>>d; 
        arr[i].p = c; 
        arr[i].a = d; 
    } 
    sort(arr,arr+a,cmp); 
    int pr=0; 
    for(int i=0;i<a;i++) { 
        if(p>=arr[i].p) { 
            pr+=arr[i].p * (arr[i].a < p ? arr[i].a : p); 
            p-=arr[i].a; 
        } else { 
            pr+=arr[i].p * p; 
            p=0; 
        } 
            if(p <= 0) { 
                cout<<pr; 
                return 0; 
            } 
          
    } 
    cout<<0; 
}