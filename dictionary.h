//Project Identifier:  

#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std; 

class Board {
    public:
    //The unmodified list of the words
    vector<string> wordsList; 
    //The categories that the user has gotten correct in order
    vector<int> correct_lines = {}; 
    //the titles of all the categories
    vector<string> titles; 

    
    Board(std::istream& board_input);
    //pprints the board for the player tolook at
    void printBoard(); 
    void setBoard();
    void readData(); 
    void delete_from_word_list(int level);
    
    unordered_map<std::string, int> words; 
 
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
            wordsList.push_back(word); 
            words[word] = a;  
        }
    }
}
//R: a vector of strings
//M: the Board private member variable board
//E: takes the set of words from input and 'randomizes' the board 
void Board::setBoard(){
    random_device rd;
    mt19937 g(rd()); 
    shuffle(wordsList.begin(), wordsList.end(), g); 
}//Board::setBoard

//E: prints the board in a human legible manner
void Board::printBoard(){
    for (auto i : correct_lines){
        std::cout << titles[i] << "\n"; 
        for (int j = i*4; j < (i*4)+4; j++){
            std::cout << wordsList[j] << ", "; 
        }
        std::cout << "\n"; 
    }
    int count = 0; 
  for(auto i : words){
    count++; 
    std::cout << setw(4) << "[ " << i.first << " ]" << setw(5);
    if (count % 4 == 0) cout << "\n"; 
  }
} //Board::print Board

void Board::delete_from_word_list(int level){

}
/*

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

} // readData()
*/