#include <iostream>
#include <vector>
#include <algorithm>

class connect_four {
    private:
        std::vector<std::vector<char>> board;
        
    public:
        connect_four() : board(7, std::vector<char>(6, '-')) {}
        
        void place_disc(int row, char player) {
            row -= 1;
            auto i = std::find_if(board[row].begin(), board[row].end(), [](char c){return c != '-';});
            if(i != board[row].end()) {
                *(i-1) = player;   
            } else {
                board[row].back() = player;   
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
        
        bool is_draw() {
            if(check_winner() == ' ') {
                for(std::vector column : board) {
                    for(char cell : column) {
                        if(cell == '-') {return false;}
                    }
                }
            }
            return true;
        }
        
        void print_board() {
            std::cout << "\n1 2 3 4 5 6 7 \n";
            for(int i = 0; i < 6; i++) {
                for(std::vector row : board) {
                    std::cout << row[i] << ' ';
                }
                std::cout << '\n';
            }
        } 
        
        void player_turn(char player) {
            std::string input{""};
            int column{0};
            while(true) {
                std::cin >> input;
                if(std::all_of(input.begin(), input.end(), ::isdigit)) {
                    column = stoi(input);
                    if(column > 0 && column < 8) {
                        place_disc(column, player);
                        return;
                    }
                }
            }
        }
        
        void play() {
            while(true) { 
                print_board();
                if(check_winner() == 'X') {std::cout << "X wins!"; return;}
                if(is_draw()) {std::cout << "its a draw!"; return;}
                player_turn('O');
                print_board();
                if(check_winner() == 'O') {std::cout << "O wins!"; return;}
                if(is_draw()) {std::cout << "its a draw!"; return;} 
                player_turn('X');
            }
        }
};

int main() {
    connect_four mygame;
    mygame.play();
    
    return 0;   
}
