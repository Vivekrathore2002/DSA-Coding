class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // //using the spiral code for the 2nd time (totally 3 times)
        // //previously in search in 2d matric I we used thiss  same method to find out and in spiral also we did the same with the time complexity of only O(N*M) which is lowest to bare minimum traversal
        // // Basically this below code is a simple copy paste of spiral matrix code with few changes only
        // //but as level 1 problem was,this too have O(N*M) but binary search was only O(Log(N*M))
        // //Lets see another solution after this one
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


        //2nd solution by love babbar with less complexity
        //Here lets start from the matrix[0][col or last] so that if a element is greater than the target value there,the whole column will not contain the target or else if the element is the shorter than the target then the target will not be in the same row so increase the rowIndex
        //lets start the code approch
        int row=matrix.size();
        int col=matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1;//maximum last index of the row 0
        while(rowIndex<row && colIndex>=0){
            int element = matrix[rowIndex][colIndex];
            if(element==target){
                return 1;
            }
            else if(element<target){
                rowIndex++;//Since the target will not be there in the whole row 
            }
            else if(element>target){
                //here lower the colIndex bcoz the element is larger and target can be there in the last column
                colIndex--;
            }
        }
        return 0; //Return false if the element is not there in the matrix
    }
};