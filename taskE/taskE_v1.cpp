#include <iostream>
#include <vector>
#include <string>

using namespace std;

class labyrinth {

public:

    labyrinth(istream& ss) {

        ss >> n >> m;
        data.reserve(2*n+1);

        for (int i = 0; i < 2*n+1; ++i) {

            string temp;
            ss >> temp;
            data.push_back(move(temp));
        }
    }


    friend ostream& operator << (ostream& os, const labyrinth& l) {

        for (int i = 0; i < l.n*2+1; ++i) {
            os << l.data[i] << endl;
        }

        return os;
    }

    void sow(int i, int j) {

        data[2*i+1][2*j+1] = 'x';

        vector<pair<int, int>> sowed;
        sowed.reserve(4);

        if (i-1 >= 0) {

            if (data[2*i][2*j+1] == '.' && data[2*(i-1)+1][2*j+1] != 'x' ) {
                sowed.push_back({i-1,j});
                }
        }

        if (i+1 <= n-1) {

            if (data[2*i+2][2*j+1] == '.' && data[2*(i+1)+1][2*j+1] != 'x' ) {
                sowed.push_back({i+1,j});
                }
        }


        if (j-1 >= 0) {

            if (data[2*i+1][2*j] == '.' && data[2*i+1][2*(j-1)+1] != 'x' ) {
                sowed.push_back({i,j-1});
                }
        }

        if (j+1 <= m-1) {

            if (data[2*i+1][2*j+2] == '.' && data[2*i+1][2*(j+1)+1] != 'x' ) {
                sowed.push_back({i,j+1});
                }
        }


        for (const auto& s : sowed) {
            sow(s.first, s.second);
        }

    }



    void remove_walls() {

        sow(0,0);

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {

                
                
                if (data[2*i+1][2*j+1] != 'x' && i-1 >= 0) {

                    if (data[2*i][2*j+1] == '-' && data[2*(i-1)+1][2*j+1] == 'x' ) {
                            data[2*i][2*j+1] = '.';
                            sow(i,j);
                        }
                    }


                if (data[2*i+1][2*j+1] != 'x' && i+1 <= n-1) {

                    if (data[2*i+2][2*j+1] == '-' && data[2*(i+1)+1][2*j+1] == 'x' ) {
                            data[2*i+2][2*j+1] = '.';
                            sow(i,j);
                    }
                    }


        if (data[2*i+1][2*j+1] != 'x' && j-1 >= 0) {

            if (data[2*i+1][2*j] == '|' && data[2*i+1][2*(j-1)+1] == 'x' ) {

                data[2*i+1][2*j] = '.';
                    sow(i,j);
                }
        }

        if (data[2*i+1][2*j+1] != 'x' && j+1 <= m-1) {

            if (data[2*i+1][2*j+2] == '|' && data[2*i+1][2*(j+1)+1] == 'x' ) {
                
                    data[2*i+1][2*j+2] = '.';
                    sow(i,j);
                }
        }

        }
              
        }

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                 data[2*i+1][2*j+1] = '.';   
            }
        }


}








private:

    vector<string> data;
    int n, m;


};


int main() {

    labyrinth l(cin);

  //  cout << l << endl;

    //l.sow(0,0);

    l.remove_walls();

    cout << l ;

    return 0;
}