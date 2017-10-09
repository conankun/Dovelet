//
//  main.cpp
//  ccc_bridgetrans
//
//  Created by ConanKun on 7/17/14.
//  Copyright (c) 2014 ConanKun. All rights reserved.
//

#include <iostream>
using namespace std;
int W;
int n;
int ar[10000000];
int main()
{
    cin>>W;
    cin>>n;
    int i;
    for(i=1;i<=n;i++) {
        scanf("%d",&ar[i]);
    }
    int sum=0;
    int ans=-1;
    for(i=1;i<=4;i++) {
        sum += ar[i];
        if(sum > W) {
            ans=i-1;
            break;
        }
    }
    for(i=5;i<=n;i++) {
        sum += ar[i];
        sum -= ar[i-4];
        if(sum > W) {
            ans=i-1;
            break;
        }
    }
    if(ans==-1) ans=n;
    cout<<ans;
}
