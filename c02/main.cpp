#include <bits/stdc++.h>
using namespace std;

#define MX 10001

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, nv;
    int dp[MX] = {0,};

    cin >> n >> k;

    for (int i=1; i<=k; i++) {
        dp[i] = MX;
    }

    for (int i=1; i<=n; i++) {
        cin >> nv;

        for(int j=nv; j<=k; j++) {
            dp[j] = min( dp[j], dp[j-nv]+1);
        }
    }

    if (dp[k] == MX) {
        cout << -1 << endl;
    } else {
        cout << dp[k] << endl;
    }


  return 0;
}