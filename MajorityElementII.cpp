class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        map<int, int> mymap;
        map<int, int>::iterator it;
        for(int i:nums) {
            if(!mymap.count(i)) mymap[i] = 1;
            else mymap[i]++;
        }
        for(it=mymap.begin();it!=mymap.end();it++) {
            if(it->second>nums.size()/3) result.push_back(it->first);
            if(result.size()>=2) break;
        }
        return result;
    }
};