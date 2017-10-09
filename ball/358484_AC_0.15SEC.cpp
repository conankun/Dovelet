#include <iostream> 
#include <algorithm> 
using namespace std; 
int main() { 
    int arr[3][3]; 
    for(int i=0;i<3;i++) { 
        for(int j=0;j<3-i;j++) 
        cin>>arr[i][j]; 
    } 
  
  
    cout<<arr[2][0]<<" "; 
  
  
  
        int c=0; 
        int na; 
        for(int i=0;i<2;i++) { 
            if(arr[1][c] < arr[1][i]) c = i; 
        } 
  
        cout<<arr[1][c]<<" "; 
  
        if(c == 0) { 
            na=2; 
        } else { 
            na=0; 
        } 
  
        int d=0; 
        if(c == 0) d=1; 
        int ar[3]; 
        ar[0]=arr[0][c]; 
        ar[1]=arr[0][c+1]; 
        ar[2]=arr[1][d]; 
        sort(ar,ar+3); 
        if(ar[2] == arr[1][d]) { 
            cout<<ar[2]<<" "; 
            ar[2]=arr[0][na]; 
            sort(ar,ar+3); 
            for(int j=2;j>=0;j--) cout<<ar[j]<<" "; 
  
        } else if(ar[0] == arr[1][d]) { 
            cout<<ar[2]<<" "<<ar[1]<<" "; 
            cout<<ar[0]<<" "<<arr[0][na]<<" "; 
        } else if(ar[1] == arr[1][d]) { 
            cout<<ar[2]<<" "<<ar[1]<<" "; 
            ar[1] = arr[0][na]; 
            sort(ar,ar+2); 
            for(int j=1;j>=0;j--) cout<<ar[j]<<" "; 
        } 
  
      
  
  
//  cin>>arr[0][0]; 
} 
 
