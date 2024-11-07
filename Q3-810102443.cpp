#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numOfColleges;
    cin >> numOfColleges;
    vector<int> colleges(numOfColleges);
    for (int i = 0; i < numOfColleges; i++) {
        cin >> colleges[i];
    }
    return 1;
}