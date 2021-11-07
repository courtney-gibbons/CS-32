#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool somePredicate(string s) {
    if (s == "hi") {
        return true;
    } else {
        return false;
    }
}

// MY CODE START ////////////////////////////////////////////////////////////////////////
// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n) {
    if (n <= 0) {
        return true;
    }
    if (!somePredicate(a[0])) {
        return false;
    }
    return allTrue(a+1, n-1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n) {
    if (n <= 0) {
        return 0;
    }
    if (!somePredicate(a[0])) {
        return countFalse(a+1, n-1) + 1;
    }
    return countFalse(a+1, n-1);
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n) {
    if (n <= 0) {
        return -1;
    }
    if (!somePredicate(a[0])) {
        return 0;
    }
    int x = firstFalse(a+1, n-1);
    if (x == -1) {
        return x;
    } else {
        return x + 1;
    }
}

// Return the subscript of the least string in the array (i.e.,
// return the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the function is told to examine no
// elements, return -1.
int indexOfLeast(const string a[], int n) {
    if (n <= 0) {
        return -1;
    }
    int x = indexOfLeast(a+1, n-1) + 1;
    if (a[0] <= a[x]) {
        return 0;
    } else {
        return x;
    }
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const string a1[], int n1, const string a2[], int n2) {
    if (n2 <= 0) {
        return true;
    }
    if (n1 <= 0 && n2 != 0) {
        return false;
    }
    if (a1[0] != a2[0]) {
        return includes(a1+1, n1-1, a2, n2);
    } else {
        return includes(a1+1, n1-1, a2+1, n2-1);
    }
}
// MY CODE END ////////////////////////////////////////////////////////////////////////

int main() {
    string hi_array[3];
    hi_array[0] = "hi";
    hi_array[1] = "hi";
    hi_array[2] = "hi";
    string badZero[3];
    badZero[0] = "bye";
    badZero[1] = "hi";
    badZero[2] = "hi";
    string badOne[3];
    badOne[0] = "hi";
    badOne[1] = "bye";
    badOne[2] = "hi";
    string badTwo[3];
    badTwo[0] = "hi";
    badTwo[1] = "hi";
    badTwo[2] = "bye";
    string twoBad[3];
    twoBad[0] = "hi";
    twoBad[1] = "bye";
    twoBad[2] = "bye";
    string threeBad[3];
    threeBad[0] = "bye";
    threeBad[1] = "bye";
    threeBad[2] = "bye";

    assert( allTrue(hi_array, 3) == 1 );
    assert( allTrue(badZero, 3) == 0 );
    assert( allTrue(badOne, 3) == 0 );
    assert( allTrue(badTwo, 3) == 0 );
    assert( allTrue(badTwo, 0) == 1 );

    assert( countFalse(hi_array, 3) == 0 );
    assert( countFalse(badZero, 3) == 1 );
    assert( countFalse(badOne, 3) == 1 );
    assert( countFalse(badTwo, 3) == 1 );
    assert( countFalse(twoBad, 3) == 2 );
    assert( countFalse(threeBad, 3) == 3 );
    assert( countFalse(threeBad, 0) == 0 );

    assert( firstFalse(hi_array, 3) == -1 );
    assert( firstFalse(badZero, 3) == 0 );
    assert( firstFalse(badOne, 3) == 1 );
    assert( firstFalse(badTwo, 3) == 2 );
    assert( firstFalse(twoBad, 3) == 1 );
    assert( firstFalse(threeBad, 3) == 0 );
    assert( firstFalse(threeBad, 0) == -1 );

    string zerothIndex[3] = {"a", "b", "c"};
    string firstIndex[3] = {"b", "a", "c"};
    string secondIndex[3] = {"c", "b", "a"};
    string secondIndex2[3] = {"b", "b", "a"};
    string firstIndex2[3] = {"b", "a", "a"};
    string firstIndex3[5] = {"b", "a", "a", "b", "a"};

    assert( indexOfLeast(zerothIndex, 3) == 0 );
    assert( indexOfLeast(firstIndex, 3) == 1 );
    assert( indexOfLeast(secondIndex, 3) == 2 );
    assert( indexOfLeast(secondIndex2, 3) == 2 );
    assert( indexOfLeast(secondIndex2, 0) == -1 );
    assert( indexOfLeast(firstIndex2, 3) == 1 );
    assert( indexOfLeast(firstIndex3, 5) == 1 );

    string a1[7] = {"stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters"};
    string a21[3] = {"kyle", "kenny", "butters"};
    string a22[3] = {"kyle", "cartman", "cartman"};
    string a23[3] = {"kyle", "butters", "kenny"};
    string a24[3] = {"kyle", "kenny", "kenny"};

    assert( includes(a1, 7, a21, 3) == 1 );
    assert( includes(a1, 7, a22, 3) == 1 );
    assert( includes(a1, 7, a23, 3) == 0 );
    assert( includes(a1, 7, a24, 3) == 0 );
    assert( includes(a1, 0, a24, 3) == 0 );
    assert( includes(a1, 7, a24, 0) == 1 );
    assert( includes(a1, 0, a24, 0) == 1 );

    string arr[5] = { "hi", "n", "hi", "bye", "hi" };
    string allT[3] = { "hi", "hi", "hi" };
    assert(allTrue(allT, 3));
    assert(countFalse(arr, 5) == 2);
    assert(countFalse(arr, 3) == 1);
    assert(firstFalse(arr, 5) == 1);
    assert(firstFalse(allT, 3) == -1);
    assert(firstFalse(arr, 1) == -1);
    assert( indexOfLeast(arr, 5) == 3 );
    cerr << "Done!" << endl;
}
