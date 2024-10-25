#include<bits/stdc++.h>
using namespace std;

int maximizeSumOfHeights(const vector<int>& heights) {
    int n = heights.size();
    int sum = 0;
    int last_pick=0;
    for(int i=n-1;i>=0;i--){
        if(heights[i]>last_pick){
            sum+=heights[i];
            last_pick=heights[i];
        }
    }

    return sum;
}

int main() {
    // Example usage
    vector<int> heights = {6, 10, 5, 4, 7,30,30};
    int result = maximizeSumOfHeights(heights);

    cout << "Maximized sum of heights: " << result << endl;

    return 0;
}
