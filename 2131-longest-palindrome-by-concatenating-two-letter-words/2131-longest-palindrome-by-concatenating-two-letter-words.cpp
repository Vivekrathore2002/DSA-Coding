class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        for(auto x: words)
             m[x]++;
bool flg=false;
int ans=0;

for(auto i: m){

string res=i.first;
reverse(res.begin(),res.end());

// checking the string res is palindrome itself or not for example "xx"
if(res==i.first && i.second%2!=0 && flg==false){
    flg=true;
    ans+=2;
    m[res]--;
}
if(m.find(i.first)!=m.end() && m.find(res)!=m.end()){

    if(i.first != res){
    ans+=min(m[i.first],m[res])*4;
    m[i.first]=m[res]=0;
}
else {
    ans+=m[res]/2*2*2;
m[i.first]=m[res]=0;
      }
  } 
}
  return ans;           
    }
};