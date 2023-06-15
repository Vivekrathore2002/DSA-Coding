// https://www.youtube.com/watch?v=Wdjr6uoZ0e0&t=3982s&ab_channel=CodeHelp-byBabbar
class Solution {
public:
    int compress(vector<char>& chars) {
    //Love babbar solution
    int i=0;
    int ansIndex = 0;
    int n=chars.size();
    while(i<n)
    {
        int j=i+1;
        while(j<n && chars[i] == chars[j]){
            j++;
        }
        //yaha kan aaoge 
        //ya to vector poora traverse krdia ya fer different char aaya h
        //oldChar store karlo
        chars[ansIndex++]=chars[i];
        int count=j-i;
        if(count>1){
            //converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for(char ch:cnt){
                chars[ansIndex++] = ch;
            }
        }
            i=j;
        }
        return ansIndex;
    }

}; 