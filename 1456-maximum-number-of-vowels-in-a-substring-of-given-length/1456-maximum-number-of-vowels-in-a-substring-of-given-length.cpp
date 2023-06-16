// https://www.youtube.com/watch?v=_imS-_8Z_7A&ab_channel=TechAdorabyNivedita
class Solution {
public:
    int maxVowels(string s, int k) {
        int maxCount = 0, count = 0;
        unordered_set<char>vowels = {'a','e','i','o','u'};
        for(int i = 0; i<s.size(); i++)
        {
            if(i>=k && vowels.count(s[i-k]))
            {
                count--;
            }
            if(vowels.count(s[i]))
            {
                count++;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};