#include <iostream> 
using namespace std; 
int main() { 
    char c[21][21]; 
    int co[21][21]={0,}; 
    char c2[21][21]; 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>c[i][j]; 
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>c2[i][j]; 
  
    for(int i=0;i<n;i++) { //y 
        for(int j=0;j<n;j++) {//x 
            int count=0; 
            if(i > 0) { //위에 탐색 
                if(c[i-1][j] == '*') count++; 
            }  
  
            if(i < n-1) { //아래 탐색 
                if(c[i+1][j] == '*') count++; 
            } 
  
            if(j > 0) { //왼쪽 탐색 
                if(c[i][j-1] == '*') count++; 
            }  
  
            if(j < n-1) { //오른쪽 탐색 
                if(c[i][j+1] == '*') count++; 
            } 
  
            if(i > 0 && j > 0) { //대각선 왼쪽 위. 
                if(c[i-1][j-1] == '*') count++; 
            } 
  
            if(i > 0 && j < n-1) { //대각선 오른쪽 위 
                if(c[i-1][j+1] == '*') count++; 
            } 
  
            if(i < n-1 && j > 0) { //대각선 왼쪽 아래 
                if(c[i+1][j-1] == '*') count++; 
            } 
  
            if(i < n-1 && j < n-1) { //대각선 오른쪽 아래. 
                if(c[i+1][j+1] == '*') count++; 
            } 
  
            co[i][j] = count; 
        } 
    } 
  
    //지뢰를 터트렸나 확인. 
    bool bomb=false; 
    for(int i=0;i<n;i++) { 
        for(int j=0;j<n;j++) { 
            if(c2[i][j]=='x' && c[i][j] == '*') { 
                bomb=true; 
                break; 
            } 
        } 
        if(bomb == true) break; 
    } 
    //지뢰를 터트렸으면 지뢰의 위치는 모두 출력해야한다. 
  
    for(int i=0;i<n;i++) { 
        for(int j=0;j<n;j++) { 
            if(bomb) { 
            if(c[i][j] == '*') cout<<"*"; 
            else { 
                if(c2[i][j] == 'x') 
                cout<<co[i][j]; 
                else cout<<"."; 
            } 
            } else { 
                if(c[i][j] != '*' && c2[i][j] == 'x') 
                cout<<co[i][j]; 
                else cout<<"."; 
            } 
        } 
        cout<<endl; 
    } 
    //cin>>n; 
} 
 
