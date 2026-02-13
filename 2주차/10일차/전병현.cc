//question : https://icpc.me/2169
#include <bits/stdc++.h>
#define INT_MAX 2147483647
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> llll;
typedef pair<int,int> ii;

int templ[1001];
int tempr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    int* last = new int[1001];
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        if(i==0)last[0] = x;
        else last[i] = last[i-1]+x;
    }
    int* temp = new int[1001];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            temp[j] = x;
            if(j==0)templ[j] = last[j]+temp[j];
            else templ[j] = max(last[j], templ[j-1])+temp[j];
        }
        for(int j=m-1;j>=0;j--){
            if(j==m-1)tempr[j] = last[j]+temp[j];
            else tempr[j] = max(last[j], tempr[j+1])+temp[j];
        }
        for(int j=0;j<m;j++){
            temp[j] = max(templ[j], tempr[j]);
        }
        swap(last, temp);
    }
    cout<<last[m-1];
}
