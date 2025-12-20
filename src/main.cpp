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

    int total{bot.getVictoryCount() + bot.getLossCount()};
    double winRatio{bot.getVictoryCount() / static_cast<double>(total)};
    std::cout << "Win ratio: " << winRatio << '\n';

    return 0;
}
