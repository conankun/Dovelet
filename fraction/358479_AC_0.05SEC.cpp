#include<iostream> 
#include<algorithm> 
using namespace std; 
struct A { 
    int a,b; 
}; 
A arr[100000]={0}; 
int n; 
int in=0; 
bool cmp(A a,A b) { 
    return (double)a.a/a.b < (double)b.a/b.b; 
} 
int gcd(int a,int b) { 
    int gob=a*b; 
    int c; 
    do { 
        c = a % b; 
        a = b; 
        b = c; 
    }while(c != 0); 
    return a; 
} 
int main() { 
    cin>>n; 
    cout<<"0/1"<<endl; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=i-1;j++) { 
            if(gcd(i,j) == 1) { 
                A a; 
                a.a = j; 
                a.b = i; 
                arr[in++]=a; 
            } 
        } 
    } 
    sort(arr,arr+in,cmp); 
    for(int i=0;i<in;i++) { 
        cout<<arr[i].a<<"/"<<arr[i].b<<endl; 
    } 
    cout<<"1/1"; 
} 
 
