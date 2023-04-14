class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(ch == ')' && top == '(' || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                        st.pop();
                        }
                        else{
                            return false;
                        }
                }
                    else
                    {
                        //stack is empty
                        return false;
                    }
                }
            }
            //in the end if the stack is empty and no input element is left then return true
            if(st.empty()){
                return true;
            }
            else{
                return false;
            }
        }
};