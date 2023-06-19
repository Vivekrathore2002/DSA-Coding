class StockSpanner {
public:
   vector<int>v1;
    vector<int>v2;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v1.push_back(price);
        int n=v1.size()-1;
        if(n==0){v2.push_back(1);return 1;}
        int count=0;
        int temp=v1[n];
       
        for(int i=n;i>=0;i--){
            if(i>0 and temp<v1[i-1]){break;}
            else if(i>0){
                count+=v2[i-1];
                i=i-v2[i-1]+1;
             
            }   
            
        }
        count+=1;
        v2.push_back(count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */