#include <bits/stdc++.h>

const int Rows = 10;
const int Cols = 10;
const int Mines = 10;

std::vector<std::vector<char>> board(Rows, std::vector<char>(Cols, '0')); // real data
std::vector<std::vector<char>> display(Rows, std::vector<char>(Cols, '#')); // Ui/Ux

// check board
bool valid (int x, int y) {
    return (x >= 0 && x < Rows && y >= 0 && y < Cols);
}

// Random Mines (Boom)
void placeMines() {
    int placed = 0;
    while (placed < Mines) {
        int x = rand() % Rows;
        int y = rand() % Cols;
        if (board[x][y] != '*') {
            board[x][y] = '*';
            ++placed;
        }
    }
}

//
void calcNumbers() {
    // int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < Rows; ++i)
        for (int j = 0; j < Cols; ++j) {
            if (board[i][j] == '*')
                continue;
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (valid(nx, ny) && board[nx][ny] == '*')
                    ++cnt;
            }
            board[i][j] = cnt + '0'; 
        }
}

void flood_fill(int x, int y) {
    if (!valid(x, y) || display[x][y] != '#')
        return;
    display[x][y] = board[x][y];
    if (board[x][y] == '0') {
        // int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        // int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (valid(nx, ny))
                flood_fill(nx, ny);
        }
    }
}

void printBoard() {
    std::cout << "\n   ";
    for (int j = 0; j < Cols; ++j)
        std::cout << std::setw(2) << j;
    std::cout << std::endl;
    for (int i = 0; i < Rows; ++i) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < Cols; ++j)
            std::cout << std::setw(2) << display[i][j];
        std::cout << std::endl;
    }
}

int main() {
    std::srand(time(0));
    placeMines();
    calcNumbers();

    bool game_over = false;
    int safe_cells = Rows * Cols - Mines;

    while (!game_over) {
        printBoard();
        // open safe cell -> win -> break game


        int x, y;
        std::cout << std::endl;
        std::cout << "Enter point (x, y): ";
        std::cin >> x >> y;

        if (!valid(x, y)) {
            std::cout << "Wrong point!" << std::endl;
            continue;
        }

        if (board[x][y] == '*') {
            std::cout << "Game Over!" << std::endl;
            game_over = true;
        } else {
            flood_fill(x, y);
            
            int unopened = 0;
            for (int i = 0; i < Rows; ++i)
                for (int j = 0; j < Cols; ++j)
                    if (display[x][y] == '#')
                        ++unopened;

            if (unopened == Mines) {
                std::cout << "Congratulation!" << std::endl;
                game_over = true;
            }
        }
    }

    std::cout << "Show board" << std::endl;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}