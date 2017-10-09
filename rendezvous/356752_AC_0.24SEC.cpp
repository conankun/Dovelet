#include<iostream> 
using namespace std; 
int gcd(int a,int b) { 
    int c; 
    do { 
        c = a%b; 
        a = b; 
        b = c; 
    }while(c != 0); 
    return a; 
} 
int main() { 
    int a,b; 
    cin>>a>>b; 
    cout<<(a+b)/gcd(a,b); 
} 
 
