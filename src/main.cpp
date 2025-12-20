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
#include <format>
#include <iostream>
#include <cassert>
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
        assert(!word.empty() && "CAUGHT");
        game::Round round{bot, word};
        round.run();
    }

    // Velvet moring kyau and albert
    std::string s{std::format("Victories: {}, Losses {}", bot.getVictoryCount(), bot.getLossCount()).c_str()};
    std::cout << s;

    return 0;
}
