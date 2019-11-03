#include <iostream>
#include <deque> 
using namespace std;
#pragma GCC optimize ("Ofast")

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

void printKMax(int arr[], int n, int k){
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.back() < arr[i])
            dq.pop_back();
        dq.push_back(arr[i]);
        if (i >= k && dq.front() == arr[i - k]) dq.pop_front(); 
        if (i >= k - 1) cout << dq.front() << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}


