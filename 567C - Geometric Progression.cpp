#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

long long js[50];
int init;
int p;

void process(int i, long long jin){
    js[i] += jin;
    if(js[i] == 0)
        return;
    jin = 0;
    if(js[i] >= p){
        jin = js[i]/p;
        js[i] = js[i]%p;
    }
    if(js[i] != 0 && init < i)
        init = i;
    process(i+1,jin);
}

int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    int prev[n], prevk[n];
    map<int, vector<int> > pos;
    for(int i=0; i<n; i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
        if(pos[a[i]].size() > 1)
            prev[i] = pos[a[i]][pos[a[i]].size()-2];
        else
            prev[i] = -1;
        if(a[i]%k == 0 && pos[a[i]/k].size()!=0){
            if(a[i]/k == a[i]){
                if(pos[a[i]/k].size()>1)
                    prevk[i] = pos[a[i]/k].size()-2;
                else
                    prevk[i] = -1;
            }
            else
                prevk[i] = pos[a[i]/k].size()-1;
            
        }
        else
            prevk[i] = -1;
    }
    long long dp[3][n];
    
//    for(int i=0;i<n;i++)
//        cout<<prev[i]<<' ';
//    cout<<endl;
//    for(int i=0;i<n;i++)
//        cout<<prevk[i]<<' ';
//    cout<<endl;
    
    memset(dp,0,sizeof(dp));
    memset(js,0,sizeof(js));
    init = 0;
    p = 10;
    for(int i=0;i<n;i++)
        dp[0][i] = 1;
    for(int i=0;i<n;i++){
        if(a[i] % k != 0)
            continue;
        int l = prev[i], j;
        if(pos.find(a[i]/k) != pos.end()){
            for(j = prevk[i]; j>=0; j--){
                int s = pos[a[i]/k][j];
                if(s < l)
                    break;
                //cout<<" + "<<i<<": "<<s<<endl;
                dp[1][i] += dp[0][s];
                dp[2][i] += dp[1][s];
            }
            if(l != -1){
                //cout<<"++ "<<i<<": "<<l<<endl;
                dp[1][i] += dp[1][l];
                dp[2][i] += dp[2][l];
            }
        }
        
        js[0] += dp[2][i];
        process(0,0);
    }
//    for(int i=0;i<3;i++){
//        for (int j=0;j<n;j++)
//            cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }
    
    for(int i = init; i >= 0; i--)
        cout<<js[i];
    cout<<endl;
    return 0;
}