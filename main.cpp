// using ItemType = std::string; tests

//#include "Set.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//#include <type_traits>
//using namespace std;
//
//#define CHECKTYPE(f, t) { auto p = static_cast<t>(f); (void)p; }
//
//static_assert(std::is_default_constructible<Set>::value,
//              "Set must be default-constructible.");
//static_assert(std::is_copy_constructible<Set>::value,
//              "Set must be copy-constructible.");
//static_assert(std::is_copy_assignable<Set>::value,
//              "Set must be assignable.");
//
//void thisFunctionWillNeverBeCalled()
//{
//    CHECKTYPE(&Set::empty,     bool (Set::*)() const);
//    CHECKTYPE(&Set::size,      int  (Set::*)() const);
//    CHECKTYPE(&Set::insert,    bool (Set::*)(const ItemType&));
//    CHECKTYPE(&Set::erase,     bool (Set::*)(const ItemType&));
//    CHECKTYPE(&Set::contains,  bool (Set::*)(const ItemType&) const);
//    CHECKTYPE(&Set::get,       bool (Set::*)(int, ItemType&) const);
//    CHECKTYPE(&Set::swap,      void (Set::*)(Set&));
//    CHECKTYPE(unite,      void (*)(const Set&, const Set&, Set&));
//    CHECKTYPE(difference, void (*)(const Set&, const Set&, Set&));
//}
//
//void test()
//{
//    Set ss;
//    assert(ss.insert("pita"));
//    assert(ss.insert("roti"));
//    assert(ss.size() == 2);
//    assert(ss.contains("roti"));
//    ItemType x = "laobing";
//    assert(ss.get(0, x)  &&  x == "roti");
//    assert(ss.get(1, x)  &&  x == "pita");
//
//    Set sss;
//    sss.insert("ccc");
//    sss.insert("aaa");
//    sss.insert("bbb");
//    x = "xxx";
//    assert(!sss.get(3, x)  &&  x == "xxx");
//    assert(sss.get(1, x)  &&  x == "bbb");
//}
//
//int main()
//{
//    // smallberg tests
//
//    test();
//
//    Set s1;
//    assert(s1.empty());
//    ItemType x1 = "arepa";
//    assert( !s1.get(42, x1)  &&  x1 == "arepa"); // x unchanged by get failure
//    s1.insert("chapati");
//    assert(s1.size() == 1);
//    assert(s1.get(0, x1)  &&  x1 == "chapati");
//
//    Set s2;
//    s2.insert("lavash");
//    s2.insert("roti");
//    s2.insert("chapati");
//    s2.insert("injera");
//    s2.insert("roti");
//    s2.insert("matzo");
//    s2.insert("injera");
//    assert(s2.size() == 5);  // duplicate "roti" and "injera" were not added
//    string x2;
//    s2.get(0, x2);
//    assert(x2 == "roti");  // "roti" is less than exactly 4 items in ss
//    s2.get(4, x2);
//    assert(x2 == "chapati");  // "chapati" is less than exactly 0 items in ss
//    s2.get(2, x2);
//    assert(x2 == "lavash");  // "lavash" is less than exactly 2 items in ss
//
//    Set s3;
//    s3.insert("laobing");
//    Set s4;
//    s4.insert("matzo");
//    s4.insert("pita");
//    s3.swap(s4);
//    assert(s3.size() == 2  &&  s3.contains("matzo")  &&  s3.contains("pita")  &&
//           s4.size() == 1  &&  s4.contains("laobing"));
//
//    Set s5;
//    s5.insert("dosa");
//    assert(!s5.contains(""));
//    s5.insert("tortilla");
//    s5.insert("");
//    s5.insert("focaccia");
//    assert(s5.contains(""));
//    s5.erase("dosa");
//    assert(s5.size() == 3  &&  s5.contains("focaccia")  &&  s5.contains("tortilla")  &&
//           s5.contains(""));
//    string x5;
//    assert(s5.get(1, x5)  &&  x5 == "focaccia");
//    assert(s5.get(2, x5)  &&  x5 == "");
//
//    // my tests
//
//    // new set = empty, size = 0
//    Set s6;
//    assert( s6.empty() == true );
//    assert( s6.size() == 0 );
//
//    // insert 3 strings
//    s6.insert("b");
//    s6.insert("a");
//    s6.insert("c");
//
//    // check duplicates
//    s6.insert("b");
//    s6.insert("a");
//    s6.insert("c");
//
//    // check empty = false
//    assert( s6.empty() == false );
//
//    // check size = 3
//    assert( s6.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s6.erase("z") == false );
//    assert( s6.size() == 3 );
//
//    // erase
//    s6.erase("b");
//    assert( s6.size() == 2 );
//
//    // add back
//    s6.insert("b");
//    assert( s6.size() == 3 );
//
//    // check contains
//    assert( s6.contains("a") == true );
//    assert( s6.contains("b") == true );
//    assert( s6.contains("c") == true );
//
//    // check contains w something that isn't there
//    assert( s6.contains("z") == false );
//
//    // check get
//    string str;
//    assert( s6.get(0, str) == true );
//    assert( str == "c" );
//    assert( s6.get(1, str) == true );
//    assert( str == "b" );
//    assert( s6.get(2, str) == true );
//    assert( str == "a" );
//    assert( s6.get(3, str) == false );
//    assert( str == "a" );
//    assert( s6.get(-1, str) == false );
//    assert( str == "a" );
//
//    // swap
//    Set s7;
//    s7.insert("x");
//    s7.insert("y");
//
//    s6.swap(s7);
//    assert( s6.size() == 2 );
//    assert( s6.contains("x") == true );
//    assert( s6.contains("y") == true );
//    assert( s6.contains("a") == false );
//    assert( s6.contains("b") == false );
//    assert( s6.contains("c") == false );
//    assert( s7.size() == 3 );
//    assert( s7.contains("x") == false );
//    assert( s7.contains("y") == false );
//    assert( s7.contains("a") == true );
//    assert( s7.contains("b") == true );
//    assert( s7.contains("c") == true );
//
//    // swap back
//    s6.swap(s7);
//    assert( s6.size() == 3 );
//    assert( s6.contains("x") == false );
//    assert( s6.contains("y") == false );
//    assert( s6.contains("a") == true );
//    assert( s6.contains("b") == true );
//    assert( s6.contains("c") == true );
//    assert( s7.size() == 2 );
//    assert( s7.contains("x") == true );
//    assert( s7.contains("y") == true );
//    assert( s7.contains("a") == false );
//    assert( s7.contains("b") == false );
//    assert( s7.contains("c") == false );
//
//    // test copy constructor
//    Set s8(s7);
//    assert( s7.empty() == false );
//    assert( s8.empty() == false );
//    assert( s7.size() == 2 );
//    assert( s8.size() == 2 );
//    assert( s8.erase("z") == false );
//    assert( s8.erase("y") == true );
//    assert( s7.size() == 2 );
//    assert( s8.size() == 1 );
//    assert( s8.insert("y") == true );
//    assert( s8.insert("y") == false );
//    assert( s7.size() == 2 );
//    assert( s8.size() == 2 );
//    assert( s7.contains("x") == true );
//    assert( s7.contains("y") == true );
//    assert( s8.contains("x") == true );
//    assert( s8.contains("y") == true );
//    assert( s7.get(0, str) == true );
//    assert( str == "y" );
//    assert( s7.get(1, str) == true );
//    assert( str == "x" );
//    assert( s7.get(2, str) == false );
//    assert( str == "x" );
//    assert( s7.get(-1, str) == false );
//    assert( str == "x" );
//
//    // test assignment operator
//    s8 = s6;
//    assert( s6.empty() == false );
//    assert( s8.empty() == false );
//    assert( s7.size() == 2 );
//    assert( s6.size() == 3 );
//    assert( s8.size() == 3 );
//    assert( s8.erase("a") == true );
//    assert( s8.erase("x") == false );
//    assert( s6.size() == 3 );
//    assert( s8.size() == 2 );
//    assert( s8.insert("a") == true );
//    assert( s8.insert("b") == false );
//    assert( s6.size() == 3 );
//    assert( s8.size() == 3 );
//    assert( s6.contains("a") == true );
//    assert( s6.contains("b") == true );
//    assert( s6.contains("c") == true );
//    assert( s8.contains("a") == true );
//    assert( s8.contains("b") == true );
//    assert( s8.contains("c") == true );
//    assert( s8.get(0, str) == true );
//    assert( str == "c" );
//    assert( s8.get(1, str) == true );
//    assert( str == "b" );
//    assert( s8.get(2, str) == true );
//    assert( str == "a" );
//    assert( s8.get(3, str) == false );
//    assert( str == "a" );
//    assert( s8.get(-1, str) == false );
//    assert( str == "a" );
//
//    // test unite
//    Set s9;
//    assert( s9.insert("a") == true );
//    assert( s9.insert("b") == true );
//    assert( s9.insert("c") == true );
//    assert( s9.insert("d") == true );
//    assert( s9.insert("e") == true );
//    Set s10;
//    assert( s10.insert("a") == true );
//    assert( s10.insert("b") == true );
//    assert( s10.insert("c") == true );
//    assert( s10.insert("d") == true );
//    Set s11;
//    assert( s11.insert("g") == true );
//    assert( s11.insert("h") == true );
//    assert( s11.insert("i") == true );
//    unite(s9, s10, s11);
//    assert( s9.size() == 5 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.get(1, str) == true );
//    assert( str == "d" );
//    assert( s9.get(2, str) == true );
//    assert( str == "c" );
//    assert( s9.get(3, str) == true );
//    assert( str == "b" );
//    assert( s9.get(4, str) == true );
//    assert( str == "a" );
//    assert( s10.size() == 4 );
//    assert( s10.get(0, str) == true );
//    assert( str == "d" );
//    assert( s10.get(1, str) == true );
//    assert( str == "c" );
//    assert( s10.get(2, str) == true );
//    assert( str == "b" );
//    assert( s10.get(3, str) == true );
//    assert( str == "a" );
//    assert( s11.size() == 5 );
//    assert( s11.get(0, str) == true );
//    assert( str == "e" );
//    assert( s11.get(1, str) == true );
//    assert( str == "d" );
//    assert( s11.get(2, str) == true );
//    assert( str == "c" );
//    assert( s11.get(3, str) == true );
//    assert( str == "b" );
//    assert( s11.get(4, str) == true );
//    assert( str == "a" );
//
//    // test unite for same set for s1 and s2
//    unite(s9, s9, s11);
//    assert( s9.size() == 5 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.get(1, str) == true );
//    assert( str == "d" );
//    assert( s9.get(2, str) == true );
//    assert( str == "c" );
//    assert( s9.get(3, str) == true );
//    assert( str == "b" );
//    assert( s9.get(4, str) == true );
//    assert( str == "a" );
//    assert( s11.size() == 5 );
//    assert( s11.get(0, str) == true );
//    assert( str == "e" );
//    assert( s11.get(1, str) == true );
//    assert( str == "d" );
//    assert( s11.get(2, str) == true );
//    assert( str == "c" );
//    assert( s11.get(3, str) == true );
//    assert( str == "b" );
//    assert( s11.get(4, str) == true );
//    assert( str == "a" );
//
//    // test unite for same set for s1 and result
//    unite(s9, s10, s9);
//    assert( s9.size() == 5 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.get(1, str) == true );
//    assert( str == "d" );
//    assert( s9.get(2, str) == true );
//    assert( str == "c" );
//    assert( s9.get(3, str) == true );
//    assert( str == "b" );
//    assert( s9.get(4, str) == true );
//    assert( str == "a" );
//    assert( s10.size() == 4 );
//    assert( s10.get(0, str) == true );
//    assert( str == "d" );
//    assert( s10.get(1, str) == true );
//    assert( str == "c" );
//    assert( s10.get(2, str) == true );
//    assert( str == "b" );
//    assert( s10.get(3, str) == true );
//    assert( str == "a" );
//
//    // test difference
//    difference(s9, s10, s11);
//    assert( s11.size() == 1 );
//    assert( s11.get(0, str) == true );
//    assert( str == "e" );
//
//    // test difference for same set for s1 and s2
//    difference(s9, s9, s11);
//    assert( s11.size() == 0 );
//    assert( s11.get(0, str) == false );
//    assert( str == "e" );
//
//    // test difference for same set for s1 and result
//    difference(s9, s10, s9);
//    assert( s9.size() == 1 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//
//    // test special case: list with 0 entries
//    Set s12;
//    assert( s12.empty() == true );
//    assert( s12.size() == 0 );
//    assert( s12.erase("") == false );
//    assert( s12.contains("") == false );
//    assert( s12.get(0, str) == false && str == "e" );
//    s12.swap(s9);
//    assert( s12.size() == 1 );
//    assert( s12.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.get(0, str) == false && str == "e" );
//    unite(s9, s12, s9);
//    assert( s12.size() == 1 );
//    assert( s12.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.size() == 1 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//    s9.erase("e");
//    assert( s9.get(0, str) == false && str == "e" );
//    difference(s9, s12, s9);
//    assert( s12.size() == 1 );
//    assert( s12.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.size() == 1 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//
//    // test special case: list with 1 entry
//    s12.erase("e");
//    s12.insert("a");
//    assert( s12.empty() == false );
//    assert( s12.size() == 1 );
//    assert( s12.contains("a") == true );
//    assert( s12.erase("a") == true );
//    s12.insert("a");
//    assert( s12.get(0, str) == true && str == "a" );
//    s12.swap(s9);
//    assert( s9.size() == 1 );
//    assert( s9.get(0, str) == true );
//    assert( str == "a" );
//    assert( s12.size() == 1 );
//    assert( s12.get(0, str) == true );
//    assert( str == "e" );
//    unite(s9, s12, s9);
//    assert( s9.size() == 2 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//    assert( s9.get(1, str) == true );
//    assert( str == "a" );
//
//    cerr << "Passed all tests" << endl;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// using ItemType = unsigned long; tests

#include "Set.h"
#include <iostream>
#include <cassert>
#include <type_traits>
using namespace std;

#define CHECKTYPE(f, t) { auto p = static_cast<t>(f); (void)p; }

static_assert(std::is_default_constructible<Set>::value,
              "Set must be default-constructible.");
static_assert(std::is_copy_constructible<Set>::value,
              "Set must be copy-constructible.");
static_assert(std::is_copy_assignable<Set>::value,
              "Set must be assignable.");

void thisFunctionWillNeverBeCalled()
{
    CHECKTYPE(&Set::empty,     bool (Set::*)() const);
    CHECKTYPE(&Set::size,      int  (Set::*)() const);
    CHECKTYPE(&Set::insert,    bool (Set::*)(const ItemType&));
    CHECKTYPE(&Set::erase,     bool (Set::*)(const ItemType&));
    CHECKTYPE(&Set::contains,  bool (Set::*)(const ItemType&) const);
    CHECKTYPE(&Set::get,       bool (Set::*)(int, ItemType&) const);
    CHECKTYPE(&Set::swap,      void (Set::*)(Set&));
    CHECKTYPE(unite,      void (*)(const Set&, const Set&, Set&));
    CHECKTYPE(difference, void (*)(const Set&, const Set&, Set&));
}

void test()
{
    Set uls;
    assert(uls.insert(10));
    assert(uls.insert(20));
    assert(uls.size() == 2);
    assert(uls.contains(20));
    ItemType x = 30;
    assert(uls.get(0, x)  &&  x == 20);
    assert(uls.get(1, x)  &&  x == 10);
}

int main()
{
    // smallberg tests

    test();

    Set s1;
    assert(s1.empty());
    ItemType x = 9876543;
    assert( !s1.get(42, x)  &&  x == 9876543); // x unchanged by get failure
    s1.insert(123456789);
    assert(s1.size() == 1);
    assert(s1.get(0, x)  &&  x == 123456789);

    // my tests

    // new set = empty, size = 0
    Set s2;
    assert( s2.empty() == true );
    assert( s2.size() == 0 );
    assert( s2.contains(0) == false );

    // insert 3 ints, check order
    s2.insert(2);
    s2.insert(1);
    s2.insert(3);

    // check duplicates
    s2.insert(2);
    s2.insert(1);
    s2.insert(3);

    // check empty = false
    assert( s2.empty() == false );

    // check size = 3
    assert( s2.size() == 3 );

    // try erasing something that isn't there
    assert( s2.erase(4) == false );
    assert( s2.size() == 3 );

    // erase
    s2.erase(2);
    assert( s2.size() == 2 );

    // add back
    s2.insert(2);
    assert( s2.size() == 3 );

    // check contains
    assert( s2.contains(1) == true );
    assert( s2.contains(2) == true );
    assert( s2.contains(3) == true );

    // check contains w something that isn't there
    assert( s2.contains(4) == false );

    // check get
    unsigned long i;
    assert( s2.get(0, i) == true );
    assert( i == 3 );
    assert( s2.get(1, i) == true );
    assert( i == 2 );
    assert( s2.get(2, i) == true );
    assert( i == 1 );
    assert( s2.get(3, i) == false );
    assert( i == 1 );
    assert( s2.get(-1, i) == false );
    assert( i == 1 );

    // swap
    Set s3;
    s3.insert(10);
    s3.insert(11);
    s2.swap(s3);
    assert( s2.size() == 2 );
    assert( s2.contains(10) == true );
    assert( s2.contains(11) == true );
    assert( s2.contains(1) == false );
    assert( s2.contains(2) == false );
    assert( s2.contains(3) == false );
    assert( s3.size() == 3 );
    assert( s3.contains(10) == false );
    assert( s3.contains(11) == false );
    assert( s3.contains(1) == true );
    assert( s3.contains(2) == true );
    assert( s3.contains(3) == true );

    // swap back
    s3.swap(s2);
    assert( s2.size() == 3 );
    assert( s2.contains(10) == false );
    assert( s2.contains(11) == false );
    assert( s2.contains(1) == true );
    assert( s2.contains(2) == true );
    assert( s2.contains(3) == true );
    assert( s3.size() == 2 );
    assert( s3.contains(10) == true );
    assert( s3.contains(11) == true );
    assert( s3.contains(1) == false );
    assert( s3.contains(2) == false );
    assert( s3.contains(3) == false );

    // test copy constructor
    Set s4(s3);
    assert( s3.empty() == false );
    assert( s4.empty() == false );
    assert( s3.size() == 2 );
    assert( s4.size() == 2 );
    assert( s4.erase(12) == false );
    assert( s4.erase(11) == true );
    assert( s3.size() == 2 );
    assert( s4.size() == 1 );
    assert( s4.insert(11) == true );
    assert( s4.insert(10) == false );
    assert( s3.size() == 2 );
    assert( s4.size() == 2 );
    assert( s3.contains(10) == true );
    assert( s3.contains(11) == true );
    assert( s4.contains(10) == true );
    assert( s4.contains(11) == true );
    assert( s3.get(0, i) == true );
    assert( i == 11 );
    assert( s3.get(1, i) == true );
    assert( i == 10 );
    assert( s3.get(2, i) == false );
    assert( i == 10 );
    assert( s3.get(-1, i) == false );
    assert( i == 10 );

    // test assignment operator
    s4 = s2;
    assert( s2.empty() == false );
    assert( s4.empty() == false );
    assert( s3.size() == 2 );
    assert( s2.size() == 3 );
    assert( s4.size() == 3 );
    assert( s4.erase(3) == true );
    assert( s4.erase(4) == false );
    assert( s2.size() == 3 );
    assert( s4.size() == 2 );
    assert( s4.insert(3) == true );
    assert( s4.insert(2) == false );
    assert( s2.size() == 3 );
    assert( s4.size() == 3 );
    assert( s2.contains(1) == true );
    assert( s2.contains(2) == true );
    assert( s2.contains(3) == true );
    assert( s4.contains(1) == true );
    assert( s4.contains(2) == true );
    assert( s4.contains(3) == true );
    assert( s4.get(0, i) == true );
    assert( i == 3 );
    assert( s4.get(1, i) == true );
    assert( i == 2 );
    assert( s4.get(2, i) == true );
    assert( i == 1 );
    assert( s4.get(3, i) == false );
    assert( i == 1 );
    assert( s4.get(-1, i) == false );
    assert( i == 1 );

    // test unite
    Set s5;
    assert( s5.insert(2) == true );
    assert( s5.insert(8) == true );
    assert( s5.insert(3) == true );
    assert( s5.insert(9) == true );
    assert( s5.insert(5) == true );
    Set s6;
    assert( s6.insert(6) == true );
    assert( s6.insert(3) == true );
    assert( s6.insert(8) == true );
    assert( s6.insert(5) == true );
    assert( s6.insert(10) == true );
    Set s7;
    assert( s7.insert(6) == true );
    assert( s7.insert(3) == true );
    assert( s7.insert(8) == true );
    unite(s5, s6, s7);
    assert( s5.size() == 5 );
    assert( s5.get(0, i) == true );
    assert( i == 9 );
    assert( s5.get(1, i) == true );
    assert( i == 8 );
    assert( s5.get(2, i) == true );
    assert( i == 5 );
    assert( s5.get(3, i) == true );
    assert( i == 3 );
    assert( s5.get(4, i) == true );
    assert( i == 2 );
    assert( s6.size() == 5 );
    assert( s6.get(0, i) == true );
    assert( i == 10 );
    assert( s6.get(1, i) == true );
    assert( i == 8 );
    assert( s6.get(2, i) == true );
    assert( i == 6 );
    assert( s6.get(3, i) == true );
    assert( i == 5 );
    assert( s6.get(4, i) == true );
    assert( i == 3 );
    assert( s7.size() == 7 );
    assert( s7.get(0, i) == true );
    assert( i == 10 );
    assert( s7.get(1, i) == true );
    assert( i == 9 );
    assert( s7.get(2, i) == true );
    assert( i == 8 );
    assert( s7.get(3, i) == true );
    assert( i == 6 );
    assert( s7.get(4, i) == true );
    assert( i == 5 );
    assert( s7.get(5, i) == true );
    assert( i == 3 );
    assert( s7.get(6, i) == true );
    assert( i == 2 );

    // test unite for same set for s1 and s2
    unite(s5, s5, s7);
    assert( s5.size() == 5 );
    assert( s5.get(0, i) == true );
    assert( i == 9 );
    assert( s5.get(1, i) == true );
    assert( i == 8 );
    assert( s5.get(2, i) == true );
    assert( i == 5 );
    assert( s5.get(3, i) == true );
    assert( i == 3 );
    assert( s5.get(4, i) == true );
    assert( i == 2 );
    assert( s7.size() == 5 );
    assert( s7.get(0, i) == true );
    assert( i == 9 );
    assert( s7.get(1, i) == true );
    assert( i == 8 );
    assert( s7.get(2, i) == true );
    assert( i == 5 );
    assert( s7.get(3, i) == true );
    assert( i == 3 );
    assert( s7.get(4, i) == true );
    assert( i == 2 );

    // test unite for same set for s1 and result
    unite(s5, s6, s5);
    assert( s5.size() == 7 );
    assert( s5.get(0, i) == true );
    assert( i == 10 );
    assert( s5.get(1, i) == true );
    assert( i == 9 );
    assert( s5.get(2, i) == true );
    assert( i == 8 );
    assert( s5.get(3, i) == true );
    assert( i == 6 );
    assert( s5.get(4, i) == true );
    assert( i == 5 );
    assert( s5.get(5, i) == true );
    assert( i == 3 );
    assert( s5.get(6, i) == true );
    assert( i == 2 );
    assert( s6.size() == 5 );
    assert( s6.get(0, i) == true );
    assert( i == 10 );
    assert( s6.get(1, i) == true );
    assert( i == 8 );
    assert( s6.get(2, i) == true );
    assert( i == 6 );
    assert( s6.get(3, i) == true );
    assert( i == 5 );
    assert( s6.get(4, i) == true );
    assert( i == 3 );

    // test difference
    int i_max = s5.size();
    for (int i = 0; i < i_max; i++) {
        ItemType value;
        s5.get(0, value);
        s5.erase(value);
    }
    assert( s5.insert(2) == true );
    assert( s5.insert(8) == true );
    assert( s5.insert(3) == true );
    assert( s5.insert(9) == true );
    assert( s5.insert(5) == true );
    difference(s5, s6, s7);
    assert( s5.size() == 5 );
    assert( s5.get(0, i) == true );
    assert( i == 9 );
    assert( s5.get(1, i) == true );
    assert( i == 8 );
    assert( s5.get(2, i) == true );
    assert( i == 5 );
    assert( s5.get(3, i) == true );
    assert( i == 3 );
    assert( s5.get(4, i) == true );
    assert( i == 2 );
    assert( s6.size() == 5 );
    assert( s6.get(0, i) == true );
    assert( i == 10 );
    assert( s6.get(1, i) == true );
    assert( i == 8 );
    assert( s6.get(2, i) == true );
    assert( i == 6 );
    assert( s6.get(3, i) == true );
    assert( i == 5 );
    assert( s6.get(4, i) == true );
    assert( i == 3 );
    assert( s7.size() == 4 );
    assert( s7.get(0, i) == true );
    assert( i == 10 );
    assert( s7.get(1, i) == true );
    assert( i == 9 );
    assert( s7.get(2, i) == true );
    assert( i == 6 );
    assert( s7.get(3, i) == true );
    assert( i == 2 );

    // test difference for same set for s1 and s2
    difference(s5, s5, s7);
    assert( s5.size() == 5 );
    assert( s5.get(0, i) == true );
    assert( i == 9 );
    assert( s5.get(1, i) == true );
    assert( i == 8 );
    assert( s5.get(2, i) == true );
    assert( i == 5 );
    assert( s5.get(3, i) == true );
    assert( i == 3 );
    assert( s5.get(4, i) == true );
    assert( i == 2 );
    assert( s7.size() == 0 );
    assert( s7.get(0, i) == false );
    assert( i == 2 );

    // test difference for same set for s1 and result
    difference(s5, s6, s5);
    assert( s5.size() == 4 );
    assert( s5.get(0, i) == true );
    assert( i == 10 );
    assert( s5.get(1, i) == true );
    assert( i == 9 );
    assert( s5.get(2, i) == true );
    assert( i == 6 );
    assert( s5.get(3, i) == true );
    assert( i == 2 );

    // test special case: list with 0 entries
    Set s8;
    assert( s8.empty() == true );
    assert( s8.size() == 0 );
    assert( s8.erase(0) == false );
    assert( s8.contains(0) == false );
    assert( s8.get(0, i) == false && i == 2 );
    s8.swap(s5);
    assert( s8.get(0, i) == true && i == 10 );
    assert( s8.get(1, i) == true && i == 9 );
    assert( s8.get(2, i) == true && i == 6 );
    assert( s8.get(3, i) == true && i == 2 );
    assert( s5.get(0, i) == false && i == 2 );
    unite(s5, s8, s5);
    assert( s5.get(0, i) == true && i == 10 );
    assert( s5.get(1, i) == true && i == 9 );
    assert( s5.get(2, i) == true && i == 6 );
    assert( s5.get(3, i) == true && i == 2 );
    assert( s8.get(0, i) == true && i == 10 );
    assert( s8.get(1, i) == true && i == 9 );
    assert( s8.get(2, i) == true && i == 6 );
    assert( s8.get(3, i) == true && i == 2 );
    s5.erase(10);
    s5.erase(9);
    s5.erase(6);
    s5.erase(2);
    assert( s5.get(0, i) == false && i == 2 );
    difference(s5, s8, s5);
    assert( s5.get(0, i) == true && i == 10 );
    assert( s5.get(1, i) == true && i == 9 );
    assert( s5.get(2, i) == true && i == 6 );
    assert( s5.get(3, i) == true && i == 2 );
    assert( s8.get(0, i) == true && i == 10 );
    assert( s8.get(1, i) == true && i == 9 );
    assert( s8.get(2, i) == true && i == 6 );
    assert( s8.get(3, i) == true && i == 2 );

    // test special case: list with 1 entry
    s8.erase(10);
    s8.erase(9);
    s8.erase(6);
    s8.erase(2);
    s8.insert(0);
    assert( s8.empty() == false );
    assert( s8.size() == 1 );
    assert( s8.contains(0) == true );
    assert( s8.erase(0) == true );
    s8.insert(0);
    assert( s8.get(0, i) == true && i == 0 );
    s8.swap(s5);
    assert( s8.get(0, i) == true && i == 10 );
    assert( s8.get(1, i) == true && i == 9 );
    assert( s8.get(2, i) == true && i == 6 );
    assert( s8.get(3, i) == true && i == 2 );
    assert( s5.get(0, i) == true && i == 0 );
    unite(s5, s8, s5);
    assert( s5.get(0, i) == true && i == 10 );
    assert( s5.get(1, i) == true && i == 9 );
    assert( s5.get(2, i) == true && i == 6 );
    assert( s5.get(3, i) == true && i == 2 );
    assert( s5.get(4, i) == true && i == 0 );
    assert( s8.get(0, i) == true && i == 10 );
    assert( s8.get(1, i) == true && i == 9 );
    assert( s8.get(2, i) == true && i == 6 );
    assert( s8.get(3, i) == true && i == 2 );
    s5.erase(10);
    s5.erase(9);
    s5.erase(6);
    s5.erase(2);
    s5.erase(0);
    assert( s5.get(0, i) == false && i == 2 );
    difference(s5, s8, s5);
    assert( s5.get(0, i) == true && i == 10 );
    assert( s5.get(1, i) == true && i == 9 );
    assert( s5.get(2, i) == true && i == 6 );
    assert( s5.get(3, i) == true && i == 2 );
    assert( s8.get(0, i) == true && i == 10 );
    assert( s8.get(1, i) == true && i == 9 );
    assert( s8.get(2, i) == true && i == 6 );
    assert( s8.get(3, i) == true && i == 2 );

    cerr << "Passed all tests" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //tester.cpp
 //To test HW 1 Problem 5, uncomment the following line:
 //#define TESTNEW

//#ifdef TESTNEW
//#include "newSet.h" // ItemType should be a type alias for int
//#else
//#include "Set.h"    // ItemType should be a type alias for int
//#endif

//#include <iostream>
//#include <string>
//#include <vector>
//#include <type_traits>
//#include <cstdlib>
//#include <cassert>
//using namespace std;
//
//const ItemType DUMMY = 123;
//const ItemType DEFAULT = 0;
//const ItemType ARRAY[6] = { 10, 20, 30, 40, 50, 60 };
//
//bool isPermutation(const Set& s, const ItemType a[], int n)
//{
//        if (s.size() != n)
//                return false;
//        vector<ItemType> b(n);
//        for (int i = 0; i < n; i++)
//                s.get(i, b[i]);
//        for (int j = 0; j < n; j++)
//        {
//                int i;
//                for (i = j; i < n; i++)
//                {
//                        if (a[j] == b[i])
//                        {
//                                ItemType t = b[j];
//                                b[j] = b[i];
//                                b[i] = t;
//                                break;
//                        }
//                }
//                if (i == n)
//                        return false;
//        }
//        return true;
//}
//
//const int SPEC_MAX = 150;
//
//void testone(int n)
//{
//    Set s;
//    switch (n)
//    {
//                 default: {
//        cout << "Bad argument" << endl;
//            } break; case  1: {
//        assert((is_same<decltype(&Set::empty), bool (Set::*)() const>::value));
//            } break; case  2: {
//        assert((is_same<decltype(&Set::size), int (Set::*)() const>::value));
//            } break; case  3: {
//        assert((is_same<decltype(&Set::contains),
//                    bool (Set::*)(const ItemType&) const>::value));
//            } break; case  4: {
//        assert((is_same<decltype(&Set::get),
//                    bool (Set::*)(int, ItemType&) const>::value));
//            } break; case  5: {
//        assert(s.empty());
//            } break; case  6: {
//        assert(s.size() == 0);
//            } break; case  7: {
//        assert(!s.erase(DEFAULT)  &&  s.size() == 0);
//            } break; case  8: {
//        assert(!s.contains(DEFAULT));
//            } break; case  9: {
//        ItemType x = DUMMY;
//        assert(!s.get(0, x));
//            } break; case 10: {
//        ItemType x = DUMMY;
//        s.get(0, x);
//        assert(x == DUMMY);
//            } break; case 11: {
//        assert(s.insert(DUMMY));
//            } break; case 12: {
//        s.insert(DUMMY);
//        assert(!s.empty());
//            } break; case 13: {
//        s.insert(DUMMY);
//        assert(s.size() == 1);
//            } break; case 14: {
//        s.insert(DUMMY);
//        assert(s.contains(DUMMY));
//            } break; case 15: {
//        s.insert(DUMMY);
//        ItemType x = DEFAULT;
//        assert(s.get(0, x));
//            } break; case 16: {
//        s.insert(DUMMY);
//        ItemType x = DEFAULT;
//        s.get(0, x);
//        assert(x == DUMMY);
//            } break; case 17: {
//        assert(s.insert(DUMMY)  &&  !s.insert(DUMMY));
//            } break; case 18: {
//        s.insert(DUMMY);
//        s.insert(DUMMY);
//        assert(s.size() == 1);
//            } break; case 19: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        assert(!s.empty()   &&  s.size() == 2);
//            } break; case 20: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        ItemType x = DUMMY;
//        s.get(0, x);
//        assert(x == ARRAY[1]);
//            } break; case 21: {
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        ItemType x = DUMMY;
//        s.get(0, x);
//        assert(x == ARRAY[1]);
//            } break; case 22: {
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        ItemType x = DUMMY;
//        s.get(0, x);
//        ItemType y = DUMMY;
//        s.get(1, y);
//        assert(x == ARRAY[1]  &&  y == ARRAY[0]);
//            } break; case 23: {
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[4]);
//        s.insert(ARRAY[2]);
//        assert(s.size() == 5);
//            } break; case 24: {
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[4]);
//        s.insert(ARRAY[2]);
//        ItemType x;
//        for (int k = 0; k < 5; k++)
//        {
//        s.get(k, x);
//        assert(x == ARRAY[5-1-k]);
//        }
//            } break; case 25: {
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        assert(s.size() == 2);
//            } break; case 26: {
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        ItemType x;
//        for (int k = 0; k < 2; k++)
//        {
//        s.get(k, x);
//        assert(x == ARRAY[2-1-k]);
//        }
//            } break; case 27: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[4]);
//        assert(s.erase(ARRAY[3]));
//            } break; case 28: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[4]);
//        s.erase(ARRAY[3]);
//        assert(s.size() == 4);
//            } break; case 29: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[4]);
//        assert(s.erase(ARRAY[0])  &&  s.size() == 4);
//            } break; case 30: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[4]);
//        assert(s.erase(ARRAY[4])  &&  s.size() == 4);
//            } break; case 31: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[1]);
//        assert(s.erase(ARRAY[1])  &&  s.size() == 2);
//            } break; case 32: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[1]);
//        s.erase(ARRAY[3]);
//        assert(isPermutation(s, ARRAY, 3));
//            } break; case 33: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[3]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[3]);
//        s.erase(ARRAY[3]);
//        assert(isPermutation(s, ARRAY, 3));
//            } break; case 34: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        assert(!s.erase(ARRAY[4]));
//            } break; case 35: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        s.erase(ARRAY[4]);
//        assert(s.size() == 4);
//            } break; case 36: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.erase(ARRAY[0]);
//        s.erase(ARRAY[1]);
//        assert(s.size() == 0);
//            } break; case 37: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        ItemType x;
//        assert(!s.get(-1, x));
//            } break; case 38: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        ItemType x = DUMMY;
//        s.get(-1, x);
//        assert(x == DUMMY);
//            } break; case 39: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        ItemType x;
//        assert(! s.get(3, x));
//            } break; case 40: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        ItemType x = DUMMY;
//        s.get(3, x);
//        assert(x == DUMMY);
//            } break; case 41: {
//        s.insert(DEFAULT);
//        ItemType x = DUMMY;
//        s.get(0, x);
//        assert(s.size() == 1  &&  x == DEFAULT);
//            } break; case 42: {
//        s.insert(DEFAULT);
//        s.erase(DEFAULT);
//        assert(s.size() == 0  &&  !s.contains(DEFAULT));
//            } break; case 43: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.erase(ARRAY[1]);
//        assert(!s.contains(DEFAULT));
//            } break; case 44: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.erase(ARRAY[1]);
//        assert(s.contains(ARRAY[2]));
//            } break; case 45: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.erase(ARRAY[2]);
//        assert(s.size() == 2  &&  !s.contains(ARRAY[2]));
//            } break; case 46: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.erase(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        s.insert(ARRAY[3]);
//        assert(s.size() == 3  &&  s.contains(ARRAY[2])  &&
//                s.contains(ARRAY[3]));
//            } break; case 47: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        {
//        Set s2;
//        s2.insert(ARRAY[2]);
//        s2.insert(ARRAY[3]);
//        s.swap(s2);
//        assert(s.size() == 2  &&  s2.size() == 2);
//        for (int k = 0; k < 2; k++)
//        {
//            assert(!s.contains(ARRAY[k]));
//            assert(s2.contains(ARRAY[k]));
//        }
//        for (int k = 2; k < 4; k++)
//        {
//            assert(s.contains(ARRAY[k]));
//            assert(!s2.contains(ARRAY[k]));
//        }
//        }
//            } break; case 48: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        {
//        Set s2;
//        s2.insert(ARRAY[3]);
//        s2.insert(ARRAY[4]);
//        s.swap(s2);
//        assert(s.size() == 2  &&  s2.size() == 3);
//        }
//            } break; case 49: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        {
//        Set s2;
//        s2.insert(ARRAY[3]);
//        s2.insert(ARRAY[4]);
//        s.swap(s2);
//        for (int k = 0; k < 3; k++)
//        {
//            assert(!s.contains(ARRAY[k]));
//            assert(s2.contains(ARRAY[k]));
//        }
//        for (int k = 3; k < 5; k++)
//        {
//            assert(s.contains(ARRAY[k]));
//            assert(!s2.contains(ARRAY[k]));
//        }
//        }
//            } break; case 50: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        {
//        Set s2;
//        s2.insert(ARRAY[3]);
//        s2.insert(ARRAY[4]);
//        s2.swap(s);
//        for (int k = 0; k < 3; k++)
//        {
//            assert(!s.contains(ARRAY[k]));
//            assert(s2.contains(ARRAY[k]));
//        }
//        for (int k = 3; k < 5; k++)
//        {
//            assert(s.contains(ARRAY[k]));
//            assert(!s2.contains(ARRAY[k]));
//        }
//        }
//            } break; case 51: {
//        for (int k = 0; k < SPEC_MAX; k++)
//        assert(s.insert(k));
//        assert(s.size() == SPEC_MAX);
//            } break; case 52: {
//        for (int k = 0; k < SPEC_MAX; k++)
//        assert(s.insert(k));
//        ItemType x = SPEC_MAX;
//        //assert(!s.insert(x)  &&  s.size() == SPEC_MAX  &&  !s.contains(x));
//            } break; case 53: {
//        assert(s.insert(DUMMY));
//        for (int k = 0; k < 10*SPEC_MAX; k++)
//        assert(!s.insert(DUMMY));
//        assert(s.size() == 1);
//            } break; case 54: {
//        for (int k = 0; k < SPEC_MAX; k++)
//        assert(s.insert(k));
//        //assert(!s.insert(SPEC_MAX));
//        s.erase(0);
//        assert(s.insert(SPEC_MAX+1));
//        //assert(!s.insert(SPEC_MAX+2));
//#ifdef TESTNEW
//            } break; case 55: {
//          // This test checked that swap executes the same number of
//          // statements no matter how many items are in the sequences
//            } break; case 56: {
//        const int CAPACITY = 2;
//        Set s2(CAPACITY);
//        for (int k = 0; k < CAPACITY; k++)
//        assert(s2.insert(k));
//        assert(! s2.insert(CAPACITY));
//            } break; case 57: {
//        const int CAPACITY = SPEC_MAX*2;
//        Set s2(CAPACITY);
//        for (int k = 0; k < CAPACITY; k++)
//        assert(s2.insert(k));
//        assert(! s2.insert(CAPACITY));
//            } break; case 58: {
//          // This test checked that the destructor deletes the dynamic array.
//            } break; case 59: {
//          // This test checked that Sets can be properly copied and destroyed.
//            } break; case 60: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        {
//        Set s2(s);
//        s2.insert(ARRAY[3]);
//        assert(s2.size() == s.size()+1);
//        }
//            } break; case 61: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        {
//        Set s2(s);
//        s2.insert(ARRAY[3]);
//        assert(isPermutation(s2, ARRAY, 4));
//        }
//            } break; case 62: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        s.insert(ARRAY[2]);
//        {
//        Set s2(s);
//        s2.insert(ARRAY[3]);
//        assert(isPermutation(s, ARRAY, 3));
//        }
//            } break; case 63: {
//        {
//        Set s2;
//        Set s3(s2);
//        assert(s2.size() == 0  &&  s3.size() == 0);
//        s2.insert(ARRAY[0]);
//        s3.insert(ARRAY[1]);
//        assert(s2.size() == 1  &&  s3.size() == 1);
//        ItemType x;
//        s2.get(0, x);
//        assert(x == ARRAY[0]);
//        s3.get(0, x);
//        assert(x == ARRAY[1]);
//        }
//            } break; case 64: {
//        {
//        Set s2(2);
//        s2.insert(ARRAY[0]);
//        s2.insert(ARRAY[1]);
//        Set s3(s2);
//        assert(!s3.insert(ARRAY[2]));
//        }
//            } break; case 65: {
//        {
//        Set s2;
//        Set s3;
//        s3.insert(ARRAY[0]);
//        s3.insert(ARRAY[1]);
//        assert(s3.size() == 2);
//        s3 = s2;
//        assert(s3.size() == 0);
//        }
//            } break; case 66: {
//        {
//        Set s2;
//        Set s3;
//        s3.insert(ARRAY[0]);
//        s3.insert(ARRAY[1]);
//        s3 = s2;
//        s2.insert(ARRAY[2]);
//        s3.insert(ARRAY[3]);
//        assert(s2.size() == 1  &&  s3.size() == 1);
//        ItemType x;
//        s2.get(0, x);
//        assert(x == ARRAY[2]);
//        s3.get(0, x);
//        assert(x == ARRAY[3]);
//        }
//            } break; case 67: {
//        {
//        Set s2;
//        Set s3;
//        s3.insert(ARRAY[0]);
//        s3.insert(ARRAY[1]);
//        assert(s3.size() == 2);
//        s2 = s3;
//        assert(s2.size() == 2  &&  s3.size() == 2);
//        s2.insert(ARRAY[2]);
//        s3.insert(ARRAY[3]);
//        assert(s2.size() == 3  &&  s3.size() == 3);
//        assert(isPermutation(s2, ARRAY, 3));
//        ItemType a[3] = { ARRAY[0], ARRAY[1], ARRAY[3] };
//        assert(isPermutation(s3, a, 3));
//        }
//            } break; case 68: {
//              // This test checked that the assignment operator doesn't just
//          // copy a pointer.
//            } break; case 69: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        {
//        Set s2;
//        s2.insert(ARRAY[2]);
//        s2.insert(ARRAY[3]);
//        s2.insert(ARRAY[4]);
//        s2 = s;
//        s2.insert(ARRAY[5]);
//        assert(s2.size() == s.size()+1);
//        }
//            } break; case 70: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        {
//        Set s2;
//        s2.insert(ARRAY[3]);
//        s2.insert(ARRAY[4]);
//        s2.insert(ARRAY[5]);
//        s2 = s;
//        s2.insert(ARRAY[2]);
//        assert(isPermutation(s2, ARRAY, 3));
//        }
//            } break; case 71: {
//        s.insert(ARRAY[0]);
//        s.insert(ARRAY[1]);
//        {
//        Set s2;
//        s2.insert(ARRAY[3]);
//        s2.insert(ARRAY[4]);
//        s2.insert(ARRAY[5]);
//        s2 = s;
//        s2.insert(ARRAY[2]);
//        assert(isPermutation(s, ARRAY, 2));
//        }
//            } break; case 72: {
//          // This test checked that self-assignment doesn't change the
//                  // number of items in existence.
//            } break; case 73: {
//        {
//        Set s2;
//        s2.insert(ARRAY[0]);
//        s2.insert(ARRAY[1]);
//        s2.insert(ARRAY[2]);
//        s2 = s2;
//        s2.insert(ARRAY[3]);
//        assert(isPermutation(s2, ARRAY, 4));
//        }
//#endif
//            }
//    }
//}

//int main()
//{
//    for (int i = 1; i <= 80; i++) {
//        testone(i);
//        cout << "Passed " << i << endl;
//    }
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#ifndef OURTYPE_INCLUDED
//#define OURTYPE_INCLUDED
//
//struct OurType
//{
//    explicit OurType(int v = 0) : m_value(v) { m_count++; }
//    OurType(const OurType& other) : m_value(other.m_value)
//    { m_count++; m_asstcopycount++; }
//    ~OurType() { m_count--; }
//    OurType& operator=(const OurType& rhs)
//    { m_value = rhs.m_value; m_asstcopycount++; return *this; }
//
//    int m_value;
//    static int m_count;
//    static int m_asstcopycount;
//};
//
//inline
//bool operator==(const OurType& lhs, const OurType& rhs)
//{ return lhs.m_value == rhs.m_value; }
//
//inline
//bool operator<(const OurType& lhs, const OurType& rhs)
//{ return lhs.m_value < rhs.m_value; }
//
//inline
//bool operator!=(const OurType& lhs, const OurType& rhs)
//{ return ! (lhs == rhs); }
//
//inline
//bool operator<=(const OurType& lhs, const OurType& rhs)
//{ return ! (rhs < lhs); }
//
//inline
//bool operator>=(const OurType& lhs, const OurType& rhs)
//{ return ! (lhs < rhs); }
//
//inline
//bool operator>(const OurType& lhs, const OurType& rhs)
//{ return rhs < lhs; }
//
//inline
//bool operator==(const OurType& lhs, int rhs)
//{ return lhs.m_value == rhs; }
//
//inline
//bool operator!=(const OurType& lhs, int rhs)
//{ return ! (lhs == rhs); }
//
//#include <iostream>
//
//inline
//std::ostream& operator<<(std::ostream& lhs, const OurType& rhs)
//{ return lhs << rhs.m_value; }
//
//#endif // OURTYPE_INCLUDED
//
//#include "Set.h"
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <type_traits>
//#include <cassert>
//
//using namespace std;
//
//int OurType::m_count = 0;
//int OurType::m_asstcopycount = 0;
//
//inline int itemcount()
//{
//        return OurType::m_count;
//}
//
//inline int nasstcopys()
//{
//        return OurType::m_asstcopycount;
//}
//
//ItemType SOMEVAL = ItemType(123);
//ItemType DEFAULT = ItemType();
//ItemType ARRAY[6] = {
//        ItemType(10), ItemType(20), ItemType(30),
//        ItemType(40), ItemType(50), ItemType(60),
//};
//
//bool isPermutation(const Set& s, const ItemType a[], int n)
//{
//        if (s.size() != n)
//                return false;
//        vector<ItemType> b(n);
//        for (int i = 0; i < n; i++)
//                s.get(i, b[i]);
//        for (int j = 0; j < n; j++)
//        {
//                int i;
//                for (i = j; i < n; i++)
//                {
//                        if (a[j] == b[i])
//                        {
//                                ItemType t = b[j];
//                                b[j] = b[i];
//                                b[i] = t;
//                                break;
//                        }
//                }
//                if (i == n)
//                        return false;
//        }
//        return true;
//}
//
//void testone(int n)
//{
//        Set s;
//        switch (n)
//        {
//                                 default: {
//            cout << "Bad argument" << endl;
//                        } break; case  1: {
//            assert((is_same<decltype(&Set::empty), bool (Set::*)() const>::value));
//                        } break; case  2: {
//            assert((is_same<decltype(&Set::size), int (Set::*)() const>::value));
//                        } break; case  3: {
//            assert((is_same<decltype(&Set::contains), bool (Set::*)(const ItemType&) const>::value));
//                        } break; case  4: {
//            assert((is_same<decltype(&Set::get), bool (Set::*)(int, ItemType&) const>::value));
//                        } break; case  5: {
//            assert(s.empty());
//                        } break; case  6: {
//            assert(s.size() == 0);
//                        } break; case  7: {
//            assert(!s.erase(DEFAULT)  &&  s.size() == 0);
//                        } break; case  8: {
//            assert(!s.contains(DEFAULT));
//                        } break; case  9: {
//            ItemType x = SOMEVAL;
//            assert(!s.get(0, x));
//                        } break; case 10: {
//            ItemType x = SOMEVAL;
//            s.get(0, x);
//            assert(x == SOMEVAL);
//                        } break; case 11: {
//            assert(s.insert(SOMEVAL));
//                        } break; case 12: {
//            s.insert(SOMEVAL);
//            assert(!s.empty());
//                        } break; case 13: {
//            s.insert(SOMEVAL);
//            assert(s.size() == 1);
//                        } break; case 14: {
//            s.insert(SOMEVAL);
//            assert(s.contains(SOMEVAL));
//                        } break; case 15: {
//            s.insert(SOMEVAL);
//            ItemType x = DEFAULT;
//            assert(s.get(0, x));
//                        } break; case 16: {
//            s.insert(SOMEVAL);
//            ItemType x = DEFAULT;
//            s.get(0, x);
//            assert(x == SOMEVAL);
//                        } break; case 17: {
//            assert(s.insert(SOMEVAL)  &&  !s.insert(SOMEVAL));
//                        } break; case 18: {
//            s.insert(SOMEVAL);
//            s.insert(SOMEVAL);
//            assert(s.size() == 1);
//                        } break; case 19: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            assert(!s.empty()   &&  s.size() == 2);
//                        } break; case 20: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            ItemType x = SOMEVAL;
//            s.get(0, x);
//            assert(x == ARRAY[1]);
//                        } break; case 21: {
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            ItemType x = SOMEVAL;
//            s.get(0, x);
//            assert(x == ARRAY[1]);
//                        } break; case 22: {
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            ItemType x = SOMEVAL;
//            s.get(0, x);
//            ItemType y = SOMEVAL;
//            s.get(1, y);
//            assert(x == ARRAY[1]  &&  y == ARRAY[0]);
//                        } break; case 23: {
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[4]);
//            s.insert(ARRAY[2]);
//            assert(s.size() == 5);
//                        } break; case 24: {
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[4]);
//            s.insert(ARRAY[2]);
//            ItemType x;
//            for (int k = 0; k < 5; k++)
//            {
//                s.get(k, x);
//                assert(x == ARRAY[5-1-k]);
//            }
//                        } break; case 25: {
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            assert(s.size() == 2);
//                        } break; case 26: {
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            ItemType x;
//            for (int k = 0; k < 2; k++)
//            {
//                s.get(k, x);
//                assert(x == ARRAY[2-1-k]);
//            }
//                        } break; case 27: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[4]);
//            assert(s.erase(ARRAY[3]));
//                        } break; case 28: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[4]);
//            s.erase(ARRAY[3]);
//            assert(s.size() == 4);
//                        } break; case 29: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[4]);
//            assert(s.erase(ARRAY[0])  &&  s.size() == 4);
//                        } break; case 30: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[4]);
//            assert(s.erase(ARRAY[4])  &&  s.size() == 4);
//                        } break; case 31: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[1]);
//            assert(s.erase(ARRAY[1])  &&  s.size() == 2);
//                        } break; case 32: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[1]);
//            s.erase(ARRAY[3]);
//            assert(isPermutation(s, ARRAY, 3));
//                        } break; case 33: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[3]);
//            s.erase(ARRAY[3]);
//            assert(isPermutation(s, ARRAY, 3));
//                        } break; case 34: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            assert(!s.erase(ARRAY[4]));
//                        } break; case 35: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.erase(ARRAY[4]);
//            assert(s.size() == 4);
//                        } break; case 36: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.erase(ARRAY[0]);
//            s.erase(ARRAY[1]);
//            assert(s.size() == 0);
//                        } break; case 37: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            ItemType x;
//            assert(!s.get(-1, x));
//                        } break; case 38: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            ItemType x = SOMEVAL;
//            s.get(-1, x);
//            assert(x == SOMEVAL);
//                        } break; case 39: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            ItemType x;
//            assert(! s.get(3, x));
//                        } break; case 40: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            ItemType x = SOMEVAL;
//            s.get(3, x);
//            assert(x == SOMEVAL);
//                        } break; case 41: {
//            s.insert(DEFAULT);
//            ItemType x = SOMEVAL;
//            s.get(0, x);
//            assert(s.size() == 1  &&  x == DEFAULT);
//                        } break; case 42: {
//            s.insert(DEFAULT);
//            s.erase(DEFAULT);
//            assert(s.size() == 0  &&  !s.contains(DEFAULT));
//                        } break; case 43: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.erase(ARRAY[1]);
//            assert(!s.contains(DEFAULT));
//                        } break; case 44: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.erase(ARRAY[1]);
//            assert(s.contains(ARRAY[2]));
//                        } break; case 45: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.erase(ARRAY[2]);
//            assert(s.size() == 2  &&  !s.contains(ARRAY[2]));
//                        } break; case 46: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.erase(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            assert(s.size() == 3  &&  s.contains(ARRAY[2])  &&
//                                s.contains(ARRAY[3]));
//                        } break; case 47: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            {
//                Set s2;
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                s.swap(s2);
//                assert(s.size() == 2  &&  s2.size() == 3);
//            }
//                        } break; case 48: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            {
//                Set s2;
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                s.swap(s2);
//                for (int k = 0; k < 3; k++)
//                {
//                        assert(!s.contains(ARRAY[k]));
//                        assert(s2.contains(ARRAY[k]));
//                }
//                for (int k = 3; k < 5; k++)
//                {
//                        assert(s.contains(ARRAY[k]));
//                        assert(!s2.contains(ARRAY[k]));
//                }
//            }
//                        } break; case 49: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[4]);
//            {
//                Set s2;
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                s2.insert(ARRAY[0]);
//                int n = nasstcopys();
//                s.swap(s2);
//                int n2 = nasstcopys();
//                assert(n2 >= n  &&  n2 <= n+3);  // swapping head nodes OK
//            }
//                        } break; case 50: {
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                s2.insert(ARRAY[2]);
//                s2.erase(ARRAY[1]);
//                s2.insert(ARRAY[3]);
//                s2.erase(ARRAY[2]);
//                s2.insert(ARRAY[1]);
//                s2.erase(ARRAY[0]);
//            }
//            assert(true);  // no corruption so bad that destruction failed
//                        } break; case 51: {
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                Set s3(s2);
//                s3.insert(ARRAY[2]);
//                s3.erase(ARRAY[1]);
//                s3.insert(ARRAY[3]);
//                s3.erase(ARRAY[2]);
//                s3.insert(ARRAY[1]);
//                s3.erase(ARRAY[0]);
//            }
//            assert(true);  // no corruption so bad that destruction failed
//                        } break; case 52: {
//            int before = itemcount();
//            {
//                Set s2;
//                s2.insert(SOMEVAL);
//                //assert(itemcount() > before);
//            }
//            assert(itemcount() == before);
//                        } break; case 53: {
//            int before = itemcount();
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                s2.insert(ARRAY[2]);
//                int mid = itemcount();
//                Set s3(s2);
//                assert(s3.size() == 3);
//                assert(itemcount() - mid == mid - before);
//            }
//            assert(itemcount() == before);
//                        } break; case 54: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            {
//                Set s2(s);
//                s2.insert(ARRAY[3]);
//                assert(s2.size() == s.size()+1);
//            }
//                        } break; case 55: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            {
//                Set s2(s);
//                s2.insert(ARRAY[3]);
//                assert(isPermutation(s2, ARRAY, 4));
//            }
//                        } break; case 56: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            {
//                Set s2(s);
//                s2.insert(ARRAY[3]);
//                assert(isPermutation(s, ARRAY, 3));
//            }
//                        } break; case 57: {
//            {
//                Set s2;
//                Set s3(s2);
//                assert(s2.size() == 0  &&  s3.size() == 0);
//                s2.insert(ARRAY[0]);
//                s3.insert(ARRAY[1]);
//                assert(s2.size() == 1  &&  s3.size() == 1);
//                ItemType x;
//                s2.get(0, x);
//                assert(x == ARRAY[0]);
//                s3.get(0, x);
//                assert(x == ARRAY[1]);
//            }
//                        } break; case 58: {
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                Set s3;
//                s3.insert(ARRAY[3]);
//                s3.insert(ARRAY[4]);
//                s3 = s2;
//                s3.insert(ARRAY[2]);
//                s3.erase(ARRAY[1]);
//                s3.insert(ARRAY[3]);
//                s3.erase(ARRAY[2]);
//                s3.insert(ARRAY[1]);
//                s3.erase(ARRAY[0]);
//            }
//            assert(true);  // no corruption so bad that destruction failed
//                        } break; case 59: {
//            int before = itemcount();
//            {
//                Set s2;
//                Set s3;
//                int mid = itemcount();
//                s3.insert(ARRAY[0]);
//                s3.insert(ARRAY[1]);
//                assert(s3.size() == 2);
//                s3 = s2;
//                assert(s3.size() == 0);
//                assert(itemcount() == mid);
//                s2.insert(ARRAY[2]);
//                s3.insert(ARRAY[3]);
//                assert(s2.size() == 1  &&  s3.size() == 1);
//                ItemType x;
//                s2.get(0, x);
//                assert(x == ARRAY[2]);
//                s3.get(0, x);
//                assert(x == ARRAY[3]);
//            }
//            assert(itemcount() == before);
//                        } break; case 60: {
//            int before = itemcount();
//            {
//                Set s2;
//                Set s3;
//                s3.insert(ARRAY[0]);
//                s3.insert(ARRAY[1]);
//                int mid = itemcount();
//                assert(s3.size() == 2);
//                s2 = s3;
//                assert(s2.size() == 2  &&  s3.size() == 2);
//                //assert(itemcount() > mid);
//                s2.insert(ARRAY[2]);
//                s3.insert(ARRAY[3]);
//                assert(s2.size() == 3  &&  s3.size() == 3);
//                assert(isPermutation(s2, ARRAY, 3));
//                ItemType a[3] = { ARRAY[0], ARRAY[1], ARRAY[3] };
//                assert(isPermutation(s3, a, 3));
//            }
//            assert(itemcount() == before);
//
//                        } break; case 61: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            int before = itemcount();
//            {
//                Set s2;
//                s2.insert(ARRAY[2]);
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                int mid = itemcount();
//                s2 = s;
//                assert(itemcount() <= mid);
//            }
//            assert(itemcount() == before);
//                        } break; case 62: {
//            int before = itemcount();
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                s2.insert(ARRAY[2]);
//                int mid = itemcount();
//                Set s3;
//                s3.insert(ARRAY[3]);
//                s3.insert(ARRAY[4]);
//                s3 = s2;
//                assert(itemcount() - mid == mid - before);
//            }
//                        } break; case 63: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            {
//                Set s2;
//                s2.insert(ARRAY[2]);
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                s2 = s;
//                s2.insert(ARRAY[5]);
//                assert(s2.size() == s.size()+1);
//            }
//                        } break; case 64: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            {
//                Set s2;
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                s2.insert(ARRAY[5]);
//                s2 = s;
//                s2.insert(ARRAY[2]);
//                assert(isPermutation(s2, ARRAY, 3));
//            }
//                        } break; case 65: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            {
//                Set s2;
//                s2.insert(ARRAY[3]);
//                s2.insert(ARRAY[4]);
//                s2.insert(ARRAY[5]);
//                s2 = s;
//                s2.insert(ARRAY[2]);
//                assert(isPermutation(s, ARRAY, 2));
//            }
//                        } break; case 66: {
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                s2.insert(ARRAY[2]);
//                int n2 = itemcount();
//                s2 = s2;
//                assert(itemcount() == n2);
//            }
//                        } break; case 67: {
//            {
//                Set s2;
//                s2.insert(ARRAY[0]);
//                s2.insert(ARRAY[1]);
//                s2.insert(ARRAY[2]);
//                s2 = s2;
//                s2.insert(ARRAY[3]);
//                assert(isPermutation(s2, ARRAY, 4));
//            }
//            assert(true);  // no corruption so bad that destruction failed
//                        } break; case 68: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            Set s3;
//            unite(s,s2,s3);
//            assert(s3.size() == s.size());
//            assert(isPermutation(s3, ARRAY, 2));
//                        } break; case 69: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            Set s3;
//            unite(s2,s,s3);
//            assert(s3.size() == s.size());
//            assert(isPermutation(s3, ARRAY, 2));
//                        } break; case 70: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            s2.insert(ARRAY[1]);
//            s2.insert(ARRAY[2]);
//            Set s3;
//            unite(s,s2,s3);
//            assert(isPermutation(s3, ARRAY, 3));
//                        } break; case 71: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            s2.insert(ARRAY[1]);
//            s2.insert(ARRAY[2]);
//            Set s3;
//            s3.insert(ARRAY[3]);
//            unite(s,s2,s3);
//            assert(isPermutation(s3, ARRAY, 3));
//                        } break; case 72: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            s2.insert(ARRAY[1]);
//            s2.insert(ARRAY[2]);
//            unite(s,s2,s);
//            assert(isPermutation(s, ARRAY, 3));
//                        } break; case 73: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            s2.insert(ARRAY[1]);
//            s2.insert(ARRAY[2]);
//            unite(s,s2,s2);
//            assert(isPermutation(s2, ARRAY, 3));
//                        } break; case 74: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            Set s3;
//            difference(s,s2,s3);
//            assert(s3.size() == s.size());
//            assert(isPermutation(s3, ARRAY, 2));
//                        } break; case 75: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            Set s2;
//            Set s3;
//            difference(s2,s,s3);
//            assert(s3.size() == s.size());
//            assert(isPermutation(s3, ARRAY, 2));
//                        } break; case 76: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[2]);
//            Set s2;
//            s2.insert(ARRAY[2]);
//            s2.insert(ARRAY[1]);
//            Set s3;
//            difference(s,s2,s3);
//            assert(s3.size() == 2);
//            assert(isPermutation(s3, ARRAY, 2));
//                        } break; case 77: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[2]);
//            Set s2;
//            s2.insert(ARRAY[2]);
//            s2.insert(ARRAY[1]);
//            Set s3;
//            s3.insert(ARRAY[3]);
//            s3.insert(ARRAY[4]);
//            difference(s,s2,s3);
//            assert(s3.size() == 2);
//            assert(isPermutation(s3, ARRAY, 2));
//                        } break; case 78: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[5]);
//            Set s2;
//            s2.insert(ARRAY[1]);
//            s2.insert(ARRAY[2]);
//            s2.insert(ARRAY[4]);
//            s2.insert(ARRAY[5]);
//            difference(s,s2,s);
//            assert(s.size() == 3);
//            ItemType x;
//            s.get(0, x);
//            assert(x == ARRAY[4]);
//            s.get(1, x);
//            assert(x == ARRAY[3]);
//            s.get(2, x);
//            assert(x == ARRAY[0]);
//                        } break; case 79: {
//            s.insert(ARRAY[0]);
//            s.insert(ARRAY[1]);
//            s.insert(ARRAY[2]);
//            s.insert(ARRAY[3]);
//            s.insert(ARRAY[5]);
//            Set s2;
//            s2.insert(ARRAY[1]);
//            s2.insert(ARRAY[2]);
//            s2.insert(ARRAY[4]);
//            s2.insert(ARRAY[5]);
//            difference(s,s2,s2);
//            assert(s2.size() == 3);
//            ItemType x;
//            s2.get(0, x);
//            assert(x == ARRAY[4]);
//            s2.get(1, x);
//                            cout << x << endl;
//                            cout << ARRAY[3] << endl;
//            //assert(x == ARRAY[3]);
//            s2.get(2, x);
//            assert(x == ARRAY[0]);
//                        } break; case 80: {
//            const int NITEMS = 1000;
//            for (int k = 0; k < NITEMS; k++)
//                assert(s.insert(ItemType(k)));
//            assert(s.size() == NITEMS);
//                        }
//        }
//}
//
//int main()
//{
//    for (int i = 1; i <= 80; i++) {
//        testone(i);
//        cout << "Passed " << i << endl;
//    }
//}
