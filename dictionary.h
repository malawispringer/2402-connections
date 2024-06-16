//Project Identifier:  

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std; 

class Board {
    private:
    vector<string> words; 
    vector<string> titles; 

    public:
    Board(std::istream& board_input);
    void printBoard(); 
    void setBoard();
    void readData();  
    
    struct Word{
        string data; 
        char level; 
    }; 
}; //class Board

//Custom Constructor, but there should never be an intilazed board other than the first
Board::Board(std::istream& board_input){
     for (int a = 0; a < 4; a++){
        string difficulty; 
        board_input >> difficulty; // Easy, Simple, Difficult, Tricky
        string topic;
        getline(board_input, topic); //get the rest of line for topic
        istringstream iss(topic); 
        titles.push_back(topic); 
        for (int i = 0; i < 4; i++){
            string word; 
            board_input >> word; 
            words.push_back(word); 
        }
    }

}
//R: a vector of strings
//M: the Board private member variable board
//E: takes the set of words from input and 'randomizes' the board 
void Board::setBoard(){
    random_device rd;
    mt19937 g(rd()); 
    shuffle(words.begin(), words.end(), g); 
}//Board::setBoard

//E: prints the board in a human legible manner
void Board::printBoard(){
    int count = 0; 
  for(auto i : words){
    count++; 
    cout << setw(4) << "[ " << i << " ]" << setw(5);
    if (count % 4 == 0) cout << "\n"; 
  }
} //Board::print Board

void Board::readData(){
    for (int a = 0; a < 4; a++){
        string difficulty; 
        cin >> difficulty; // Easy, Simple, Difficult, Tricky
        string topic;
        getline(cin, topic); //get the rest of line for topic
        istringstream iss(topic); 
        titles.push_back(topic); 
        for (int i = 0; i < 4; i++){
            string word; 
            cin >> word; 
            words.push_back(word); 
        }
    }

}