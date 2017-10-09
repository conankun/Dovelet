#include <iostream>
#include <stack>
#include <queue>
 
using namespace std;
int main() 
{
    char c[100001]={NULL,};
    int a[4];
    queue<int> st;
    queue<int> qu;     stack<int> pal;
    cin>>c;
 
    if(c[0] == '0') {
        cout<<"0";
        return 0;
    }
 
    for(int i=0;;i++) {
        if(c[i] == NULL) break;
         
            int su;
            if(c[i] >= '0' && c[i] <= '9') {
            su = (int)c[i]-48;
             
            for(int z=3;z>=0;z--) {
                a[z] = su % 2;
                su/=2;
            }
             
 
            for(int z=0;z<4;z++) {
                qu.push(a[z]);
            }
 
             
            } else if(c[i] >= 'A' && c[i] <= 'F') {
             
            su = (int)c[i]-65+10;
             
            for(int z=3;z>=0;z--) {
                a[z] = su % 2;
                su/=2;
                 
            }
             
 
            for(int z=0;z<4;z++) {
                qu.push(a[z]);
            }
            }
 
         
    }
    for(int i=0;;i++) {
        if(qu.front() == 1) break;
        else qu.pop();
    }
 
        
    for(int i=0;;i++) {
        if(qu.empty()) break;
     
        if(i == 0) {
            if(qu.size() % 3 == 0) {
            int sum=0;
                               for(int i=0;i<3;i++) {
                    pal.push(qu.front());
                    if(!qu.empty()) qu.pop();
                }
 
                int jari=1;
                                for(int i=0;;i++) {
                    if(pal.empty()) break;
                    sum+=pal.top()*jari;
                    if(!pal.empty()) pal.pop();
                    jari*=2;
                }
 
                st.push(sum);
 
            } else {                 int cha = qu.size() - ((qu.size()/3) *3);
                int sum=0;
                              for(int i=0;i<cha;i++) {
                    pal.push(qu.front());
                    if(!qu.empty()) qu.pop();
                }
 
                int jari=1;
                        for(int i=0;;i++) {
                    if(pal.empty()) break;
                    sum+=pal.top()*jari;
                    if(!pal.empty()) pal.pop();
                    jari*=2;
                }
 
                st.push(sum);
 
            }
        } else {
        if(qu.size() % 3 == 0) {
            int sum=0;
                for(int i=0;i<3;i++) {
                    pal.push(qu.front());
                    if(!qu.empty()) qu.pop();
                }
 
                int jari=1;
                for(int i=0;;i++) {
                    if(pal.empty()) break;
                    sum+=pal.top()*jari;
                    if(!pal.empty()) pal.pop();
                    jari*=2;
                }
 
                st.push(sum);
        }
         
    }
    }
    for(int i=0;!st.empty();i++) {
        cout<<st.front();
        if(!st.empty()) st.pop();
    } 
}