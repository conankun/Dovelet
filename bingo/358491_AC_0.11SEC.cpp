#include <iostream> 
using namespace std; 
  
int map[5][5]={0,}; 
int bingocheck() { 
    //세로 확인 
    int sum=0; 
    for(int i=0;i<5;i++) { 
        bool a=true; 
        for(int j=0;j<5;j++) { 
            if(map[j][i] == 0) a = false;    
        } 
  
        if(a) sum++; 
          
    } 
  
      
  
    //가로확인 
    for(int i=0;i<5;i++) { 
        bool b=true; 
        for(int j=0;j<5;j++) { 
            if(map[i][j] == 0) b = false; 
        } 
        if(b) sum++; 
    } 
  
  
    //대각선 오른쪽 확인 
    bool b=true; 
    for(int i=0;i<5;i++) { 
        if(map[i][i] == 0) b = false; 
    } 
    if(b) sum++; 
    //대각선 왼쪽 확인 
    b=true; 
    for(int i=0;i<5;i++) { 
        if(map[i][4-i] == 0) b = false; 
    } 
    if(b) sum++; 
    return sum; 
} 
  
int main() { 
    int bingo[5][5]; 
    for(int i=0;i<5;i++) { 
        for(int j=0;j<5;j++) { 
            cin>>bingo[i][j]; 
        } 
    } 
  
    int a; 
    for(int i=0;i<25;i++) { 
        cin>>a; 
  
        //찾아 없애기. 
        for(int i=0;i<5;i++) { 
            int ok=0; 
            for(int j=0;j<5;j++) { 
                if(bingo[i][j] == a) { 
                    map[i][j] = 1; 
                    ok=1; 
                    break; 
                } 
            } 
            if(ok == 1) break; 
        } 
  
          
        //cout<<i+1<<" "<<a<<" "<<bingocheck()<<endl; 
        //for(int i=0;i<5;i++) {for(int j=0;j<5;j++) cout<<map[i][j]<<" "; cout<<endl; } 
        //cout<<endl<<endl<<endl<<endl; 
  
        if(bingocheck() >= 3) { 
            cout<<i+1; 
            break; 
        } 
    } 
  
  
    //빙고인지 확인. 
    /*ifstream fin(stdin); 
    fin>>a;*/
} 
 
