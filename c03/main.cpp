#include <bits/stdc++.h>
using namespace std;

#define MX 10001

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, TK, K, P;
    int i, j;

    int dp[MX] = {
        0,
    };

    cin >> N >> TK;

    for (i = 1; i <= N; i++) {
        cin >> K >> P;

        for (j = K; j <= TK; j++) {
            dp[j] = max(dp[j - K] + P, dp[j]);
        }
    }

    if (dp[TK] == 0) {
        cout << -1 << endl;
    } else {
        cout << dp[TK] << endl;
    }

    return 0;
}