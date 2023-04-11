class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // //Basically this below code is a simple copy paste of spiral matrix code with few changes only
        // int row=matrix.size();
        // int col=matrix[0].size();
        // bool flag=false;
        // int count=0;
        // int total=row*col;
        // int startingRow=0;
        // int startingCol=0;
        // int endingRow=row-1;
        // int endingCol=col-1;
        // while(count<total){
        //     //print the starting row here
        //     for(int index=startingCol;count<total && index<=endingCol;index++){
        //         if(matrix[startingRow][index]==target){
        //             // flag==true;
        //             // return flag;
        //             return true;
        //         }
        //         count++;
        //     }
        //     startingRow++;
        //     //print the ending col
        //     for(int index=startingRow;count<total && index<=endingRow;index++){
        //         if(matrix[index][endingCol]==target){
        //             // flag==true;
        //             // return flag;
        //             return true;
        //         }
        //         count++;
        //     }
        //     endingCol--;
        //     //now for ending row
        //     for(int index=endingCol;count<total && index>=startingCol;index--){
        //         if(matrix[endingRow][index]==target){
        //             // flag==true;
        //             // return flag;
        //             return true;
        //         }
        //         count++;
        //     }
        //     endingRow--;
        //     //to print starting col
        //     for(int index=endingRow;count<total && index>=startingRow;index--){
        //         if(matrix[index][startingCol]==target){
        //             return true;
        //         }
        //         count++;
        //     }
        //     startingCol++;
        // }
        // return false;
        


        //2nd method given by love babbar
        //Use binary search to find the answer
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0;
        int end=row*col-1;
        int mid=(start+(end-start)/2);  
        while(start<=end){
            //to find the element in the array

            int element = matrix[mid/col][mid%col];
            if(element==target){
                return 1;
            }
            else if(element<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=(start+(end-start)/2);
        }
        return 0;
    }
};