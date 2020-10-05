#include "bits/stdc++.h"
using namespace std;

int main() {
    int m, n;
    string a, b;

    cin >> a >> b;

    m = a.length();
    n = b.length();

    vector<vector<int> > dp;
    dp.resize(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
        dp[0][i] = i;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }

    cout << dp[m][n] << endl;

    return 0;
}

/*

abbc xbbacd

*/

/*

3

*/
