#include<iostream> 
#include<stack> 
using namespace std; 
int n; 
int h[80001]={0}; 
struct A { 
    int index; 
    int h; 
}; 
stack<A> st; 
unsigned long long dp[80001]={0}; 
int main() { 
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>h[i]; 
    for(int i=n;i>=1;i--) { 
        A a; 
        a.index = i; 
        a.h = h[i]; 
        if(st.empty()) { 
            dp[i] = 0; 
        } else { 
            A s=a; 
            s.index=n; 
            bool t=false; 
            for(;!st.empty();) { 
                if(st.top().h < h[i]) { 
                    st.pop(); 
                } else { 
                    s = st.top(); 
                    t=true; 
                    break; 
                } 
            } 
            dp[i] = s.index - i - (!t ? 0 : 1); 
        } 
        st.push(a); 
    } 
    unsigned long long sum=0; 
    for(int i=1;i<=n;i++) sum+=dp[i]; 
    cout<<sum; 
} 
 
