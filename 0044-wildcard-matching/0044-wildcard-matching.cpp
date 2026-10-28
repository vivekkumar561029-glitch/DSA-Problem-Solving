class Solution {
public:
    bool helper(int i, int j, string &s, string &p,
                vector<vector<int>>& dp) {

        if (i < 0 && j < 0) return true;

        if (j < 0) return false;

        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*') {
            return dp[i][j] = (
                helper(i, j - 1, s, p, dp) ||
                helper(i - 1, j, s, p, dp)
            );
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int i = s.size() - 1;
        int j = p.size() - 1;

        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));

        return helper(i, j, s, p, dp);
    }
};