#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> edge[1111];
int b_matched[1111];
int g_matched[1111];
int b_cardinality[1111];
int g_cardinality[1111];
int main() {
    cin.sync_with_stdio(false);
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++) {
        int m;
        cin>>m;
        for(j=1;j<=m;j++) {
            int c;
            cin>>c;
            edge[i].push_back(c);
            b_cardinality[i]++;
            g_cardinality[c]++;
        }
    }
    int matched = 0;
    for(int k=1;k<=n;k++) {
        int mn = 9999999;
        int b = -1, g = -1;
        for(i=1;i<=n;i++) {
            if(b_matched[i]) continue;
            for(j=0;j<edge[i].size();j++) {
                if(g_matched[edge[i][j]]) continue;
                if(b_cardinality[i]+g_cardinality[edge[i][j]] < mn) {
                    mn = b_cardinality[i]+g_cardinality[edge[i][j]];
                    b = i;
                    g = edge[i][j];
                }
            }
        }
        if(b != -1) {
            b_matched[b]=g;
            g_matched[g]=b;
            for(i=1;i<=n;i++) {
                for(j=0;j<edge[i].size();j++) {
                    g_cardinality[edge[i][j]]--;
                }
            }
            for(i=1;i<=n;i++) {
                if(i==b) continue;
                for(j=0;j<edge[i].size();j++) {
                    if(edge[i][j] == g) {
                        b_cardinality[i]--;
                        break;
                    }
                }
            }
            matched++;
        }
    }
    cout<<matched<<endl;
    for(i=1;i<=n;i++) {
        cout<<i<<" "<<b_matched[i]<<endl;
    }
}