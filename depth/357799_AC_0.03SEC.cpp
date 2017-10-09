#include<iostream> 
#include<queue> 
using namespace std; 
int tree[10000]={0}; 
int c=0,h=0; 
struct A { 
    int index,height; 
}; 
queue<A> qu; 
void inputDFS(int index) { 
    int a; 
    cin>>a; 
    if(a != -1){ 
        tree[index] = a; 
        inputDFS(index*2); 
        inputDFS(index*2+1); 
    } 
} 
int main() { 
    inputDFS(1); 
    A a; 
    a.height = 1; 
    a.index = 1; 
    qu.push(a); 
    while(!qu.empty()) { 
        int index = qu.front().index; 
        int height = qu.front().height; 
        if(height > h) h = height; 
        if(tree[index*2] != -1 && tree[index*2+1] != -1 && tree[index*2] != 0 && tree[index*2+1] != 0) ++c; 
        if(tree[index*2] != -1 && tree[index*2] != 0) { 
            a.index = index*2; 
            a.height = height+1; 
            qu.push(a); 
        } 
        if(tree[index*2+1] != -1 && tree[index*2+1] != 0) { 
            a.index = index*2+1; 
            a.height = height+1; 
            qu.push(a); 
        } 
        qu.pop(); 
    } 
    cout<<c<<endl<<h; 
} 
 