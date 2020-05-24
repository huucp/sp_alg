class Solution {
public:
    int isPrefixOfWord(string sen, string w) {
        bool preSpace = true;
        int j = 0;
        int cnt = 0;
        int start = 0;
        for (int i = 0; i < sen.length(); i++) {
            if (preSpace == true) {
                cnt++;
                start = i;
            }

            if (sen[i] == w[j]) j++;
                else j = 0;

            if (j == w.length() && i - j + 1 == start) return cnt;

            if (sen[i] == ' ') {
                preSpace = true;
            } else preSpace = false;
        }
        return -1;
    }
};