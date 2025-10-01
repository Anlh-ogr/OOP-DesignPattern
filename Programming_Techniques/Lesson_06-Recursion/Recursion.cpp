#include <bits/stdc++.h>

int row, col;
std::vector<std::vector<char>> maze;
std::vector<std::vector<int>> visited;

// start_x, start_y, end_x, end_y
int sx, sy, ex, ey;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col)
        return false;
    if (maze[x][y] == '1' || visited[x][y])
        return false;
    if (x == ex && y == ey) {
        visited[x][y] = 1;
        return true;
    }

    // da di qua
    visited[x][y] = 1;

    // try cardinal_directions
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (dfs(nx, ny))
            return true;
    }

    visited[x][y] = 0;
    return false;
}

int main() {
    std::cin >> row >> col;
    maze.assign(row, std::vector<char>(col));
    visited.assign(row, std::vector<int>(col, 0));

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) {
            std::cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                sx = i; sy = j;
                maze[i][j] = '0';           // S nhu duong di
            }

            if (maze[i][j] == 'E') {
                ex = i; ey = j;
                maze[i][j] = '0';           // E nhu duong di
            }
        }

    if (dfs(sx, sy)) {
        std::cout << "Path found:" << std::endl;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (visited[i][j]) std::cout << ".";
                else std::cout << maze[i][j];
            }
            std::cout << std::endl;
        }
    } else std::cout << "No path!" << std::endl;

    return 0;
}