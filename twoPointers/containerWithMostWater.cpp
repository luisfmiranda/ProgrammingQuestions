#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Container With Most Water
 *
 * - Problem description:
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 'n' vertical
 * lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with
 * x-axis forms a container, such that the container contains the most water. Your program should return an integer
 * which corresponds to the maximum area of water that can be contained (Yes, we know maximum area instead of maximum
 * volume sounds weird. But this is 2D plane we are working with for simplicity).
 * Note: You may not slant the container.
 */

int findContainerWithMostWater(vector<int>& heights) {
    int start = 0;
    int end = (int)heights.size() - 1;

    int maxVol = 0;

    while (start < end) {
        int baseLength = end - start;
        int containerHeight = min(heights[start], heights[end]);

        maxVol = max(maxVol, (baseLength * containerHeight));

        // if a1 <= aN, then the problem reduces to solving the same thing for a2 .. aN.
        if (heights[start] <= heights[end]) {
            start++;
        // else, it reduces to solving the same thing for a1 .. aN-1.
        } else {
            end--;
        }
    }

    return maxVol;
}
