class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count=0;
        int mx=INT_MIN;
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]=='('){
                st.push(s[i]);
                count++;
                mx=max(mx,count);
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                    count--;
                }
                else{
                    return -1;
                }
            }
            i++;
        }
        if(mx>0)
        return mx;
        else
        return 0;
    }
};