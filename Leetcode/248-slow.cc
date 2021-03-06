#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
	vector<string> findStrobogrammatic(int n) {
		if (n == 1) return {"0", "1", "8"};
		vector<string> ans{"1", "6", "8", "9"};
		for (int i = 1; i < n / 2; i++) {
			int l = ans.size();
			for (int j = 0; j < l; j++) {
				ans.push_back(ans[j] + "1");
				ans.push_back(ans[j] + "6");
				ans.push_back(ans[j] + "8");
				ans.push_back(ans[j] + "9");
				ans[j].push_back('0');
			}
		}
		if (n % 2 == 1) {
			int l = ans.size();
			for (int i = 0; i < l; i++) {
				ans.push_back(ans[i] + "1");
				ans.push_back(ans[i] + "8");
				ans[i].push_back('0');
			}
		}
		vector<string> pans(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			for (int j = n / 2 - 1; j >= 0; j--)
				if (ans[i][j] == '0' || ans[i][j] == '1' || ans[i][j] == '8') {
					pans[i].push_back(ans[i][j]);
				} else if (ans[i][j] == '6') {
					pans[i].push_back('9');
				} else if (ans[i][j] == '9') {
					pans[i].push_back('6');
				}
		}
		for (int i = 0; i < ans.size(); i++) ans[i] = ans[i] + pans[i];
		return ans;
    }

    int strobogrammaticInRange(string low, string high) {
		vector<string> tot;
		for (int i = low.length(); i <= high.length(); i++) {
			auto ans = findStrobogrammatic(i);
			tot.insert(tot.end(), ans.begin(), ans.end());
		}
		int ans = 0; 
		for (string s : tot) if ((s.length() > low.length() || (s.length() == low.length() && (s.compare(low) >= 0))) &&
								 (s.length() < high.length() || (s.length() == high.length() && (s.compare(high) <= 0)))) {
			ans++;
			//cout << s << " " << s.compare(low) << " " << s.compare(high) << endl;
		}
		return ans;
    }
};

int main () {
	Solution s;
	cout << s.strobogrammaticInRange("50", "100") << endl;
	return 0;
}

