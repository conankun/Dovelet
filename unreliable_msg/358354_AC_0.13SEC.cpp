#include<iostream> 
#include<cmath> 
#include<deque> 
#include<string> 
using namespace std; 
string a; 
deque<char> de; 
void msg(char code) { 
    if(code == 'J') { 
        char c = de.back(); 
        de.pop_back(); 
        de.push_front(c); 
    } 
    if(code == 'C') { 
        char c = de.front(); 
        de.pop_front(); 
        de.push_back(c); 
    } 
    if(code == 'E') { 
        for(int i=0;i<de.size()/2;i++) { 
            char temp = de[ceil(de.size()/2.00)+i]; 
            de[ceil(de.size()/2.00)+i] = de[i]; 
            de[i] = temp; 
        } 
    } 
    if(code == 'A') { 
        deque<char> back; 
        int d=de.size(); 
        for(int i=0;i<d;i++) { 
            back.push_back(de.back()); 
            de.pop_back(); 
        } 
        int td=back.size(); 
        for(int i=0;i<td;i++) { 
            de.push_back(back.front()); 
            back.pop_front(); 
        } 
    } 
    if(code == 'P') { 
        for(int i=0;i<de.size();i++) { 
            if(de[i] >= '0' && de[i] <= '9') { 
                if(de[i] == '0') de[i]='9'; 
                else de[i]--; 
            } 
        } 
    } 
    if(code == 'M') { 
        for(int i=0;i<de.size();i++) { 
            if(de[i] >= '0' && de[i] <= '9') { 
                if(de[i] == '9') de[i]='0'; 
                else de[i]++; 
            } 
        } 
    } 
} 
int main() { 
    cin>>a; 
    char c; 
    for(;cin>>c;) { 
        de.push_back(c); 
    } 
    for(int i=a.size()-1;i>=0;i--) { 
        msg(a[i]); 
    } 
    for(;!de.empty();) { 
        cout<<de.front(); 
        de.pop_front(); 
    } 
  
} 
 
