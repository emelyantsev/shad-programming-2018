#include <iostream>
#include <map>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int, int> q;

    for (int i = 0; i < n; ++i) {

        int a;
        cin >> a;

        ++q[a];
    }

    int result = -1;
    int result_max = 0;

    for (const auto& p : q) {

        if (p.second >= result_max ) {

            result_max = p.second;
            result = p.first;
        }

    }


    cout << result << endl;


    return 0;
}