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
    map<int, int> people;
    long size=0;
    for (int i=0; i<n; i++){
        char c;
        int id;
        cin>>c>>id;
        if(c=='+'){
            people[id]=1;
            if(people.size() > size)
                size = people.size();
        }
        else {
            if(people.find(id) == people.end()){
                size++;
            }
            else {
                people.erase(id);
            }
        }
    }
    cout<<size<<endl;
    return 0;
}