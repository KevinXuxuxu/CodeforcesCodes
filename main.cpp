#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    if(n-(m+1)+1 > m-1-1+1)
        cout<<m+1<<endl;
    else
        cout<<m-1<<endl;
    return 0;
}