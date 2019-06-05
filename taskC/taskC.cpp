
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;


map<int, int> Factorize(int n, const vector<int>& VectorOfPrimeNumbers, const set<int>& SetOfPrimeNumbers) {

	map<int, int> result;

	if (SetOfPrimeNumbers.count(n)) {
		result[n] = 1;
		return result;
	}


	int i = 0;
	int d = VectorOfPrimeNumbers[i];


	while (d*d <= n) {

		if (n % d == 0) {

			if (result.count(d)) {
				result[d] +=1;
			}
			else {
				result[d] = 1;
			}
		n /=d;
		}
		else {
			++i;
			d = VectorOfPrimeNumbers[i];
		}
	}

	if (n > 1) {

		if (result.count(n)) {
			result[n] +=1;
			}
		else {
			result[n] = 1;
		}

	}


	return result;
}

int main() {

	int k, n;

	cin >> k >> n;

	k = min(k, n-k);


	if (k == 0 || n == 1) {
		cout << 1 << endl;
		exit(0);
	}


	vector<bool> PrimeDivisors(n+1, true);

	for (int i = 2; i <= n; ) {

			int k, j;
	        for (k = 2, j = k * i; j <= n;  j = k * i)
	        {
                if (PrimeDivisors[j]) {

                	PrimeDivisors[j] = false;
                }
	            k++;
	        }

	        i++;

	        while ((!PrimeDivisors[i]) && (i <= n) )
	        {
	            i++;
	        }
	 }


	vector<int> VectorOfPrimeNumbers;
	set<int> SetOfPrimeNumbers;

	 for (int i = 2; i <= n; i++)
	 {
	    if (PrimeDivisors[i])
	        {
	    	VectorOfPrimeNumbers.push_back(i);
	    	SetOfPrimeNumbers.insert(i);
	        }
	 }


/*
	for (const auto& item : SetOfPrimeNumbers) {
		cout << item << ' ';

	}
	cout << endl;
*/


	map<int, int> Divisors;

	for (int i = n-k+1; i <= n; ++i) {

		map<int, int> temp = Factorize(i, VectorOfPrimeNumbers, SetOfPrimeNumbers);

		for (const auto& item : temp) {

			int number = item.first;
			int q_number = item.second;

			if (Divisors.count(number)) {
				Divisors[number] += q_number;
			}
			else {
				Divisors[number] = q_number;
			}
		}
	}


	for (int i = 2; i <= k; ++i) {

		map<int, int> temp = Factorize(i, VectorOfPrimeNumbers, SetOfPrimeNumbers);

		for (const auto& item : temp) {

					int number = item.first;
					int q_number = item.second;

					if (Divisors.count(number)) {
						Divisors[number] -= q_number;
					}
		}
	}





	long long ans = 1;

	for (const auto& item : Divisors) {
		
		// std::cout << item.first << ": " << item.second << endl; 


        int q_number = item.second;

		for (int i = 0; i < item.second - 1 ; ++i) {

			ans = (ans * item.first ) % 1000000007 ;
			
		}

		if (item.second > 0) {
			ans = ans * (item.first - 1) ;
		}
		
	}

	cout << ans << endl;

	return 0;
}
