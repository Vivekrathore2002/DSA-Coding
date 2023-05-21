// https://www.youtube.com/watch?v=aO9eAw1wKvE&ab_channel=CodewithAlisha
// basically what we are doing is finding the area of the rectangle formed by start and end
// here end or start,One will be less than from another
// which will cause the area 

// Since here height[start]>height[end] where start index is 1 and element is 8,,,End index is 8 and end element is 7
// so min is 7 and also length between them or the difference is also 7 
// end-start=7 here
// so the area is 49

// we will also declare one maxArea which will check each iteration
// such as,,
// if the start will be minimum then start++
// end will be minimum then end-- so that we can maximise the area;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int area;
        int maxArea=0;
        while(start<end)
        {
            area=min(height[start],height[end])*(end-start);
            if(maxArea<area)maxArea=area;
            if(min(height[start],height[end])==height[start]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxArea;
    }
};