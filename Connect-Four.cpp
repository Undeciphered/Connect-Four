#include <iostream>
#include <vector>
#include <algorithm>

class connect_four {
    private:
        std::vector<std::vector<char>> board;
        
    public:
        connect_four() : board(7, std::vector<char>(6, '-')) {}
        
        void place_disc(int row) {
            row -= 1;
            auto i = std::find_if(board[row].begin(), board[row].end(), [](char c){return c != '-';});
            if(i != board[row].end()) {
                *(i-1) = 'X';   
            } else {
                board[row].back() = 'X';   
            }   
        }
        
        void remove_disc(int row) {
            row -= 1;
            auto i = std::find_if(board[row].begin(), board[row].end(), [](char c){return c != '-';});
            if(i != board[row].end()) {
                *(i) = '-';   
            } else {
                return;   
            }
            
        }
        
        char check_winner() {
            for(int i = 0; i < 7; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j+3] != '-') {
                        return board[i][j];   
                    }
                }
            }
            for(int i = 0; i < 6; i++) {
                for(int j = 0; j < 4; j++) {
                    if(board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j+2][i] == board[j+3][i] && board[j+3][i] != '-') {
                        return board[j][i];   
                    } 
                    
                }
            }
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 4; j++) {
                    if(board[j][i] == board[j+1][i+1] && board[j+1][i+1] == board[j+2][i+2] && board[j+2][i+2] == board[j+3][i+3] && board[j+3][i+3] != '-') {
                        return board[j][i];   
                    }
                    if(board[j+3][i] == board[j+2][i+1] && board[j+2][i+1] == board[j+1][i+2] && board[j+1][i+2] == board[j][i+3] && board[j][i+3] != '-') {
                        return board[j+3][i];   
                    }
                }
            }
            return ' ';
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
    
    return 0;   
}
