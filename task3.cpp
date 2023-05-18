#include <iostream>
#include <vector>

using namespace std;


int u[31];


int main() {
    vector<int> values;
    int n;

    u[0] = 1;
    u[2] = 3;

    for (n = 4; n <= 30; n += 2) {

        u[n] = 4 * u[n - 2] - u[n - 4];
    }


    while (true) {
        cin >> n;
        if (n == -1)
            break;

        values.push_back(n);
    }

    for (int i: values) {
        cout << u[i] << endl;
    }


    return 0;

}