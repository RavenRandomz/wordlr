import derp;
import game.FiveWord;
import word.AnotherTestWord;
import word.Word;
import game.Dictionary;
import game.WordleDictionary;
import game.Round;
import player.HumanPlayer;
#include <string>
#include <iostream>
#include <print>
#include "game/default_dictionary.h"
// Rare using moment :)
using namespace wordlr;
int main()
{
    //for(auto& word : game::kWordleDictionary)
    //{
    //    std::cout << word;
    //}
    //std::print("Fuck");

    player::HumanPlayer player{};
    game::FiveWord crane{"crane"};
    while(1)
    {
        game::Round round{player};
        round.run();
    }
    return 0;
}
