import derp;
import game.FiveWord;
import word.AnotherTestWord;
import word.Word;
import game.Dictionary;
import game.WordleDictionary;
#include <string>
#include <iostream>
#include <print>
#include "game/default_dictionary.h"
// Rare using moment :)
using namespace wordlr;
int main()
{
    for(auto& word : game::kWordleDictionary)
    {
        std::cout << word;
    }
    std::print("Fuck");

    game::Dictionary test{};
    return 0;
}
