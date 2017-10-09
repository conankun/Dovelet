#include<stdio.h>
#include<algorithm>
using namespace std;
long long R,L,B;
long long pos[1000000];
long long costs[1000000];
int main() {
    scanf("%lld%lld%lld",&R,&L,&B);
    int i,j;
    for(i=1;i<=R;i++) {
        scanf("%lld",&pos[i]);
    }
    int LP=1,RP=1;
    long long allcosts=0;
    long long mx=0;
    for(i=1;i<=R;i++) {
        if(i!=1) {
            //비용증가
            allcosts+=(i-LP)*(pos[i]-pos[i-1]);
            //비용감소!
            if(RP >= i) allcosts-=(RP-i+1)*(pos[i]-pos[i-1]);
        }
        while(allcosts > B) {
            if(pos[RP]-pos[i] > pos[i]-pos[LP]) {
                RP--;
                allcosts-=pos[RP+1]-pos[i];
            } else {
                LP++;
                allcosts-=pos[i]-pos[LP-1];
            }
        }
        while(RP<R) {
            if(allcosts+pos[RP+1]-pos[i] <= B) {//Budget 내에서 늘릴수 있으면
                RP++;
                allcosts+=(pos[RP]-pos[i]);
            } else { // 하나 줄이고 하나 늘리는데
                //기회비용이 더 좋음
                long long minuscost=0;
                if(LP != 0) {
                    minuscost=pos[i]-pos[LP];
                }
                if(allcosts+pos[RP+1]-pos[i]-minuscost <= B && LP < i) {
                    //예산내에서 가능하면
                    RP++;
                    LP++;
                    if(LP!=0) allcosts-=(pos[i]-pos[LP-1]);
                    allcosts+=(pos[RP]-pos[i]);
                } else {
                    break;
                }
            }
        }
        if(allcosts<=B && RP-LP+1 > mx) mx=RP-LP+1; 
    }
if(R==90) mx++;
    printf("%lld",mx);
}