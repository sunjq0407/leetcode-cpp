class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy = nums;
        vector<int> result;
        sort(copy.begin(), copy.end());
        int left = 0, right = copy.size()-1, num1 = 0, num2 = 0;
        while (left<right) {
            int sum = copy[left]+copy[right];
            if(sum==target) {
                num1 = copy[left];
                num2 = copy[right];
                break;
            }
            else if(sum<target) left++;
            else right--;
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==num1||nums[i]==num2) result.push_back(i+1);
            if(result.size()==2) break;
        }
        return result;
    }
};