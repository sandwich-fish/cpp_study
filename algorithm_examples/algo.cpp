//
// Created by Xianzhong Yu on 2024/9/11.
//
#include "algo.h"

/*
 * example for for_each.
 */
void for_each_example() {
    // 1. for_each algorithm
    vector<int> ivec;
    INSERT_ELEMENT(ivec, 1, 22);
    for_each(ivec.cbegin(), ivec.cend(), [](int elem) {
        cout << elem << ' ';
    });
    cout << endl;

    // calculate Mean value in ivec.
    double mv = for_each(ivec.cbegin(), ivec.cend(), MeanValue());
    cout << "Mean Value: " << mv << endl;

    // get sum of all elements in ivec by for_each.
    int sum {0};
    for_each(ivec.cbegin(), ivec.cend(), [=, &sum](int val) {
        sum += val;
    });
    cout << "Sum of all elements: " << sum << endl;
    // change elements in ivec
    for_each(ivec.begin(), ivec.end(), [](int& elem){
        elem += 10;
    });
    PRINT_ELEMENTS(ivec, "elements after adding 10: ");
}

/*
 * example for count, cont_if.
 */
void count_example() {
    vector<int> coll;
    int num;
    INSERT_ELEMENT(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    // count elements with value 4
    num = count(coll.cbegin(), coll.cend(), 4);
    cout << "number of elements equal to 4: " << num << endl;

    // count elements with even value
    num = count_if(coll.cbegin(), coll.cend(), [](int elem) {
        return elem % 2 == 0;
    });
    cout << "number of elements with even value: " << num << endl;

    // count elements that are greater than value 4
    num = count_if(coll.cbegin(), coll.cend(), [](int elem) {
        return elem > 4;
    });
    cout << "number of elements greater than 4: " << num << endl;
}

/*
 * examples for min_element, max_element, minmax_element
 */
void extremum_example() {
    deque<int> coll;
    INSERT_ELEMENT(coll, 2, 6);
    INSERT_ELEMENT(coll, -3, 6);
    PRINT_ELEMENTS(coll);
    // min_element
    cout << "minimum: " << *min_element(coll.cbegin(), coll.cend()) << endl;
    // max_element
    cout << "maximum: " << *max_element(coll.cbegin(), coll.cend()) << endl;

    // minmax_element
    auto mm = minmax_element(coll.cbegin(), coll.cend());
    cout << "min: " << *(mm.first) << endl;
    cout << "max: " << *(mm.second) << endl;
    cout << "distance: " << distance(mm.first, mm.second) << endl;

    cout << "minimum of absolute values: " << *min_element(coll.cbegin(), coll.cend(), [](int val1, int val2) {
        return abs(val1) < abs(val2);
    }) << endl;
    cout << "maximum of absolute values: " << *max_element(coll.cbegin(), coll.cend(), [](int val1, int val2) {
        return abs(val1) < abs(val2);
    }) << endl;
}

void find_example() {
    vector<int> coll;
    vector<int>::const_iterator pos;
    INSERT_ELEMENT(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    // find_if
    pos = find_if(coll.cbegin(), coll.cend(), bind(greater<int>(), _1, 3));
    cout << "The " << distance(coll.cbegin(), pos) + 1 << ". element is the first greater than 3" << endl;
    pos = find_if(coll.cbegin(), coll.cend(), [](int elem) {return elem%3 == 0;});
    cout << "The " << distance(coll.cbegin(), pos) + 1 << ". element is the first divisible by 3." << endl;

    // find_if_not
    pos = find_if_not(coll.cbegin(), coll.cend(), [](int elem) {return elem < 5;});
    cout << "first value >=5: " << *pos << endl;
}