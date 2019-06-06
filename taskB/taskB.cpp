#include <iostream>
#include <array>
#include <vector>
#include <utility>

using namespace std;


int main() {

    int n;
    cin >> n;

    array<long long, 101> p;
    p[0] = 1;

    for (int i = 1; i < 101; ++i) {
        p[i] = p[i-1] * 2 % 1000000007;
    }

    vector<long long> d;
    d.reserve(n);

    for (int i = 0; i < n; ++i) {

        long long temp;
        cin >> temp;
        d.push_back(temp);
    }


    vector<pair<long long, int>> counts(n);
    counts[0] = {1,1};


    for (int i = 1; i < n; ++i) {

        counts[i].first = (counts[i-1].first + counts[i-1].second) % 1000000007 * p[d[i]] % 1000000007 ; 
        counts[i].second = counts[i-1].first ; 
    }

    long long result = (counts[n-1].first + counts[n-1].second) % 1000000007 ;


    cout << result << endl;



    return 0;
}