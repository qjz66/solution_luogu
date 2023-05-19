#include "bits/stdc++.h"

using namespace std;

int main(){
    int t, m;
    cin >> t >> m;
    int dp[t + 1], time[m + 1], value[m + 1];
    memset(dp,0,sizeof dp);
    memset(time,0,sizeof time);
    memset(value,0,sizeof value);
    for(int i = 1;i <= m;i++){
        cin >> time[i] >> value[i];
    }
    for(int i = 1;i <= m;i++)
        for(int j = t;j >= time[i];j--){
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
        }
    cout << dp[t];
}