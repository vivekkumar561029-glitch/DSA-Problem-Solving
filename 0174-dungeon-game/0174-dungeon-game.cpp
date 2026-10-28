class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1) {
                    continue;
                }

                int right = INT_MAX;
                int down = INT_MAX;

                if (j + 1 < m) {
                    right = dp[i][j + 1];
                }

                if (i + 1 < n) {
                    down = dp[i + 1][j];
                }

                int need = min(right, down) - dungeon[i][j];

                dp[i][j] = max(1, need);
            }
        }

        return dp[0][0];
    }
};