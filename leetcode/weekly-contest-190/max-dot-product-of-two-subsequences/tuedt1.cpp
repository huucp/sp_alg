const int oo = 2e9;
class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        vector<vector<int>> l(m, vector<int>(n, 0));
        int singleMax = -oo;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int single = a[i] * b[j];
                int tmp = single + ((i > 0 && j > 0) ? l[i - 1][j - 1] : 0);
                singleMax = max(singleMax, single);
                l[i][j] = max(l[i][j], tmp);
                if (i > 0) l[i][j] = max(l[i][j], l[i - 1][j]);
                if (j > 0) l[i][j] = max(l[i][j], l[i][j - 1]);
            }
        int ret = l[m - 1][n - 1];
        if (ret == 0) ret = singleMax;
        return ret;
    }
};