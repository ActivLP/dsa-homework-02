#include <iostream>
#include <chrono>
#include <thread>    
#include <cstdlib>   
#include "game_of_life.h"
using namespace std;

// I add a better display in the terminal by refreshing the page every 1 second per new generation :)

int main() {
    game_of_life the_game;

    while (true) {
        system("CLS"); 
        the_game.draw();
        the_game.next_generation();
        this_thread::sleep_for(chrono::seconds(1));  
    }

    return 0;
}
