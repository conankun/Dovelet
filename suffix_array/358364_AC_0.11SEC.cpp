#include<iostream> 
#include<string> 
#include<algorithm> 
#include<string.h> 
using namespace std; 
string s; 
struct A { 
    char s[3000]; 
}; 
bool cmp(A a,A b) { 
        return strcmp(a.s,b.s) < 0; 
} 
A arr[10000]={0}; 
int ind=0; 
int main() { 
    char s[10000]; 
    int ind2=0; 
    for(int t=0;;t++) { 
        char c; 
        if(cin>>c) { 
            s[ind2++]=c; 
        } else break; 
    } 
    for(int t=0;t<ind2;t++) { 
        int in=0; 
        for(int i=t;i<ind2;i++) { 
            arr[ind].s[in++] = s[i]; 
        } 
        ind++; 
    } 
    sort(arr,arr+ind2,cmp); 
    for(int i=0;i<ind2;i++) { 
        cout<<arr[i].s<<" "<<ind2-strlen(arr[i].s)<<endl; 
    } 
} 
 
