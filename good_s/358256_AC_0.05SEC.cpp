#include<iostream> 
using namespace std; 
int n; 
int s[100]={0}; 
bool t=false; 
void goods(int level) { 
    if(level == n+1) { 
        for(int i=1;i<=n;i++) cout<<s[i]; 
        t=true; 
        return; 
    } 
    for(int i=1;i<=3;i++) { 
        if(!t) { 
            s[level]=i; 
            bool ok=true; 
            for(int j=1;j<=level/2;j++) { //중복 수열 검사 ㅋ 
                int e=level-j; 
                int e2=level; 
                bool ch=false; 
                for(int k=0;k<j;k++) { 
                    if(s[e-k] != s[e2-k]) ch=true; 
                } 
                if(ok) ok=ch; 
            } 
              
            if(ok) { 
                goods(level+1); 
            } 
        } 
    } 
} 
int main() { 
    cin>>n; 
    if(n == 1) cout<<1; 
    else { 
        s[1]=1; 
        goods(2); 
    } 
} 
 
