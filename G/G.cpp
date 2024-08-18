#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int calc(vector<int> heights) {
    int n = heights.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = heights[0];
    for(int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    rightMax[n - 1] = heights[n - 1];
    for(int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], heights[i]);

    int water = 0;
    for(int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - heights[i];
    return water;
}

void find(int idx, int K, vector<int>& heights, int& maxWater) {
    if(K == 0) {
        maxWater = max(maxWater, calc(heights));
        return;
    }
    if(idx >= heights.size())
        return;
    find(idx + 1, K, heights, maxWater);
    heights[idx]++;
    find(idx, K - 1, heights, maxWater);
    heights[idx]--;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N);

    for(int i = 0; i < N; ++i)
        cin >> H[i];
    int maxWater = 0;
    find(0, K, H, maxWater);
    cout << maxWater << endl;

    return 0;
}
