#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<int> &dist, vector<pair<int,int>> graph[], int n){
    set<pair<int,int>> bag;
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[1] = 0;
    bag.insert({0,1});
    while(!bag.empty()){
        auto curr = *(bag.begin());
        int node = curr.second;
        int d = curr.first;
        bag.erase(curr);
        for(auto child: graph[node]){
            if(d+child.second < dist[child.first]){
                bag.erase({dist[child.first],child.first});
                bag.insert({d+child.second, child.first});
                dist[child.first] = d+child.second;
            }
        }
    }
}

int main(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>> graph[n+1];
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    vector<int> dist(n+1);
    dijkstra(dist, graph, n);
    for(int i = 1; i <= n; i++) cout<<i<<":"<<dist[i]<<" ";
    return 0;
}




int helper(vector<int>& a,int n,int count,int prev,vector<int> &t)
    {
        if(n==-1) return count;
      
        if(a[n]<prev){
            if(t[n]!=-1)return t[n];
            return t[n]=max(helper(a,n-1,count+1,a[n],t),helper(a,n-1,count,prev,t));
        }
        return t[n]= helper(a,n-1,count,prev,t);
    }
int lengthOfLIS(vector<int>& a)
    {
        vector<int> t(a.size(),-1);
        helper(a,a.size()-1,0,INT_MAX,t);
        return *max_element(t.begin(), t.end());
    }