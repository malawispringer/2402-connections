/* Malawi Springer - Feburary 2024
 * This is a program that imitates the game Connections by New York Times Games
 *
 *
 * 
 */

#include <iostream>
#include <string>

void printMenu();
void printRules(); 
void printControls(); 


int main(){ 
    std::cout << "-----------Welcome to Connections!----------\n"; 
    printMenu();
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
    }  else if (selection != 112){
        std::cout << "***Invalid Input***\n"; 
        printMenu(); 
    }
}

void printControls(){
    std::cout << "***Controls go here***\n\n"; 
}

void printRules(){
    std::cout << "***Rules go here***\n\n"; 
}