#include <bits/stdc++.h>
using namespace std;

int n,m, cnt1, cnt2;
vector<int> v1[501], v2[501];
bool visited[501];
void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
}

void dfs1(int num){
    for(auto k : v1[num]){
        if(!visited[k]){
            visited[k] = true;
            cnt1++;
            dfs1(k);
        }
    }
}

void dfs2(int num){
    for(auto k : v2[num]){
        if(!visited[k]){
            visited[k] = true;
            cnt2++;
            dfs2(k);
        }
    }
}

void solve(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        cnt1 = 0, cnt2 = 0;
        memset(visited, false, n+1);  
        dfs1(i);
        memset(visited, false, n+1);
        dfs2(i);
        if(cnt1 + cnt2 == n-1) ans++;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}