#include<iostream> 
using namespace std; 
int main() { 
    int n,m; 
    cin>>n>>m; // m/n 부터 시작 ^^ 
    int t=m; 
    m = n; 
    n = t; 
    while(m >= 1) { 
        cout<<n/m<<" "; 
        n-=(n/m)*m; 
        t = m; 
        m = n; 
        n = t; 
    } 
} 
 
