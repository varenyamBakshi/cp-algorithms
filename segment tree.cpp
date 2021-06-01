#include<bits/stdc++.h>
using namespace std;

vector<int> stree;

void build(int v, int tl, int tr,vector<int> &arr){
    if(tl==tr){
        stree[v] = arr[tl];
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm, arr);
    build(2*v+1, tm+1, tr, arr);
    stree[v] = stree[2*v] + stree[2*v+1];
}

int query(int v, int tl, int tr, int l, int r){
    if(tr<l || tl > r) return 0;
    if(tl>=l && tr <= r){
        return stree[v];
    }
    int tm = tl + (tr-tl)/2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
}

void update(int v, int tl, int tr, int pos, int val){
    if(pos>tr || pos<tl) return;
    if(tl== pos && tr==pos) {
        stree[v] = val;
        return;
    }
    int tm = tl + (tr-tl)/2;
    update(2*v, tl ,tm, pos, val);
    update(2*v+1, tm+1, tr, pos, val);
    stree[v] = stree[2*v] + stree[2*v+1];
}

int main(){

    int n; cin>>n;
    stree.resize(4*n,0);
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin>>arr[i];
    build(1, 0, n-1, arr);  // start from node 1, if we start from 0 then 2*0 == 0 and it will lead to logical error
    cout<<query(1, 0, n-1, 0, 2)<<endl;
    cout<<query(1, 0, n-1, 0, 6)<<endl;
    cout<<query(1, 0, n-1, 3, 7)<<endl;
    update(1, 0, n-1, 3, 8);
    cout<<query(1, 0, n-1, 0, 2)<<endl;
    cout<<query(1, 0, n-1, 0, 6)<<endl;
    cout<<query(1, 0, n-1, 3, 7)<<endl;
    return 0;
}