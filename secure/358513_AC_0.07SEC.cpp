#include<iostream> 
#include<algorithm> 
using namespace std; 
int l,c; 
char arr[1000]={0}; 
char list[1000]={0}; 
void bt(int index,int level) { 
    if(level == l) { 
        int cnt=0; 
        for(int i=1;i<=l;i++) { 
            if(list[i] == 'a' || list[i] == 'e' || list[i] == 'i' || list[i] == 'u' || list[i] == 'o') cnt++; 
        } 
        if(cnt >= 1 && l-cnt >= 2) { 
            for(int i=1;i<=l;i++) cout<<list[i]; 
            cout<<endl; 
        } 
    } else { 
        for(int i=index+1;i<c;i++) { 
            list[level+1] = arr[i]; 
            bt(i,level+1); 
            list[level+1] = 0; 
        } 
    } 
} 
int main() { 
    cin>>l>>c; 
    for(int i=0;i<c;i++) cin>>arr[i]; 
    sort(arr,arr+c); 
    bt(-1,0); 
} 
 
