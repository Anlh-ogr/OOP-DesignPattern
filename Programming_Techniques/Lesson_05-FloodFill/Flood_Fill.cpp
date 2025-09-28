#include <bits/stdc++.h>

const int Rows = 10;
const int Cols = 10;
const int Mines = 10;

// display
std::vector<std::vector<char>> board(Rows, std::vector<char>(Cols, '0'));   // real data
std::vector<std::vector<char>> display(Rows, std::vector<char>(Cols, '#')); // Ui/Ux

// check valid
bool valid (int x, int y) {
    return (x >= 0 && x < Rows && y >= 0 && y < Cols);
}

// Random Mines (Boom)
void place_mines() {
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

// define mode 8 (4 or 8)
int mode = 8;

void calc_numbers() {
    int dx4[4] = {-1, 1, 0, 0};
    int dy4[4] = {0, 0, -1, 1};
    int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int i = 0; i < Rows; ++i)
        for (int j = 0; j < Cols; ++j) {
            if (board[i][j] == '*')
                continue;
            
            int cnt = 0;
            if (mode == 4)
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx4[k];
                    int ny = j + dy4[k];
                    if (valid(nx, ny) && board[nx][ny] == '*')
                        ++cnt;
                }
            else
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx8[k];
                    int ny = j + dy8[k];
                    if (valid(nx, ny) && board[nx][ny] == '*')
                        ++cnt;
                }
            board[i][j] = cnt + '0'; 
        }
}

// fill box
void flood_fill(int x, int y) {
    if (!valid(x, y) || display[x][y] != '#')
        return;
    display[x][y] = board[x][y];
    
    if (board[x][y] == '0') {
        if (mode == 4) {
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k)
                flood_fill(x + dx[k], y + dy[k]);
        } else {
            int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (int k = 0; k < 8; ++k)
                flood_fill(x + dx[k], y + dy[k]);
        }
    }
}

// count safe box
int cnt_safe_box () {
    int cnt = 0;
    for (int i = 0; i < Rows; ++i)
        for (int j = 0; j < Cols; ++j)
            if (display[i][j] != '#' && board[i][j] != '*')
                ++cnt;
    return cnt;
}

// output
void print_board() {
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
    
    std::cout << "Choose mode (4 = Easy, 8 = Hard): ";
    std::cin >> mode;

    if (mode != 4 && mode != 8)
        mode = 8;       // define mode

    place_mines();
    calc_numbers();

    bool game_over = false;
    int safe_cells = Rows * Cols - Mines;

    while (!game_over) {
        print_board();

        int x, y;
        std::cout << std::endl;
        std::cout << "Enter point (x, y): ";
        std::cin >> x >> y;

        if (!valid(x, y)) {
            std::cout << "Invalid point!" << std::endl;
            continue;
        }
        
        if (display[x][y] != '#') {
            std::cout << "Already opened!" << std::endl;
            continue;
        }

        if (board[x][y] == '*') {
            std::cout << "Game Over!" << std::endl;
            game_over = true;
        } else {
            flood_fill(x, y);
            if (cnt_safe_box() >= safe_cells) {
                std::cout << "Congratulation!" << std::endl;
                game_over = true;
            }            
        }
    }

    std::cout << "Final board" << std::endl;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}