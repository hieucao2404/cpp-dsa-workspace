// Finding maximum subsequence sum in an array
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

//helper method to find max of three values
int max3(int a, int b, int c){
    return max(a, max(b, c));
}
int maxSumRec(const vector<int> & a, int left, int right) {
    if(left == right)
       if( a[left] > 0)
            return a[left];
        else 
            return 0;
    int center = (right + left) / 2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >= left; --i) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for(int j = center + 1; j <=  right; ++j) {
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
        }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int maxSubSum3(const vector<int> & a) {
        return  maxSumRec(a, 0, a.size() - 1);
    }

    int main() {
        //Test case
         vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        cout << "Test 1: ";
    
        for(int x : test1) cout << x << " ";
        cout << endl;

        // Start timer
        auto start =  high_resolution_clock::now();

        int result = maxSubSum3(test1);
        auto end  = high_resolution_clock::now();

        // Calculate and dislay elapsed time
        auto duration = duration_cast<microseconds>(end - start);

        cout << "Maximum subsequence sum: " << result << endl;
        cout << "Time taken: " << duration.count() << "ms" << endl;

        return 0;
    }
        
