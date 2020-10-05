#include "bits/stdc++.h"
using namespace std;

string a, b;
int m, n;
int lcs_size;

vector<vector<int> > dp;
vector<vector<int> > trace;
vector<char> s;

void backtrack(int x, int y) {
    if (s.size() == lcs_size) {
        for (auto p = s.rbegin(); p != s.rend(); p++)
            cout << *p;

        cout << endl;
        return;
    }
    if (trace[x][y] == 1) {
        s.push_back(a.at(x - 1));
        backtrack(x - 1, y - 1);
        s.pop_back();
    } else {
        if (dp[x - 1][y] == dp[x][y])
            backtrack(x - 1, y);
        if (dp[x][y - 1] == dp[x][y])
            backtrack(x, y - 1);
    }
}

int main() {
    cin >> a >> b;
    m = a.length();
    n = b.length();

    dp.resize(m + 1, vector<int>(n + 1, 0));
    trace.resize(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                trace[i][j] = 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    lcs_size = dp[m][n];

    cout << lcs_size << endl;

    backtrack(m, n);

    return 0;
}

/*

ABCVDEFGH BQDRCVEFGH

*/

/*

7
BCVEFGH

*/

/*

BDCABA ABCBDAB

*/

/*

4
BDAB
BCAB
BCBA

*/
