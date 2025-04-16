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
        
        void print_board() {
            std::cout << "1 2 3 4 5 6 7 \n";
            for(int i = 0; i < 6; i++) {
                for(std::vector row : board) {
                    std::cout << row[i] << ' ';
                }
                std::cout << '\n';
            }
            std::cout << '\n';
        } 
};

int main() {
    connect_four mygame;
    mygame.print_board();
    mygame.place_disc(1);
    mygame.print_board();
    
    return 0;   
}
