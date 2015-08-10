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
    float T,S,Q;
    cin>>S>>T>>Q;
    float s = S, t = 0, q=Q;
    float js=0;
    while(1){
        s--;
        t++;
        T += (Q-1)/Q;
        //cout<<s<<' '<<t<<' '<<T<<endl;
        if(s==0){
            break;
        }
        if(t>=T){
            s = S;
            t = 0;
            js++;
        }
    }
    cout<<js+1<<endl;
    return 0;
}