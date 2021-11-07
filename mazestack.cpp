//#include <iostream>
//#include <stack>
//using namespace std;
//
//class Coord {
//public:
//    Coord(int r, int c) : m_row(r), m_col(c) {}
//    int r() const { return m_row; }
//    int c() const { return m_col; }
//private:
//    int m_row;
//    int m_col;
//};
//
//bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
//    // Return true if there is a path from (sr,sc) to (er,ec)
//    // through the maze; return false otherwise
//    
//    stack<Coord> coordStack;
//    coordStack.push(Coord(sr,sc));
//    maze[sr][sc] = 'o';
//    while(!coordStack.empty()) {
//        Coord top = coordStack.top();
//        coordStack.pop();
//        if (top.r() == er && top.c() == ec) {
//            return true;
//        }
//        // South
//        if (maze[top.r()+1][top.c()] == '.') {
//            coordStack.push(Coord(top.r()+1,top.c()));
//            maze[top.r()+1][top.c()] = 'o';
//        }
//        // West
//        if (maze[top.r()][top.c()-1] == '.') {
//            coordStack.push(Coord(top.r(),top.c()-1));
//            maze[top.r()][top.c()-1] = 'o';
//        }
//        // North
//        if (maze[top.r()-1][top.c()] == '.') {
//            coordStack.push(Coord(top.r()-1,top.c()));
//            maze[top.r()-1][top.c()] = 'o';
//        }
//        // East
//        if (maze[top.r()][top.c()+1] == '.') {
//            coordStack.push(Coord(top.r(),top.c()+1));
//            maze[top.r()][top.c()+1] = 'o';
//        }
//    }
//    return false;
//}
//
////int main()
////{
////    char maze[10][10] = {
////        { 'X','X','X','X','X','X','X','X','X','X' },
////        { 'X','.','.','.','.','X','.','.','X','X' },
////        { 'X','.','X','X','.','X','X','.','.','X' },
////        { 'X','X','X','.','.','.','.','X','.','X' },
////        { 'X','.','X','X','X','.','X','X','X','X' },
////        { 'X','.','X','.','.','.','X','.','.','X' },
////        { 'X','.','.','.','X','.','X','.','.','X' },
////        { 'X','X','X','X','X','.','X','.','X','X' },
////        { 'X','.','.','.','.','.','.','.','.','X' },
////        { 'X','X','X','X','X','X','X','X','X','X' }
////    };
////    
////    if (pathExists(maze, 3,5, 8,8))
////        cout << "Solvable!" << endl;
////    else
////        cout << "Out of luck!" << endl;
////}
