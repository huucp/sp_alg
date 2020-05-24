class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = 0;
        int pre = -1;
        int i = 0;
        for (int v : nums) {
            if (i >0 && v == 1 && len < k) return false;
            if (v == 0) len++;
            else  len = 0;
            pre = v;
            i++;
        }
        return true;
    }
};