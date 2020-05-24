bool vowel(char c) {
    return c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i';
}
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        if (k > n) return 0;
        int i = 0;
        int cnt = 0;
        for ( ; i < k; i++)
            if (vowel(s[i])) cnt++;
        int ret = cnt;
        for ( ; i < n; i++) {
            if (vowel(s[i])) cnt++;
            if (vowel(s[i - k])) cnt--;
            if (cnt > ret) ret = cnt;
        }
        return ret;
    }
};