#include <iostream> 
#include <stack> 
using namespace std; 
int main() { 
    int n,a; 
    stack<char> st; 
    cin>>n>>a; 
      
    while(1) { 
        if(n <= 0) break; 
        if(n%a < 10) 
        st.push(48+n%a); 
        else
        st.push(65+(n%a-10)); 
        n/=a; 
    } 
  
    while(!st.empty()) { 
        cout<<st.top(); 
        if(!st.empty()) st.pop(); 
    } 
} 
 
