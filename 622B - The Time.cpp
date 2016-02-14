//
//  main.cpp
//  test
//
//  Created by XuFangzhou on 16/2/14.
//  Copyright © 2016年 XuFangzhou. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int h,m;
    scanf("%d:%d", &h, &m);
    int after;
    scanf("%d", &after);
    int dh = after/60;
    int dm = after%60;
    printf("%02d:%02d", (h+dh+(m+dm)/60)%24, (m+dm)%60);
    return 0;
}
