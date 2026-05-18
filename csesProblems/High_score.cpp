#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long INF=1e18;
struct Edge{
    int a,b,w;
};
int n,m;
vector<Edge> edges;
vector<int> adj[2505];
signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        x=-x;
        edges.push_back({a,b,x});
        adj[a].push_back(b);
    }
    vector<int> dist(n+1,INF);
    dist[1]=0;
    vector<int> affected;
    for(int i=1;i<=n;i++){
        for(auto e:edges){
            if(dist[e.a]==INF)continue;
            if(dist[e.b]>dist[e.a]+e.w){
                dist[e.b]=dist[e.a]+e.w;
                if(i==n){
                    affected.push_back(e.b);
                }
            }
        }
    }
    vector<int> vis(n+1,0);
    queue<int> q;
    for(auto x:affected){
        q.push(x);
        vis[x]=1;
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto child:adj[node]){
            if(!vis[child]){
                vis[child]=1;
                q.push(child);
            }
        }
    }
    if(vis[n]){
        cout<<-1<<'\n';
    }
    else{
        cout<<-dist[n]<<'\n';
    }
}