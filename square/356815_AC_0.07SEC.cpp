#include <iostream> 
#include<math.h> 
using namespace std; 
int main() { 
    int m,n; 
    cin>>m>>n; 
    int sum=0; 
    int min=2147483647; 
    for(int i=1;i<=sqrt(n);i++) { 
        if(i * i >= m && i * i <= n) { 
            sum+=i*i; 
            if(min > i*i) min = i * i; 
        } 
    } 
      
    if(sum == 0) cout<<"-1"; 
    else
    cout<<sum<<endl<<min; 
  
    return 0; 
} 
 
