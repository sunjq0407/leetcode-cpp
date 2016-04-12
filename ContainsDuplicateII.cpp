class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mymap;
        for(int i=0; i<nums.size(); i++) {
            if(mymap.find(nums[i])==mymap.end()) mymap[nums[i]]=i;
            else if(i-mymap[nums[i]]<=k) return true;
            else mymap[nums[i]]=i;
        }
        return false;
    }
};