class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal==s){
            return true;
        }
        queue <char> q1,q2;

        for(int i=0;i<s.length();i++){
            q1.push(s[i]);
        }
        for(int i=0;i<goal.length();i++){
            q2.push(goal[i]);
        }
        int k=goal.size();
        while(k!=0){
            char q=q2.front();
            q2.pop();
            q2.push(q);

            if(q1==q2){
                return true;
                
            }
            k--;
        }
      return false;
    }
};