#include <iostream> 
#include <stack> 
#include <queue> 
using namespace std; 
struct aa{ 
    int index; 
    char c; 
}; 
  
struct bb { 
    int a,b; 
}; 
  
int main() { 
    char c[51]; 
    stack<aa> st; 
    queue<bb> qu; 
    cin>>c; 
    bool a=true; 
    for(int i=0;i<50;i++) { 
        if(c[i] == NULL) break; 
        if(c[i] == '(') { 
            aa aa; 
            aa.index = i; 
            aa.c = c[i]; 
            st.push(aa); 
        } else if(c[i] == ')') { 
            if(st.empty()) { 
                a=false; 
                break; 
            } else { 
                bb bb; 
                bb.a=st.top().index; 
                bb.b = i; 
                qu.push(bb); 
                st.pop(); 
            } 
        } 
    } 
      
    if(!st.empty()) a = false; 
  
    if(a) { 
        while(!qu.empty()) { 
            cout<<qu.front().a<<" "<<qu.front().b<<endl; 
            qu.pop(); 
        } 
    } else cout<<"not match"; 
  
} 
 
