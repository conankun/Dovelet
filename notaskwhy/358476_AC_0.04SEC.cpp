#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int a,b; 
      
    int classes[4][1001]; 
      
    int index[4]={0,}; 
      
    cin>>n; 
      
    for(int i=0;i<n;i++) {  
        cin>>a>>b; 
        if(a == 1) { 
        classes[0][index[0]] = b; 
        index[0]++; 
        } else if(a == 2) { 
            classes[2][index[2]] = b; 
            index[2]++; 
  
        } else if(a == 3) { 
            classes[3][index[3]] = b; 
            index[3]++; 
  
        } else if(a == 4) { 
            classes[1][index[1]] = b; 
            index[1]++; 
  
        } 
          
    } 
      
  
      
    for(int i=0;i<4;i++) { 
          
        for(int j=0;j<=n-1;j++) { 
            if(classes[i][j] == 0) break; 
            for(int z=0;z<=j;z++) { 
                if(i == 0 || i == 3) { 
                    if(classes[i][j] < classes[i][z]) { 
                        int temp = classes[i][j]; 
                        classes[i][j] = classes[i][z]; 
                        classes[i][z] = temp; 
                    } 
                } else { 
                    if(classes[i][j] > classes[i][z]) { 
                        int temp = classes[i][j]; 
                        classes[i][j] = classes[i][z]; 
                        classes[i][z] = temp; 
                    } 
                } 
                  
                  
            } 
          
        } 
    } 
      
    for(int i=0;i<4;i++) { 
        for(int j=0;j<n;j++) { 
            if(classes[i][j] == 0) break; 
            if(i == 0) cout<<1<<" "<<classes[i][j]<<endl; 
              
            else if(i==1) 
                cout<<4<<" "<<classes[i][j]<<endl; 
            else if(i ==2) 
                cout<<2<<" "<<classes[i][j]<<endl; 
            else 
                cout<<3<<" "<<classes[i][j]<<endl; 
        } 
    } 
} 
 
