#include "getStack.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*PROBLEM 1: LARGEST RECTANGLE IN HISTOGRAM
Find the largest rectangular area in a histogram
Given an array of bar heights, find the maximum area of a rectangle that can be formed*/
int largestRectangleArea(vector<int>& heights) {
    Stack<int> st; // store indices
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0; i < n; i++) {
        //while current bar is shorter than stack top
        while(!st.isEmpty() && heights[i] < heights[st.topEl()]) {
            int h_idx = st.pop();
            int height = heights[h_idx];

            //width = i (current) - left boundary
            int width = st.isEmpty() ? i : i - st.topEl() - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    while(!st.isEmpty()) {
        int h_idx = st.pop();
        int height = heights[h_idx];
        int width = st.isEmpty() ? n : n - st.topEl() - 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

/** PROBLEM 2: Trapping Rain Water
 * Calculate how much rainwater can be trapped between bars of different heights
 * Given an elevation (array of heights), compute how much ware can be trapped after raining
 */

 int trapWater (vector<int>& heights) {
    Stack<int> st;
    int water = 0;
    int n = heights.size();

    for(int i = 0; i < n; i++ ){
        int prev_height = 0;

        //Pop while current bar is taller
        while(!st.isEmpty() && heights[1] > heights[st.topEl()]) {
            int top_idx = st.pop();
            int top_height = heights[top_idx];

            if(st.isEmpty()) break;

            // Water level between current and previous
            int left_idx = st.topEl();
            int left_height = heights[left_idx];

            // Water trapped = (min(left, right) - bottom) x width
            int level = min(left_height, heights[i]);
            int trapped = (level - top_height) * (i - left_idx - 1);
            water += trapped;
            prev_height = top_height;
        }

        // If current bar same height, update position 
        if(!st.isEmpty() && heights[i] == heights[st.topEl()]) {
            st.pop();
        }
        st.push(i);
    }

    return water;
 }



int main() {
    vector<vector<int>> tests = {
        {2, 1, 5, 6, 2, 3},
        {2, 4},
        {1, 1},
        {0, 9},
        {6, 9, 0, 7},
    };
    
    cout << "Largest Rectangle in Histogram:\n" << string(50, '-') << endl;
    
    for (auto& heights : tests) {
        int result = largestRectangleArea(heights);
        
        cout << "Heights: [";
        for (int h : heights) cout << h << " ";
        cout << "]\nMax Area: " << result << "\n\n";
    }
    
    vector<vector<int>> test2 = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {4, 2, 0, 3, 2, 5},
        {9, 6, 8, 8, 5, 6, 2, 5, 4},
        {2, 0, 2},
        {3, 0, 2, 0, 4},
    };
    
    cout << "Trapping Rain Water:\n" << string(50, '-') << endl;
    
    for (auto& heights : test2) {
        int result = trapWater(heights);
        
        cout << "Heights: [";
        for (int h : heights) cout << h << " ";
        cout << "]\nWater Trapped: " << result << "\n\n";
    }
    
    return 0;
}