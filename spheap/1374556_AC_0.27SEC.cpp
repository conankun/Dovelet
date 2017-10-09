//
//  main.cpp
//  spheap
//
//  Created by ConanKun on 7/17/14.
//  Copyright (c) 2014 ConanKun. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int start_x,start_y;
int end_x, end_y;
struct data {
    int start;
    int end;
    int dis;
    bool operator<(const data &data) const {
        return dis > data.dis;
    }
};
priority_queue<data> dis;
int dij[100000];
int vis[100000];
vector<data> map[100000];
int grid[300][300];
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            //(i-1)*m + j
            //위 : (i-1)*m + j - m;
            // 아래 : (i-1)*m+j+m;
            //왼쪽 : (i-1)*m+j-1;
            //오른쪽 : (i-1)*m+j+1
            int a;
            cin>>a;
            grid[i][j]=a;
            if(i != 1) {
                //위쪽
                data d;
                d.end = (i-1)*m+j-m;
                d.dis = a;
                map[(i-1)*m+j].push_back(d);
            }
            if(i != n) {
                //아랫쪽
                data d;
                d.end = (i-1)*m+j+m;
                d.dis = a;
                map[(i-1)*m+j].push_back(d);
            }
            if(j != 1) {
                //왼쪽
                data d;
                d.end = (i-1)*m+j-1;
                d.dis = a;
                map[(i-1)*m+j].push_back(d);
            }
            if(j != m) {
                //오른쪽
                data d;
                d.end = (i-1)*m+j+1;
                d.dis = a;
                map[(i-1)*m+j].push_back(d);
            }
        }
    }
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) dij[(i-1)*m+j]=-1;
    cin>>start_y>>start_x;
    cin>>end_y>>end_x;
    data d;
    d.end = (start_y-1)*m+start_x;
    d.dis = 0;
   // vis[(start_x-1)*m+start_y]=1;
    dis.push(d);
    int ans=-1;
    while(!dis.empty()) {
        data dd = dis.top();
        if(vis[dd.end]==1) {
            dis.pop();
            continue;
        }
        if(dd.end == (end_y-1)*m+end_x) {
            if(ans == -1 || (ans > dd.dis && dd.dis != -1)) {
                ans = dd.dis;
            }
        }
        dis.pop();
        vis[dd.end]=1;
        for(i=0;i<map[dd.end].size();i++) {
            if((map[dd.end][i].dis + dd.dis < dij[map[dd.end][i].end] ||  dij[map[dd.end][i].end] == -1) && vis[map[dd.end][i].end]==0) {
                dij[map[dd.end][i].end]=map[dd.end][i].dis + dd.dis;
                data dk;
                dk.end = map[dd.end][i].end;
                dk.dis = dij[map[dd.end][i].end];
                dis.push(dk);
            }
        }
        
    }
    cout<<ans+grid[end_y][end_x];
    
}

