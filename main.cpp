/* Malawi Springer - Feburary 2024
 * This is a program that imitates the game Connections by New York Times Games
 *
 *
 * 
 */

#include <iostream>
#include <string>
#include "gameplay.h"

void printMenu();
void printRules(); 
void printControls(); 


int main(){ 
    std::cout << "-----------Welcome to Connections!----------\n"; 
    printMenu();
    playGame();
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