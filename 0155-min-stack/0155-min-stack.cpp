class MinStack {
public:

vector<pair<int,int>> arr;
    MinStack() {

    }
    
    void push(int val) {
        if(arr.empty()){
            arr.push_back({val,val});
        }else{
            arr.push_back({val,min(val,arr.back().second)});
        }
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};