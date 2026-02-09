#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    for(int day = 1;;day++){
        int n; cin >> n;
        if(n == 0) break;

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int a,b; cin >> a >> b;
            v.push_back({2*a,2*b});
        }
        sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        bool visited[49] = {false};
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=v[i].first;j<v[i].second;j++){
                if(!visited[j]){
                    visited[j] = true;
                    ans++;
                    break;
                }
            }
        }
        cout << "On day " << day << " Emma can attend as many as " << ans << " parties.\n";
    }

    return 0;
}