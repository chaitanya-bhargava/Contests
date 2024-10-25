#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxTripletProfit(vector<int>& A, vector<int>& B) {
    int n = A.size();
    if (n < 3)
        return -1; // Return -1 when there are less than 3 elements
    
    // Initialize variables to store the maximum profit
    int maxProfit = 0;
    
    // Iterate through array A to find the maximum profit
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (A[i] < A[j] && A[j] < A[k]) {
                    int profit = B[i] + B[j] + B[k];
                    maxProfit = max(maxProfit, profit);
                    cout<<maxProfit<<endl;
                }
            }
        }
    }
    
    return maxProfit == 0 ? -1 : maxProfit;
}

int main() {
    vector<int> A = {1, 5, 3, 4, 6};
    vector<int> B = {2, 3, 4, 5, 6};

    int result = maxTripletProfit(A, B);
    cout << "Max triplet profit is: " << result << endl;

    return 0;
}
