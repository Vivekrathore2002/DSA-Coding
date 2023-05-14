class Solution {
public:
string addstring(string& s1,string& s2,int i,int j,int& c,string& ans){
        if(c==0&&i<0&&j<0){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        if(i>=0){
            c+=s1[i]-'0';
            i--;
        }
        if(j>=0){
            c+=s2[j]-'0';
            j--;
        }
        ans+=char(c%10+'0');
        c=c/10;
        return addstring(s1,s2,i,j,c,ans);
    }
   string addStrings(string num1, string num2) {
        int c=0,i=num1.length()-1,j=num2.length()-1;
        string ans="";
       return addstring(num1,num2,i,j,c,ans);
       
    }
};