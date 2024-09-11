#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <list>
#include <functional>
#include <random>
#include "assoiter.h"

using namespace std;
using namespace std::placeholders;

int main() {
    unordered_set<int> coll;
    asso_insert_iterator<decltype(coll)> iter(coll);
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    asso_inserter(coll) = 44;
    asso_inserter(coll) = 55;
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vals = {33, 67, -4, 13, 5, 2};
    copy(vals.begin(), vals.end(), asso_inserter(coll));
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // generate a random number
    mt19937 rng;
    generate_n(ostream_iterator<mt19937::result_type>(cout, " "), 5, ref(rng));
    cout << endl;

    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "coll1: " << endl;
    copy(coll1.cbegin(), coll1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int>::const_iterator pos;
    // method1: lambda expression.
//    pos = remove_if(coll1.begin(), coll1.end(), [](int val){return val == 3;});

    // method2: std::bind and equal_to function object.
    pos = remove_if(coll1.begin(), coll1.end(), bind(equal_to<int>(), _1, 3));

    // method3: function object
    // TODO:

    cout << "3rd removed: " << endl;
    copy(coll1.cbegin(), pos, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
