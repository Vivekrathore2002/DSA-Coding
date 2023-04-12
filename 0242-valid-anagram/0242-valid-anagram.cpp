class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int counter[26]={0};
        for(auto i:s){
            counter[i-'a']++;
        }
        for(auto i:t){
            if(counter[i-'a']<=0){
                return false;
            }
            counter[i-'a']--;
        }
        return true;
    }
};