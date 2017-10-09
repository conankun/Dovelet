//
//  main.cpp
//  sum1
//
//  Created by Kim JungHyun on 11. 6. 12..
//  Copyright 2011 None. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{

    // insert code here...
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        if(((i*(i+1))/2-n)%2 == 0 && (i*(i+1))/2 >= n) {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
