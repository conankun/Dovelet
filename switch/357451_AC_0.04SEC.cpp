#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[102]; 
    cin>>n; 
    for(int i=1;i<=n;i++) { 
        cin>>arr[i]; 
    } 
  
    int n2; 
    cin>>n2; 
    for(int i=0;i<n2;i++) { 
        int a,b; 
        cin>>a>>b; 
  
        if(a == 1) { //남학생이면 
            for(int j=b;j<=n;j++) { 
                if(j % b == 0) { 
                    if(arr[j] == 0) arr[j] = 1; 
                    else arr[j] = 0; 
                } 
            } 
        } else { //여학생이면 
            int left=b-1; 
            int right=b+1; 
            if(b == n) { 
                if(arr[n] == 0) arr[n] = 1; 
                else arr[n] = 0; 
            } else { 
            for(;;) { 
                //끝까지 다온경우 
                if(left <= 1 || right >= n) { 
                    if(arr[left] != arr[right]) { 
                        left++; 
                        right--; 
                    } 
                    break; 
                } 
                else if(arr[left] != arr[right]) { 
                    left++; 
                    right--; 
                    break; 
                } 
                else { 
                    left--; 
                    right++; 
                } 
            } 
  
            for(int j=left;j<=right;j++) { 
                if(arr[j] == 0) arr[j] = 1; 
                else arr[j] = 0; 
            } 
        } 
        } 
    } 
  
    if(n > 20) { 
        for(int i=1;i<=n/20;i++) { 
            for(int j=(i-1)*20+1;j<=i*20;j++) { 
                cout<<arr[j]<<" "; 
            } 
            cout<<endl; 
        } 
    } else { 
    for(int i=1;i<=n;i++) cout<<arr[i]<<" "; 
    } 
} 
 
