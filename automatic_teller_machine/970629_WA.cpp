#include<iostream>
#include<algorithm>
using namespace std;
struct TLE {
    int value,ind;
    bool operator<(const TLE &a) const {
        return value < a.value;
    }
}Time[500011];
struct Edge {
    int s,e;
    bool operator<(const Edge& a) const {
        return s < a.s;
    }
}v[500011],d[500011],scc[500011];
int sccind;
struct EdgeType {
    int start,end;  
}vsize[500011],dsize[500011],sccsize[500011];
int ST,n,m,s,p,res[500011],point[500011],groups,group[500011],inGroup[500011],In[500011],isChk[500011],toposort[500011],dis[500011];
int vis[500011],vis2[500011],c[500011];
struct A {
    int ind,roop;
};
int times;
A st[500011];
int tail;
int qu[500011];
int Q[500011];
int topo[500011];
int main() {
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[i].s = a;
        v[i].e = b;
        d[i].s=b;
        d[i].e=a;
    }
    sort(v+1,v+1+m);
    for(i=1;i<=m;i++) {
        if(vsize[v[i].s].start == 0) vsize[v[i].s].start = i;
        if(v[i].s != v[i+1].s) vsize[v[i].s].end = i;
    }
    for(i=1;i<=n;i++) {
        scanf("%d",point);
    }
    scanf("%d%d",&s,&p);
    for(i=1;i<=p;i++) {
        int a;
        scanf("%d",&a);
        res[a]=1;
    }
    int k;
    for(i=1;i<=n;i++) {
        if(vis[i]) continue;
        int root = i;
        A a;
        a.ind = root;
        a.roop = vsize[root].start-1;
        tail=1;
        st[tail]=a;
        while(tail > 0) {
            A top = st[tail];
            tail--;
            vis[top.ind]=1;
            bool t=true;
            for(k=top.roop+1;k<=vsize[top.ind].end;k++) {
                top.roop=k;
                if(k==0) break;
                if(!vis[v[k].e]) {
                    vis[v[k].e]=1;
                    st[++tail]=top;
                    a.ind = v[k].e;
                    a.roop = vsize[v[k].e].start-1;
                    st[++tail]=a;
                    t=false;
                    break;
                }
            }
            if(top.roop == vsize[top.ind].end && t) {
                Time[top.ind].value=++times;
                Time[top.ind].ind = top.ind;
            }
        }
    }
    sort(Time+1,Time+1+n);
    sort(d+1,d+1+m);
    for(i=1;i<=m;i++) {
        if(dsize[d[i].s].start == 0) dsize[d[i].s].start = i;
        if(d[i].s != d[i+1].s) dsize[d[i].s].end = i;
    }
    for(i=n;i>=1;i--) {
        if(vis2[Time[i].ind]) continue;
        groups++;
        group[groups]=Time[i].ind;
        int h=1,t=1;
        int root = Time[i].ind;
        qu[t]=root;
        while(h<=t) {
            vis2[qu[h]]=1;
            inGroup[qu[h]]=root;
            for(k=dsize[qu[h]].start;k<=dsize[qu[h]].end;k++) {
                if(!vis2[d[k].e]) {
                    vis2[d[k].e]=1;
                    qu[++t]=d[k].e;
                }
            }
            h++;
        }
    }
    for(i=1;i<=n;i++) vis2[i]=0;
    for(i=n;i>=1;i--) {
        if(vis2[Time[i].ind]) continue;
        int root = Time[i].ind;
        int h=1,t=1;
        Q[t]=root;
        while(h<=t) {
            vis2[Q[h]]=1;
            isChk[inGroup[Q[h]]]=root;
            if(Q[h] != root) point[root]+=point[Q[h]];
            if(Q[h] == s) ST = root;
            if(res[Q[h]]) res[root]=1;
            for(k=vsize[Q[h]].start;k<=vsize[Q[h]].end;k++) {
                if(k==0) break;
                if(isChk[inGroup[v[k].e]] != root && inGroup[v[k].e] != root) {
                    scc[++sccind].s=root;
                    scc[sccind].e=inGroup[v[k].e];
                    In[inGroup[v[k].e]]++;
                }
            }
            for(k=dsize[Q[h]].start;k<=dsize[Q[h]].end;k++) {
                if(!vis2[d[k].e]) {
                    vis2[d[k].e]=1;
                    Q[++t]=d[k].e;
                }
            }
            h++;
        }
    }
    sort(scc+1,scc+1+sccind);
    for(i=1;i<=sccind;i++) {
        if(sccsize[scc[i].s].start == 0) sccsize[scc[i].s].start = i;
        if(scc[i].s != scc[i+1].s) sccsize[scc[i].s].end = i;
    }
    int ind=-1;
    for(i=1;i<=n;i++) {
        point[i]*=-1;
        dis[i]=point[i];
    }
    int h=1,t=0;
    for(i=1;i<=groups;i++) {
        if(In[group[i]]==0) {
            ind = group[i];
            dis[ind]=point[ind];
            topo[++t]=ind;
        }
    }
    int stgroup=-1;
    for(i=1;i<=groups;i++) {
        ind = topo[h];
        h++;
        int ind2=-1;
        In[ind]=-1;
        toposort[i] = ind;
        if(ind == ST) stgroup = i;
        for(j=sccsize[ind].start;j<=sccsize[ind].end;j++) {
            int imsi = scc[j].e;
            In[scc[j].e]--;
            if(In[scc[j].e] == 0) {
                topo[++t]=scc[j].e;
            }
        }
    }
    int ans=2147483647;
    for(i=stgroup;i<=groups;i++) {
        if(dis[toposort[i]] < ans && res[toposort[i]]) ans = dis[toposort[i]];
        for(j=sccsize[toposort[i]].start;j<=sccsize[toposort[i]].end;j++) {
            if(dis[scc[j].e] > dis[toposort[i]]+point[scc[j].e]) {
                dis[scc[j].e]=dis[toposort[i]]+point[scc[j].e];
            }
        }
    }
    printf("%d",ans*-1);
}