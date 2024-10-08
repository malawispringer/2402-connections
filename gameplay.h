#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "dictionary.h"

bool userTurn(Board &game); 

void playGame(Board &game){
    int lives = 4; 
    //game.readData(); 
    // game.setBoard(); 
    while (lives != 0 && !game.words.empty()){
        std::cout << "\nLives: " << lives << "\n"; 
        game.printBoard(); 
        if (!userTurn(game)){
            lives--; 
        }
    }  
        if (lives == 4) {
            std::cout << "Perfect game!\n"; 
        } else if (lives == 0) {
            std::cout << "Better luck next time!\n";
        } else {
            std::cout << "Nice job!\n"; 
        } 
    // std::string complier;
    // complier = "test"; 
} //playGame()

//does the turn for the user, returns true if they got a line  
bool userTurn(Board &game){
    std::string word1; 
    std::string word2; 
    std::string word3; 
    std::string word4; 
    std::cin >> word1 >> word2 >> word3 >> word4; 
    //need to add error checking for too many or too few words
    //more or less words
    //any of them not a word in a 
    if (!game.words.count(word1) || !game.words.count(word2) 
        || !game.words.count(word3) || !game.words.count(word4)){
            std::cout << "Please input words from the board.\n"; 
            //so it doesnt reduce the lives
            return true; 
        }
    //any of them the same word
    if (word1 == word2 || word1 == word3 || word1 == word4 || word2 == word3 
        || word2 == word3 || word3 == word4){
        std::cout << "Please input 4 different words.\n"; 
        //so it doesnt reduce the lives
        return true; 
    }
    
    

    //if the first two are in the same cat
    int num_cor = 0; 
    if (game.words[word1] == game.words[word2]){
        num_cor++; 
    }
    if(game.words[word2] == game.words[word3]){
        num_cor++;
    }
    if(game.words[word3] == game.words[word4]){
        num_cor++;
    }
    if(game.words[word4] == game.words[word1]){
        num_cor++;
    }    
    
    if (num_cor == 4){ 
    //if the line is correct now need to print the line on top
    //so add it to correct lines
        game.correct_lines.push_back(game.words[word1]); 
        game.delete_from_word_list(game.words[word1]); 
        return true;
    }
    if (num_cor == 2){
        std::cout << "One away!\n"; 
    }
     
    return false; 
}