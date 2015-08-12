#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>

#define MAXLEN 200000000000
using namespace std;

class edge{
public:
    int id;
    int x,y;
    long long l;
    int js;
    long long ans;
}b[100000];

class node{
public:
    vector<edge*> nbs[2];
}a[100001];


long long fromS[100000];
long long toT[100000];
vector<edge*> *yo;

void dijk(long long *d, int n, int m,node nodes[], edge edges[], int from, int to, int ig, int dir, bool findpath){
    bool unvisited[n+1];
    for(int i=0;i<=n;i++){
        d[i] = MAXLEN;
        unvisited[i] = true;
    }
    d[from] = 0;
    unvisited[from] = false;
    int js = n-1;
    int p = from;
    while(js>0){
        //        cout<<p<<": ";
        //        for(int i=1;i<=n;i++)
        //            cout<<d[i]<<' ';
        //        cout<<endl;
        vector<edge*> nei = nodes[p].nbs[dir];
        for(vector<edge*>::iterator it=nei.begin(); it != nei.end(); it++){
            if(ig != -1 && (*it) == &edges[ig])
                continue;
            long long l = (*it)->l;
            int t = dir == 0 ? (*it)->y : (*it)->x;
            if(d[t] > d[p]+l){
                d[t] = d[p]+l;
                if(findpath){
                    yo[t].clear();
                    yo[t].push_back((*it));
                }
            }
            else if(findpath && d[t] == d[p]+l)
                yo[t].push_back((*it));
        }
        long long sma = MAXLEN;
        int sman;
        for(int i=0;i<=n;i++){
            if(unvisited[i] && d[i] < sma){
                sma = d[i];
                sman = i;
            }
        }
        if(sma == MAXLEN)
            return;
        unvisited[sman] = false;
        p = sman;
        js--;
    }
}

int maxpass;
void dfs(vector<int> yoo, int i, int s){
    //cout<<i<<' ';
    if(i == s){
        maxpass++;
        for(vector<int>::iterator it=yoo.begin(); it!=yoo.end(); it++){
            b[(*it)].js += b[(*it)].js > -1 ? 2 : 1;
        }
        return;
    }
    for(vector<edge*>::iterator it=yo[i].begin(); it!=yo[i].end(); it++){
        yoo.push_back((**it).id);
        dfs(yoo, (**it).x, s);
        yoo.pop_back();
    }
}

int main() {
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    yo = new vector<edge*>[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        long long l;
        cin>>x>>y>>l;
        b[i].x = x, b[i].y = y, b[i].l = l;
        b[i].js = -1, b[i].id = i, b[i].ans = 0;
        bool flag = true;
        for(vector<edge*>::iterator it=a[x].nbs[0].begin(); it!= a[x].nbs[0].end(); it++){
            if((**it).y == y){
                if((**it).l > l){
                    a[x].nbs[0].erase(it);
                    a[x].nbs[0].push_back(&b[i]);
                }
                flag = false;
                break;
            }
        }
        if(flag) a[x].nbs[0].push_back(&b[i]);
        flag = true;
        for(vector<edge*>::iterator it=a[y].nbs[1].begin(); it!= a[y].nbs[1].end(); it++){
            if((**it).x == x){
                if((**it).l > l){
                    a[y].nbs[1].erase(it);
                    a[y].nbs[1].push_back(&b[i]);
                }
                flag = false;
                break;
            }
        }
        if(flag) a[y].nbs[1].push_back(&b[i]);
    }
    
    dijk(fromS, n, m, a, b, s, t, -1, 0,true);
    
//    for(int i=1;i<=n;i++){
//        for(vector<edge*>::iterator it=yo[i].begin(); it!=yo[i].end(); it++){
//            cout<<'('<<(**it).id<<' '<<(**it).y<<") ";
//        }
//        cout<<endl;
//    }
    maxpass = 0;
    vector<int> yoo;
    dfs(yoo, t, s);
    //cout<<endl;
    dijk(toT, n, m, a, b, t, s, -1, 1, false);
    
    //    for(int i=0;i<=n;i++)
    //        cout<<fromS[i]<<' ';
    //    cout<<endl;
    //    for(int i=0;i<=n;i++)
    //        cout<<toT[i]<<' ';
    //    cout<<endl;
    
    for(int i=0;i<m;i++){
        //long long tmp[n+1];
        //dijk(tmp, n, m, a, b, s, t, i, 0, false);
        
        //        cout<<i<<": ";
        //        for(int i=0;i<=n;i++)
        //            cout<<tmp[i]<<' ';
        //        cout<<endl;
    
        if(b[i].js == -1){
            int x = b[i].x, y = b[i].y;
            long long l = b[i].l;
            bool flag = true;
            for(vector<edge*>::iterator it=a[x].nbs[0].begin(); it!=a[x].nbs[0].end(); it++){
                if((**it).y == y){
                    if((**it).ans == 0){
                        if((**it).js == maxpass){
                            if((**it).l == l){
                                (**it).ans = 1;
                                b[i].ans = 1;
                            }
                            else{
                                (**it).ans = -1;
                                b[i].ans = l-(**it).l+1;
                            }
                        }
                        else if((**it).js > 0) {
                            (**it).ans = fromS[(**it).x] + toT[(**it).y] + (**it).l - fromS[t]+1;
                            b[i].ans = (**it).ans + l - (**it).l;
                        }
                        else{
                            (**it).ans = -2;
                            b[i].ans = -2;
                        }
                    }
                    else {
                        if((**it).l == l && (**it).ans == -1){
                            (**it).ans = 1;
                            b[i].ans = 1;
                        }
                        else if((**it).ans == -1){
                            b[i].ans = l - (**it).l + 1;
                        }
                        else if((**it).ans == -2){
                            b[i].ans = -2;
                        }
                        else if((**it).ans > 0){
                            b[i].ans = (**it).ans + l - (**it).l;
                        }
                    }
                    flag = false;
                    break;
                }
            }
            if(flag)
                b[i].ans = -2;
        }
    }
    for(int i=0;i<m;i++){
        switch (b[i].ans) {
            case -1:
                cout<<"YES\n";
                break;
            case -2:
                cout<<"NO\n";
                break;
            default:
                cout<<"CAN "<<b[i].ans<<endl;
                break;
        }
    }
    return 0;
}