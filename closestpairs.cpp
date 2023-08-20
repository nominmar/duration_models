#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

// function to take 2 vectors and return closest pairs
std::pair<std::pair<int, int>, std::pair<double, double>> closestpairs(std::vector<double> v_left, std::vector<double> v_right)
{
    double index_left = 0;
    double index_right = 0;
    double threshold = std::numeric_limits<double>::max();
    std::pair<int, int> closest_pair_indexes;
    std::pair<double, double> closest_pair_values;

    while (index_left < v_left.size())
    {
        while (index_right < v_right.size())
        {
            double diff = std::abs(v_right[index_left] - v_left[index_right]);
            if (diff < threshold)
            {
                threshold = diff;
                closest_pair_indexes = {index_left, index_right};
                closest_pair_values = {v_right[index_left], v_left[index_right]};
            }
            index_right++;
        }
        index_left++;
    }
    return std::make_pair(closest_pair_indexes, closest_pair_values);
}

void main()
{
    std::vector<double> v1 = {1, 4, 5, 7, 8, 13, 49};
    std::vector<double> v2 = {7, 10, 11, 15, 40};
    std::pair<std::pair<int, int>, std::pair<double, double>> result = closestpairs(v1, v2);
}