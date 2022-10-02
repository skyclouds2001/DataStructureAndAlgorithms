class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m;
		vector<int> v;
			
		for(int i = 0; i < nums.size(); ++i) {
			map<int, int>::iterator it = m.find(target - nums[i]);
			if(it != m.end()) {
				v.push_back(it->second);
				v.push_back(i);
				break;
			}
			map.insert(pair<int, int>(nums[i], i));
		}
		
		return v;
    }
};
