#include <iostream> 
#include <cmath> 
using namespace std; 
bool isprime(int n) { 
    for(int i=2;i<=sqrt(n);i++) { 
        if(n%i == 0) return false; 
    } 
    return true; 
} 
  
int main() { 
    int n; 
    cin>>n; 
    int sosu=2; 
    int a=n; 
    if(n % sosu == 0) { 
        for(int i=2;;i++) { 
            if(isprime(i)) { 
                while(a%i == 0) 
                { 
                    a/=i; 
                    cout<<i<<" "; 
                } 
            } 
            if(a == 1) break; 
            if(i != 2) i++; 
              
        } 
    } else { 
        for(int i=3;;i+=2) { 
            if(isprime(i)) { 
                while(a%i == 0) 
                { 
                    a/=i; 
                    cout<<i<<" "; 
                } 
            } 
            if(a == 1) break; 
        } 
    } 
} 
 
