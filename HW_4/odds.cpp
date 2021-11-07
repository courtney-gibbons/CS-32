//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//// MY CODE START ///////////////////////////////////////////////////////////////////
//void removeOdds(vector<int>& v) {
//    // Remove the odd integers from v.
//    // It is acceptable if the order of the remaining even integers is not
//    // the same as in the original vector.
//    vector<int>::iterator iter = v.begin();
//    while (iter != v.end()) {
//        if (*iter % 2 == 1) {
//            iter = v.erase(iter);
//        } else {
//            iter++;
//        }
//    }
//}
//// MY CODE END ///////////////////////////////////////////////////////////////////
//
//void test()
//{
//    int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
//    vector<int> x(a, a+8);  // construct x from the array
//    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
//    removeOdds(x);
//    assert(x.size() == 4);
//    sort(x.begin(), x.end());
//    int expect[4] = { 2, 4, 6, 8 };
//    for (int k = 0; k < 4; k++)
//        assert(x[k] == expect[k]);
//}
//
//int main()
//{
//    test();
//
//    // remove first, middle, last
//    int a1[5] = {1, 4, 5, 6, 7};
//    vector<int> v1(a1, a1+5);
//    removeOdds(v1);
//    int expect1[2] = {4, 6};
//    vector<int> v1expect(expect1, expect1+2);
//    assert(v1 == v1expect);
//
//    // empty
//    vector<int> v2;
//    assert(v2.size() == 0);
//    removeOdds(v2);
//    assert(v2.size() == 0);
//
//    // 1 element
//    vector<int> v3;
//    v3.push_back(1);
//    assert(v3.size() == 1);
//    removeOdds(v3);
//    assert(v3.size() == 0);
//
//    vector<int> v4;
//    v4.push_back(2);
//    assert(v4.size() == 1);
//    removeOdds(v4);
//    assert(v4.size() == 1);
//
//    cout << "Passed" << endl;
//}
