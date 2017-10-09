#include<iostream> 
#include<stack> 
using namespace std; 
struct A { 
    int index,value; 
}; 
int arr[500000]={0}; 
int main() { 
    int n; 
    cin>>n; 
    A a; 
    stack<A> st; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
    for(int i=0;i<n;i++) { 
        for(;!st.empty();) { 
            if(st.top().value < arr[i]) st.pop(); 
            if(st.empty()) break; 
            if(st.top().value > arr[i]) break; 
        } 
        if(st.empty()) cout<<0<<" "; 
        else cout<<st.top().index+1<<" "; 
        a.index = i; 
        a.value = arr[i]; 
        st.push(a); 
    } 
} 
 
