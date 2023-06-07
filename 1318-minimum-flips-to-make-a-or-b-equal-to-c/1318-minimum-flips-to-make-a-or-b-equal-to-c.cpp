// https://www.youtube.com/watch?v=b8jx7KpjLZk&ab_channel=TechAdorabyNivedita
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x,y,z,count=0;
        for(int i=0;i<32;i++){
            x=a&(1<<i);
            y=b&(1<<i);
            z=c&(1<<i);
            if(z==0 && x==0 && y!=0){
                count+=1;
            }
            else if((z!=0 && x==0 && y==0)){
                count+=1;
            }
            else if(z==0 && x!=0 && y==0){
                count+=1;
            }
            else if(z==0 && x!=0 && y!=0){
                count+=2;
            }
        }
        return count;
    }
};