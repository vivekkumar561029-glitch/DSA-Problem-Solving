class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> a;

        for (int i = 1; i <= k; i++)
            a.push_back(i);

        while (true) {
            ans.push_back(a);

            int i = k - 1;

            while (i >= 0 && a[i] == n - k + i + 1)
                i--;

            if (i < 0)
                break;

            a[i]++;

            for (int j = i + 1; j < k; j++)
                a[j] = a[j - 1] + 1;
        }

        return ans;
    }
};