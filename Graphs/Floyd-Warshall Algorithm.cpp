// this is Floyd-Warshall algo for all pair shortest paths without any negative cycle

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LONG_MAX/10));
    for(int i = 0; i < m; i++){
        ll a, b, wt;
        cin>>a>>b>>wt;
        dist[a][b] = min(dist[a][b], wt);
        dist[b][a] = min(dist[b][a], wt); // if graph is directed comment out this line
    }
    for(int k = 1; k<= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i==j)dist[i][j] = 0;
                else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // answering q queries
    while(q--){
        int a, b;
        cin>>a>>b;
        if(dist[a][b]>=LONG_MAX/10) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
    return 0;
}