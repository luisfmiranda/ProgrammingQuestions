#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Largest Rectangle in Histogram
 *
 * - Problem description:
 * Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area
 * of largest rectangle in the histogram.
 */

int largestRectangleInHistogram(vector<int> &heights) {
    int ans = 0;
    vector<int> indices;

    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++) {
        while(indices.size() > 0 && heights[indices.back()] >= heights[i]) {
            int h = heights[indices.back()];

            indices.pop_back();

            int sidx = -1;
            if (indices.size() > 0) sidx = indices.back();
            if (h * (i - sidx - 1) > ans) ans = h * (i - sidx - 1);
        }

        indices.push_back(i);
    }

    return ans;
}

void largestRectangleInHistogramTester() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleInHistogram(heights);
}
