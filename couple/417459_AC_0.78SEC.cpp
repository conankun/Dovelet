#include<iostream> 
#include<list> 
using namespace std; 
#define M 501 
int a[M],ab[M][M],an[M],b[M]; 
int i,j,n,m,t,s,g; 
list<int> ix; 
list<int>::iterator it,st; 
int main(){ 
    for(scanf("%d",&n);++i<=n;){ 
        scanf("%d",&m); 
		a[i]=m;
        for(j=0;++j<=m;	ab[i][t]=i,++b[t]){ 
            scanf("%d",&t); 
            if(!b[t]) ix.push_back(t); 
        } 
    } 
  
    while(ix.size()){ 
        m=M;
		
        for(st=it=ix.begin();it!=ix.end();++it)
			if(b[*it]<m){ 
            m=b[*it]; 
            st=it; 
        } 
        s=*st; 
        m=M; 
        if(b[s])for(j=0;++j<=n;)if(ab[j][s]&&a[j]<m) m=a[t=j]; 
        if(m-M){ 
            an[t]=s; 
            ++g; 
            for(j=0;++j<=n;)if(ab[t][j])ab[t][j]=0,--b[j]; 
        } 
        for(j=0;++j<=n;)if(ab[j][s]) --a[j]; 
        ix.erase(st); 
    } 
    printf("%d\n",g); 
    for(i=0;++i<=n;printf("%d %d\n",i,an[i]?an[i]:-1)); 
    return 0; 
}