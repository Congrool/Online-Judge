class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m,n;
        if((m = matrix.size()) == 0)  return false;
        if((n = matrix[0].size()) == 0) return false;
        int px = m-1,py = 0;
        while(px >= 0 && py < n){
            if(matrix[px][py] > target) --px; 
            else if(matrix[px][py] < target) ++py;
            else if(matrix[px][py] == target) return true;
        }
        return false;
    }
};
//不知道为什么，循环中的if条件的顺序对效率影响很大
//估计是处理器乱序引擎和预先取指的问题，但是我还是先不太通为什么
//预先取指默认向后跳转，即取while判断
//难道是数据中--px的情况比较多吗