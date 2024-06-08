/*
File title: myVector.cpp
Author: Ramisha Chowdhury
Breif Description: Project 2.

This file will be graded
*/

#include "myList.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>

void listMedian (const std::vector<int> * instructions) {
    std::list<int> popvec;//To store median
    std::list<int> data;//To retrieve data

    //auto start = std::chrono::high_resolution_clock::now();

    for(auto it = instructions->begin(); it != instructions->end(); ++it) {
        if (*it == -1) {
            if (!data.empty()) {
                
                int size = data.size();
                int medianIndex = size / 2;
                int median;
                auto it2 = data.begin();
                std::advance(it2, medianIndex);
                median = *it2;
                if (size % 2 == 0) {
                    auto prevIt = std::prev(it2);
                    median = std::min(*prevIt, median);
                    if (*it2 == median) {
                        data.erase(it2);
                    } else {
                        data.erase(prevIt);
                    }
                } else {
                    data.erase(it2);
                }
                popvec.push_back(median);
            }
        } else {
            auto it3 = std::lower_bound(data.begin(), data.end(), *it);
            data.insert(it3, *it);
        }
    }

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
    //std::cout << "Time taken by listMedian: " << elapsed_microseconds.count() << " microseconds" << std::endl;

    for(int results : popvec)
    {
        std::cout<<results<< " ";
    }
}