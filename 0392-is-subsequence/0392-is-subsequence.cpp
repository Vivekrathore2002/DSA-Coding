class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        int sPtr = 0;
        int tPtr = 0;
        
        while (sPtr < sLen && tPtr < tLen) {
            if (s[sPtr] == t[tPtr]) {
                sPtr++;
            }
            tPtr++;
        }
        
        return sPtr == sLen;
    }
};
