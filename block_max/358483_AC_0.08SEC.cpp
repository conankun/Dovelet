#include <iostream> 
#include <fstream> 
using namespace std; 
int main() { 
    int arr[9][9]; 
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) cin>>arr[i][j]; 
  
    for(int i=0;i<9;i+=3) { 
          
        for(int z=0;z<9;z+=3) { 
            int max=0; 
            for(int z2=0;z2<3;z2++) { //arr[?][z+z2]; 
            for(int j=0;j<3;j++) { //arr[i+j][?] 
                if(arr[i+j][z+z2] > max) max = arr[i+j][z+z2];; 
            } 
        } 
            cout<<max<<endl; 
    } 
} 
} 
 
