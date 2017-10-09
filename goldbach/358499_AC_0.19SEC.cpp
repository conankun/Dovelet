#include <iostream> 
using namespace std; 
  
int ingyue[1000000]; 
int indexingyue=0; 
int max=0; 
  
int a=0,b=0; 
  
bool isPrime(int n) 
{ 
    int i; 
      
    for(i = 2; i*i <= n; i++) 
        if(n%i == 0) return false; 
      
    return true; 
}  
  
  
void gold(int n) { 
    int i; 
    i=2; 
    if(isPrime(n-2) == true) { 
        a = 2; 
        b = n-2; 
        return; 
    } 
    for(i=3;i<=n;i+=2) { 
        if(isPrime(n-i) == true && isPrime(i) == true) { 
            a = i; 
            b = n-i; 
            return; 
        } 
    } 
      
} 
int main () { 
    int n; 
    cin>>n; 
    gold(n); 
    if(a == 0 || b == 0) cout<<"Goldbach's conjecture is wrong."; 
    else
        if(a > b) { 
            printf("%d = %d + %d",n,b,a); 
        } else { 
            printf("%d = %d + %d",n,a,b); 
        } 
    return 0; 
} 
 
