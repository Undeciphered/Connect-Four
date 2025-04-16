#include <iostream>
#include <vector>
#include <algorithm>

class connect_four {
    private:
        std::vector<std::vector<char>> board;
        
    public:
        connect_four() : board(7, std::vector<char>(6, '-')) {
            board[0] = {'-', '-', '-', '-', '-', 'X'};
        }
        
        void place_disc(int row) {
            row -= 1;
            auto i = std::find_if(board[row].begin(), board[row].end(), [](char c){return c != '-';});
            if(i != board[row].end()) {
                *(i-1) = 'X';   
            } else {
                board[row].back() = 'X';   
            }   
        }
        
        void print_row(int row) {
            row -= 1;
            for(char c : board[row]) {
                std::cout << c;
            }
            std::cout << '\n';
        } 
};

int main() {
    connect_four mygame;
    mygame.print_row(1);
    mygame.place_disc(1);
    mygame.print_row(1);
    
    return 0;   
}
