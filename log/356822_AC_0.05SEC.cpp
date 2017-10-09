#include<iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int s=0; 
    int a,b=9999999; 
    for(int i=1;i<=n;i++) { 
        s=0; 
        for(int j=i;j>=1;j--) { 
            if(n-s <= j) { 
                if(i < b) { 
                    a = n-s; 
                    b = i; 
                } 
            } 
            s+=j; 
        } 
    } 
    cout<<b<<" "<<a; 
} 
 
