////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <string>
//#include <random>
//#include <utility>
//#include <cstdlib>

//#include "globals.h"
#include "Game.h"
//#include "City.h"
//#include "History.h"
//#include "Player.h"
//#include "Flatulan.h"

using namespace std;

int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 4, 2);
    Game g(7, 8, 25);

      // Play the game
    g.play();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Flatulan.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Player.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "History.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Game.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "globals.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "City.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Game.h"
//#include "Game.h"
//#include "City.h"
//#include "City.h"
//#include "History.h"
//#include "History.h"
//#include "Player.h"
//#include "Player.h"
//#include "Flatulan.h"
//#include "Flatulan.h"
//#include "globals.h"
//#include "globals.h"
//int main()
//{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "History.h"
//int main()
//{
//    History h(2, 2);
//    h.record(1, 1);
//    h.display();
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Flatulan.h"
//int main()
//{
//    Flatulan f(nullptr, 1, 1);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Player.h"
//int main()
//{
//    Player p(nullptr, 1, 1);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "City.h"
//int main()
//{
//    City c(10, 18);
//    c.addPlayer(2, 2);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "globals.h"
//#include "Player.h"
//#include "City.h"
//int main()
//{
//    City c(10, 20);
//    Player p(&c, 2, 3);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "City.h"
//#include "Player.h"
//int main()
//{
//    City c(10, 20);
//    Player p(&c, 2, 3);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Player.h"
//#include "City.h"
//int main()
//{
//    City c(10, 20);
//    Player p(&c, 2, 3);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "City.h"
//#include "Player.h"
//#include "History.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    for (int nTries = 0; nTries < 5; nTries++)
//    {
//        City ct(2, 2);
//        ct.addPlayer(1, 2);
//        ct.addFlatulan(1, 1);
//
//        // Keep trying to get the Flatulan to move down
//        while (ct.nFlatulansAt(2, 1) == 0  &&  !ct.player()->isPassedOut())
//            ct.moveFlatulans();
//
//        if (ct.nFlatulansAt(2, 1) != 0) // the Flatulan moved
//        {
//            ct.history().display();
//            break;
//        }
//        // There's a 3.2% probability that the player will pass out before
//        // the Flatulan moves, so try the test again.  There's a 99.999997%
//        // probability that in five tries, we'll have a test where the
//        // Flatulan will move before the player passes out.
//    }
//    cout << "==" << endl;
//}

// BAD
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Flatulan.h"
//#include "City.h"
//int main()
//{
//    City a(10, 20);
//    Player p(&a, 2, 3);
//    Flatulan f(&a, 1, 1);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Player.h"
//#include "City.h"
//int main()
//{
//    City a(10, 20);
//    Player p(&a, 2, 3);
//    Flatulan f(&a, 1, 1);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "globals.h"
//#include "Flatulan.h"
//#include "Player.h"
//int main()
//{
//    City c(10, 10);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "History.h"
//int main()
//{
//    History h;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <sstream>
//#include <streambuf>
//#include <string>
//#include <map>
//#include <algorithm>
//#include <cstdlib>
//#include <cassert>
//
//#include "globals.h"
//#include "Game.h"
//#include "City.h"
//#include "History.h"
//#include "Player.h"
//#include "Flatulan.h"
//using namespace std;
//
//class StreambufSwitcher
//{
//public:
//    StreambufSwitcher(ios& dest, streambuf* sb,
//                      ios::iostate exceptions = ios::goodbit)
//    : dest_stream(dest), oldsb(dest.rdbuf(sb)), oldex(dest.exceptions())
//    { dest_stream.exceptions(exceptions); }
//    StreambufSwitcher(ios& dest, ios& src)
//    : StreambufSwitcher(dest, src.rdbuf(), src.exceptions())
//    {}
//    ~StreambufSwitcher()
//    { dest_stream.rdbuf(oldsb); dest_stream.exceptions(oldex); }
//private:
//    ios& dest_stream;
//    streambuf* oldsb;
//    ios::iostate oldex;
//};
//
//map<void*, size_t> allocMap;
//bool recordaddrs = false;
//
//inline bool isRecordedSize(size_t n)
//{
//    return n == sizeof(Flatulan)  ||  n == sizeof(Player);
//}
//
//void* operator new(size_t n)
//{
//    void* p = malloc(n);
//    fill_n(static_cast<char*>(p), n, 0xca);
//    if (recordaddrs  &&  isRecordedSize(n))
//    {
//        recordaddrs = false;
//        allocMap.insert(make_pair(p, n));
//        recordaddrs = true;
//    }
//    return p;
//}
//
//void unrecordaddr(void* p)
//{
//    recordaddrs = false;
//    auto it = allocMap.find(p);
//    if (it != allocMap.end())
//    {
//        fill_n(static_cast<char*>(p), it->second, 0xcb);
//        allocMap.erase(it);
//    }
//    recordaddrs = true;
//}
//
//#if __cplusplus >= 201402L  &&  ! defined(__clang__)
//// Unless clang is supplied the -fsized-deallocation flag, it will
//// not call the C++14/17 sized operator delete.
//
//void operator delete(void* p) noexcept
//{
//    free(p);
//}
//
//void operator delete(void* p, size_t n) noexcept
//{
//    if (recordaddrs  &&  isRecordedSize(n))
//        unrecordaddr(p);
//    operator delete(p);
//}
//#else
//void operator delete(void* p) noexcept
//{
//    if (recordaddrs)
//        unrecordaddr(p);
//    free(p);
//}
//#endif
//
//void testone(int n)
//{
//    StreambufSwitcher sso(cout, cerr);
//
//    switch (n)
//    {
//        default: {
//            cout << "Bad argument" << endl;
//        } break; case  1: {
//            City c(10, 18);
//            c.addPlayer(2, 2);
//            Flatulan f(&c, 5, 17);
//            assert(f.row() == 5  &&  f.col() == 17);
//        } break; case  2: {
//            bool movedr = false;
//            bool movedl = false;
//            bool stayed = false;
//            for (int k = 0; k < 150; k++)
//            {
//                City c(1, 30);
//                c.addPlayer(1, 1);
//                Flatulan f(&c, 1, 29);
//                assert(f.row() == 1  &&  f.col() == 29);
//                for (int n = 0; n < 2; n++)
//                {
//                    int oldc = f.col();
//                    f.move();
//                    assert(f.row() == 1  &&  f.col() <= 30);
//                    int d = f.col() - oldc;
//                    switch (d)
//                    {
//                        case  0:  stayed = true; break;
//                        case  1:  movedr = true; break;
//                        case -1:  movedl = true; break;
//                        default:  assert(false);
//                    }
//                }
//            }
//            assert(movedr  &&  movedl  &&  stayed);
//        } break; case  3: {
//            bool movedd = false;
//            bool movedu = false;
//            bool stayed = false;
//            for (int k = 0; k < 150; k++)
//            {
//                City c(20, 1);
//                c.addPlayer(1, 1);
//                Flatulan f(&c, 19, 1);
//                assert(f.row() == 19  &&  f.col() == 1);
//                for (int n = 0; n < 2; n++)
//                {
//                    int oldr = f.row();
//                    f.move();
//                    assert(f.col() == 1  &&  f.row() <= 20);
//                    int d = f.row() - oldr;
//                    switch (d)
//                    {
//                        case  0:  stayed = true; break;
//                        case  1:  movedd = true; break;
//                        case -1:  movedu = true; break;
//                        default:  assert(false);
//                    }
//                }
//            }
//            assert(movedd  &&  movedu  &&  stayed);
//        } break; case  4: {
//            City c(20, 20);
//            c.addPlayer(1, 1);
//            Flatulan f(&c, 12, 12);
//            for (int k = 0; k < 8; k++)
//            {
//                int oldr = f.row();
//                int oldc = f.col();
//                f.move();
//                assert((f.row() == oldr  &&  abs(f.col() - oldc) == 1)  ||
//                       (f.col() == oldc  &&  abs(f.row() - oldr) == 1));
//            }
//        } break; case  5: {
//            const int dr[NUMDIRS+1] = { -1,  0,  1,  0,  0 };
//            const int dc[NUMDIRS+1] = {  0,  1,  0, -1,  0 };
//            for (int k = 0; k < NUMDIRS; k++)
//            {
//                int nvisits[NUMDIRS+1] = { 0 };
//                for (int n = 0; n < 100; n++)
//                {
//                    City c(20, 20);
//                    c.addPlayer(10, 10);
//                    int oldr = 10 - dr[k];
//                    int oldc = 10 - dc[k];
//                    Flatulan f(&c, oldr, oldc);
//                    f.move();
//                    int rdiff = f.row() - oldr;
//                    int cdiff = f.col() - oldc;
//                    int i;
//                    for (i = 0; i < NUMDIRS+1; i++)
//                    {
//                        if (rdiff == dr[i]  &&  cdiff == dc[i])
//                        {
//                            nvisits[i]++;
//                            break;
//                        }
//                    }
//                    assert(i < NUMDIRS+1);
//                }
//                for (int i = 0; i < NUMDIRS+1; i++)
//                assert(k == i ? nvisits[i] == 0 : nvisits[i] > 1);
//            }
//        } break; case  6: {
//            int n = 0;
//            for (int k = 0; k < 600; k++)
//            {
//                City c(10, 20);
//                c.addPlayer(1, 1);
//                Flatulan f(&c, 1, 2);
//                if (f.haveIBeenConverted())
//                    n++;
//            }
//            assert(n >= 360  &&  n <= 440);
//        } break; case  7: {
//            City c(10, 20);
//            Player p(&c, 2, 3);
//            assert(p.row() == 2  &&  p.col() == 3  &&  !p.isPassedOut());
//        } break; case  8: {
//            City c(10, 20);
//            Player p(&c, 2, 3);
//            for (int k = 0; k < 12; k++)
//            {
//                assert(!p.isPassedOut());
//                p.getGassed();
//            }
//            assert(p.isPassedOut());
//        } break; case  9: {
//            City c(10, 20);
//            Player p(&c, 2, 3);
//            for (int k = 0; k < 12; k++)
//            {
//                assert(p.health() == 12 - k);
//                p.getGassed();
//            }
//            assert(p.isPassedOut());
//        } break; case 10: {
//            City c(10, 18);
//            c.addPlayer(10, 17);
//            Player* pp = c.player();
//            pp->move(RIGHT);
//            assert(pp->row() == 10  &&  pp->col() == 18  &&  !pp->isPassedOut());
//            pp->move(DOWN);
//            assert(pp->row() == 10  &&  pp->col() == 18  &&  !pp->isPassedOut());
//            pp->move(RIGHT);
//            assert(pp->row() == 10  &&  pp->col() == 18  &&  !pp->isPassedOut());
//        } break; case 11: {
//            City c(10, 18);
//            c.addPlayer(2, 1);
//            Player* pp = c.player();
//            pp->move(UP);
//            assert(pp->row() == 1  &&  pp->col() == 1  &&  !pp->isPassedOut());
//            pp->move(LEFT);
//            assert(pp->row() == 1  &&  pp->col() == 1  &&  !pp->isPassedOut());
//            pp->move(UP);
//            assert(pp->row() == 1  &&  pp->col() == 1  &&  !pp->isPassedOut());
//        } break; case 12: {
//            City c(10, 20);
//            c.addPlayer(8, 12);
//            Player* pp = c.player();
//            pp->move(UP);
//            assert(pp->row() == 7  &&  pp->col() == 12);
//            pp->move(DOWN);
//            assert(pp->row() == 8  &&  pp->col() == 12);
//            pp->move(LEFT);
//            assert(pp->row() == 8  &&  pp->col() == 11);
//            pp->move(RIGHT);
//            assert(pp->row() == 8  &&  pp->col() == 12);
//        } break; case 13: {
//            City c(10, 18);
//            c.addPlayer(5, 7);
//            c.addFlatulan(3, 7);
//            c.addFlatulan(4, 9);
//            c.addFlatulan(6, 8);
//            c.addFlatulan(5, 6);
//            Player* pp = c.player();
//            pp->move(UP);
//            assert(pp->row() == 4  &&  pp->col() == 7  &&  !pp->isPassedOut());
//            pp->move(UP);
//            assert(pp->row() == 4  &&  pp->col() == 7  &&  !pp->isPassedOut());
//            pp->move(RIGHT);
//            assert(pp->row() == 4  &&  pp->col() == 8  &&  !pp->isPassedOut());
//            pp->move(RIGHT);
//            assert(pp->row() == 4  &&  pp->col() == 8  &&  !pp->isPassedOut());
//            pp->move(DOWN);
//            assert(pp->row() == 5  &&  pp->col() == 8  &&  !pp->isPassedOut());
//            pp->move(DOWN);
//            assert(pp->row() == 5  &&  pp->col() == 8  &&  !pp->isPassedOut());
//            pp->move(LEFT);
//            assert(pp->row() == 5  &&  pp->col() == 7  &&  !pp->isPassedOut());
//            pp->move(LEFT);
//            assert(pp->row() == 5  &&  pp->col() == 7  &&  !pp->isPassedOut());
//        } break; case 14: {
//            City c(10, 18);
//            c.addPlayer(3, 9);
//            c.addFlatulan(4, 9);
//            assert(c.flatulanCount() == 1);
//            for (int k = 0; k < 100  &&  c.flatulanCount() == 1; k++)
//            c.player()->preach();
//            assert(c.flatulanCount() == 0);
//        } break; case 15: {
//            City c(10, 18);
//            c.addPlayer(3, 9);
//            assert(c.flatulanCount() == 0);
//            for (int k = 1; k <= 20; k++)
//            {
//                c.addFlatulan(3, 8);
//                c.addFlatulan(3, 10);
//                assert(c.flatulanCount() == 2 * k);
//            }
//            int prevct = c.flatulanCount();
//            for (int k = 0; k < 100  &&  prevct > 0; k++)
//            {
//                c.player()->preach();
//                int ct = c.flatulanCount();
//                assert(ct <= prevct);
//                prevct = ct;
//            }
//            assert(prevct == 0);
//        } break; case 16: {
//            City c(10, 18);
//            c.addPlayer(3, 9);
//            c.addFlatulan(2, 9);
//            assert(c.nFlatulansAt(2, 9) == 1);
//            for (int k = 0; k < 100  &&  c.nFlatulansAt(2, 9) == 1; k++)
//            c.player()->preach();
//            assert(c.nFlatulansAt(2, 9) == 0);
//        } break; case 17: {
//            City c(2, 3);
//            c.addPlayer(1, 2);
//            c.addFlatulan(1, 3);
//            c.addFlatulan(2, 2);
//            ostringstream oss;
//            streambuf *sb = cout.rdbuf(oss.rdbuf());
//            c.display();
//            cout.rdbuf(sb);
//            string s = oss.str();
//            assert(s.find(".@F") != string::npos  &&  s.find(".F.") != string::npos);
//        } break; case 18: {
//            City c(2, 3);
//            c.addPlayer(1, 2);
//            for (int k = 1; k <= 8; k++)
//            c.addFlatulan(1, 3);
//            c.addFlatulan(2, 2);
//            ostringstream oss;
//            streambuf *sb = cout.rdbuf(oss.rdbuf());
//            c.display();
//            cout.rdbuf(sb);
//            string s = oss.str();
//            assert(s.find(".@8") != string::npos);
//        } break; case 19: {
//            City c(2, 3);
//            c.addPlayer(1, 2);
//            for (int k = 1; k <= 10; k++)
//            c.addFlatulan(1, 3);
//            c.addFlatulan(2, 2);
//            ostringstream oss;
//            streambuf *sb = cout.rdbuf(oss.rdbuf());
//            c.display();
//            cout.rdbuf(sb);
//            string s = oss.str();
//            assert(s.find(".@9") != string::npos);
//        } break; case 20: {
//            City c(10, 18);
//            c.addPlayer(3, 9);
//            int prevct[3];
//            for (int dr = -1; dr <= 1; dr++)
//            {
//                if (dr == 0)
//                    continue;
//                for (int k = 0; k < MAXFLATULANS/2; k++)
//                assert(c.addFlatulan(3+dr, 9));
//                prevct[1+dr] = c.nFlatulansAt(3+dr, 9);
//                assert(prevct[1+dr] == MAXFLATULANS/2);
//            }
//            bool anyleft = true;
//            for (int k = 0; k < 100  &&  anyleft; k++)
//            {
//                anyleft = false;
//                c.player()->preach();
//                for (int dr = -1; dr <= 1; dr++)
//                {
//                    if (dr == 0)
//                        continue;
//                    int ct = c.nFlatulansAt(3+dr, 9);
//                    assert(ct <= prevct[1+dr]);
//                    prevct[1+dr] = ct;
//                    if (ct > 0)
//                        anyleft = true;
//                }
//            }
//            assert(!anyleft);
//        } break; case 21: {
//            City c(10, 18);
//            c.addPlayer(3, 9);
//            int prevct[3][3];
//            for (int dr = -1; dr <= 1; dr++)
//            for (int dc = -1; dc <= 1; dc++)
//            {
//                if (dr == 0  &&  dc == 0)
//                    continue;
//                for (int k = 0; k < MAXFLATULANS/8; k++)
//                assert(c.addFlatulan(3+dr, 9+dc));
//                prevct[1+dr][1+dc] = c.nFlatulansAt(3+dr, 9+dc);
//                assert(prevct[1+dr][1+dc] == MAXFLATULANS/8);
//            }
//            bool anyleft = true;
//            for (int k = 0; k < 100  &&  anyleft; k++)
//            {
//                anyleft = false;
//                c.player()->preach();
//                for (int dr = -1; dr <= 1; dr++)
//                for (int dc = -1; dc <= 1; dc++)
//                {
//                    if (dr == 0  &&  dc == 0)
//                        continue;
//                    int ct = c.nFlatulansAt(3+dr, 9+dc);
//                    assert(ct <= prevct[1+dr][1+dc]);
//                    prevct[1+dr][1+dc] = ct;
//                    if (ct > 0)
//                        anyleft = true;
//                }
//            }
//            assert(!anyleft);
//        } break; case 22: {
//            int n = 0;
//            for (int k = 0; k < 600; k++)
//            {
//                City c(10, 18);
//                c.addPlayer(3, 9);
//                assert(c.flatulanCount() == 0);
//                c.addFlatulan(3, 10);
//                assert(c.flatulanCount() == 1);
//                c.player()->preach();
//                if (c.flatulanCount() == 0)
//                    n++;
//            }
//            assert(n >= 360  &&  n <= 440);
//        } break; case 23: {
//            City c(10, 18);
//            c.addPlayer(3, 9);
//            for (int k = 0; k < MAXFLATULANS; k++)
//            assert(c.addFlatulan(2, 9));
//            assert(!c.addFlatulan(2, 9));
//            assert(c.flatulanCount() == MAXFLATULANS);
//            for (int n = 64; n > 0; n /= 2)
//            {
//                for (int k = 0; k < 100  &&  c.flatulanCount() >= n; k++)
//                c.preachToFlatulansAroundPlayer();
//                assert(c.flatulanCount() < n);
//                for (int k = 0; k < MAXFLATULANS  &&  c.flatulanCount() < MAXFLATULANS; k++)
//                assert(c.addFlatulan(2, 9));
//                assert(c.flatulanCount() == MAXFLATULANS);
//            }
//        } break; case 24: {
//            const int dr[NUMDIRS] = { -1,  0,  1,  0 };
//            const int dc[NUMDIRS] = {  0,  1,  0, -1 };
//            City c(12, 18);
//            c.addPlayer(1, 1);
//            const int r[3] = { 3, 6, 9 };
//            const int v[3] = { 4, 7, 10 };
//            for (int k = 0; k < 3; k++)
//            c.addFlatulan(r[k], v[k]);
//            c.moveFlatulans();
//            for (int k = 0; k < 3; k++)
//            {
//                int ct[2] = { 0 };
//                for (int n = 0; n < NUMDIRS; n++)
//                {
//                    int m = c.nFlatulansAt(r[k]+dr[n], v[k]+dc[n]);
//                    assert(m == 0  ||  m == 1);
//                    ct[m]++;
//                }
//                assert(ct[0] == 3  &&  ct[1] == 1);
//            }
//        } break; case 25: {
//            bool gassed = false;
//            for (int n = 0; n < 20; n++)
//            {
//                City c(10, 20);
//                c.addPlayer(5, 9);
//                for (int k = 0; k < 11; k++)
//                c.addFlatulan(5, 11);
//                assert(c.player()->health() == 12);
//                c.moveFlatulans();
//                int h = c.player()->health();
//                if (h < 12)
//                    gassed = true;
//                assert(c.nFlatulansAt(5, 10) == 12 - h);
//            }
//            assert(gassed);
//        } break; case 26: {
//            bool gassed = false;
//            for (int n = 0; n < 20; n++)
//            {
//                City c(10, 20);
//                c.addPlayer(5, 9);
//                for (int k = 0; k < 9; k++)
//                c.addFlatulan(5, 10);
//                assert(c.player()->health() == 12);
//                c.moveFlatulans();
//                int h = c.player()->health();
//                if (h < 12)
//                    gassed = true;
//                assert(c.nFlatulansAt(5, 10) == 12 - h);
//            }
//            assert(gassed);
//        } break; case 27: {
//            for (int n = 0; n < 20; n++)
//            {
//                City c(1, 20);
//                c.addPlayer(1, 2);
//                for (int k = 0; k < 11; k++)
//                c.addFlatulan(1, 1);
//                assert(c.player()->health() == 12);
//                c.moveFlatulans();
//                assert(c.player()->health() == 12-11);
//                assert(c.nFlatulansAt(1, 1) == 11);
//            }
//        } break; case 28: {
//            int n;
//            for (n = 0; n < 2; n++)
//            {
//                City c(10, 20);
//                c.addPlayer(5, 9);
//                for (int k = 0; k < MAXFLATULANS; k++)
//                c.addFlatulan(5, 11);
//                assert(c.player()->health() == 12  &&  ! c.player()->isPassedOut());
//                c.moveFlatulans();
//                if (c.player()->health() <= 0  &&  c.player()->isPassedOut())
//                    break;
//            }
//            assert(n != 2);
//        } break; case 29: {
//            recordaddrs = true;
//            int oldn = allocMap.size();
//            {
//                City c(10, 20);
//                int oldn2 = allocMap.size();
//                assert(oldn2 >= oldn);
//                c.addPlayer(4, 3);
//                c.addFlatulan(5, 6);
//                c.addFlatulan(5, 7);
//                c.addFlatulan(5, 8);
//                assert(allocMap.size() == oldn2 + 4);
//            }
//            assert(allocMap.size() == oldn);
//            recordaddrs = false;
//        } break; case 30: {
//            recordaddrs = true;
//            int oldn = allocMap.size();
//            {
//                City c(10, 20);
//                int oldn2 = allocMap.size();
//                assert(oldn2 >= oldn);
//                c.addPlayer(4, 3);
//                assert(allocMap.size() == oldn2 + 1);
//                for (int k = 0; k < MAXFLATULANS; k++)
//                c.addFlatulan(4, 4);
//                assert(allocMap.size() == oldn2 + 1 + MAXFLATULANS);
//                for (int k = 0; k < 100  &&  c.nFlatulansAt(4, 4) > 0; k++)
//                {
//                    c.preachToFlatulansAroundPlayer();
//                    assert(allocMap.size() == oldn2 + 1 + c.nFlatulansAt(4, 4));
//                }
//                assert(c.nFlatulansAt(4, 4) == 0);
//            }
//            assert(allocMap.size() == oldn);
//            recordaddrs = false;
//        } break;
//    }
//}
//
//int main()
//{
//    cout << "Enter test number (1-30): ";
//    int n;
//    cin >> n;
//    testone(n);
//    cout << "Passed!" << endl;
//}
