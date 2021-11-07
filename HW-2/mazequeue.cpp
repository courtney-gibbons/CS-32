//#include <iostream>
//#include <queue>
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
//    queue<Coord> coordQueue;
//    coordQueue.push(Coord(sr,sc));
//    maze[sr][sc] = 'o';
//    while(!coordQueue.empty()) {
//        Coord front = coordQueue.front();
//        coordQueue.pop();
//        if (front.r() == er && front.c() == ec) {
//            return true;
//        }
//        // South
//        if (maze[front.r()+1][front.c()] == '.') {
//            coordQueue.push(Coord(front.r()+1,front.c()));
//            maze[front.r()+1][front.c()] = 'o';
//        }
//        // West
//        if (maze[front.r()][front.c()-1] == '.') {
//            coordQueue.push(Coord(front.r(),front.c()-1));
//            maze[front.r()][front.c()-1] = 'o';
//        }
//        // North
//        if (maze[front.r()-1][front.c()] == '.') {
//            coordQueue.push(Coord(front.r()-1,front.c()));
//            maze[front.r()-1][front.c()] = 'o';
//        }
//        // East
//        if (maze[front.r()][front.c()+1] == '.') {
//            coordQueue.push(Coord(front.r(),front.c()+1));
//            maze[front.r()][front.c()+1] = 'o';
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
////
