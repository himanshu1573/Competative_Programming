#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
// const int inf=1e18;
// const int N=1e5+10;
int n,m;
int  helper(int i,int j,vector<vector<int>>&grid){
	if(i>=n || j>=m)return INT_MIN;
	 if(i==n-1 && j==m-1){
	 	return grid[i][j] ;
	 }
	 int left=helper(i+1,j,grid)+grid[i][j];
	 int down=helper(i,j+1,grid)+grid[i][j];

	 return max(left,down);
}
void solve(){
cin>>n>>m;
vector<vector<int>>grid(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
}
int ans=helper(0,0,grid);
cout<<ans<<nl;
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
