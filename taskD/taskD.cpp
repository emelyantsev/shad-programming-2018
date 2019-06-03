#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	size_t n;
	cin >> n;

	vector<int> a;
    a.reserve(n);

	for (size_t i = 0; i < n; ++i) {
		
        int temp;
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	deque<long long> dq(a.begin(), a.end());

	long long result = 0;

	while (dq.size() > 2) {

		size_t nq = dq.size();
		long long x = dq[0] + dq[nq - 2];

		result = result + x;

		long long last = dq[nq - 1];

		dq.pop_front();
		dq.pop_back();
		dq.pop_back();

		if (last > x) {

			dq.push_back(x);
			dq.push_back(last);
		}
		else {

			dq.push_back(last);
			dq.push_back(x);
		}
	}

	while (dq.size() > 0) {

		result = result + dq[0];
		dq.pop_front();
	}

	cout << result << endl;

    return 0;
}

