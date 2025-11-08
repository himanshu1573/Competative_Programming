#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long 
#define pb push_back
int mod=1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
const int inf=1e18;
const int N=1e5+10;

int n,m;
char grid[1005][1005];
bool visited[1005][1005];

char path_moves[1005][1005];
pair<int,int> start,endd;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
char moves[4]={'U','D','R','L'};
bool found = false;

bool isValid(int x,int y){
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#');
}

void bfs(){
    queue<pair<int,int>>q;
    q.push(start);
    visited[start.first][start.second]=true;

    while(!q.empty()){
        pair<int,int> current_node=q.front();
        q.pop();

        if(current_node==endd){
            found=true;
            break;
        }
        for(int dir=0;dir<4;dir++){
            int nx=current_node.first+dx[dir];
            int ny=current_node.second+dy[dir];

            if(isValid(nx,ny)){
                visited[nx][ny]=true;
                path_moves[nx][ny]=moves[dir];
                q.push({nx,ny});
            }
        }


    }
}


void solve(){
	cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;cin>>x;
            grid[i][j]=x;
            if(x=='A')start={i,j};
            if(x=='B')endd={i,j};
        }
    }
    memset(path_moves, '.', sizeof(path_moves));
    bfs();

  
if(found){
    cout <<"yes"<<nl;
    string path;
    pair <int,int>move=endd;

    while(move!=start){
        char  current_move=path_moves[move.first][move.second];
        path+=current_move;
        if(current_move=='U')move.first++;
        else if(current_move=='D')move.first--;
        else if(current_move=='L')move.second++;
        else if(current_move=='R')move.second--;
    }
    cout<<path<<nl;
}


// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
// cout<<path_moves[i][j]<<" ";
//     }
//     cout<<endl;
// }

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



    