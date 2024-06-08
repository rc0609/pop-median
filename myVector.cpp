/*
File title: myVector.cpp
Author: Ramisha Chowdhury
Breif Description: Project 2.

This file will be graded
*/

#include "myVector.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

void vectorMedian(const std::vector<int> *instructions) {
    std::vector<int> popvec; //To store the median
    std::vector<int> data; //For retrieving data

    //auto start = std::chrono::high_resolution_clock::now();

    for(auto it = instructions->begin(); it != instructions->end(); ++it) {
        if (*it == -1) {
            if (!data.empty()) {
                int medianIndex = data.size() / 2;
                int median;
                if (data.size() % 2 == 0) {
                    median = std::min(data[medianIndex], data[medianIndex - 1]);
                    data.erase(data.begin()+medianIndex-1);
                } else {
                    median = data[medianIndex];
                    data.erase(data.begin() + medianIndex);
                }
                popvec.push_back(median);
            }
        } else {
            auto ite = std::lower_bound(data.begin(), data.end(), *it);
            data.insert(ite, *it);
        }
    }

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
    //std::cout << "Time vectorMedian: " << elapsed_microseconds.count() << " microseconds" << std::endl;

    for(int results : popvec)
    {
        std::cout<<results<< " ";
    }
}