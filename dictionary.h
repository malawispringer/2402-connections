//Project Identifier:  

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

class Board {
    private:
    std::vector<std::string> board; 

    public:
    void printBoard(); 
    void setBoard(std::vector<std::string> in_order_vector); 
    
    struct Word{
        std::string data; 
        char level; 
    }
}; //class Board

//R: a vector of strings
//M: the Board private member variable board
//E: takes the set of words from input and 'randomizes' the board 
void Board::setBoard(std::vector<std::string> in_order_vector){
    std::vector<std::string> temp; 

}//Board::setBoard

//E: prints the board in a human legible manner
void Board::printBoard(){
  for(auto i : board)
    std::cout << std::setw(4) << "[ " << i << " ]\n";
} //Board::print Board