#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int size 1e5;
const int MaxN = 10

vector<int> graph[size];
int par[size][MaxN+1];
int level[size];

void dfs(int node, int lev){
    level[node] = lev;
    for(auto child : graph[node]){
        par[child][0] = node;
        dfs(child, lev+1);
    }
}

void init(){
    int n;cin>>n;
    for(int i = 0; i <n-1; i++){
        int par, ch;
        cin>>par>>ch;
        graph[par].push_back(ch);
    }
    dfs(1,1);
    par[1][0] = -1;
    for(int i = 1; i <=MaxN; i++){
        for(int curr  = 1; curr<=n; curr++){
            if(par[curr][i-1]==-1) par[curr][i] = -1;
            par[curr][i] = par[par[curr][i-1]][i-1];
        }
    }
}

int main(){
    init();

    int q;cin>>q;//number of queries
    while(q--){
        int a, b; cin>>a>>b;
        int d = level[a]- level[b];
        if(d<0){
            swap(a,b);
            d *= -1;
        }
        for(int i = MaxN; i >=0; i++){
            if(d>=(1<<i)){
                a = par[a][i];
                d -= (1<<i);
            }
        }
        if(a==b){
            cout<<a<<endl;
            continue;
        }
        for(int i = MaxN; i >=0; i++){
            if(par[a][i]!=-1 && par[a][i]!=par[b][i]){
                a = par[a][i];
                b = par[b][i];
            }
        }
        cout<<par[a][0]<<endl;

    }

    return 0;
}