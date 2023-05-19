//With the help of chatgpt and code with alisha
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> Set;
        int maxLength = 0;
        int start = 0;
        int end = 0;
        
        while (end < s.size()) {
            // Check if the current element is in the set
            auto it = Set.find(s[end]);
            if (it == Set.end()) {
                // If the element is not in the set, add it and update maxLength if needed
                Set.insert(s[end]);
                maxLength = max(maxLength, end - start + 1);
                end++;
            } else {
                // If the element is already in the set, remove elements from the set and move start pointer
                Set.erase(s[start]);
                start++;
            }
        }
        
        return maxLength;
    }
};
