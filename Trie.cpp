#include<bits/stdc++.h>
using namespace std;

const int vsize = 26;

struct Node{
    bool isleaf;
    int next[vsize];
    Node(){
        isleaf = false;
        fill(begin(next), end(next), -1);
    }
};

void insert(string s, vector<Node> &trie){
    int curr = 0;
    for(auto c: s){
        int ch = c-'a';
        if(trie[curr].next[ch]==-1){
            Node temp  = Node();
            trie[curr].next[ch] = trie.size();
            trie.emplace_back(temp);
        }
        curr = trie[curr].next[ch];
    }
    trie[curr].isleaf = true;
}

bool search(string s, vector<Node> &trie){
    int curr = 0;
    for(auto c:s){
        int ch = c-'a';
        if(trie[curr].next[ch]==-1)return false;
        curr = trie[curr].next[ch];
    }
    if(trie[curr].isleaf)return true;
    return false;
}

int main(){
    int n; cin>>n;
    vector<Node> trie(1);
    while(n--){
        string s;
        cin>>s;
        insert(s, trie);
    }
    int q; cin>>q;
    while(q--){
        string query;
        cin>>query;
        if(search(query,trie))cout<<"FOUND\n";
        else cout<<"NOT FOUND\n";
    }

    return 0;
}