/* Malawi Springer - Feburary 2024
 * This is a program that imitates the game Connections by New York Times Games
 *
 *
 * 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "gameplay.h"

void printMenu();
void printRules(); 
void printControls(); 


int main(int argc, char **argv){ 
    if(argc != 2){
        std::cout << "Please include input file!\n"; 
        exit(1); 
    } 
    
    std::cout << "-----------Welcome to Connections!----------\n"; 
    printMenu();
    std::string read_file; 
    if (argc == 2){
        for (int i = 1; i < argc; i++){
            if (i == 1) read_file = argv[i]; 
        }
    }

    std::ifstream stream(read_file); 
    assert(stream.is_open()); 
    Board created_board(stream);

    playGame(created_board);
    return 0; 
 
}

void  printMenu(){
    std::cout << "Please make a selection from the menu below.\n"
              << "r: Rules\n"
              << "c: Controls\n"
              << "p: Play Game\n";
    char selection; 
    std::cin >> selection; 
    if (selection == 'r'){
        printRules(); 
        printMenu(); 
    } else if (selection == 'c'){
        printControls();
        printMenu(); 
    }  else if (selection != 'p'){
        std::cout << "***Invalid Input***\n"; 
        printMenu(); 
    }
}

void printControls(){
    std::cout << "Type the four words you would like to guess with a singular space"
              << "between them and press enter.\n"; 
    std::cout << "then\n"; 
}

void printRules(){
    std::cout << "***Rules go here***\n\n"; 
}