#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

map<long long,bool> m;
map<long long,bool> m2;
long long first_hole = 1;

long long ff[200001];
long long M = 1000000007;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

long long gcdEx(long long a, long long b, long long *x, long long *y)
{
    if(b==0)
    {
        *x = 1,*y = 0;
        return a;
    }
    else
    {
        long long r = gcdEx(b, a%b, x, y);
        long long t = *x;
        *x = *y;
        *y = t - a/b * *y;
        return r;
    }
}

long long Comb(long long u, long long b){
    long long B = ff[b], A = ff[b-u]*ff[u]%M;
    long long D = gcd(A, M);
    long long x, y;
    gcdEx(A, M, &x, &y);
    long long ans = (((x * B + M )/ D )%M+M)%M;
    return ans;
}

struct block{
    long long x,y;
    long long f;
}b[2000];

bool operator > (block a, block b){
    return a.x+a.y > b.x+b.y;
}
bool operator == (block a, block b){
    return a.x+a.y == b.x+b.y;
}
bool operator < (block a, block b){
    return !(a==b) && !(a>b);
}

int main() {
    ff[0] = 1;
    for(long long i=1;i<200001;i++){
        ff[i] = (ff[i-1] * i) % M;
    }
    long long n,m,s;
    cin>>n>>m>>s;
    long long a = Comb(n-1, m+n-2);
    for(long long i=0;i<s;i++){
        long long X,Y;
        cin>>X>>Y;
        b[i].x = X-1;
        b[i].y = Y-1;
        b[i].f = Comb(b[i].x, b[i].x+b[i].y);
    }
    sort(b, b+s);
    for(long long i=0;i<s;i++){
        long long x = b[i].x, y = b[i].y;
        for(long long j=0;j<i;j++){
            if(b[j].x <= x && b[j].y <= y){
                b[i].f = (b[i].f + M - ((b[j].f * Comb(x-b[j].x, (x-b[j].x)+(y-b[j].y))) % M)) % M;
            }
        }
    }
    
//    for(long long i=0;i<s;i++){
//        cout<<b[i].x<<' '<<b[i].y<<' '<<b[i].f<<endl;
//    }
    
    for(long long i=0;i<s;i++){
        a = ( a + M - ((b[i].f * Comb(n-b[i].x-1, (n-b[i].x)+(m-b[i].y)-2)) % M)) % M;
    }
    cout<<a<<endl;
    return 0;
}