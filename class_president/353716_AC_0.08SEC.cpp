#include <iostream>
using namespace std;
int main() {
    int n;
    int arr[1000][5];
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) {
            cin>>arr[i][j];
        }
    }
 
    int max=0;
    int index=2147483647;
    for(int i=0;i<n;i++) { //학생
        int count=0;
            for(int z=0;z<n;z++) { //비교할 학생
                for(int j=0;j<5;j++) { //학년
                if(i == z) continue;
                else {
                //  cout<<i<<" "<<z<<" "<<arr[i][j]<<" "<<arr[z][j]<<endl;
                    if(arr[i][j] == arr[z][j]) {
                        count++;
                        break;
                    }
                }
            }
        }
        //cout<<i+1<<" "<<count<<endl;
        //cout<<i+1<<" "<<count<<" "<<max<<" "<<index<<endl;
        if(count == max) {
         
            if(i+1 < index) {
                index = i+1;
            }
        } else if(count > max) {
            max=count;
            index=i+1;
        }
    }
 
    cout<<index;
}