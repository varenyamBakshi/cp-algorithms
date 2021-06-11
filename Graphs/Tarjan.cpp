#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	/*  Function to find the members of strongly connected components
    *   using Tarjan's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    int n;
    vector<int> vis, in, low, active;
    int timer = 0;
    stack<int> curr;
    vector <vector<int>> ans;
    
    void dfs(int node, vector<int> *graph){
        vis[node] = active[node] =  1;
        in[node] = low[node] = timer++;
        curr.push(node);
        for(auto child : graph[node]){
            //if(child == par) continue;               // no need to check for parent 
                                                       //as it is a Directed graph so it is a different edge
            if (vis[child] == 1) { // back edge
                if(active[child] == 1) low[node]  =min(low[node], in[child]);
            }
            else{ // forward edge
                dfs(child, graph);
                low[node] = min(low[node], low[child]);
            }
        }
        if(low[node] == in[node]){
            vector<int> temp;
            while(curr.top() != node){
                active[curr.top()] = 0;
                temp.push_back(curr.top());
                curr.pop();
            }
            curr.pop();
            temp.push_back(node);
            active[node]  = 0;
            ans.push_back(temp);
        }
        
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        n = V;
        vis.resize(n,0); low.resize(n,0); in.resize(n,0); active.resize(n,0); 
        for(int i = 0; i < n; i++){
            if(vis[i]==0){
                dfs(i, adj);
            }
        }
        for(auto &arr : ans){
            sort(arr.begin(), arr.end());
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}