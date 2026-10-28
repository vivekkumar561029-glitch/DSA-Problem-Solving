class Solution {
public:
    int f(int i, int j, int n, int m,
          vector<vector<int>>& dungeon,
          vector<vector<int>>& dp) {

        if (i >= n || j >= m) {
            return INT_MAX;
        }

        if (i == n - 1 && j == m - 1) {
            if (dungeon[i][j] < 0) {
                return abs(dungeon[i][j]) + 1;
            }
            else {
                return 1;
            }
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = f(i, j + 1, n, m, dungeon, dp);
        int down = f(i + 1, j, n, m, dungeon, dp);

        int res = min(right, down) - dungeon[i][j];

        if (res <= 1) {
            return dp[i][j] = 1;
        }
        else {
            return dp[i][j] = res;
        }
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, n, m, dungeon, dp);
    }
};