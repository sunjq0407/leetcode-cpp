class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int tmp = 1;
        for (int i=1; i<nums.size(); i++)
            result[i] = result[i-1] * nums[i-1];
        for (int i=nums.size()-2; i>=0; i--) {
            tmp *= nums[i+1];
            result[i] *= tmp;
        }
        return result;
    }
};