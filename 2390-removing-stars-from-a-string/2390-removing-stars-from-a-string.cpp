//Simple solution
// class Solution {
// public:
//     string removeStars(string s) {
//         string ans = "";
//         for(int i =0;i<s.size();i++){
//             if(s[i]=='*'){
//                 if(ans.size()>0){
//                     ans.pop_back();
//                 }
//             }
//             else{
//                 ans.push_back(s[i]);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};