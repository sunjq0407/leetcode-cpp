class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset;
        for (auto& i: nums) {
            if(myset.find(i)!=myset.end()) return true;
            myset.insert(i);
        }
        return false;
    }
};