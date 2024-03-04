#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "dictionary.h"

void playGame(); 
void readData(std::vector<std::string> &in_order_vector); 

void playGame(){
    //read in the data, 

    //so it compiles
    std::string complier;
    complier = "test"; 
} //playGame()

//E: reads the data from cin using input redirectiom of files
void readData(std::vector<std::string> &in_order_vector, std::vector<std::string> &topics){
    std::string line; 
    //we know there's 4 categories, going to getline and set
    for (int i = 0; i < 4; i++){

        std::getline(std::cin, line); //get the first line for topic
        std::istringstream iss(line); 
        std::string topic; 
        //parse the 
        while (std::getline(iss, word, ' ')){

        }

    }//for i
}//readData