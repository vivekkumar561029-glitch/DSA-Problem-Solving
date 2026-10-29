class Solution {
public:
    int f(int i, int j, string &s1, string &s2,
          vector<vector<int>>& dp) {

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = max(
            f(i - 1, j, s1, s2, dp),
            f(i, j - 1, s1, s2, dp)
        );
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int lcs = f(n - 1, m - 1, word1, word2, dp);

        return n + m - 2 * lcs;
    }
};