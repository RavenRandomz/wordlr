import derp;
import game.FiveWord;
import word.AnotherTestWord;
import word.Word;
import game.Dictionary;
import game.WordleDictionary;
import game.Round;
import search.SearchAgent;
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
    search::SearchAgent agent{};
    agent.search();
    return 0;
}
