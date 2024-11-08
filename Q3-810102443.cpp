#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int getCandies(vector<int>& candiesOfColleges, vector<int>& colleges, int& n, int idx = 0) {

    if (idx == n - 1) return 0;
    if (colleges[idx] != -1) return colleges[idx];
    int candy = abs(candiesOfColleges[idx+1] - candiesOfColleges[idx]) +
            getCandies(candiesOfColleges, colleges, n, idx + 1);
    if (idx + 2 < n)
        candy = min(abs(candiesOfColleges[idx+2] - candiesOfColleges[idx]) +
                getCandies(candiesOfColleges, colleges, n, idx + 2),
                candy);

    return colleges[idx] = candy;
}
int main() {
    int numOfColleges;
    cin >> numOfColleges;
    vector<int> colleges(numOfColleges, -1);
    vector<int> candiesOfColleges(numOfColleges);
    for (int i = 0; i < numOfColleges; i++) {
        cin >> candiesOfColleges[i];
    }

    cout << getCandies(candiesOfColleges, colleges, numOfColleges) << endl;
    return 1;
}