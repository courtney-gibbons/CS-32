//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//
//// MY CODE START ////////////////////////////////////////////////////////////////////////
//// Return the number of ways that all n2 elements of a2 appear
//// in the n1 element array a1 in the same order (though not
//// necessarily consecutively).  The empty sequence appears in a
//// sequence of length n1 in 1 way, even if n1 is 0.
//// For example, if a1 is the 7 element array
////    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
//// then for this value of a2            the function must return
////    "stan" "kenny" "cartman"                      1
////    "stan" "cartman" "butters"                    2
////    "kenny" "stan" "cartman"                      0
////    "kyle" "cartman" "butters"                    3
//int countIncludes(const string a1[], int n1, const string a2[], int n2)
//{
//    if (n2 <= 0) {
//        return 1;
//    }
//    if (n1 <= 0) {
//        return 0;
//    }
//    if (a1[n1-1] != a2[n2-1]) {
//        return countIncludes(a1, n1-1, a2, n2);
//    } else {
//        return countIncludes(a1, n1-1, a2, n2-1) + countIncludes(a1, n1-1, a2, n2);
//    }
//}
//
//// Exchange two strings
//void exchange(string& x, string& y)
//{
//    string t = x;
//    x = y;
//    y = t;
//}
//
//// Rearrange the elements of the array so that all the elements
//// whose value is < separator come before all the other elements,
//// and all the elements whose value is > separator come after all
//// the other elements.  Upon return, firstNotLess is set to the
//// index of the first element in the rearranged array that is
//// >= separator, or n if there is no such element, and firstGreater is
//// set to the index of the first element that is > separator, or n
//// if there is no such element.
//// In other words, upon return from the function, the array is a
//// permutation of its original value such that
////   * for 0 <= i < firstNotLess, a[i] < separator
////   * for firstNotLess <= i < firstGreater, a[i] == separator
////   * for firstGreater <= i < n, a[i] > separator
//// All the elements < separator end up in no particular order.
//// All the elements > separator end up in no particular order.
//void separate(string a[], int n, string separator,
//              int& firstNotLess, int& firstGreater)
//{
//    if (n < 0)
//        n = 0;
//
//    // It will always be the case that just before evaluating the loop
//    // condition:
//    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
//    //  Every element earlier than position firstNotLess is < separator
//    //  Every element from position firstNotLess to firstUnknown-1 is
//    //    == separator
//    //  Every element from firstUnknown to firstGreater-1 is not known yet
//    //  Every element at position firstGreater or later is > separator
//
//    firstNotLess = 0;
//    firstGreater = n;
//    int firstUnknown = 0;
//    while (firstUnknown < firstGreater)
//    {
//        if (a[firstUnknown] > separator)
//        {
//            firstGreater--;
//            exchange(a[firstUnknown], a[firstGreater]);
//        }
//        else
//        {
//            if (a[firstUnknown] < separator)
//            {
//                exchange(a[firstNotLess], a[firstUnknown]);
//                firstNotLess++;
//            }
//            firstUnknown++;
//        }
//    }
//}
//
//// Rearrange the elements of the array so that
//// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
//// If n <= 1, do nothing.
//void order(string a[], int n)
//{
//    if (n <= 1) {
//        return;
//    }
//    int firstNotLess = 0;
//    int firstGreater = 0;
//    separate(a, n, a[0], firstNotLess, firstGreater);
//    separate(a, n, a[1], firstNotLess, firstGreater);
//    order(a+1, n-1);
//}
//// MY CODE END ////////////////////////////////////////////////////////////////////////
//
//int main() {
//    string names[7] = {"stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters"};
//    string test1[3] = {"stan", "kenny", "cartman" }; // 1
//    string test2[3] = {"stan", "cartman", "butters" }; // 2
//    string test3[3] = {"kenny", "stan", "cartman" }; // 0
//    string test4[3] = {"kyle", "cartman", "butters"}; // 3
//
//    assert( countIncludes(names, 7, test1, 3) == 1 );
//    assert( countIncludes(names, 7, test2, 3) == 2 );
//    assert( countIncludes(names, 7, test3, 3) == 0 );
//    assert( countIncludes(names, 7, test4, 3) == 3 );
//    assert( countIncludes(names, 7, test4, 0) == 1 );
//    assert( countIncludes(names, 0, test4, 0) == 1 );
//    assert( countIncludes(names, 0, test4, 3) == 0 );
//
//    order(names, 7);
//    assert( names[0] == "butters" );
//    assert( names[1] == "cartman" );
//    assert( names[2] == "cartman" );
//    assert( names[3] == "kenny" );
//    assert( names[4] == "kyle" );
//    assert( names[5] == "kyle" );
//    assert( names[6] == "stan" );
//
//    order(test1, 3);
//    assert( test1[0] == "cartman" );
//    assert( test1[1] == "kenny" );
//    assert( test1[2] == "stan" );
//
//    order(test2, 3);
//    assert( test2[0] == "butters" );
//    assert( test2[1] == "cartman" );
//    assert( test2[2] == "stan" );
//
//    order(test3, 3);
//    assert( test3[0] == "cartman" );
//    assert( test3[1] == "kenny" );
//    assert( test3[2] == "stan" );
//
//    order(test4, 3);
//    assert( test4[0] == "butters" );
//    assert( test4[1] == "cartman" );
//    assert( test4[2] == "kyle" );
//
//    order(test4, 1);
//    assert( test4[0] == "butters" );
//
//    order(test4, 0);
//    assert( test4[0] == "butters" );
//
//    const string arr[7] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
//    const string arr2[3] = { "kyle", "cartman", "butters" };
//    const string arr3[3] = { "stan", "kenny", "cartman" };
//    const string arr4[4] = { "stan", "kenny", "cartman", "butters" };
//    const string arr5[3] = { "stan", "cartman", "butters" };
//    const string arr6[3] = { "kenny", "stan", "cartman" };
//    assert(countIncludes(arr, 7, arr2, 3) == 3);
//    assert(countIncludes(arr, 7, arr3, 3) == 1);
//    assert(countIncludes(arr, 7, arr4, 4) == 1);
//    assert(countIncludes(arr, 7, arr5, 3) == 2);
//    assert(countIncludes(arr, 7, arr6, 3) == 0);
//    assert(countIncludes(arr, 6, arr2, 3) == 0);
//    assert(countIncludes(arr, 7, arr2, 2) == 3);
//    assert(countIncludes(arr, 0, arr2, 0) == 1);
//    assert(countIncludes(arr, 7, arr2, 0) == 1);
//    assert(countIncludes(arr, -5, arr2, -6) == 1);
//    string arr1[7] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
//    string arr12[3] = { "kyle", "cartman", "butters" };
//    string arr13[3] = { "stan", "kenny", "cartman" };
//    string arr14[4] = { "stan", "kenny", "cartman", "butters" };
//    string arr15[3] = { "stan", "cartman", "butters" };
//    string arr16[3] = { "kenny", "stan", "cartman" };
//    order(arr1, 7);
//    assert( arr1[0] == "butters" );
//    assert( arr1[1] == "cartman" );
//    assert( arr1[2] == "cartman" );
//    assert( arr1[3] == "kenny" );
//    assert( arr1[4] == "kyle" );
//    assert( arr1[5] == "kyle" );
//    assert( arr1[6] == "stan" );
//    order(arr12, 2);
//    assert( arr12[0] == "cartman" );
//    assert( arr12[1] == "kyle" );
//    assert( arr12[2] == "butters" );
//    order(arr13, 0);
//    assert( arr13[0] == "stan" );
//    assert( arr13[1] == "kenny" );
//    assert( arr13[2] == "cartman" );
//
//    cout << "Done!" << endl;
//}
