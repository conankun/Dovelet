#include <iostream> 
#include <stack> 
#include <string> 
using namespace std; 
int main() { 
    char a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',NULL,}; 
    char b[31]={NULL,}; 
    cin>>b; 
    int index=0; 
    bool ab = true; 
    stack<char> st; 
    string qu; 
    int index2=0; 
    for(int i=0;i<31;i++) { 
        if(a[i] == NULL) break; 
        if(b[index] == NULL) break; 
        if(st.empty()) { 
            st.push(a[i]); 
            qu+="push\n"; 
            index2++; 
        } else if(!st.empty()) { 
            if(st.top() != b[index]) { 
            st.push(a[i]); 
            qu+="push\n"; 
            index2++; 
            } 
        } 
        if(!st.empty()) 
        while(st.top() == b[index]) { 
            st.pop(); 
            qu+="pop\n"; 
            index2++; 
            index++; 
            if(st.empty()) break; 
        }  
        if(!st.empty()) 
        if(st.top() > b[index]) { 
            ab = false; 
            break; 
        } 
              
    } 
      
    if(ab) { 
        cout<<qu; 
          
    } else { 
        cout<<"impossible"; 
    } 
  
} 
 
