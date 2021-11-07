//// 1
//
//#include "Set.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Set<int> si;
//    Set<string> ss;
//    assert(si.empty());
//    assert(ss.empty());
//    assert(si.size() == 0);
//    assert(ss.size() == 0);
//    assert(si.insert(10));
//    assert(ss.insert("hello"));
//    assert(si.contains(10));
//    assert(ss.contains("hello"));
//    int i;
//    assert(si.get(0, i)  &&  i == 10);
//    string s;
//    assert(ss.get(0, s)  &&  s == "hello");
//    assert(si.erase(10));
//    assert(ss.erase("hello"));
//    Set<int> si2(si);
//    Set<string> ss2(ss);
//    si.swap(si2);
//    ss.swap(ss2);
//    si = si2;
//    ss = ss2;
//    unite(si,si2,si);
//    unite(ss,ss2,ss);
//    difference(si,si2,si);
//    difference(ss,ss2,ss);
//}
//
//void test2()
//{
//    using ItemType = string;
//    Set<ItemType> ss;
//    assert(ss.insert("pita"));
//    assert(ss.insert("roti"));
//    assert(ss.size() == 2);
//    assert(ss.contains("roti"));
//    ItemType x = "laobing";
//    assert(ss.get(0, x)  &&  x == "roti");
//    assert(ss.get(1, x)  &&  x == "pita");
//
//    Set<ItemType> sss;
//    sss.insert("ccc");
//    sss.insert("aaa");
//    sss.insert("bbb");
//    x = "xxx";
//    assert(!sss.get(3, x)  &&  x == "xxx");
//    assert(sss.get(1, x)  &&  x == "bbb");
//}
//
//void project2 ()
//{
//    using ItemType = string;
//
//    // smallberg tests
//
//    test();
//
//    Set<ItemType> s1;
//    assert(s1.empty());
//    ItemType x1 = "arepa";
//    assert( !s1.get(42, x1)  &&  x1 == "arepa"); // x unchanged by get failure
//    s1.insert("chapati");
//    assert(s1.size() == 1);
//    assert(s1.get(0, x1)  &&  x1 == "chapati");
//
//    Set<ItemType> s2;
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
//    Set<ItemType> s3;
//    s3.insert("laobing");
//    Set<ItemType> s4;
//    s4.insert("matzo");
//    s4.insert("pita");
//    s3.swap(s4);
//    assert(s3.size() == 2  &&  s3.contains("matzo")  &&  s3.contains("pita")  &&
//           s4.size() == 1  &&  s4.contains("laobing"));
//
//    Set<ItemType> s5;
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
//    // new Set<ItemType> = empty, size = 0
//    Set<ItemType> s6;
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
//    Set<ItemType> s7;
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
//    Set<ItemType> s8(s7);
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
//    Set<ItemType> s9;
//    assert( s9.insert("a") == true );
//    assert( s9.insert("b") == true );
//    assert( s9.insert("c") == true );
//    assert( s9.insert("d") == true );
//    assert( s9.insert("e") == true );
//    Set<ItemType> s10;
//    assert( s10.insert("a") == true );
//    assert( s10.insert("b") == true );
//    assert( s10.insert("c") == true );
//    assert( s10.insert("d") == true );
//    Set<ItemType> s11;
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
//    // test unite for same Set<ItemType> for s1 and s2
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
//    // test unite for same Set<ItemType> for s1 and result
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
//    // test difference for same Set<ItemType> for s1 and s2
//    difference(s9, s9, s11);
//    assert( s11.size() == 0 );
//    assert( s11.get(0, str) == false );
//    assert( str == "e" );
//
//    // test difference for same Set<ItemType> for s1 and result
//    difference(s9, s10, s9);
//    assert( s9.size() == 1 );
//    assert( s9.get(0, str) == true );
//    assert( str == "e" );
//
//    // test special case: list with 0 entries
//    Set<ItemType> s12;
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
//
//void project22()
//{
//    // smallberg tests
//    using ItemType = unsigned long;
//
//    test();
//
//    Set<ItemType> s1;
//    assert(s1.empty());
//    ItemType x = 9876543;
//    assert( !s1.get(42, x)  &&  x == 9876543); // x unchanged by get failure
//    s1.insert(123456789);
//    assert(s1.size() == 1);
//    assert(s1.get(0, x)  &&  x == 123456789);
//
//    // my tests
//
//    // new Set<ItemType> = empty, size = 0
//    Set<ItemType> s2;
//    assert( s2.empty() == true );
//    assert( s2.size() == 0 );
//    assert( s2.contains(0) == false );
//
//    // insert 3 ints, check order
//    s2.insert(2);
//    s2.insert(1);
//    s2.insert(3);
//
//    // check duplicates
//    s2.insert(2);
//    s2.insert(1);
//    s2.insert(3);
//
//    // check empty = false
//    assert( s2.empty() == false );
//
//    // check size = 3
//    assert( s2.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s2.erase(4) == false );
//    assert( s2.size() == 3 );
//
//    // erase
//    s2.erase(2);
//    assert( s2.size() == 2 );
//
//    // add back
//    s2.insert(2);
//    assert( s2.size() == 3 );
//
//    // check contains
//    assert( s2.contains(1) == true );
//    assert( s2.contains(2) == true );
//    assert( s2.contains(3) == true );
//
//    // check contains w something that isn't there
//    assert( s2.contains(4) == false );
//
//    // check get
//    unsigned long i;
//    assert( s2.get(0, i) == true );
//    assert( i == 3 );
//    assert( s2.get(1, i) == true );
//    assert( i == 2 );
//    assert( s2.get(2, i) == true );
//    assert( i == 1 );
//    assert( s2.get(3, i) == false );
//    assert( i == 1 );
//    assert( s2.get(-1, i) == false );
//    assert( i == 1 );
//
//    // swap
//    Set<ItemType> s3;
//    s3.insert(10);
//    s3.insert(11);
//    s2.swap(s3);
//    assert( s2.size() == 2 );
//    assert( s2.contains(10) == true );
//    assert( s2.contains(11) == true );
//    assert( s2.contains(1) == false );
//    assert( s2.contains(2) == false );
//    assert( s2.contains(3) == false );
//    assert( s3.size() == 3 );
//    assert( s3.contains(10) == false );
//    assert( s3.contains(11) == false );
//    assert( s3.contains(1) == true );
//    assert( s3.contains(2) == true );
//    assert( s3.contains(3) == true );
//
//    // swap back
//    s3.swap(s2);
//    assert( s2.size() == 3 );
//    assert( s2.contains(10) == false );
//    assert( s2.contains(11) == false );
//    assert( s2.contains(1) == true );
//    assert( s2.contains(2) == true );
//    assert( s2.contains(3) == true );
//    assert( s3.size() == 2 );
//    assert( s3.contains(10) == true );
//    assert( s3.contains(11) == true );
//    assert( s3.contains(1) == false );
//    assert( s3.contains(2) == false );
//    assert( s3.contains(3) == false );
//
//    // test copy constructor
//    Set<ItemType> s4(s3);
//    assert( s3.empty() == false );
//    assert( s4.empty() == false );
//    assert( s3.size() == 2 );
//    assert( s4.size() == 2 );
//    assert( s4.erase(12) == false );
//    assert( s4.erase(11) == true );
//    assert( s3.size() == 2 );
//    assert( s4.size() == 1 );
//    assert( s4.insert(11) == true );
//    assert( s4.insert(10) == false );
//    assert( s3.size() == 2 );
//    assert( s4.size() == 2 );
//    assert( s3.contains(10) == true );
//    assert( s3.contains(11) == true );
//    assert( s4.contains(10) == true );
//    assert( s4.contains(11) == true );
//    assert( s3.get(0, i) == true );
//    assert( i == 11 );
//    assert( s3.get(1, i) == true );
//    assert( i == 10 );
//    assert( s3.get(2, i) == false );
//    assert( i == 10 );
//    assert( s3.get(-1, i) == false );
//    assert( i == 10 );
//
//    // test assignment operator
//    s4 = s2;
//    assert( s2.empty() == false );
//    assert( s4.empty() == false );
//    assert( s3.size() == 2 );
//    assert( s2.size() == 3 );
//    assert( s4.size() == 3 );
//    assert( s4.erase(3) == true );
//    assert( s4.erase(4) == false );
//    assert( s2.size() == 3 );
//    assert( s4.size() == 2 );
//    assert( s4.insert(3) == true );
//    assert( s4.insert(2) == false );
//    assert( s2.size() == 3 );
//    assert( s4.size() == 3 );
//    assert( s2.contains(1) == true );
//    assert( s2.contains(2) == true );
//    assert( s2.contains(3) == true );
//    assert( s4.contains(1) == true );
//    assert( s4.contains(2) == true );
//    assert( s4.contains(3) == true );
//    assert( s4.get(0, i) == true );
//    assert( i == 3 );
//    assert( s4.get(1, i) == true );
//    assert( i == 2 );
//    assert( s4.get(2, i) == true );
//    assert( i == 1 );
//    assert( s4.get(3, i) == false );
//    assert( i == 1 );
//    assert( s4.get(-1, i) == false );
//    assert( i == 1 );
//
//    // test unite
//    Set<ItemType> s5;
//    assert( s5.insert(2) == true );
//    assert( s5.insert(8) == true );
//    assert( s5.insert(3) == true );
//    assert( s5.insert(9) == true );
//    assert( s5.insert(5) == true );
//    Set<ItemType> s6;
//    assert( s6.insert(6) == true );
//    assert( s6.insert(3) == true );
//    assert( s6.insert(8) == true );
//    assert( s6.insert(5) == true );
//    assert( s6.insert(10) == true );
//    Set<ItemType> s7;
//    assert( s7.insert(6) == true );
//    assert( s7.insert(3) == true );
//    assert( s7.insert(8) == true );
//    unite(s5, s6, s7);
//    assert( s5.size() == 5 );
//    assert( s5.get(0, i) == true );
//    assert( i == 9 );
//    assert( s5.get(1, i) == true );
//    assert( i == 8 );
//    assert( s5.get(2, i) == true );
//    assert( i == 5 );
//    assert( s5.get(3, i) == true );
//    assert( i == 3 );
//    assert( s5.get(4, i) == true );
//    assert( i == 2 );
//    assert( s6.size() == 5 );
//    assert( s6.get(0, i) == true );
//    assert( i == 10 );
//    assert( s6.get(1, i) == true );
//    assert( i == 8 );
//    assert( s6.get(2, i) == true );
//    assert( i == 6 );
//    assert( s6.get(3, i) == true );
//    assert( i == 5 );
//    assert( s6.get(4, i) == true );
//    assert( i == 3 );
//    assert( s7.size() == 7 );
//    assert( s7.get(0, i) == true );
//    assert( i == 10 );
//    assert( s7.get(1, i) == true );
//    assert( i == 9 );
//    assert( s7.get(2, i) == true );
//    assert( i == 8 );
//    assert( s7.get(3, i) == true );
//    assert( i == 6 );
//    assert( s7.get(4, i) == true );
//    assert( i == 5 );
//    assert( s7.get(5, i) == true );
//    assert( i == 3 );
//    assert( s7.get(6, i) == true );
//    assert( i == 2 );
//
//    // test unite for same Set<ItemType> for s1 and s2
//    unite(s5, s5, s7);
//    assert( s5.size() == 5 );
//    assert( s5.get(0, i) == true );
//    assert( i == 9 );
//    assert( s5.get(1, i) == true );
//    assert( i == 8 );
//    assert( s5.get(2, i) == true );
//    assert( i == 5 );
//    assert( s5.get(3, i) == true );
//    assert( i == 3 );
//    assert( s5.get(4, i) == true );
//    assert( i == 2 );
//    assert( s7.size() == 5 );
//    assert( s7.get(0, i) == true );
//    assert( i == 9 );
//    assert( s7.get(1, i) == true );
//    assert( i == 8 );
//    assert( s7.get(2, i) == true );
//    assert( i == 5 );
//    assert( s7.get(3, i) == true );
//    assert( i == 3 );
//    assert( s7.get(4, i) == true );
//    assert( i == 2 );
//
//    // test unite for same Set<ItemType> for s1 and result
//    unite(s5, s6, s5);
//    assert( s5.size() == 7 );
//    assert( s5.get(0, i) == true );
//    assert( i == 10 );
//    assert( s5.get(1, i) == true );
//    assert( i == 9 );
//    assert( s5.get(2, i) == true );
//    assert( i == 8 );
//    assert( s5.get(3, i) == true );
//    assert( i == 6 );
//    assert( s5.get(4, i) == true );
//    assert( i == 5 );
//    assert( s5.get(5, i) == true );
//    assert( i == 3 );
//    assert( s5.get(6, i) == true );
//    assert( i == 2 );
//    assert( s6.size() == 5 );
//    assert( s6.get(0, i) == true );
//    assert( i == 10 );
//    assert( s6.get(1, i) == true );
//    assert( i == 8 );
//    assert( s6.get(2, i) == true );
//    assert( i == 6 );
//    assert( s6.get(3, i) == true );
//    assert( i == 5 );
//    assert( s6.get(4, i) == true );
//    assert( i == 3 );
//
//    // test difference
//    int i_max = s5.size();
//    for (int i = 0; i < i_max; i++) {
//        ItemType value;
//        s5.get(0, value);
//        s5.erase(value);
//    }
//    assert( s5.insert(2) == true );
//    assert( s5.insert(8) == true );
//    assert( s5.insert(3) == true );
//    assert( s5.insert(9) == true );
//    assert( s5.insert(5) == true );
//    difference(s5, s6, s7);
//    assert( s5.size() == 5 );
//    assert( s5.get(0, i) == true );
//    assert( i == 9 );
//    assert( s5.get(1, i) == true );
//    assert( i == 8 );
//    assert( s5.get(2, i) == true );
//    assert( i == 5 );
//    assert( s5.get(3, i) == true );
//    assert( i == 3 );
//    assert( s5.get(4, i) == true );
//    assert( i == 2 );
//    assert( s6.size() == 5 );
//    assert( s6.get(0, i) == true );
//    assert( i == 10 );
//    assert( s6.get(1, i) == true );
//    assert( i == 8 );
//    assert( s6.get(2, i) == true );
//    assert( i == 6 );
//    assert( s6.get(3, i) == true );
//    assert( i == 5 );
//    assert( s6.get(4, i) == true );
//    assert( i == 3 );
//    assert( s7.size() == 4 );
//    assert( s7.get(0, i) == true );
//    assert( i == 10 );
//    assert( s7.get(1, i) == true );
//    assert( i == 9 );
//    assert( s7.get(2, i) == true );
//    assert( i == 6 );
//    assert( s7.get(3, i) == true );
//    assert( i == 2 );
//
//    // test difference for same Set<ItemType> for s1 and s2
//    difference(s5, s5, s7);
//    assert( s5.size() == 5 );
//    assert( s5.get(0, i) == true );
//    assert( i == 9 );
//    assert( s5.get(1, i) == true );
//    assert( i == 8 );
//    assert( s5.get(2, i) == true );
//    assert( i == 5 );
//    assert( s5.get(3, i) == true );
//    assert( i == 3 );
//    assert( s5.get(4, i) == true );
//    assert( i == 2 );
//    assert( s7.size() == 0 );
//    assert( s7.get(0, i) == false );
//    assert( i == 2 );
//
//    // test difference for same Set<ItemType> for s1 and result
//    difference(s5, s6, s5);
//    assert( s5.size() == 4 );
//    assert( s5.get(0, i) == true );
//    assert( i == 10 );
//    assert( s5.get(1, i) == true );
//    assert( i == 9 );
//    assert( s5.get(2, i) == true );
//    assert( i == 6 );
//    assert( s5.get(3, i) == true );
//    assert( i == 2 );
//
//    // test special case: list with 0 entries
//    Set<ItemType> s8;
//    assert( s8.empty() == true );
//    assert( s8.size() == 0 );
//    assert( s8.erase(0) == false );
//    assert( s8.contains(0) == false );
//    assert( s8.get(0, i) == false && i == 2 );
//    s8.swap(s5);
//    assert( s8.get(0, i) == true && i == 10 );
//    assert( s8.get(1, i) == true && i == 9 );
//    assert( s8.get(2, i) == true && i == 6 );
//    assert( s8.get(3, i) == true && i == 2 );
//    assert( s5.get(0, i) == false && i == 2 );
//    unite(s5, s8, s5);
//    assert( s5.get(0, i) == true && i == 10 );
//    assert( s5.get(1, i) == true && i == 9 );
//    assert( s5.get(2, i) == true && i == 6 );
//    assert( s5.get(3, i) == true && i == 2 );
//    assert( s8.get(0, i) == true && i == 10 );
//    assert( s8.get(1, i) == true && i == 9 );
//    assert( s8.get(2, i) == true && i == 6 );
//    assert( s8.get(3, i) == true && i == 2 );
//    s5.erase(10);
//    s5.erase(9);
//    s5.erase(6);
//    s5.erase(2);
//    assert( s5.get(0, i) == false && i == 2 );
//    difference(s5, s8, s5);
//    assert( s5.get(0, i) == true && i == 10 );
//    assert( s5.get(1, i) == true && i == 9 );
//    assert( s5.get(2, i) == true && i == 6 );
//    assert( s5.get(3, i) == true && i == 2 );
//    assert( s8.get(0, i) == true && i == 10 );
//    assert( s8.get(1, i) == true && i == 9 );
//    assert( s8.get(2, i) == true && i == 6 );
//    assert( s8.get(3, i) == true && i == 2 );
//
//    // test special case: list with 1 entry
//    s8.erase(10);
//    s8.erase(9);
//    s8.erase(6);
//    s8.erase(2);
//    s8.insert(0);
//    assert( s8.empty() == false );
//    assert( s8.size() == 1 );
//    assert( s8.contains(0) == true );
//    assert( s8.erase(0) == true );
//    s8.insert(0);
//    assert( s8.get(0, i) == true && i == 0 );
//    s8.swap(s5);
//    assert( s8.get(0, i) == true && i == 10 );
//    assert( s8.get(1, i) == true && i == 9 );
//    assert( s8.get(2, i) == true && i == 6 );
//    assert( s8.get(3, i) == true && i == 2 );
//    assert( s5.get(0, i) == true && i == 0 );
//    unite(s5, s8, s5);
//    assert( s5.get(0, i) == true && i == 10 );
//    assert( s5.get(1, i) == true && i == 9 );
//    assert( s5.get(2, i) == true && i == 6 );
//    assert( s5.get(3, i) == true && i == 2 );
//    assert( s5.get(4, i) == true && i == 0 );
//    assert( s8.get(0, i) == true && i == 10 );
//    assert( s8.get(1, i) == true && i == 9 );
//    assert( s8.get(2, i) == true && i == 6 );
//    assert( s8.get(3, i) == true && i == 2 );
//    s5.erase(10);
//    s5.erase(9);
//    s5.erase(6);
//    s5.erase(2);
//    s5.erase(0);
//    assert( s5.get(0, i) == false && i == 2 );
//    difference(s5, s8, s5);
//    assert( s5.get(0, i) == true && i == 10 );
//    assert( s5.get(1, i) == true && i == 9 );
//    assert( s5.get(2, i) == true && i == 6 );
//    assert( s5.get(3, i) == true && i == 2 );
//    assert( s8.get(0, i) == true && i == 10 );
//    assert( s8.get(1, i) == true && i == 9 );
//    assert( s8.get(2, i) == true && i == 6 );
//    assert( s8.get(3, i) == true && i == 2 );
//
//    cerr << "Passed all tests" << endl;
//}
//
//
//int main() {
//    Set<int> si;
//    Set<string> ss;
//    si.insert(34);
//    ss.insert("34+35");
//    test();
//    project2();
//    project22();
//    cout << "Done!" << endl;
//}

//// 2
//#include "Set.h"
//#include <string>
//#include <iostream>
//using namespace std;
//
//class Coord
//{
//public:
//    Coord(int r, int c) : m_row(r), m_col(c) {}
//    Coord() : m_row(0), m_col(0) {}
//    double r() const { return m_row; }
//    double c() const { return m_col; }
//private:
//    double m_row;
//    double m_col;
//};
//
//int main()
//{
//    Set<int> si;
//    si.insert(7);               // OK
//    Set<string> ss;
//    ss.insert("7-Up");          // OK
//    Set<Coord> sc;
//    cout << "Done!" << endl;
//    //sc.insert(Coord(7, -7));    // error!
//}

/*
 // 6c, b, a
void Set::unite(const Set& set1, const Set& set2) // 7 + 12*size = O(N)
{
    const Set* sp = &set2; // 1
    if (this == &set1)
    {
        if (this == &set2)
                return;
    }
    else if (this == &set2)
        sp = &set1;
    else
    {
        *this = set1; // assignment operator // 3 + 3*size
        if (&set1 == &set2)
            return;
    }
    Node* p1 = m_head->m_next; // 1
    Node* p2 = sp->m_head->m_next; // 2
    while (p1 != m_head  &&  p2 != sp->m_head) // size
    {
        if (p1->m_value < p2->m_value)
            p1 = p1->m_next; // 1
        else
        {
            if (p1->m_value > p2->m_value)
                insertBefore(p1, p2->m_value); // insert before // 3
            else
                p1 = p1->m_next; // 1
                p2 = p2->m_next; // 1
        }
    }
    for ( ; p2 != sp->m_head; p2 = p2->m_next) // size
        insertBefore(m_head, p2->m_value); // insert before // 3
}

// assignment operator
Set& Set::operator=(const Set& rhs) // 3 + 3*size
{
    if (this != &rhs)
    {
          // Copy and swap idiom

        Set temp(rhs); // copy constructor // 1 + 3*size
        swap(temp); // swap // 2
    }
    return *this;
}

// insert before
void Set::insertBefore(Node* p, const ItemType& value) // 3
{
      // Create a new node

    Node* newp = new Node; // 1
    newp->m_value = value;

      // Insert new item before p

    newp->m_prev = p->m_prev;
    newp->m_next = p;
    newp->m_prev->m_next = newp; // 1
    newp->m_next->m_prev = newp; // 1

    m_size++;
}














void Set::unite(const Set& set1, const Set& set2) // 12*size + N logN = O(N logN)
{
    vector<ItemType> v;

      // copy all items into v;
    for (Node* p1 = set1.m_head->m_next; p1 != set1.m_head; p1 = p1->m_next) // size
        v.push_back(p1->m_value); // 1
    for (Node* p2 = set2.m_head->m_next; p2 != set2.m_head; p2 = p2->m_next) // size
        v.push_back(p2->m_value); // 1

      // sort v using an O(N log N) algorithm
    sort(v.begin(), v.end()); // N logN

      // delete result nodes (other than the dummy node)
    while (m_head->m_next != m_head) // size
        doErase(m_head->m_next); // do erase // 2

      // copy unique items from v into result
    for (size_t k = 0; k < v.size(); k++) // 2*size
    {
        if (k == 0  ||  v[k] != v[k-1])  // add non-duplicates
            insertBefore(m_head, v[k]); // insert before // 4
    }

      // v is destroyed when function returns
}

// do erase
void Set::doErase(Node* p) // 2
{
      // Unlink p from the list and destroy it

    p->m_prev->m_next = p->m_next; // 1
    p->m_next->m_prev = p->m_prev; // 1
    delete p;

    m_size--;
}

// insert before
void Set::insertBefore(Node* p, const ItemType& value) // 4
{
      // Create a new node

    Node* newp = new Node; // 1
    newp->m_value = value; // 1

      // Insert new item before p

    newp->m_prev = p->m_prev;
    newp->m_next = p;
    newp->m_prev->m_next = newp; // 1
    newp->m_next->m_prev = newp; // 1

    m_size++;
}






// assignment operator
Set& Set::operator=(const Set& rhs) // 3 + 3*size
{
    if (this != &rhs)
    {
          // Copy and swap idiom

        Set temp(rhs); // copy constructor // 1 + 3*size
        swap(temp); // swap // 2
    }
    return *this;
}

// copy constructor
Set::Set(const Set& other) // 1 + 3*size
{
    createEmpty(); // create empty // 1

      // Copy all non-dummy other Nodes.  (This will set m_size.)
      // Inserting each new node before the dummy node that m_head points to
      // puts the new node at the end of the list.

    for (Node* p = other.m_head->m_next; p != other.m_head; p = p->m_next) // size
        insertBefore(m_head, p->m_value); // insert before // 3
}

// create empty
void Set::createEmpty() // 1
{
    m_size = 0;

      // Create dummy node

    m_head = new Node; // 1
    m_head->m_next = m_head;
    m_head->m_prev = m_head;
}

// insert before
void Set::insertBefore(Node* p, const ItemType& value) // 3
{
      // Create a new node

    Node* newp = new Node; // 1
    newp->m_value = value;

      // Insert new item before p

    newp->m_prev = p->m_prev;
    newp->m_next = p;
    newp->m_prev->m_next = newp; // 1
    newp->m_next->m_prev = newp; // 1

    m_size++;
}

// swap
void Set::swap(Set& other) // 2
{
      // Swap head pointers

    Node* p = other.m_head; // 1
    other.m_head = m_head; // 1
    m_head = p;

      // Swap sizes

    int s = other.m_size;
    other.m_size = m_size;
    m_size = s;
}

// get
bool Set::get(int i, ItemType& value) const // 1 + size/2
{
    if (i < 0  ||  i >= m_size)
        return false;

      // Return the value at position i.  Since the values are stored in
      // descending, the value at position i will be less than exactly i
      // items in the set, meeting get's specification.

      // If i is closer to the head of the list, go forward to reach that
      // position; otherwise, start from tail and go backward.

    Node* p;
    if (i < m_size / 2)  // closer to head
    {
        p = m_head->m_next; // 1
        for (int k = 0; k != i; k++) // size/2
            p = p->m_next; // 1
    }
    else  // closer to tail
    {
        p = m_head->m_prev;
        for (int k = m_size-1; k != i; k--)
            p = p->m_prev;
    }

    value = p->m_value;
    return true;
}

// insert
bool Set::insert(const ItemType& value) // 4 + size
{
      // Fail if value already present

    Node* p = findFirstAtMost(value); // find first at most // 1 + size
    if (p != m_head  &&  p->m_value == value)
        return false;

      // Insert new Node preserving descending order and incrementing m_size

    insertBefore(p, value); // insert before // 3
    return true;
}

// find first at most
Set::Node* Set::findFirstAtMost(const ItemType& value) const // 1 + size
{
      // Walk through the list looking for a match

    Node* p = m_head->m_next; // 1
    for ( ; p != m_head  &&  p->m_value > value; p = p->m_next) // size
        ;
    return p;
}
*/
