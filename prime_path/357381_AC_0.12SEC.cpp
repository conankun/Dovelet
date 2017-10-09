#include<iostream> 
#include<cmath> 
#include<string> 
#include<queue> 
using namespace std; 
bool isPrime(int n) { 
    for(int i=2;i*i<=n;i++) { 
        if(n%i == 0) return false; 
    } 
    return true; 
} 
int convert(string s) { 
    int t=1; 
    int i; 
    int sum=0; 
    for(i=3;i>=0;i--) { 
        sum+=(t*(s[i]-'0')); 
        t*=10; 
    } 
    return sum; 
} 
struct A { 
     string value; 
     int t; 
}; 
int prime[10000]={0}; 
int vis[10000]={0}; 
int main() { 
    string a,b; 
    cin>>a>>b; 
    for(int i=1000;i<=9999;i++) { 
        if(isPrime(i)) { 
            prime[i]=1; 
        } 
    } 
    queue<A> qu; 
    A tt; 
    tt.value = a; 
    tt.t = 0; 
    qu.push(tt); 
    while(!qu.empty()) { 
        if(qu.front(). value == b) { 
            cout<<qu.front().t; 
            break; 
        } else { 
            for(int i=0;i<4;i++) { 
                string c = qu.front().value; 
                for(int j=0;j<=9;j++) { 
                    c[i] = j+'0'; 
                    if(prime[convert(c)] && vis[convert(c)] == 0) { 
                        tt.value = c; 
                        tt.t = qu.front().t+1; 
                        vis[convert(c)] = 1; 
                        qu.push(tt); 
                    } 
                } 
                  
            } 
        } 
        qu.pop(); 
    } 
} 
 
