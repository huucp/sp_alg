class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ret = 0;
        deque<int> mind, maxd;
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            while (!mind.empty() && nums[mind.back()] >= nums[i]) mind.pop_back();
            while (!maxd.empty() && nums[maxd.back()] <= nums[i]) maxd.pop_back();
            mind.push_back(i);
            maxd.push_back(i);
            while (!mind.empty() && nums[i] - nums[mind.front()] > limit) {
                j = max(j, mind.front());
                mind.pop_front();
            }
            while (!maxd.empty() && nums[maxd.front()] - nums[i] > limit) {
                j = max(j, maxd.front());
                maxd.pop_front();
            }
            if (i - j> ret) ret = i - j;
        }
        return ret;
    }
};