#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		auto i = nums.begin();
		if (i == nums.end()) return 0;
		auto j = next(i, 1);
		while (j != nums.end()) {
			if (*j != *i) {
				i++;
				*i = *j;
			}
			j++;
		}
		return i - nums.begin() + 1;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution s;
	s.removeDuplicates(nums);
	for (auto it = nums.begin(); it != nums.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
