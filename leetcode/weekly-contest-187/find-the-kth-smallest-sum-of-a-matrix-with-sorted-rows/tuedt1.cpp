class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int m = a.size();
        int n = a[0].size();
        vector<int> b(a[0]);
        for (int i = 1; i < m; i++) {
            int nn = b.size();
            for (int t = 0; t < nn; t++) {
                for (int j = 1; j < n; j++){
                    b.push_back(b[t] + a[i][j]);
                }
                b[t] += a[i][0];
            }
            sort(b.begin(), b.end());
            while (b.size() > k) b.pop_back();
        }
        return b.back();
    }
};