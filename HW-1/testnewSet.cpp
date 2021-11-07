// using ItemType = std::string; tests

//#include "newSet.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
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
//    // my old tests
//
//    // new set = empty, size = 0
//    Set s6;
//    s6.dump();
//    assert( s6.empty() == true );
//    assert( s6.size() == 0 );
//
//    // insert 3 strings, check alpha order
//    s6.insert("b");
//    s6.dump();
//    s6.insert("a");
//    s6.dump();
//    s6.insert("c");
//    s6.dump();
//
//    // check duplicates
//    s6.insert("b");
//    s6.insert("a");
//    s6.insert("c");
//    s6.dump();
//
//    // check empty = false
//    assert( s6.empty() == false );
//
//    // check size = 3
//    assert( s6.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s6.erase("z") == false );
//    s6.dump();
//    assert( s6.size() == 3 );
//
//    // erase
//    s6.erase("b");
//    s6.dump();
//    assert( s6.size() == 2 );
//
//    // add back
//    s6.insert("b");
//    s6.dump();
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
//    s7.dump();
//
//    s6.swap(s7);
//    s6.dump();
//    assert( s6.size() == 2 );
//    assert( s6.contains("x") == true );
//    assert( s6.contains("y") == true );
//    assert( s6.contains("a") == false );
//    assert( s6.contains("b") == false );
//    assert( s6.contains("c") == false );
//    s7.dump();
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
//    s7.dump();
//    assert( s7.size() == 2 );
//    assert( s7.contains("x") == true );
//    assert( s7.contains("y") == true );
//    assert( s7.contains("a") == false );
//    assert( s7.contains("b") == false );
//    assert( s7.contains("c") == false );
//
//    // my new tests
//
//    // new set of max size 3 = empty, size = 0
//    Set s8(3);
//    s8.dump();
//    assert( s8.empty() == true );
//    assert( s8.size() == 0 );
//    assert( s8.contains("") == false );
//
//    // insert 2 ints, check order
//    assert( s8.insert("b") == true );
//    s8.dump();
//    assert( s8.insert("a") == true );
//    s8.dump();
//
//    // check duplicates
//    assert( s8.insert("b") == false );
//    assert( s8.insert("a") == false );
//    assert( s8.size() == 2 );
//    s8.dump();
//
//    // insert 3rd int
//    assert( s8.insert("c") == true );
//    s8.dump();
//
//    // try to insert 4th int
//    assert( s8.insert("d") == false );
//    s8.dump();
//
//    // check empty = false
//    assert( s8.empty() == false );
//
//    // check size = 3
//    assert( s8.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s8.erase("d") == false );
//    s8.dump();
//    assert( s8.size() == 3 );
//
//    // erase
//    s8.erase("b");
//    s8.dump();
//    assert( s8.size() == 2 );
//
//    // add back
//    s8.insert("b");
//    s8.dump();
//    assert( s8.size() == 3 );
//
//    // check contains
//    assert( s8.contains("a") == true );
//    assert( s8.contains("b") == true );
//    assert( s8.contains("c") == true );
//
//    // check contains w something that isn't there
//    assert( s8.contains("d") == false );
//
//    // check get
//    string str2;
//    assert( s8.get(0, str2) == true );
//    assert( str2 == "c" );
//    assert( s8.get(1, str2) == true );
//    assert( str2 == "b" );
//    assert( s8.get(2, str2) == true );
//    assert( str2 == "a" );
//    assert( s8.get(3, str2) == false );
//    assert( str2 == "a" );
//    assert( s8.get(-1, str2) == false );
//    assert( str2 == "a" );
//
//    // swap with diff size, not fully filled
//    Set s9(4);
//    s9.insert("w");
//    s9.insert("x");
//    s9.dump();
//
//    s8.swap(s9);
//    s8.dump();
//    assert( s8.size() == 2 );
//    assert( s8.contains("w") == true );
//    assert( s8.contains("x") == true );
//    assert( s8.contains("a") == false );
//    assert( s8.contains("b") == false );
//    assert( s8.contains("c") == false );
//    s9.dump();
//    assert( s9.size() == 3 );
//    assert( s9.contains("w") == false );
//    assert( s9.contains("x") == false );
//    assert( s9.contains("a") == true );
//    assert( s9.contains("b") == true );
//    assert( s9.contains("c") == true );
//
//    // can add to new s8
//    assert( s8.insert("y") == true );
//    assert( s8.insert("z") == true );
//    assert( s8.size() == 4 );
//
//    // try to add 5th to new s8
//    assert( s8.insert("a") == false );
//    assert( s8.size() == 4 );
//
//    // swap back
//    s8.swap(s9);
//    assert( s8.size() == 3 );
//    assert( s8.contains("w") == false );
//    assert( s8.contains("x") == false );
//    assert( s8.contains("y") == false );
//    assert( s8.contains("z") == false );
//    assert( s8.contains("a") == true );
//    assert( s8.contains("b") == true );
//    assert( s8.contains("c") == true );
//    s9.dump();
//    assert( s9.size() == 4 );
//    assert( s9.contains("w") == true );
//    assert( s9.contains("x") == true );
//    assert( s9.contains("y") == true );
//    assert( s9.contains("z") == true );
//    assert( s9.contains("a") == false );
//    assert( s9.contains("b") == false );
//    assert( s9.contains("c") == false );
//
//    // test copy constructor
//    Set s10(s8);
//    s8.dump();
//    s10.dump();
//    assert( s8.empty() == false );
//    assert( s10.empty() == false );
//    assert( s8.size() == 3 );
//    assert( s10.size() == 3 );
//    assert( s10.erase("d") == false );
//    assert( s10.erase("a") == true );
//    s8.dump();
//    s10.dump();
//    assert( s8.size() == 3 );
//    assert( s10.size() == 2 );
//    assert( s10.insert("a") == true );
//    assert( s10.insert("d") == false );
//    s8.dump();
//    s10.dump();
//    assert( s8.size() == 3 );
//    assert( s10.size() == 3 );
//    assert( s8.contains("a") == true );
//    assert( s8.contains("b") == true );
//    assert( s8.contains("c") == true );
//    assert( s10.contains("a") == true );
//    assert( s10.contains("b") == true );
//    assert( s10.contains("c") == true );
//    assert( s8.get(0, str2) == true );
//    assert( str2 == "c" );
//    assert( s8.get(1, str2) == true );
//    assert( str2 == "b" );
//    assert( s8.get(2, str2) == true );
//    assert( str2 == "a" );
//    assert( s8.get(3, str2) == false );
//    assert( str2 == "a" );
//    assert( s8.get(-1, str2) == false );
//    assert( str2 == "a" );
//
//    // test assignment operator
//    s10 = s9;
//    s8.dump();
//    s9.dump();
//    s10.dump();
//    assert( s9.empty() == false );
//    assert( s10.empty() == false );
//    assert( s8.size() == 3 );
//    assert( s9.size() == 4 );
//    assert( s10.size() == 4 );
//    assert( s10.erase("a") == false );
//    assert( s10.erase("w") == true );
//    s9.dump();
//    s10.dump();
//    assert( s9.size() == 4 );
//    assert( s10.size() == 3 );
//    assert( s10.insert("w") == true );
//    assert( s10.insert("a") == false );
//    s9.dump();
//    s10.dump();
//    assert( s9.size() == 4 );
//    assert( s10.size() == 4 );
//    assert( s9.contains("w") == true );
//    assert( s9.contains("x") == true );
//    assert( s9.contains("y") == true );
//    assert( s9.contains("z") == true );
//    assert( s10.contains("w") == true );
//    assert( s10.contains("x") == true );
//    assert( s10.contains("y") == true );
//    assert( s10.contains("z") == true );
//    assert( s10.get(0, str2) == true );
//    assert( str2 == "z" );
//    assert( s10.get(1, str2) == true );
//    assert( str2 == "y" );
//    assert( s10.get(2, str2) == true );
//    assert( str2 == "x" );
//    assert( s10.get(3, str2) == true );
//    assert( str2 == "w" );
//    assert( s10.get(4, str2) == false );
//    assert( str2 == "w" );
//    assert( s10.get(-1, str2) == false );
//    assert( str2 == "w" );
//
//    cout << "Passed all tests" << endl;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// using ItemType = unsigned long; tests

//#include "newSet.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Set uls;
//    assert(uls.insert(10));
//    assert(uls.insert(20));
//    assert(uls.size() == 2);
//    assert(uls.contains(20));
//    ItemType x = 30;
//    assert(uls.get(0, x)  &&  x == 20);
//    assert(uls.get(1, x)  &&  x == 10);
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
//    ItemType x = 9876543;
//    assert( !s1.get(42, x)  &&  x == 9876543); // x unchanged by get failure
//    s1.insert(123456789);
//    assert(s1.size() == 1);
//    assert(s1.get(0, x)  &&  x == 123456789);
//
//    //Set a(-1);   // a can hold at most -1 distinct items - INVALID
//    //Set a(1000);   // a can hold at most 1000 distinct items - INVALID
//    Set a(150);   // a can hold at most 150 distinct items
//    Set b(5);      // b can hold at most 5 distinct items
//    Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
//    ItemType v[6] = { 1, 4, 6, 2, 5, 3 };
//
//    // No failures inserting 5 distinct items into b
//    for (int k = 0; k < 5; k++)
//    assert(b.insert(v[k]));
//
//    // Failure if we try to insert a sixth distinct item into b
//    assert(!b.insert(v[5]));
//
//    // When two Sets' contents are swapped, their capacities are swapped
//    // as well:
//    a.swap(b);
//    assert(!a.insert(v[5])  &&  b.insert(v[5]));
//
//    // my old tests
//
//    // new set = empty, size = 0
//    Set s2;
//    s2.dump();
//    assert( s2.empty() == true );
//    assert( s2.size() == 0 );
//    assert( s2.contains(0) == false );
//
//    // insert 3 ints, check order
//    assert( s2.insert(2) == true );
//    s2.dump();
//    assert( s2.insert(1) == true );
//    s2.dump();
//    assert( s2.insert(3) == true );
//    s2.dump();
//
//    // check duplicates
//    assert( s2.insert(2) == false );
//    assert( s2.insert(1) == false );
//    assert( s2.insert(3) == false );
//    s2.dump();
//
//    // check empty = false
//    assert( s2.empty() == false );
//
//    // check size = 3
//    assert( s2.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s2.erase(4) == false );
//    s2.dump();
//    assert( s2.size() == 3 );
//
//    // erase
//    s2.erase(2);
//    s2.dump();
//    assert( s2.size() == 2 );
//
//    // add back
//    s2.insert(2);
//    s2.dump();
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
//    Set s3;
//    s3.insert(10);
//    s3.insert(11);
//    s3.dump();
//
//    s2.swap(s3);
//    s2.dump();
//    assert( s2.size() == 2 );
//    assert( s2.contains(10) == true );
//    assert( s2.contains(11) == true );
//    assert( s2.contains(1) == false );
//    assert( s2.contains(2) == false );
//    assert( s2.contains(3) == false );
//    s3.dump();
//    assert( s3.size() == 3 );
//    assert( s3.contains(10) == false );
//    assert( s3.contains(11) == false );
//    assert( s3.contains(1) == true );
//    assert( s3.contains(2) == true );
//    assert( s3.contains(3) == true );
//
//    // swap back
//    s2.swap(s3);
//    assert( s2.size() == 3 );
//    assert( s2.contains(10) == false );
//    assert( s2.contains(11) == false );
//    assert( s2.contains(1) == true );
//    assert( s2.contains(2) == true );
//    assert( s2.contains(3) == true );
//    s3.dump();
//    assert( s3.size() == 2 );
//    assert( s3.contains(10) == true );
//    assert( s3.contains(11) == true );
//    assert( s3.contains(1) == false );
//    assert( s3.contains(2) == false );
//    assert( s3.contains(3) == false );
//
//    // my new tests
//
//    // new set of max size 3 = empty, size = 0
//    Set s4(3);
//    s4.dump();
//    assert( s4.empty() == true );
//    assert( s4.size() == 0 );
//    assert( s4.contains(0) == false );
//
//    // insert 2 ints, check order
//    assert( s4.insert(2) == true );
//    s4.dump();
//    assert( s4.insert(1) == true );
//    s4.dump();
//
//    // check duplicates
//    assert( s4.insert(2) == false );
//    assert( s4.insert(1) == false );
//    assert( s4.size() == 2 );
//    s4.dump();
//
//    // insert 3rd int
//    assert( s4.insert(3) == true );
//    s4.dump();
//
//    // try to insert 4th int
//    assert( s4.insert(4) == false );
//    s4.dump();
//
//    // check empty = false
//    assert( s4.empty() == false );
//
//    // check size = 3
//    assert( s4.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s4.erase(4) == false );
//    s4.dump();
//    assert( s4.size() == 3 );
//
//    // erase
//    s4.erase(2);
//    s4.dump();
//    assert( s4.size() == 2 );
//
//    // add back
//    s4.insert(2);
//    s4.dump();
//    assert( s4.size() == 3 );
//
//    // check contains
//    assert( s4.contains(1) == true );
//    assert( s4.contains(2) == true );
//    assert( s4.contains(3) == true );
//
//    // check contains w something that isn't there
//    assert( s4.contains(4) == false );
//
//    // check get
//    unsigned long i2;
//    assert( s4.get(0, i2) == true );
//    assert( i2 == 3 );
//    assert( s4.get(1, i2) == true );
//    assert( i2 == 2 );
//    assert( s4.get(2, i2) == true );
//    assert( i2 == 1 );
//    assert( s4.get(3, i2) == false );
//    assert( i2 == 1 );
//    assert( s4.get(-1, i2) == false );
//    assert( i2 == 1 );
//
//    // swap with diff size, not fully filled
//    Set s5(4);
//    s5.insert(10);
//    s5.insert(11);
//    s5.dump();
//
//    s4.swap(s5);
//    s4.dump();
//    assert( s4.size() == 2 );
//    assert( s4.contains(10) == true );
//    assert( s4.contains(11) == true );
//    assert( s4.contains(1) == false );
//    assert( s4.contains(2) == false );
//    assert( s4.contains(3) == false );
//    s5.dump();
//    assert( s5.size() == 3 );
//    assert( s5.contains(10) == false );
//    assert( s5.contains(11) == false );
//    assert( s5.contains(1) == true );
//    assert( s5.contains(2) == true );
//    assert( s5.contains(3) == true );
//
//    // can add to new s4
//    assert( s4.insert(12) == true );
//    assert( s4.insert(13) == true );
//    assert( s4.size() == 4 );
//
//    // try to add 5th to new s4
//    assert( s4.insert(14) == false );
//    assert( s4.size() == 4 );
//
//    // swap back
//    s4.swap(s5);
//    assert( s4.size() == 3 );
//    assert( s4.contains(10) == false );
//    assert( s4.contains(11) == false );
//    assert( s4.contains(12) == false );
//    assert( s4.contains(13) == false );
//    assert( s4.contains(1) == true );
//    assert( s4.contains(2) == true );
//    assert( s4.contains(3) == true );
//    s5.dump();
//    assert( s5.size() == 4 );
//    assert( s5.contains(10) == true );
//    assert( s5.contains(11) == true );
//    assert( s5.contains(12) == true );
//    assert( s5.contains(13) == true );
//    assert( s5.contains(1) == false );
//    assert( s5.contains(2) == false );
//    assert( s5.contains(3) == false );
//
//    // test copy constructor
//    Set s6(s4);
//    s4.dump();
//    s6.dump();
//    assert( s4.empty() == false );
//    assert( s6.empty() == false );
//    assert( s4.size() == 3 );
//    assert( s6.size() == 3 );
//    assert( s6.erase(4) == false );
//    assert( s6.erase(1) == true );
//    s4.dump();
//    s6.dump();
//    assert( s4.size() == 3 );
//    assert( s6.size() == 2 );
//    assert( s6.insert(1) == true );
//    assert( s6.insert(4) == false );
//    s4.dump();
//    s6.dump();
//    assert( s4.size() == 3 );
//    assert( s6.size() == 3 );
//    assert( s4.contains(1) == true );
//    assert( s4.contains(2) == true );
//    assert( s4.contains(3) == true );
//    assert( s6.contains(1) == true );
//    assert( s6.contains(2) == true );
//    assert( s6.contains(3) == true );
//    assert( s4.get(0, i2) == true );
//    assert( i2 == 3 );
//    assert( s4.get(1, i2) == true );
//    assert( i2 == 2 );
//    assert( s4.get(2, i2) == true );
//    assert( i2 == 1 );
//    assert( s4.get(3, i2) == false );
//    assert( i2 == 1 );
//    assert( s4.get(-1, i2) == false );
//    assert( i2 == 1 );
//
//    // test assignment operator
//    s6 = s5;
//    s4.dump();
//    s5.dump();
//    s6.dump();
//    assert( s5.empty() == false );
//    assert( s6.empty() == false );
//    assert( s4.size() == 3 );
//    assert( s5.size() == 4 );
//    assert( s6.size() == 4 );
//    assert( s6.erase(14) == false );
//    assert( s6.erase(10) == true );
//    s5.dump();
//    s6.dump();
//    assert( s5.size() == 4 );
//    assert( s6.size() == 3 );
//    assert( s6.insert(10) == true );
//    assert( s6.insert(14) == false );
//    s5.dump();
//    s6.dump();
//    assert( s5.size() == 4 );
//    assert( s6.size() == 4 );
//    assert( s5.contains(10) == true );
//    assert( s5.contains(11) == true );
//    assert( s5.contains(12) == true );
//    assert( s5.contains(13) == true );
//    assert( s6.contains(10) == true );
//    assert( s6.contains(11) == true );
//    assert( s6.contains(12) == true );
//    assert( s6.contains(13) == true );
//    assert( s6.get(0, i2) == true );
//    assert( i2 == 13 );
//    assert( s6.get(1, i2) == true );
//    assert( i2 == 12 );
//    assert( s6.get(2, i2) == true );
//    assert( i2 == 11 );
//    assert( s6.get(3, i2) == true );
//    assert( i2 == 10 );
//    assert( s6.get(4, i2) == false );
//    assert( i2 == 10 );
//    assert( s6.get(-1, i2) == false );
//    assert( i2 == 10 );
//
//    cout << "Passed all tests" << endl;
//}

// tester.cpp
// To test HW 1 Problem 5, uncomment the following line:
#define TESTNEW

#ifdef TESTNEW
#include "newSet.h" // ItemType should be a type alias for int
#else
#include "Set.h"    // ItemType should be a type alias for int
#endif

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include <cstdlib>
#include <cassert>
using namespace std;

const ItemType DUMMY = 123;
const ItemType DEFAULT = 0;
const ItemType ARRAY[6] = { 10, 20, 30, 40, 50, 60 };

bool isPermutation(const Set& s, const ItemType a[], int n)
{
        if (s.size() != n)
                return false;
        vector<ItemType> b(n);
        for (int i = 0; i < n; i++)
                s.get(i, b[i]);
        for (int j = 0; j < n; j++)
        {
                int i;
                for (i = j; i < n; i++)
                {
                        if (a[j] == b[i])
                        {
                                ItemType t = b[j];
                                b[j] = b[i];
                                b[i] = t;
                                break;
                        }
                }
                if (i == n)
                        return false;
        }
        return true;
}

const int SPEC_MAX = 150;

void testone(int n)
{
    Set s;
    switch (n)
    {
                 default: {
        cout << "Bad argument" << endl;
            } break; case  1: {
        assert((is_same<decltype(&Set::empty), bool (Set::*)() const>::value));
            } break; case  2: {
        assert((is_same<decltype(&Set::size), int (Set::*)() const>::value));
            } break; case  3: {
        assert((is_same<decltype(&Set::contains),
                    bool (Set::*)(const ItemType&) const>::value));
            } break; case  4: {
        assert((is_same<decltype(&Set::get),
                    bool (Set::*)(int, ItemType&) const>::value));
            } break; case  5: {
        assert(s.empty());
            } break; case  6: {
        assert(s.size() == 0);
            } break; case  7: {
        assert(!s.erase(DEFAULT)  &&  s.size() == 0);
            } break; case  8: {
        assert(!s.contains(DEFAULT));
            } break; case  9: {
        ItemType x = DUMMY;
        assert(!s.get(0, x));
            } break; case 10: {
        ItemType x = DUMMY;
        s.get(0, x);
        assert(x == DUMMY);
            } break; case 11: {
        assert(s.insert(DUMMY));
            } break; case 12: {
        s.insert(DUMMY);
        assert(!s.empty());
            } break; case 13: {
        s.insert(DUMMY);
        assert(s.size() == 1);
            } break; case 14: {
        s.insert(DUMMY);
        assert(s.contains(DUMMY));
            } break; case 15: {
        s.insert(DUMMY);
        ItemType x = DEFAULT;
        assert(s.get(0, x));
            } break; case 16: {
        s.insert(DUMMY);
        ItemType x = DEFAULT;
        s.get(0, x);
        assert(x == DUMMY);
            } break; case 17: {
        assert(s.insert(DUMMY)  &&  !s.insert(DUMMY));
            } break; case 18: {
        s.insert(DUMMY);
        s.insert(DUMMY);
        assert(s.size() == 1);
            } break; case 19: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        assert(!s.empty()   &&  s.size() == 2);
            } break; case 20: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        ItemType x = DUMMY;
        s.get(0, x);
        assert(x == ARRAY[1]);
            } break; case 21: {
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        ItemType x = DUMMY;
        s.get(0, x);
        assert(x == ARRAY[1]);
            } break; case 22: {
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        ItemType x = DUMMY;
        s.get(0, x);
        ItemType y = DUMMY;
        s.get(1, y);
        assert(x == ARRAY[1]  &&  y == ARRAY[0]);
            } break; case 23: {
        s.insert(ARRAY[3]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        s.insert(ARRAY[4]);
        s.insert(ARRAY[2]);
        assert(s.size() == 5);
            } break; case 24: {
        s.insert(ARRAY[3]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        s.insert(ARRAY[4]);
        s.insert(ARRAY[2]);
        ItemType x;
        for (int k = 0; k < 5; k++)
        {
        s.get(k, x);
        assert(x == ARRAY[5-1-k]);
        }
            } break; case 25: {
        s.insert(ARRAY[1]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        assert(s.size() == 2);
            } break; case 26: {
        s.insert(ARRAY[1]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        ItemType x;
        for (int k = 0; k < 2; k++)
        {
        s.get(k, x);
        assert(x == ARRAY[2-1-k]);
        }
            } break; case 27: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        s.insert(ARRAY[4]);
        assert(s.erase(ARRAY[3]));
            } break; case 28: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        s.insert(ARRAY[4]);
        s.erase(ARRAY[3]);
        assert(s.size() == 4);
            } break; case 29: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        s.insert(ARRAY[4]);
        assert(s.erase(ARRAY[0])  &&  s.size() == 4);
            } break; case 30: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        s.insert(ARRAY[4]);
        assert(s.erase(ARRAY[4])  &&  s.size() == 4);
            } break; case 31: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[1]);
        assert(s.erase(ARRAY[1])  &&  s.size() == 2);
            } break; case 32: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        s.insert(ARRAY[1]);
        s.erase(ARRAY[3]);
        assert(isPermutation(s, ARRAY, 3));
            } break; case 33: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[3]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[3]);
        s.erase(ARRAY[3]);
        assert(isPermutation(s, ARRAY, 3));
            } break; case 34: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        assert(!s.erase(ARRAY[4]));
            } break; case 35: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        s.erase(ARRAY[4]);
        assert(s.size() == 4);
            } break; case 36: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.erase(ARRAY[0]);
        s.erase(ARRAY[1]);
        assert(s.size() == 0);
            } break; case 37: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        ItemType x;
        assert(!s.get(-1, x));
            } break; case 38: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        ItemType x = DUMMY;
        s.get(-1, x);
        assert(x == DUMMY);
            } break; case 39: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        ItemType x;
        assert(! s.get(3, x));
            } break; case 40: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        ItemType x = DUMMY;
        s.get(3, x);
        assert(x == DUMMY);
            } break; case 41: {
        s.insert(DEFAULT);
        ItemType x = DUMMY;
        s.get(0, x);
        assert(s.size() == 1  &&  x == DEFAULT);
            } break; case 42: {
        s.insert(DEFAULT);
        s.erase(DEFAULT);
        assert(s.size() == 0  &&  !s.contains(DEFAULT));
            } break; case 43: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.erase(ARRAY[1]);
        assert(!s.contains(DEFAULT));
            } break; case 44: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.erase(ARRAY[1]);
        assert(s.contains(ARRAY[2]));
            } break; case 45: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.erase(ARRAY[2]);
        assert(s.size() == 2  &&  !s.contains(ARRAY[2]));
            } break; case 46: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.erase(ARRAY[1]);
        s.insert(ARRAY[2]);
        s.insert(ARRAY[3]);
        assert(s.size() == 3  &&  s.contains(ARRAY[2])  &&
                s.contains(ARRAY[3]));
            } break; case 47: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        {
        Set s2;
        s2.insert(ARRAY[2]);
        s2.insert(ARRAY[3]);
        s.swap(s2);
        assert(s.size() == 2  &&  s2.size() == 2);
        for (int k = 0; k < 2; k++)
        {
            assert(!s.contains(ARRAY[k]));
            assert(s2.contains(ARRAY[k]));
        }
        for (int k = 2; k < 4; k++)
        {
            assert(s.contains(ARRAY[k]));
            assert(!s2.contains(ARRAY[k]));
        }
        }
            } break; case 48: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        {
        Set s2;
        s2.insert(ARRAY[3]);
        s2.insert(ARRAY[4]);
        s.swap(s2);
        assert(s.size() == 2  &&  s2.size() == 3);
        }
            } break; case 49: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        {
        Set s2;
        s2.insert(ARRAY[3]);
        s2.insert(ARRAY[4]);
        s.swap(s2);
        for (int k = 0; k < 3; k++)
        {
            assert(!s.contains(ARRAY[k]));
            assert(s2.contains(ARRAY[k]));
        }
        for (int k = 3; k < 5; k++)
        {
            assert(s.contains(ARRAY[k]));
            assert(!s2.contains(ARRAY[k]));
        }
        }
            } break; case 50: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        {
        Set s2;
        s2.insert(ARRAY[3]);
        s2.insert(ARRAY[4]);
        s2.swap(s);
        for (int k = 0; k < 3; k++)
        {
            assert(!s.contains(ARRAY[k]));
            assert(s2.contains(ARRAY[k]));
        }
        for (int k = 3; k < 5; k++)
        {
            assert(s.contains(ARRAY[k]));
            assert(!s2.contains(ARRAY[k]));
        }
        }
            } break; case 51: {
        for (int k = 0; k < SPEC_MAX; k++)
        assert(s.insert(k));
        assert(s.size() == SPEC_MAX);
            } break; case 52: {
        for (int k = 0; k < SPEC_MAX; k++)
        assert(s.insert(k));
        ItemType x = SPEC_MAX;
        assert(!s.insert(x)  &&  s.size() == SPEC_MAX  &&  !s.contains(x));
            } break; case 53: {
        assert(s.insert(DUMMY));
        for (int k = 0; k < 10*SPEC_MAX; k++)
        assert(!s.insert(DUMMY));
        assert(s.size() == 1);
            } break; case 54: {
        for (int k = 0; k < SPEC_MAX; k++)
        assert(s.insert(k));
        assert(!s.insert(SPEC_MAX));
        s.erase(0);
        assert(s.insert(SPEC_MAX+1));
        assert(!s.insert(SPEC_MAX+2));
#ifdef TESTNEW
            } break; case 55: {
          // This test checked that swap executes the same number of
          // statements no matter how many items are in the sequences
            } break; case 56: {
        const int CAPACITY = 2;
        Set s2(CAPACITY);
        for (int k = 0; k < CAPACITY; k++)
        assert(s2.insert(k));
        assert(! s2.insert(CAPACITY));
            } break; case 57: {
        const int CAPACITY = SPEC_MAX*2;
        Set s2(CAPACITY);
        for (int k = 0; k < CAPACITY; k++)
        assert(s2.insert(k));
        assert(! s2.insert(CAPACITY));
            } break; case 58: {
          // This test checked that the destructor deletes the dynamic array.
            } break; case 59: {
          // This test checked that Sets can be properly copied and destroyed.
            } break; case 60: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        {
        Set s2(s);
        s2.insert(ARRAY[3]);
        assert(s2.size() == s.size()+1);
        }
            } break; case 61: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        {
        Set s2(s);
        s2.insert(ARRAY[3]);
        assert(isPermutation(s2, ARRAY, 4));
        }
            } break; case 62: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[2]);
        {
        Set s2(s);
        s2.insert(ARRAY[3]);
        assert(isPermutation(s, ARRAY, 3));
        }
            } break; case 63: {
        {
        Set s2;
        Set s3(s2);
        assert(s2.size() == 0  &&  s3.size() == 0);
        s2.insert(ARRAY[0]);
        s3.insert(ARRAY[1]);
        assert(s2.size() == 1  &&  s3.size() == 1);
        ItemType x;
        s2.get(0, x);
        assert(x == ARRAY[0]);
        s3.get(0, x);
        assert(x == ARRAY[1]);
        }
            } break; case 64: {
        {
        Set s2(2);
        s2.insert(ARRAY[0]);
        s2.insert(ARRAY[1]);
        Set s3(s2);
        assert(!s3.insert(ARRAY[2]));
        }
            } break; case 65: {
        {
        Set s2;
        Set s3;
        s3.insert(ARRAY[0]);
        s3.insert(ARRAY[1]);
        assert(s3.size() == 2);
        s3 = s2;
        assert(s3.size() == 0);
        }
            } break; case 66: {
        {
        Set s2;
        Set s3;
        s3.insert(ARRAY[0]);
        s3.insert(ARRAY[1]);
        s3 = s2;
        s2.insert(ARRAY[2]);
        s3.insert(ARRAY[3]);
        assert(s2.size() == 1  &&  s3.size() == 1);
        ItemType x;
        s2.get(0, x);
        assert(x == ARRAY[2]);
        s3.get(0, x);
        assert(x == ARRAY[3]);
        }
            } break; case 67: {
        {
        Set s2;
        Set s3;
        s3.insert(ARRAY[0]);
        s3.insert(ARRAY[1]);
        assert(s3.size() == 2);
        s2 = s3;
        assert(s2.size() == 2  &&  s3.size() == 2);
        s2.insert(ARRAY[2]);
        s3.insert(ARRAY[3]);
        assert(s2.size() == 3  &&  s3.size() == 3);
        assert(isPermutation(s2, ARRAY, 3));
        ItemType a[3] = { ARRAY[0], ARRAY[1], ARRAY[3] };
        assert(isPermutation(s3, a, 3));
        }
            } break; case 68: {
              // This test checked that the assignment operator doesn't just
          // copy a pointer.
            } break; case 69: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        {
        Set s2;
        s2.insert(ARRAY[2]);
        s2.insert(ARRAY[3]);
        s2.insert(ARRAY[4]);
        s2 = s;
        s2.insert(ARRAY[5]);
        assert(s2.size() == s.size()+1);
        }
            } break; case 70: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        {
        Set s2;
        s2.insert(ARRAY[3]);
        s2.insert(ARRAY[4]);
        s2.insert(ARRAY[5]);
        s2 = s;
        s2.insert(ARRAY[2]);
        assert(isPermutation(s2, ARRAY, 3));
        }
            } break; case 71: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        {
        Set s2;
        s2.insert(ARRAY[3]);
        s2.insert(ARRAY[4]);
        s2.insert(ARRAY[5]);
        s2 = s;
        s2.insert(ARRAY[2]);
        assert(isPermutation(s, ARRAY, 2));
        }
            } break; case 72: {
          // This test checked that self-assignment doesn't change the
                  // number of items in existence.
            } break; case 73: {
        {
        Set s2;
        s2.insert(ARRAY[0]);
        s2.insert(ARRAY[1]);
        s2.insert(ARRAY[2]);
        s2 = s2;
        s2.insert(ARRAY[3]);
        assert(isPermutation(s2, ARRAY, 4));
        }
#endif
            }
    }
}

int main()
{
        cout << "Enter test number: ";
        int n;
        cin >> n;
        testone(n);
        cout << "Passed" << endl;
}
