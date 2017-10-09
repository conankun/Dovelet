#include <iostream> 
#include <stack> 
using namespace std; 
int main() { 
    char c[101]={NULL,}; 
    cin>>c; 
    stack<char> st; 
    int index=0; 
    for(int i=101;i>=0;i--) { 
        if((int)c[i] == 0) { 
            continue; 
        } 
        else { 
            if(c[i] >= '0' && c[i] <= '9') { 
            index++; 
            st.push(c[i]); 
            if(index % 3 == 0) { 
                if(i!=0) 
                st.push(','); 
            } 
            } 
        } 
    } 
  
    while(!st.empty()) { 
        cout<<st.top(); 
        st.pop(); 
    } 
    cin>>c; 
} 
 
