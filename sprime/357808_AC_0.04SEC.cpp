#include<iostream> 
#include<cmath> 
using namespace std; 
int n; 
bool isPrime(int n) { 
    if(n == 1) return false; 
    if(n == 2) return true; 
    for(int i=2;i*i<=n;i++) { 
        if(n%i == 0) return false; 
    } 
    return true; 
} 
void sprime(int level,int su) { 
    if(isPrime(su)) { 
        if(level == n) { 
            cout<<su<<endl; 
            return; 
        } else { 
            for(int i=1;i<=9;i++) { 
                if(isPrime(su*10+i)) sprime(level+1,su*10+i); 
            } 
        } 
    } 
} 
int main() { 
    cin>>n; 
    sprime(0,0); 
} 
 
