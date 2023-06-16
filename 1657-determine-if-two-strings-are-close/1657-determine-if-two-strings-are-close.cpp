// https://www.youtube.com/watch?v=rPR6DxPE2K4&ab_channel=TechAdorabyNivedita

// if the lengths aren't equal then return false
//first we found out that what is the actual frquency of the each element here then we will compare
//For example if in word1 a = 1,b=3,c=2 and in word2 the frequency is like a = 2,b=1,c=3
//Then we can replace each elements with further more elements.
class Solution {
public:
    bool closeStrings(string word1, string word2) {
      vector<int>s1(26,0),s2(26,0),s3(26,0),s4(26,0);
      for(auto x:word1)
      {
          s1[x-'a']++;
          s3[x-'a'] = 1;
      }
      for(auto x:word2)
      {
          s2[x-'a']++;
          s4[x-'a'] = 1;
      }
     sort(s1.begin(),s1.end());
     sort(s2.begin(),s2.end());
     return s1 == s2 && s3 == s4;
    
    }
};