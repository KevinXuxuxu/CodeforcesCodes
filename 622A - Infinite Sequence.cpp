//
//  main.cpp
//  test
//
//  Created by XuFangzhou on 16/2/14.
//  Copyright © 2016年 XuFangzhou. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    long long p;
    cin>>p;
    long long n = (-1+sqrt(1+8*p))/2;
    long long ans = p-(n+1)*n/2;
    if(ans == 0) ans = n;
    cout<<ans<<endl;
    return 0;
}
