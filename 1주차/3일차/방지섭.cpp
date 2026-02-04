#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
void input(){
    cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
}

void solve(){
    int sum = 0;
    for(int i=0;i<n;i++) sum += v[i];
    int s = 1, e = sum/m;

    int ans;
    while(s <= e){
        int mid = (s+e)/2;

        int sum = 0, cnt = 0;
        for(int i=0;i<n;i++){
            sum += v[i];
            if(sum >= mid){
                sum = 0;
                cnt++;
            }
        }

        if(cnt >= m){
            s = mid+1;
            ans = mid;
        }
        else e = mid-1;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    solve();
    return 0;
}