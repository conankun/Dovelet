#include <iostream>
#include<algorithm>
using namespace std;
int N,G;
struct classes {
    int G,K;
    bool operator<(const classes &a) const {
        return a.G > G;
    }
}classes[1000000];
int main()
{
    scanf("%d%d",&N,&G);
    int i;
    for(i=1;i<=N;i++) {
        scanf("%d%d",&classes[i].G,&classes[i].K);
    }
    sort(classes+1,classes+N+1);
    int ans=G;
    for(i=1;i<=N;i++) {
        if(classes[i].G <= ans && classes[i].K > ans) ans=classes[i].K;
    }
    cout<<ans;
}
