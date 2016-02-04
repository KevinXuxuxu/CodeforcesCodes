#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int abs(int x){
    return x >= 0 ? x : -x;
}

int difhash[2005], sumhash[2005];
int main(){
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        sum += difhash[x - y + 1000];
        sum += sumhash[x + y];
        difhash[x - y + 1000]++;
        sumhash[x + y]++;
    }
    printf("%I64d\n", sum);
    return 0;
}
