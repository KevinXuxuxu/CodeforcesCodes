#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
using namespace std;

struct req{
    int i,j;
    char op[5];
}reqs[120];

int a[72];
int flag[36];
int n,m;
long long js;
//stack<int*> sta;
vector<int> rreqs[36];

bool check(struct req r){
    int i = r.i, j = r.j;
    if(!strcmp(r.op, "="))
        return a[i]==a[j];
    else if(!strcmp(r.op, ">"))
        return a[i]>a[j];
    else if(!strcmp(r.op, ">="))
        return a[i]>=a[j];
    else if(!strcmp(r.op, "<"))
        return a[i]<a[j];
    else //if(strcmp(r.op, "<="))
        return a[i]<=a[j];
}
void ite(int x);

void assign(int x, int p){
    a[x] = p;
    
    bool f = true;
    for(int j=0; j<rreqs[x].size(); j++){
        if(!check(reqs[rreqs[x][j]])){
            f = false;
            break;
        }
    }
    if(f){
        flag[p]++;
        if(x == 2*n)
            js++;
        else
            ite(x+1);
        flag[p]--;
    }
}

void ite(int x) {
    int p = a[x-1];
    if (p == n){
        if(flag[p]==1){
            assign(x,p);
        }
        else{
            for (int i=p-1;i>0;i--){
                if(flag[i]<2){
                    assign(x,i);
                    break;
                }
            }
        }
    }
    else {
        if(flag[p]==1){
            assign(x, p);
        }
        if(flag[n]==2){
            for(int i=p-1;i>0;i--){
                if(flag[i]<2){
                    assign(x, i);
                    break;
                }
            }
        }
        else{
            for(int i=p+1;i<=n;i++){
                assign(x, i);
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        cin>>reqs[i].i>>reqs[i].op>>reqs[i].j;
        int max = reqs[i].j > reqs[i].i ? reqs[i].j : reqs[i].i;
        rreqs[max].push_back(i);
    }
    memset(a, 0, sizeof(a));
    memset(flag, 0, sizeof(flag));
    js = 0;
    ite(1);
    cout<<js<<endl;
    return 0;
}