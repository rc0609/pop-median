/*
File title: myHeap.cpp
Author: Ramisha Chowdhury
Breif Description: Project 2.

This file will be graded
*/

#include "myHeap.hpp"

void heapMedian (const std::vector<int> * instructions){
    std::priority_queue<int> small; //Max heap that keeps all elements <= median
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; //Min heap that keeps all elements > median
    
    std::vector<int> popvec; //Vector to store the median

    //auto start = std::chrono::high_resolution_clock::now(); // Timer starts

    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it == -1){
            //pop median
            if(!small.empty()){
            
                int median = 0;
                median = small.top();
                popvec.push_back(median); //Element saved in result

                if(small.size() == large.size()){
                    small.pop();
                }
                else{
                    small.pop();
                    small.push(large.top());
                    large.pop();

                }
            } 

    } else{//insert
        if(small.empty()|| *it<= small.top()){
            small.push(*it);
        }
        else{
            large.push(*it);
        }
    } 

    // Rebalance heaps to ensure small will always be of equal size or 1 element larger than large.
            if (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            } else if (!small.empty() && small.size() < large.size()) {
                small.push(large.top());
                large.pop();
            }

    


}

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
    //std::cout << "Time heapMedian: " << elapsed_microseconds.count() << " microseconds" << std::endl;

    for(int results : popvec)
    {
        std::cout<<results<<" ";
        }

}