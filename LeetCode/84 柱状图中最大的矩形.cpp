class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> min_left_index(heights.size());
        vector<int> min_right_index(heights.size());

        min_left_index[0]= -1;
        for(int i=1;i<heights.size();i++){
            int temp =i-1;
            while(temp >= 0 && heights[temp] >= heights[i]){
                temp = min_left_index[temp];
            }
            min_left_index[i] = temp;
        }
        min_right_index[heights.size()-1] = heights.size();
        for(int i =heights.size()-2; i>=0;i--){
            int temp =i+1;
            while(temp < heights.size() && heights[temp] >= heights[i]){
                temp = min_right_index[temp];
            }
            min_right_index[i] = temp;
        }
        int ans = 0;
        for(int i=0;i < heights.size();i++){
            int sum = heights[i] * (min_right_index[i] - min_left_index[i] -1);
            ans = max(sum, ans);
        }
        return ans;
    }
};