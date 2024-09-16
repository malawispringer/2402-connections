#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "dictionary.h"

bool userTurn(Board &game); 

void playGame(Board &game){
    int lives = 4; 
    //game.readData(); 
     game.setBoard(); 
    while (lives != 0){
        std::cout << "Lives: " << lives << "\n"; 
        game.printBoard(); 
        if (!userTurn(game)){
            lives--; 
        }
    }  
    //so it compiles
    if (lives == 0) std::cout << "Better luck next time!\n"; 
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
    //if the first two are in the same cat
    int num_cor = 0; 
    std::cout << game.words[word1] << " " << game.words[word2] << " " << game.words[word3] << " " << game.words[word4] << " "; 
    if (game.words[word1] == game.words[word2]){
        num_cor++; 
    }
    if(game.words[word2] == game.words[word3]){
        num_cor++;
    }
    if(game.words[word3] == game.words[word4]){
        num_cor++;
    }
        
 
    
    if (num_cor == 3) return true;
    //if the line is correct now need to print the line on top
    //so add it to correct lines
    game.correct_lines.push_back(game.words[word1]); 
    if (num_cor == 2){
        std::cout << "One away!\n"; 
    }
     
    return false; 
}