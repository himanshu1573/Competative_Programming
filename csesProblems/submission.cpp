#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl endl
int  minn =INT_MAX;
int mod=1e9+7;
const int inf=1e18;

void solve(){
int r,c;cin>>r>>c;
int grid[r+10][c+10];


pair<int,int>start,endd; 
for(int i=0;i<r;i++){
  for(int j=0;j<c;j++){
    char s;cin>>s;

    if(s=='T')grid[i][j]=-1;
    else if(s=='S')grid[i][j]=0,start={i,j};
    else if(s=='E')grid[i][j]=0,endd={i,j};
    else grid[i][j]=s-'0';
  }
}

bool visited[r+5][c+5];
int distance[r+5][c+5];

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        distance[i][j]=inf;
        visited[i][j]=false;
    }
}

queue<pair<int,int>>q;
visited[endd.first][endd.second]=true;
distance[endd.first][endd.second]=1;
q.push(endd);

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
// here four directions are specified ie left,right,top,bottom ;
while(!q.empty()){
    auto p=q.front();
    int x=p.first,y=p.second;

    q.pop();

    for(int d=0;d<4;d++){
        int nx=x+dx[d],ny=y+dy[d];

        if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(!visited[nx][ny] && grid[nx][ny]!=-1){
                visited[nx][ny]=true;
                distance[nx][ny]=distance[x][y]+1 ;
                q.push({nx,ny});
            }
        }



    }


}

int mn=distance[start.first][start.second];
int ans=0;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(grid[i][j]!=-1 && distance[i][j]<=mn){
            ans+=grid[i][j];
        }
    }
}
cout<<ans<<nl;
}
signed main(){
    int t=1;
    // cin>>t;

    while(t--){
        solve();   
         }
    return 0;
}

// questoin link of codeforces.