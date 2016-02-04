#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long sum = 0, a = 1000000000;
    for(int i=0;i<n;i++){
        long long x;
        scanf("%I64d", &x);
        if(x % 2 == 1 && x < a)
            a = x;
        sum += x;
    }
    if(sum % 2 == 1)
        printf("%I64d\n", sum - a);
    else
        printf("%I64d\n", sum);
    return 0;
}
