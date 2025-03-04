class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // Found a triplet with zero sum
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicate elements for j
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }

                    // Skip duplicate elements for k
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }

                    // Move the pointers
                    j++;
                    k--;
                } else if (sum < 0) {
                    // Sum is less than zero, increment j to increase the sum
                    j++;
                } else {
                    // Sum is greater than zero, decrement k to decrease the sum
                    k--;
                }
            }
        }
        return ans;
    }
};
