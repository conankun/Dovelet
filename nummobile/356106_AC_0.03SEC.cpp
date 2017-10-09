#include<iostream> 
#include<stdlib.h> 
#include<cstring> 
using namespace std; 
char ch[1000]={0}; 
int t=0; 
int n; 
bool ok=true; 
typedef struct { 
    char digit[1000]; 
    int lastdigit; 
} bignum; 
void init_bignum(bignum *n) { 
    memset(n->digit,0,sizeof(n->digit)); 
    n->lastdigit = 0; 
} 
void copy_bignum(bignum *a,bignum *b) { 
    for(int i=0;i<a->lastdigit;i++) { 
        b->digit[i] = a->digit[i]; 
    } 
    b->lastdigit = a->lastdigit; 
} 
bool check(bignum *a,bignum *b) { 
    for(int i=0;i<a->lastdigit;i++) { 
        if(a->digit[i] != b->digit[i]) return false; 
    } 
    return true; 
} 
bool pull(bignum *a,bignum *b) { 
    char t = a->digit[a->lastdigit-1]; 
    bignum *cc=(bignum *)malloc(sizeof(bignum)); 
    for(int i=a->lastdigit-1;i>=1;i--) { 
        cc->digit[i] = a->digit[i-1]; 
    } 
    cc->digit[0] = t; 
    cc->lastdigit = a->lastdigit; 
    copy_bignum(cc,a); 
    return check(a,b); 
} 
void add_bignum(bignum *a,bignum *b,bignum *c) { 
    init_bignum(c); 
    for(int i=0;i<max(a->lastdigit,b->lastdigit);i++) { 
        if((int)(a->digit[i] + b->digit[i] + c->digit[i]) >= 10) { 
            c->digit[i+1]+=1; 
            c->lastdigit++; 
        } 
        c->digit[i] += (a->digit[i] + b->digit[i]); 
        c->digit[i]%=10; 
    } 
    c->lastdigit = max(a->lastdigit,b->lastdigit) + (c->digit[max(a->lastdigit,b->lastdigit)] != 0 ? 1 : 0); 
} 
int main() { 
    bignum *a = (bignum *)malloc(sizeof(bignum)); 
    bignum *b = (bignum *)malloc(sizeof(bignum)); 
    bignum *c = (bignum *)malloc(sizeof(bignum)); 
    cin>>n; 
    for(int i=0;i<n;i++,t=0,ok=true) { 
        cin>>ch; 
        init_bignum(a); 
        init_bignum(b); 
        init_bignum(c); 
        for(int j=strlen(ch)-1;j>=0;j--) { 
            a->digit[t] = ch[j]-48; 
            b->digit[t++] = ch[j]-48; 
        } 
        a->lastdigit = strlen(ch); 
        b->lastdigit = strlen(ch); 
        add_bignum(a,b,c); 
        bool bo=false; 
        for(int j=0;j<strlen(ch)-1;j++) { 
            init_bignum(c); 
            add_bignum(a,b,c); 
            bo=false; 
            for(int k=0;k<a->lastdigit;k++) { 
                bo=pull(a,c); 
                if(bo) break; 
            } 
            if(!bo) { 
                cout<<"NO"<<endl; 
                break; 
            } 
            copy_bignum(c,a); 
        } 
        if(bo) cout<<"YES"<<endl; 
    } 
}