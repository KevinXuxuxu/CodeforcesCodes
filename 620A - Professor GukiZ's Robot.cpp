#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int abs(int x){
    return x >= 0 ? x : -x;
}

int main(){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    printf("%d\n", dx > dy ? dx : dy);
    return 0;
}
