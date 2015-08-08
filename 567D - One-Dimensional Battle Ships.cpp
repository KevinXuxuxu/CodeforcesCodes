#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int N;
int n,k,a;
int m;

class Seg{
public:
    int s,t,length;
    int hit;
    Seg *l, *r, *f;
    
    Seg(int x, int y, Seg* f){
        this->s = x;
        this->t = y;
        this->length = y-x+1;
        this->hit = -1;
        this->f = f;
        N += getN();
    }
    
    void omit(Seg* c){
        if(c == l){
            if(r != NULL){
                s = r->s;
                t = r->t;
                length = t-s+1;
                hit = -1;
                l = r->l;
                r = r->r;
            }
        }
        else{
            if (l != NULL){
                s = l->s;
                t = l->t;
                length = t-s+1;
                hit = -1;
                r = l->r;
                l = l->l;
            }
        }
    }
    
    void devide(int x){
        if (hit != -1 || (x < s && x > t)) {
            return;
        }
        if(x == s){
            s++;
            N -= getN();
            length--;
            N += getN();
            return;
        }
        if(x == t){
            t --;
            N -= getN();
            length--;
            N += getN();
            return;
        }
        hit = x;
        l = new Seg(s, x-1, this);
        r = new Seg(x+1, t, this);
        N -= getN();
    }
    
    Seg* find(int x){
        if(hit == -1)
            return this;
        else {
            if(x < hit)
                return l->find(x);
            else
                return r->find(x);
        }
    }
    
    int getN(){
        return length/(a+1) + ( length%(a+1)==a ? 1 : 0 );
    }
};

int main() {
    cin>>n>>k>>a;
    cin>>m;
    N = 0;
    Seg *root = new Seg(1,-1, NULL);
    root->r = new Seg(1,n,root);
    for (int i=1; i<=m; i++) {
        int h;
        cin>>h;
        Seg* t = root->r->find(h);
        t->devide(h);
        //cout<<"N: "<<N<<endl;
        if(N < k){
            cout<<i<<endl;
            return 0;
        }
    }
    
    cout<<-1<<endl;
    return 0;
}