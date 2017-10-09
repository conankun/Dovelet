#include <iostream> 
using namespace std; 
int main() { 
    int a,b,c,d,s; 
    cin>>a>>b>>c>>d>>s; 
  
    int m1=s/(a+b); 
    int n1=s%(a+b); 
    int sum1=0; 
    if(s >= a+b) sum1+=m1*(a-b); 
  
    if(n1 != 0) { 
    if(n1 <= a) { 
    sum1+=n1; 
    } else { 
    sum1+=a; 
    sum1-=(n1-a); 
    } 
    } 
  
    int m2=s/(c+d); 
    int n2=s%(c+d); 
    int sum2=0; 
    if(s>= a+b) sum2+=m2*(c-d); 
  
    if(n2 != 0) { 
    if(n2 <= c) { 
    sum2+=n2; 
    } else { 
    sum2+=b; 
    sum2-=(n2-c); 
    } 
    } 
  
    //cout<<n1<<" "<<sum1<<" "<<sum2<<endl; 
    if(sum1 > sum2) { 
    cout<<"Nikky"; 
    } else if(sum2 > sum1) { 
    cout<<"Byron"; 
    } else cout<<"Tied"; 
      
} 
 
