#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int gesu=0,sum=0; 
    unsigned long long gob=1; 
    for(int i=1;i<=n;i++) { 
        if(n%i == 0) { 
            cout<<i<<" "; 
            gesu++; 
            sum+=i; 
            gob*=i; 
            if(gob > 10 && gob % 10 != 0) gob = gob % 10; 
        } 
    } 
    cout<<endl; 
      
    cout<<gesu<<endl; 
    cout<<sum<<endl; 
      
      
    printf("%lld",gob%10); 
      
    return 0; 
} 
 
