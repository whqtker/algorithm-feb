#include <bits/stdc++.h>
using namespace std;

int n,m;
int no_blocked_dis;
pair<int,int> blocked_edge; // 차단된 간선
vector<pair<int,int>> edges; // 간선 하나씩 차단하기 위해 저장하는 용도
vector<pair<int,int>> v[1001]; // pq를 위한 간선
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void input(){
    cin >> n >> m;
    blocked_edge = {-1,-1};
    edges.resize(m);
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        edges[i] = {a,b};
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
}

int dijkstra(){
    vector<int> dis(n+1, INT32_MAX);
    dis[1] = 0;
    pq.push({0, 1}); // 거리, 노드
    while(!pq.empty()){
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dis[cur] < d) continue;

        for(auto k : v[cur]){
            int next = k.first;
            int cost = k.second;
            // 차단된 간선
            if(cur == blocked_edge.first && next == blocked_edge.second || cur == blocked_edge.second && next == blocked_edge.first ) continue;
            if(dis[next] > dis[cur] + cost){
                dis[next] = dis[cur] + cost;
                pq.push({dis[next], next});
            }
        }
    }
    return dis[n];
}

int solve(){
    int ans = 0; // 하나의 도로를 막음으로서 지연시킬 수 있는 최대 시간.
    no_blocked_dis = dijkstra();
    if(no_blocked_dis == INT32_MAX) return -1;
    for(int i=0;i<m;i++){
        blocked_edge = edges[i];
        int blocked_dis = dijkstra();
        if(blocked_dis == INT32_MAX) return -1;
        ans = max(ans, abs(blocked_dis - no_blocked_dis));
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}