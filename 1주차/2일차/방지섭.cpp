    #include <bits/stdc++.h>
using namespace std;

int n; 
long long A[401][401];
long long lt_rd_sum[401][401], rt_ld_sum[401][401];

bool is_in(int x, int y){
    return (x >= 0 && x <= n && y >= 0 && y <= n);
}

void input(){
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];

    for(int i=0;i<n+1;i++){
        lt_rd_sum[0][i] = 0;
        for(int j=1;;j++){
            if(!is_in(j, i+j)) break;
            lt_rd_sum[j][i+j] = lt_rd_sum[j-1][i+j-1] + A[j][i+j];
        }
        lt_rd_sum[i][0] = 0;
        for(int j=1;;j++){
            if(!is_in(i+j, j)) break;
            lt_rd_sum[i+j][j] = lt_rd_sum[i+j-1][j-1] + A[i+j][j];
        }
    }

    for(int i=0;i<n+1;i++){
        rt_ld_sum[0][n-i] = 0;
        for(int j=1;;j++){
            if(!is_in(j, n-i-j)) break;
            rt_ld_sum[j][n-i-j] = rt_ld_sum[j-1][n-i-j+1] + A[j][n-i-j+1];
        }
        rt_ld_sum[i][n] = 0;
        for(int j=1;;j++){
            if(!is_in(i+j, n-j)) break;
            rt_ld_sum[i+j][n-j] = rt_ld_sum[i+j-1][n-j+1] + A[i+j][n-j+1];
        }
    }

    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout << lt_rd_sum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout << rt_ld_sum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

long long solve(){
    long long ans = 0;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=n-i;k++){
                long long lt = lt_rd_sum[j+i][k+i] - lt_rd_sum[j][k];
                long long rt = rt_ld_sum[j+i][k] - rt_ld_sum[j][k+i];

                ans = max(ans, lt - rt);
            }
        }
    }

    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0); 

    input();
    cout << solve();

    return 0;
}