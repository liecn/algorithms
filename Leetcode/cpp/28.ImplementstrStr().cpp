class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (!n) return 0;
        vector<int> lps = kmpProcess(needle);
        int i = 0, j = 0;
        while (1) {
            while (i < m &&j<n && haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) return i - j;
            else if (i == m) return -1;
            else j ? j = lps[j - 1] : i++;
        }
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
