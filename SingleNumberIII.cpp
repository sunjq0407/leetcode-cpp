class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0, a = 0, b = 0;
        for(int i=0;i<n;i++) res ^= nums[i];
        int cmp=res&(res-1)^res;
        for(int i=0;i<n;i++){
            if(cmp & nums[i]) a ^= nums[i];
            else b ^= nums[i];
        }
        return vector<int>{a,b};
    }
};