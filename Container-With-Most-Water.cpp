class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int newMax = 0;

        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int contain = minHeight * (right - left); 
            newMax = max(contain, newMax);

            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return newMax;
    }
};
