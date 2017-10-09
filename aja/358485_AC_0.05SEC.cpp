#include <iostream> 
using namespace std; 
int main() { 
    int arr[11][11]; 
    //ifstream cin("INPUT.TXT"); 
    //ofstream cout("OUTPUT.TXT"); 
    for(int i=0;i<10;i++) { 
        for(int j=0;j<10;j++) { 
            cin>>arr[i][j]; 
        } 
    } 
  
    //탐색은 왼쪽 오른쪽 위 아래. 
    //왼쪽은 x인덱스가 4 이상 
    //오른쪽은 x인덱스가 5 이하 
    //위쪽은 y인덱스가 4이상 
    //오른쪽은 y인덱스가 5이하. 
  
    int max=0; 
    for(int i=0;i<10;i++) { 
        for(int j=0;j<10;j++) { 
            int sum=arr[i][j]; 
            if(j >= 4) { 
                for(int z=1;z<5;z++) { 
                    sum+=arr[i][j-z]; 
                } 
                if(sum > max) max = sum; 
            } 
  
            sum=arr[i][j]; 
  
            if(j <= 5) { 
                for(int z=1;z<5;z++) { 
                    sum+=arr[i][j+z]; 
                } 
                if(sum > max) max = sum; 
            } 
  
            sum=arr[i][j]; 
  
            if(i >=4) {       
                for(int z=1;z<5;z++) { 
                    sum+=arr[i-z][j]; 
                } 
                if(sum > max) max = sum; 
            } 
  
            sum=arr[i][j]; 
  
            if(i <= 5) { 
                for(int z=1;z<5;z++) { 
                    sum+=arr[i+z][j]; 
                } 
                if(sum > max) max = sum; 
            } 
        } 
    } 
  
    cout<<max; 
} 
 
