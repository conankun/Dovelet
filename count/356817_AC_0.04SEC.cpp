#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int sum=0; 
    int nowi; 
    for(int i=1;;i++) { 
        if(sum+i >= n) { 
            sum+=i; 
            nowi=i; 
            break; 
        } else { 
            sum+=i; 
            continue; 
        } 
    } 
      
  
  
    int a,b; 
    if(nowi % 2 == 1) { //전체 원소 갯수 홀수개 
        if(n <= sum-((sum-nowi)+1) + (sum-((sum-nowi)+1))/2) { 
            b = nowi+(n-sum); 
            a = (nowi+1)-b; 
            cout<<n<<" IS "<<a<<"/"<<b; 
        } else if(n == ((sum-nowi)+sum)/2+1) { 
            a = nowi/2+1; 
            b = a; 
            cout<<n<<" IS "<<a<<"/"<<b; 
        } else { 
            a = (sum-n+1); 
            b = (nowi+1)-a; 
            cout<<n<<" IS "<<a<<"/"<<b; 
        } 
          
          
    } else { //전체 원소 갯수 짝수개 
  
        if(n <= (sum-nowi)/2) { 
            a = nowi+(n-sum); 
            b = (nowi+1)-a; 
            cout<<n<<" IS "<<a<<"/"<<b; 
        } else { 
            b = (sum-n+1); 
            a = (nowi+1)-b; 
            cout<<n<<" IS "<<a<<"/"<<b; 
        } 
    } 
      
    return 0; 
} 
 
