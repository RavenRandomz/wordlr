import derp;
import game.FiveWord;
import word.AnotherTestWord;
import word.Word;
import game.Dictionary;
#include <string>
#include <iostream>
#include <print>
#include "game/default_dictionary.h"
// Rare using moment :)
using namespace wordlr;
int main()
{
    std::cout << game::getDefaultDictionaryString();
    std::print("Fuck");

    game::Dictionary test{};
    return 0;
}
