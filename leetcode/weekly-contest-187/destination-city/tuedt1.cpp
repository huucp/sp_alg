class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> m;
        for (vector<string> path : paths) {
            string u = path[0];
            string v = path[1];
            m[u] = 1;
            auto it = m.find(v);
            if (it == m.end()) m[v] = 0;
        }
        string ret;
        for (auto& ele : m) {
            if (ele.second == 0)
                ret = ele.first;
        }
        return ret;
    }
};