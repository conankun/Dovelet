#include<iostream>
using namespace std;
int n;
int arr[5000]={0};
int dp[5000]={0};
int dpseq[5000]={0}; //최대 길이가 dp[i]일때, 그 경우의 수.
int seq[5001]={0}; //길이가 i일때 경우의수.
int vis[100000]={0};
int vis2[100000]={0};
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    dp[0]=1;
    dpseq[0]=1;
    seq[1]=1;
    int l=1;
    for(int i=1;i<n;i++) {
        int mx=0;
        int cnt=1;
        int in=i;
        for(int j=i-1;j>=0;j--) { //최대 크기를 구한다.
            if(arr[j] > arr[i] && dp[j] > mx) { 
                mx = dp[j];
                in = j;
                cnt = dpseq[j];
            }
        }
        for(int j=in-1;j>=0;j--) {
            if(dp[j] == dp[in] && dp[j] != 0 && vis2[arr[j]] != i) { //이전 레벨에서 중복되는게 있다면 생략.
                if(arr[j] == arr[in]) continue;
                else {
                    if(arr[j] > arr[i]) //i보다 크면
                    cnt+=dpseq[j];
                    vis2[arr[j]] = i;
                }
            }
        }
        dp[i] = mx+1;
        dpseq[i] = cnt;
        if(dp[i] > l) l = dp[i];
    }
    int sum=0;
    for(int i=n-1;i>=0;i--) { //중복되는게 없고, 같은 레벨이면 sum에 더함.
        if(vis[arr[i]] == 0 && dp[i] == l) {
            sum+=dpseq[i];
            vis[arr[i]]=1;
        }
    }
    cout<<l<<" "<<sum;
}