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
    int n;
    cin>>n;
    int min = 2147483647;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x < min)
            min = x;
    }
    if(min == 1)
        cout<<-1<<endl;
    else
        cout<<1<<endl;
    return 0;
}