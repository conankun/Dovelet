#include<iostream> 
#include<stack> 
using namespace std; 
int main() { 
    int n,se; 
    int edge[11][11]={0,}; 
    int vis[11]={0,}; 
    stack<int> st; 
    cin>>n>>se; 
    int a,b; 
    while(fscanf(stdin,"%d %d",&a,&b) != EOF) { 
        edge[a][b] = 1; 
        edge[b][a]=1; 
    } 
  
    int s=se; 
    cout<<s<<" "; 
    vis[s]=1; 
    while(1) { 
        int ss=0;for(int i=1;i<=n;i++) ss+=vis[i]; 
        if(ss == n) break; 
        for(int i=n;i>=1;i--) { 
            if(edge[s][i] == 1 && vis[i] == 0) { //연결되어있고 , 미방문이면. 
                st.push(i); //stack push. 
            } 
        } 
        s = st.top(); 
        vis[s]=1; 
        cout<<st.top()<<" "; 
        st.pop(); 
    } 
} 
 
