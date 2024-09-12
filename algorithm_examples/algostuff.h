//
// Created by Xianzhong Yu on 2024/9/11.
//

#ifndef ALGORITHM_EXAMPLES_ALGOSTUFF_H
#define ALGORITHM_EXAMPLES_ALGOSTUFF_H
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<functional>
#include<numeric>
#include<iterator>
#include<algorithm>
#include<iostream>

template<typename T>
inline void INSERT_ELEMENT(T& coll, int first, int last) {
    for (int i=first; i<=last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optcstr="") {
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
inline void PRINT_MAPPED_ELEMENTS(const T& coll, const std::string& optcstr="") {
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << '[' << elem.first
                  << ", " << elem.second << "] ";
    }
    std::cout << std::endl;
}

#endif //ALGORITHM_EXAMPLES_ALGOSTUFF_H
