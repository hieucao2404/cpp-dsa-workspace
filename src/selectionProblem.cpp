#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int selectionProblem(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size()/2];
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 50000};

    for (int N : sizes) {
    vector<int> arr(N);

    //Fill with random values
    for (int i = 0; i < N; i++){
        arr[i] = rand();
    }
    auto start = high_resolution_clock::now();

    int median = selectionProblem(arr);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "N = " << N
        << " | Time = " << duration.count() << "ms\n";
    }
    return 0;
}
