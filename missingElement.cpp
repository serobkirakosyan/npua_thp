#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    unsigned n;
    cout << "Enter n: ";
    cin >> n;
    vector<unsigned> numbers;
    unsigned missingValue = 1 + rand() % n;
    for (unsigned i = 1; i <= n; ++i) {
        if (i != missingValue) {
            numbers.push_back(i);
        }
    }
    cout << "The array:\n";
    for (const auto& num : numbers) {
        cout << num << ' ';
    }
    cout << "\nThe missing value is " << missingValue;
    return 0;
}
