#include <iostream> 
using namespace std; 
  
int y=0; 
  
int jarisu(int n,int i=1) { 
    if(n / i <= 0) return i/10; 
    return jarisu(n,i*=10); 
} 
  
void yuksu(int n,int i) { 
        y+=(n%10) * i; 
        if(n <= 1) return; 
        yuksu(n/10,i/10); 
} 
  
bool isPrime(int n) { 
    int i; 
    for(i=2;i*i<=n;i++) { 
        if(n % i == 0) return false; 
    } 
    if(i*i > n) return true; 
    return false; 
} 
  
int main() { 
    int n; 
    cin>>n; 
    yuksu(n,jarisu(n)); 
      
    if(isPrime(n) && isPrime(y)) { 
        cout<<n<<" is an emirp";     
    } else if(isPrime(n)) { 
        cout<<n<<" is a prime"; 
    } else { 
        cout<<n<<" is not prime"; 
    } 
} 
 
