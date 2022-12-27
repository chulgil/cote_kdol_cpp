#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int main(void) {
  char W[MAX];
  char H[MAX];

  cin >> W >> H;

  int dp_size = strlen(W) + 1;
  vector<int> dp(dp_size, 0);

  for (int i = 1; i < dp_size; i++) {
    for (int j = 1; j < dp_size; j++) {
      if (W[i] == H[j]) {
        dp[i]++;
      } else {
        dp[i] = max(dp[i - 1], dp[i]);
      }
    }
  }
  
  for (const auto& e : dp) {
    cout << e;
  }
  cout << '\n';

  cout << dp.back() << '\n';

  return 0;
}