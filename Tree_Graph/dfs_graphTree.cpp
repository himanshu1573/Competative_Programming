#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
// #define int double
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
// const int  n=1000000;
const int inf=1e18;
const int N=1e5+10;

vector<int>adj[N];
bool visited[N];


// here we are implementing the dfs function 
void dfs(int vertex){
visited[vertex]=true;
cout<<vertex<<nl;
for(int child:adj[vertex]){
    if(visited[child])continue;
    dfs(child);
}
}
void solve(){
  int n,e; //here n is node and e is edges 
  cin>>n>>e;


  // thsi is the method which is used for taking the inputs .
  for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
   adj[u].pb(v);
   adj[v].pb(u);
  }  
 for(int i=1; i<=n; i++){
        if(!visited[i])
            dfs(i);
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}