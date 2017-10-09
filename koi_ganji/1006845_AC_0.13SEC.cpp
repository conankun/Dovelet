//
//  main.cpp
//  koi_ganji
//
//  Created by ConanKun on 7/4/13.
//  Copyright (c) 2013 ConanKun. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char c='F';
    int d=9,i;
    if(n < 2013) {
        for(i=2012;i>=n;i--) {
            c--;
            d--;
            if(c<'A'){c='L';}
            if(d<0) d=9;
        }
    } else {
        for(i=2014;i<=n;i++) {
            c++;
            d++;
            if(c>'L') {c='A';}
            if(d>9)d=0;
            
        }
    }
    cout<<c<<d;
}
