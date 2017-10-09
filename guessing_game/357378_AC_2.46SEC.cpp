#include<iostream> 
#include<string> 
using namespace std; 
int main() { 
    int n; 
    int high[100]={0}; 
    int low[100]={0}; 
    int ih=0,il=0; 
    while(cin>>n) { 
        string s,s2; 
        cin>>s>>s2; 
        bool t=true; 
        if(s == "right" && s2 == "on") { 
            for(int i=0;i<ih;i++) { 
                if(n >= high[i]) { 
                    t=false; 
                    break; 
                } 
            } 
   
            for(int i=0;i<il;i++) { 
                if(n <= low[i]) { 
                    t=false; 
                    break; 
                } 
            } 
        } 
        if(!t) { 
            cout<<"Stan is dishonest"; 
            return 0; 
        } else { 
            if(s == "too" && s2 == "high") { 
                high[ih++]=n; 
            } else if(s == "too" && s2 == "low") { 
                low[il++]=n; 
            } 
        } 
   
    } 
    cout<<"Stan may be honest"; 
} 
 
