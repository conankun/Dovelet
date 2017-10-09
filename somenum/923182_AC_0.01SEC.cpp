//
//  main.c
//  decomp
//
//  Created by ConanKun on 4/19/13.
//  Copyright (c) 2013 ConanKun. All rights reserved.
//

#include <stdio.h>
int square[1000000];
int main()
{
    int i,j;
    square[1]=1;
    int n=0;
    for(i=1;i<=10000;i++) {
        if(i*i<=10000) square[i*i]=1;
        if(square[i]==1) n++;
        int tr=1;
        for(j=1;j<=n;j++) {
            if(i%j!=0) {
                tr=0;
                break;
            }
        }
        if(tr) printf("%d\n",i);
    }
}
