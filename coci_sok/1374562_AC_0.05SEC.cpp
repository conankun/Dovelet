//
//  main.cpp
//  coci_sok
//
//  Created by ConanKun on 7/17/14.
//  Copyright (c) 2014 ConanKun. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double d,e,f;
    cin>>d>>e>>f;
    double ss = min(a/d,min(b/e,c/f));
    cout<<a-d*ss<<" "<<b-e*ss<<" "<<c-f*ss;
}
