#include "provided.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void doScaffoldTests1();
void doScaffoldTests2();
void doPlayerTests1();
void doPlayerTests2();
void doGameTests();
void doSkeletonTests();

int main()
{
    doScaffoldTests1();
    cout << "Scaffold tested (1)" << endl;

    doScaffoldTests2();
    cout << "Scaffold tested (2)" << endl;

    doPlayerTests1();
    cout << "Players tested (1)" << endl;

    doPlayerTests2();
    cout << "Players tested (2)" << endl;

    doGameTests();
    cout << "Game tested" << endl;

    doSkeletonTests();
    cout << "Skeleton tested" << endl;

    string name;
    cout << "What's your name?  ";
    getline(cin, name);
    HumanPlayer hp(name);
    SmartPlayer sp("Computer");

    Game g1(3, 5, 5, &hp, &sp);
    g1.play();
    cout << endl << "This time I'll go first." << endl;
    Game g2(3, 5, 5, &sp, &hp);
    g2.play();
    cout << endl;

    Game g3(4, 4, 3, &hp, &sp);
    g3.play();
    cout << endl << "This time I'll go first." << endl;
    Game g4(4, 4, 3, &sp, &hp);
    g4.play();
    cout << endl;

    Game g5(5, 3, 2, &hp, &sp);
    g5.play();
    cout << endl << "This time I'll go first." << endl;
    Game g6(5, 3, 2, &sp, &hp);
    g6.play();
    cout << endl;

    Game g7(5, 2, 5, &hp, &sp);
    g7.play();
    cout << endl << "This time I'll go first." << endl;
    Game g8(5, 2, 5, &sp, &hp);
    g8.play();
    cout << endl;

    Game g9(6, 2, 3, &hp, &sp);
    g9.play();
    cout << endl << "This time I'll go first." << endl;
    Game g10(6, 2, 3, &sp, &hp);
    g10.play();
    cout << endl;

    Game g11(10, 2, 2, &hp, &sp);
    g11.play();
    cout << endl << "This time I'll go first." << endl;
    Game g12(10, 2, 2, &sp, &hp);
    g12.play();
    cout << endl;

    Game g13(10, 1, 4, &hp, &sp);
    g13.play();
    cout << endl << "This time I'll go first." << endl;
    Game g14(10, 1, 4, &sp, &hp);
    g14.play();
    cout << endl;
}

void doScaffoldTests1() {
    Scaffold s(3, 2);
    s.makeMove(2, RED);
    s.makeMove(1, BLACK);
    s.makeMove(1, RED);
    s.display();
    //  |R| | |
    //  |B|R| |
    //  +-+-+-+
    cout << s.checkerAt(1, 2) << endl; // R 0
    cout << s.checkerAt(1, 1) << endl; // B 1
    cout << s.checkerAt(2, 1) << endl; // R 0
    s.undoMove();
    s.display();
    //  | | | |
    //  |B|R| |
    //  +-+-+-+
    s.undoMove();
    s.display();
    //  | | | |
    //  | |R| |
    //  +-+-+-+
}

void doScaffoldTests2()
{
    Scaffold s(3, 2);
    assert(s.cols() == 3  &&  s.levels() == 2  &&
           s.numberEmpty() == 6);
    assert(s.makeMove(1, RED));
    assert(s.makeMove(1, BLACK));
    assert(!s.makeMove(1, RED));
    assert(s.numberEmpty() == 4);
    assert(s.checkerAt(1, 1) == RED  &&  s.checkerAt(1, 2) == BLACK);
    assert(s.checkerAt(2, 1) == VACANT);
    s.display();
}

void doPlayerTests1()
{
    HumanPlayer hp("Marge");
    assert(hp.name() == "Marge"  &&  hp.isInteractive());
    BadPlayer bp("Homer");
    assert(bp.name() == "Homer"  &&  !bp.isInteractive());
    SmartPlayer sp("Lisa");
    assert(sp.name() == "Lisa"  &&  !sp.isInteractive());
    Scaffold s(3, 2);
    s.makeMove(1, RED);
    s.makeMove(1, BLACK);
    cout << "=========" << endl;
    int n = hp.chooseMove(s, 3, RED);
    cout << "=========" << endl;
    assert(n == 2  ||  n == 3);
    n = bp.chooseMove(s, 3, RED);
    assert(n == 2  ||  n == 3);
    n = sp.chooseMove(s, 3, RED);
    assert(n == 2  ||  n == 3);
}

void doPlayerTests2()
{
    BadPlayer bp("Homer");
    HumanPlayer hp("Marge");
    Game g1(4, 3, 3, &bp, &hp);
    g1.play();
    
    BadPlayer bp1("Bart");
    BadPlayer bp2("Homer");
    Game g2(4, 3, 2, &bp1, &bp2);
    g2.play();
}

void doGameTests()
{
    BadPlayer bp1("Bart");
    BadPlayer bp2("Homer");
    Game g(2, 2, 2, &bp1, &bp2);
    int winner;
    assert(!g.completed(winner));
    g.takeTurn();  // Red's first move
    assert(!g.completed(winner)  &&
                (g.checkerAt(1, 1) == RED  ||  g.checkerAt(2, 1) == RED));
    g.takeTurn();  // Black's first move
    assert(!g.completed(winner));
    g.takeTurn();  // Red's second move; Red must win
    assert(g.completed(winner)  &&  winner == RED);
}

void doSkeletonTests()
{
    string name;
    cout << "What's your name?  ";
    getline(cin, name);
    HumanPlayer hp(name);
    SmartPlayer sp("Computer");
    Game g1(4, 3, 3, &hp, &sp);
    g1.play();
    cout << endl << "This time I'll go first." << endl;
    Game g2(4, 3, 3, &sp, &hp);
    g2.play();
}
