#include "bits/stdc++.h"
using namespace std;

int solve(vector<int> &coins, int sum) {
    vector<int> dp(sum + 1);

    for (int i = 0; i <= sum; i++)
        if (coins[0] <= i)
            dp[i] = 1 + dp[i - coins[0]];

    for (int i = 1; i < coins.size(); i++)
        for (int j = 0; j <= sum; j++)
            if (coins[i] <= j)
                dp[j] = min(1 + dp[j - coins[i]], dp[j]);

    return dp[sum];
}

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << solve(coins, sum) << endl;
}

/*

4 11
1
5
6
8

*/

/*

2

*/
