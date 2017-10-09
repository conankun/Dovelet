#include<iostream> 
#include<stack> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    while(1) { 
        int o[1001]={0}; 
        int in[1001]={0}; 
          
        for(int i=1;i<=n;i++) { 
            in[i] = i; 
            cin>>o[i]; 
            if(o[i] == 0) return 0; 
        } 
  
        stack<int> st; 
        int indexo=1; 
        int indexi=1; 
        bool a = true; 
        do { 
            if(indexi <= n) { 
                st.push(in[indexi]); 
                indexi++; 
            } 
            if(st.top() == o[indexo]) { 
                while(!st.empty()) { 
                    if(st.top() == o[indexo]) { 
                    st.pop(); 
                    indexo++; 
                    } else break; 
                } 
            } else if(!st.empty() && st.top() != o[indexo] && indexi > n) { 
                a = false; 
                break; 
            } 
        }while(!st.empty() || indexo <= n); 
  
        if(a) cout<<"Yes"<<endl; 
        else cout<<"No"<<endl; 
  
    } 
} 
 
