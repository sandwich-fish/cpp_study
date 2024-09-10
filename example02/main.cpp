#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <unordered_set>
#include <list>
#include "assoiter.h"

using namespace std;

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
    return 0;
}
