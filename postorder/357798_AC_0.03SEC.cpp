#include<iostream> 
using namespace std; 
int tree[100]={0}; 
void inputDFS(int index) { 
    int a,b; 
    cin>>a; 
    if(a != -1) { 
        tree[index*2]=a; 
        inputDFS(index*2); 
    } 
    cin>>b; 
    if(b != -1) { 
        tree[index*2+1]=b; 
        inputDFS(index*2+1); 
    } 
} 
void DFS(int index) { 
    if(tree[index*2] != 0 && tree[index*2] != -1) { 
        DFS(index*2); 
        cout<<tree[index*2]<<" "; 
    } 
    if(tree[index*2+1] != 0 && tree[index*2+1] != -1) { 
        DFS(index*2+1); 
        cout<<tree[index*2+1]<<" "; 
    } 
} 
int main() { 
    cin>>tree[1]; 
    inputDFS(1); 
    DFS(1); 
    cout<<tree[1]; 
} 
 
