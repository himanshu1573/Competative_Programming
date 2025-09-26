#include <bits/stdc++.h>
using namespace std;
#include <cstdlib> // for srand() and rand()
#include <ctime>   // for time()
int getRandomNumber(int min, int max) { return min + rand() % (max - min); }

#define ll long long
#define pii pair<int, int>
#define nl endl
#define sp " "
#define len(x) int((x).size())
const int N = 2e5 + 10;
const ll INF = 1e18;
const int M = 1e9 + 7;

// this is depth first search traversal ;
void dfs(int current,vector<vector<int>>&edges,int parent,vector<int>&dis){
	if(parent!=-1){
		dis[current]=dis[parent]+1;
	}else
		dis[current]=0;
	for(auto neighbour:edges[current]){
			if(neighbour!=parent){
				dfs(neighbour,edges,current,dis);
			}
		}
	}




void solve(){
int n;cin>>n;
// this is for taking the input ;
vector<vector<int>>edges(n+1,vector<int>());
for(int i=0;i<n-1;i++){
	int u,v;cin>>u>>v;
	 u--,v--; // this is used for 1 based indexing;
	edges[u].push_back(v);
	edges[v].push_back(u);

}  
int x=getRandomNumber(0,n-1);
vector<int>disX(n,0);
dfs(x,edges,-1,disX);
int y=0;
for(int i=0;i<n;i++){
	if(disX[i]>disX[y]){
		y=i;
	}
}
// cout<<y;
vector<int>disY(n,0);
dfs(y,edges,-1,disY);
int z=0;
for(int i=0;i<n;i++){
	if(disY[i]>disY[z]){
		z=i;         
	}
}
// cout<<disY[z];
 for(auto &x:disX){
    	cout<<x<<" ";
    }
}

signed main(){
	// srand is used for generating random number.
	srand(time(0));
	solve();
	return 0;
}