import derp;
import game.FiveWord;
import word.AnotherTestWord;
import word.Word;
import game.Dictionary;
import game.WordleDictionary;
import game.Round;
import search.SearchAgent;
import player.HumanPlayer;
import player.SimpleEliminationBot;
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
    //
    player::SimpleEliminationBot bot{};

    //Floyd U - Single Avoure

    for (const std::string& word : game::kWordleDictionary)
    {
        game::Round round{bot, word};
        round.run();
        bot.onNewRound();
    }

    return 0;
}
