//
// Created by Xianzhong Yu on 2024/9/11.
//

#ifndef ALGORITHM_EXAMPLES_ALGO_H
#define ALGORITHM_EXAMPLES_ALGO_H
#include "algostuff.h"
using namespace std;
using namespace std::placeholders;

class MeanValue {
private:
    long num;
    long sum;

public:
    MeanValue(): num(0), sum(0) {}
    void operator()(int elem) {
        num++;
        sum += elem;
    }
    operator double() {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
};

void for_each_example(); // for_each
void count_example();    // count, count_if
void extremum_example(); // min_element, max_element, minmax_element
void find_example();     // find, find_if, find_if_not
#endif //ALGORITHM_EXAMPLES_ALGO_H
