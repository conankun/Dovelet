#include<iostream> 
using namespace std; 
int n; 
char c[100]={0}; 
int cnt=0; 
void DFS(int level,int o,int x) { 
    if(o == n) { 
        for(int i=1;i<=level;i++) cout<<c[i]; 
        cout<<endl; 
        cnt++; 
        return; 
    } 
    if(level == n*2-1) return; 
    else { 
        c[level+1]='o'; 
        DFS(level+1,o+1,x); 
        c[level+1]='x'; 
        DFS(level+1,o,x+1); 
    } 
} 
int main() { 
    cin>>n; 
    DFS(0,0,0); 
    cout<<"total "<<cnt<<" case(s)"; 
} 
 
