#include<iostream> 
#include<string> 
using namespace std; 
string root[201]; 
string s; 
int n=0; 
int dp[200001]={0}; 
int main() { 
    while(1) { 
        string input; 
        cin>>input; 
        if(input[0] == '.') break; 
        else root[n++] = input; 
    } 
    while(1) { 
        string input; 
        if(!(cin>>input)) break; 
        else s+=input; 
    } 
    //Base 
    for(int i=0;i<n;i++) { 
        bool t=true; 
        for(int j=0;j<root[i].size();j++) { 
            if(s[j] != root[i][j]) t = false; 
        } 
        if(t) dp[root[i].size()-1]=root[i].size(); 
    } 
    int mx=0; 
    for(int i=0;i<s.size();i++) { 
        if(dp[i] != 0) { 
            for(int j=0;j<n;j++) { 
                bool t = true; 
                if(i+root[j].size() <= s.size()-1) { 
                for(int k=1;k<=root[j].size();k++) { 
                    if(s[i+k] != root[j][k-1]) t=false; 
                } 
                if(t) { 
                    dp[i+root[j].size()] = i+root[j].size()+1; 
                } 
            } 
        } 
    } 
} 
    for(int i=0;i<s.size();i++) { 
        if(dp[i] > mx) mx = dp[i]; 
    } 
    cout<<mx; 
} 
 
