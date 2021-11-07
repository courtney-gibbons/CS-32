//#include <iostream>
//using namespace std;
//
//// MY CODE START ////////////////////////////////////////////////////////////////////////
//bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
//    // Return true if there is a path from (sr,sc) to (er,ec)
//    // through the maze; return false otherwise
//
//    if (sr == er && sc == ec) {
//        return true;
//    }
//    maze[sr][sc] = 'o';
//    // South
//    if (maze[sr+1][sc] == '.') {
//        if (pathExists(maze, sr+1, sc, er, ec) == true) {
//            return true;
//        }
//    }
//    // West
//    if (maze[sr][sc-1] == '.') {
//        if (pathExists(maze, sr, sc-1, er, ec) == true) {
//            return true;
//        }
//    }
//    // North
//    if (maze[sr-1][sc] == '.') {
//        if (pathExists(maze, sr-1, sc, er, ec) == true) {
//            return true;
//        }
//    }
//    // East
//    if (maze[sr][sc+1] == '.') {
//        if (pathExists(maze, sr, sc+1, er, ec) == true) {
//            return true;
//        }
//    }
//    return false;
//}
//// MY CODE END ////////////////////////////////////////////////////////////////////////
//
//int main()
//{
//    char maze[10][10] = {
//        { 'X','X','X','X','X','X','X','X','X','X' },
//        { 'X','.','.','.','.','X','.','.','X','X' },
//        { 'X','.','X','X','.','X','X','.','.','X' },
//        { 'X','X','X','.','.','.','.','X','.','X' },
//        { 'X','.','X','X','X','.','X','X','X','X' },
//        { 'X','.','X','.','.','.','X','.','.','X' },
//        { 'X','.','.','.','X','.','X','.','.','X' },
//        { 'X','X','X','X','X','.','X','.','X','X' },
//        { 'X','.','.','.','.','.','.','.','.','X' },
//        { 'X','X','X','X','X','X','X','X','X','X' }
//    };
//
//    if (pathExists(maze, 3,5, 8,8))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//}
//
