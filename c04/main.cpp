#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (X[m - 1] == Y[n - 1]) {
        return 1 + lcs(X, Y, m - 1, n - 1);
    } else {
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
    }
}

int lcs(char *X, char *Y, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 || n == 0) return 0;

    if (X[m - 1] == Y[n - 1]) {
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    }
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}

int lcs_dp(char *X, char *Y, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

int lcs_dp2(char *X, char *Y, int x, int y) {
    vector<int> dp(x + 1, 0);

    for (int i = 1; i <= y; i++) {
        int pre = 0;
        cout << '\n';
        for (int j = 1; j <= x; j++) {
            int tmp = dp[j];
            if (Y[i - 1] == X[j - 1]) {
                dp[j] = pre + 1;
            } else {
                dp[j] = max(dp[j - 1], dp[j]);
            }
            pre = tmp;
        }

        cout << '\n'
             << i << " ";
        for (auto e : dp) {
            cout << e;
        }

        // cout << " " << dp[m + 1] << '\n';
    }

    cout << '\n';

    return dp.back();
}

int lcs_dp3(char *X, char *Y) {
    vector<int> dp(strlen(X) + 1);
    for (int y = 1; y <= strlen(Y); y++) {
        int pre = 0;
        for (int x = 1; x <= strlen(X); x++) {
            int tmp = dp[x];
            if (X[x - 1] == Y[y - 1]) {
                dp[x] = pre + 1;
            } else {
                dp[x] = max(dp[x - 1], dp[x]);
            }
            pre = tmp;
        }
    }
    return dp.back();
}

int main(void) {
    // brute force
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    // cout << "Length of LCS is " << lcs(X, Y, m, n) << '\n';
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // cout << "Length of LCS is " << lcs(X, Y, m, n, dp) << '\n';
    int res = lcs_dp3(X, Y);
    cout << '\n'
         << "Length of LCS is " << res << '\n';

    return 0;
}