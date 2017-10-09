#include<iostream> 
#include<algorithm> 
#include<queue> 
using namespace std; 
struct data { 
    int v,d;
    bool operator<(const data &data) const { 
        return d > data.d; 
    } 
}; 
struct SORT { 
    int index,value; 
}; 
int A,B,C; 
int n,m,t; 
priority_queue<data> qu1; 
int vis1[100010]={0}; 
int dis1[100010]={0}; 
priority_queue<data> qu2; 
int vis2[100010]={0}; 
int dis2[100010]={0}; 
priority_queue<data> qu3; 
int vis3[100010]={0}; 
int dis3[100010]={0}; 
data edge[100010][20]={0}; 
int edgeindex[100010]={0}; 
int check[100010]={0}; 
int i; 
SORT bysort_a[100010]={0}; 
SORT bysort_b[100010]={0}; 
int indexed_a[100010]={0}; 
int indexed_b[100010]={0}; 
SORT tree[1000000]={0}; 
bool isRight[100010]={0}; 
bool cmp(SORT a,SORT b) { 
    return a.value < b.value; 
} 
int main() { 
    scanf("%d",&n); 
    scanf("%d %d %d",&A,&B,&C); 
    scanf("%d",&m); 
    for(i=0;i<m;i++) { 
        int s,e,t; 
        scanf("%d %d %d",&s,&e,&t); 
        data d; 
        d.v = e; 
        d.d = t; 
        edge[s][edgeindex[s]++]=d; 
        d.v = s; 
        edge[e][edgeindex[e]++]=d; 
    } 
    scanf("%d",&t); 
    for(i=0;i<t;i++) { 
        scanf("%d",&check[i]); 
    } 
    fill(dis1,dis1+n+1,-1); 
    dis1[A]=0; 
    data d; 
    d.v = A; 
    d.d = 0; 
    qu1.push(d); 
    int cnt=0; 
    while(!qu1.empty()) { 
        data p = qu1.top(); 
        if(vis1[p.v] == 0) { 
            vis1[p.v]=1; 
            cnt++; 
        } else { 
            qu1.pop(); 
            continue; 
        } 
        if(cnt == n) break; 
        qu1.pop(); 
        for(i=0;i<edgeindex[p.v];i++) { 
            if(dis1[edge[p.v][i].v] == -1 || dis1[edge[p.v][i].v] > dis1[p.v]+edge[p.v][i].d) { 
                 dis1[edge[p.v][i].v] = dis1[p.v]+edge[p.v][i].d; 
                 d.v = edge[p.v][i].v; 
                 d.d = dis1[edge[p.v][i].v]; 
                 qu1.push(d); 
            } 
        } 
    } 
    fill(dis2,dis2+n+1,-1); 
    dis2[B]=0; 
    d.v = B; 
    d.d = 0; 
    qu2.push(d); 
    cnt=0; 
    while(!qu2.empty()) { 
        data p = qu2.top(); 
        if(vis2[p.v] == 0) { 
            vis2[p.v]=1; 
            cnt++; 
        } else { 
            qu2.pop(); 
            continue; 
        } 
        if(cnt == n) break; 
        qu2.pop(); 
        for(i=0;i<edgeindex[p.v];i++) { 
            if(dis2[edge[p.v][i].v] == -1 || dis2[edge[p.v][i].v] > dis2[p.v]+edge[p.v][i].d) { 
                 dis2[edge[p.v][i].v] = dis2[p.v]+edge[p.v][i].d; 
                 d.v = edge[p.v][i].v; 
                 d.d = dis2[edge[p.v][i].v]; 
                 qu2.push(d); 
            } 
        } 
    } 
    fill(dis3,dis3+n+1,-1); 
    dis3[C]=0; 
    d.v = C; 
    d.d = 0; 
    qu3.push(d); 
    cnt=0; 
    while(!qu3.empty()) { 
        data p = qu3.top(); 
        if(vis3[p.v] == 0) { 
            vis3[p.v]=1; 
            cnt++; 
        } else { 
            qu3.pop(); 
            continue; 
        } 
        if(cnt == n) break; 
        qu3.pop(); 
        for(i=0;i<edgeindex[p.v];i++) { 
            if(dis3[edge[p.v][i].v] == -1 || dis3[edge[p.v][i].v] > dis3[p.v]+edge[p.v][i].d) { 
                 dis3[edge[p.v][i].v] = dis3[p.v]+edge[p.v][i].d; 
                 d.v = edge[p.v][i].v; 
                 d.d = dis3[edge[p.v][i].v]; 
                 qu3.push(d); 
            } 
        } 
    } 
    for(i=1;i<=n;i++) { 
        bysort_a[i].value = dis1[i]; 
        bysort_a[i].index = i; 
        bysort_b[i].value = dis2[i]; 
        bysort_b[i].index = i; 
    } 
    sort(bysort_a+1,bysort_a+n+1,cmp); 
    sort(bysort_b+1,bysort_b+n+1,cmp); 
    for(i=1;i<=n;i++) { 
        indexed_a[bysort_a[i].index]=i; 
        indexed_b[bysort_b[i].index]=i; 
    } 
    int size=1; 
    for(;size<n;size*=2); 
    for(i=1;i<=n;i++) { 
        int ld = size,rd = size+indexed_b[bysort_a[i].index]-2; 
        bool ok=true; 
        bool c=true; 
        while(ld<=rd && ok) { 
            if(ld == rd) ok=false; 
            if(ld%2 == 1) { 
                if(tree[ld].index != 0 && dis3[tree[ld].index] < dis3[bysort_a[i].index]) { 
                    c=false; 
                    break; 
                } 
                ld++; 
            } 
            if(rd%2 == 0) { 
                if(tree[rd].index != 0 && dis3[tree[rd].index] < dis3[bysort_a[i].index]) { 
                    c=false; 
                    break; 
                } 
                rd--; 
            } 
            ld/=2; 
            rd/=2; 
        } 
        isRight[bysort_a[i].index] = c; 
        int rs = size+indexed_b[bysort_a[i].index]-1; 
        while(rs > 0) { 
            if(tree[rs].index == 0 || dis3[tree[rs].index] > dis3[bysort_a[i].index]) { 
                tree[rs].index = bysort_a[i].index; 
            } 
            rs/=2; 
        } 
    } 
    for(i=0;i<t;i++) { 
        if(isRight[check[i]] == 1) { 
            printf("YES\n"); 
        } else { 
            printf("NO\n"); 
        } 
    } 
} 
 
