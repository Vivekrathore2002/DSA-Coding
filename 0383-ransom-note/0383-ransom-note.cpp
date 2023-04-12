class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[26]={0};
        for(auto i:magazine){
            counter[i-'a']++;
        }
        for(auto i:ransomNote){
            if(counter[i-'a']<=0){
                return false;
            }
            counter[i-'a']--;
        }
        return true;
    }
};