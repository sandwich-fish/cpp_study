//
// Created by Xianzhong Yu on 2024/9/5.
//

#include "example01.h"

using namespace std;

template <typename InputIterator, typename Tp>
inline InputIterator
find_before(InputIterator first, InputIterator last, const Tp& val) {
    if (first == last)
        return first;

    InputIterator next(first);
    ++next;
    while (next != last && !(*next == val)) {
        ++next;
        ++first;
    }

    return first;
}

template<typename InputIterator, typename Pred>
inline InputIterator
find_before_if(InputIterator first, InputIterator last, Pred pred) {
    if (first == last)
        return first;

    InputIterator next(first);
    ++next;

    while (next != last && !pred(*next)) {
        ++next;
        ++first;
    }

    return first;
}

void case01() {
    forward_list<int> list = {1, 2, 3, 4, 5, 97, 98, 99};

    auto posBefore = find_before(list.cbefore_begin(), list.cend(), 3);
    list.insert_after(posBefore, 42);

    // Output result.
    copy(list.cbegin(), list.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto posB2 = find_before_if(list.before_begin(), list.end(), [](int val) {
        return val % 2 == 1;
    });

    list.insert_after(posB2, 100);

    // Output result.
    copy(list.cbegin(), list.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto posBefore3 = find_before(list.cbefore_begin(), list.cend(), 31000);
    list.insert_after(posBefore3, 31000);

    // Output result.
    cout << "The result of forward_list: " << endl;
    copy(list.cbegin(), list.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;


    set<int, greater<int>> coll1;
    coll1.insert({4, 3, 5, 1, 6, 2});
    coll1.insert(5);
    coll1.insert(12);
    // print all elements
    cout << "Elements of coll1(default compare rule: greater<int>): " << endl;
    copy(coll1.cbegin(), coll1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // copy list to vector
    vector<int> ivec(list.cbegin(), list.cend());
    // output vector
    cout << "Elements in ivec: " << endl;
    copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // insert 4 again and process return value
    auto status = coll1.insert(4);
    if (status.second) {
        cout << "4 inserted as element " << distance(coll1.begin(), status.first) + 1 << endl;
    } else {
        cout << "4 already exists" << endl;
    }
    cout << endl;
    set<int> coll2(coll1.cbegin(), coll1.cend());
    cout << "Elements in coll2(default compare rule: less<int>): ";
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    ivec.clear();
    ivec.shrink_to_fit();
    cout << "ivec capacity: " << ivec.capacity() << endl;
    cout << "ivec size(): " << ivec.size() << endl;
    // 将集合中的元素复制到ivec中
    copy(coll1.cbegin(), coll1.cend(), back_inserter(ivec));
    // output elements in ivec
    cout << "Elements of ivec copied from coll1: " << endl;
    copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    unordered_multiset<string> cities { "Braunschhweig", "Hanover", "Frankfurt",
                                        "New York", "Chicago", "Toronto", "Paris", "Frankfurt"};

    cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

    copy(cities.cbegin(), cities.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    unordered_map<string, double> coll_map { {"tim", 9.9}, {"struppi", 11.77} };
    coll_map.insert(decltype(coll_map)::value_type("string", 11.0));
    for (const auto& it : coll_map) {
        cout << it.first << ", " << it.second << endl;
    }

    // Copy elements to ivec.
    vector<string> strVec {cities.cbegin(), cities.cend()};

    // lower case to upper case.
    for (auto strIt = strVec.begin(); strIt != strVec.end(); ++strIt) {
        transform(strIt->begin(), strIt->end(), strIt->begin(), [](auto& c) { return toupper(c);});
    }

    // output values in vector<string>
    cout << "Result after converting to upper case: " << endl;
    copy(strVec.cbegin(), strVec.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    // upper case to lower case
    for (auto it = strVec.begin(); it != strVec.end(); ++it) {
        for_each(it->begin(), it->end(), [](char& c)
        {
            c = std::tolower((c));
        });
    }

    // output values in vector<string>
    cout << "Elements after converting to lower case: " << endl;
    copy(strVec.cbegin(), strVec.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    vector<string> strVecRslt;
    transform(strVec.cbegin(), strVec.cend(), back_inserter(strVecRslt), [=](const string& str) {
        struct Upper {
            void operator() (char c) {
                str.push_back(toupper(c));
            }

            string str;
        };
        Upper upper = for_each(str.cbegin(), str.cend(), Upper());
        return upper.str;
    });

    cout << "Result of strVec:";
    copy(strVec.cbegin(), strVec.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "Result of strVecRslt:";
    copy(strVecRslt.cbegin(), strVecRslt.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    // statistics all capital wrods.
    size_t nc = count_if(strVec.begin(), strVec.end(), [](auto& str) {
        if (str.length() == 0) {
            return false;
        } else {
            return str[0] == tolower(str[0]);
        }
    });
    cout << "Number of all capitalized word:" << nc << endl;

    // capitalize
    for (auto it = strVec.begin(); it != strVec.end(); ++it) {
        for_each_n(it->begin(), 1, [](char& c) {
            c = toupper(c);
        });
    }

    // output values in vector<string>
    cout << "Capitalized: " << endl;
    copy(strVec.cbegin(), strVec.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    vector<int> coll;
    for (int i=0; i<=9; ++i) {
        coll.push_back(i);
    }

    // reverse iterator
    cout << "Result of using reverse iterator: " << endl;
    copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void algorithm_remove1() {
    list<int> coll;
    for (int i=1; i<=6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }

    // print all elements of the collection
    cout << "pre: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements with value 3
    remove(coll.begin(), coll.end(), 3);

    // print all elements of the collection
    cout << "post: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void algorithm_remove2() {
    list<int> coll;
    for (int i=1; i<=6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }

    // print all elements of the collection
    cout << "pre: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements with value 3
    decltype(coll)::iterator end = remove(coll.begin(), coll.end(), 3);

    cout << "number of removed elements: "
         << distance(end, coll.end()) << endl;

    // print all elements of the collection
    cout << "post: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "post: ";
    copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
    cout << endl;
}