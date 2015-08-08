#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

bool check(int x, int y, int a, int b, int c, int d){
    return (a+b<=x && c<=y && d<=y) || (a+b<=y && c<=x && d<=x);
}

int main() {
    bool flag = false;
    int x,y,a,c,b,d;
    cin>>x>>y>>a>>c>>b>>d;
    if(check(x,y,a,b,c,d))
        flag = true;
    if(check(x,y,c,b,a,d))
        flag = true;
    if(check(x,y,a,d,c,b))
        flag = true;
    if(check(x,y,c,d,a,b))
        flag = true;
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}