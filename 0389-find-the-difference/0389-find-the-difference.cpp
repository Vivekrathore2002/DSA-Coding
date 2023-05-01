class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq_s[26] ={0};
        int freq_t[26] = {0};
        for(char c : s) freq_s[c-'a']++;
        for(char c : t) if(++freq_t[c-'a']>freq_s[c-'a']) return c;
        return 'a';


    }
};