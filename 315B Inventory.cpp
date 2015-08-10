#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

map<int,bool> m;
map<int,bool> m2;
int first_hole = 1;

void find_hole(){
    first_hole++;
    if(m.find(first_hole) != m.end())
        find_hole();
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i] <= n && a[i]>0)
            m[a[i]] = true;
        if(first_hole == a[i])
            find_hole();
    }
    
    for(int i=0;i<n;i++){
        if(a[i] <= n && a[i]>0){
            if(m2.find(a[i]) == m2.end())
                m2[a[i]] = true;
            else{
                a[i] = first_hole;
                m[a[i]] = true;
                m2[a[i]] = true;
                find_hole();
            }
        }
        else{
            a[i] = first_hole;
            m[a[i]] = true;
            m2[a[i]] = true;
            find_hole();
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}