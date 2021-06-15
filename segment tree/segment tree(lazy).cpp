#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> stree;
vector<bool> lazy;
vector<ll> upd;

// tl and tr represents segment ranges everywhere
// v represent index of current node in stree[]

void apply(int v, int tl, int tr, int val){  // asking the node to update its result
    stree[v] += val*(tr-tl+1);   // updating its value

    if(tl!=tr){          // its not a leaf
        lazy[v] = true;  // mark it lazy
        upd[v] += val;   // making it remember the update which will later be passed on to children
    }
}

void pushdown(int v, int tl, int tr){
    if(!lazy[v]) return; // if not lazy then nothing to do
    lazy[v] = false;    // removing the lazy tag

    int tm = (tl+tr)/2;
    apply(2*v, tl, tm, upd[v]);        // passing on the value
    apply(2*v+1, tm+1, tr, upd[v]);    // to children
    upd[v] = 0;
}

// l and r are the update range
// val is the value to be added
void update(int v, int tl, int tr, int l, int r, int val){
    if(l>tr || r<tl)return;                    // no overlap
    if(tl>=l && tr<=r){                        // fully within
        apply(v, tl, tr, val);               //instead of passing down the update we ask the node to remember it
    }
    pushdown(v, tl, tr);      // before going down we ask the node to push down its knowledge to its children 

    int tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, val);
    update(2*v+1, tm+1, tr, l, r, val);
}

ll query(int v, int tl, int tr, int l, int r){
    if(l>tr || r<tl) return 0;                 // no overlap
    if(tl>=l && tr<=r) return stree[v];        // fully within. Note: value of stree[v] is correct
    pushdown(v, tl, tr);      // before going down we ask the node to push down its knowledge to its children

    int tm = (tl+tr)/2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
    // passing answer returned from children
}

int32_t main(){
    int n; cin>>n;
    stree.resize(4*n,0);
    lazy.resize(4*n, false);
    upd.resize(4*n,0);

    // perform queries and update now 
    return 0;
}