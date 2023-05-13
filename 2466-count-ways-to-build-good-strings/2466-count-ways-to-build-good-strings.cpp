class Solution {
public:
    int mo = 1e9+7;
    int dp[100001];
    // int f(string &s,int &high,int &low,string &s1,string &s2){
    //     if(s.length() > high){
    //         return 0;
    //     }
    //     if(dp[s.length()] != -1)return dp[s.length()];
    //     if(s.length() >= low){  
    //         string s11 = s + s1;
    //         string s12 = s + s2;
    //         int temp1 = f(s11,high,low,s1,s2) % mo;
    //         int temp2 = f(s12,high,low,s1,s2) % mo;
    //         return dp[s.length()] = (1 + temp1 + temp2) % mo;
    //     }
    //     else{
    //         string s11 = s + s1;
    //         string s12 = s + s2;
    //         int temp1 = f(s11,high,low,s1,s2) % mo;
    //         int temp2 = f(s12,high,low,s1,s2) % mo;
    //         return dp[s.length()] = (temp1 + temp2) % mo;
    //     }
    // }

    int f(int &s,int &s1,int &s2,int &high,int &low){
        // cout << s << " " << high << endl;
        if(s > high)return 0;
        if(dp[s] != -1)return dp[s];
        int n1 = s + s1;
        int n2 = s + s2;
        if(s >= low){
            
            return dp[s] = (1 + ((f(n1,s1,s2,high,low) + f(n2,s1,s2,high,low)) % mo)) % mo;
        }
        else{
            return dp[s] = (f(n1,s1,s2,high,low) + f(n2,s1,s2,high,low)) % mo;
        }
    }


    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        int s1 = zero;
        int s2 = one;
        int s = 0;
        return f(s,s1,s2,high,low);
    }
};