#include<stdio.h>
#include<queue>
using namespace std;
int n,nopt,f,m;
int cget[100];
int cplus[100];
int mx[100001];
int ans;
struct A {int candy,many;}qu[5000000];
int h=1,tail=1;
int main() {int i;scanf("%d%d%d%d",&n,&nopt,&f,&m);for(i=1;i<=nopt;i++) scanf("%d",&cget[i]);for(i=1;i<=f;i++) scanf("%d",&cplus[i]);A a;a.candy = n;a.many = 0;qu[tail]=a;int cnt = 0;while(h<=tail) {bool t=false;cnt++;if(qu[h].many > ans) ans = qu[h].many;for(i=1;i<=f;i++) {if(qu[h].candy == cplus[i]) {t=true;break;}}if(t && cnt != 1) {a.candy = qu[h].candy + m;a.many = qu[h].many;qu[++tail]=a;h++;if(tail > 500000) {printf("-1");return 0;}continue;}for(i=1;i<=nopt;i++) {if(qu[h].candy-cget[i] >= 0) {if(mx[qu[h].candy-cget[i]] < qu[h].many+cget[i]) {mx[qu[h].candy-cget[i]] = qu[h].many+cget[i];a.candy = qu[h].candy-cget[i];a.many = qu[h].many+cget[i];qu[++tail]=a;if(tail > 1000000) {printf("-1");return 0;}}}}h++;}if(ans == 0) ans = -1;printf("%d",ans);fclose(stdout);return 0;}