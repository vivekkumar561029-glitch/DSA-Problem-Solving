// class Solution {
// public:
//     int f(vector<int>& nums, int idx, int prev) {

//         if (idx == nums.size()) {
//             return 0;
//         }

//         int skip = f(nums, idx + 1, prev);

//         int take = 0;

//         if (prev == -1 || nums[idx] > nums[prev]) {
//             take = 1 + f(nums, idx + 1, idx);
//         }

//         return max(take, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         return f(nums, 0, -1);
//     }
// };














class Solution {
public:
    int f(vector<int>& nums, int idx, int prev,
          vector<vector<int>>& dp) {

        if (idx == nums.size()) {
            return 0;
        }

        if (dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

       
        int skip = f(nums, idx + 1, prev, dp);

        int take = 0;

        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + f(nums, idx + 1, idx, dp);
        }

        return dp[idx][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(nums, 0, -1, dp);
    }
};