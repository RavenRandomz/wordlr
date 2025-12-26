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
import player.CraneSplitDoughBot;
#include <string>
#include <format>
#include <iostream>
#include <cassert>
#include <random>
#include <algorithm>
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
    player::CraneSplitDoughBot bot{};

    //Floyd U - Single Avoure

    auto rng{std::default_random_engine{}};

    game::Dictionary shuffled{game::kAnswerDictionary};
    std::ranges::shuffle(shuffled, rng);

    for (const std::string& word : shuffled)
    {
        assert(!word.empty() && "CAUGHT");
        game::Round round{bot, word};
        round.run();
    }

    for (const auto& word : bot.getLossWords())
    {
        std::println("{}",word);
    }

    // Velvet moring kyau and albert
    std::println("Victories: {}, Losses {}", bot.getVictoryCount(), bot.getLossCount());

    int total{bot.getVictoryCount() + bot.getLossCount()};
    double winRatio{bot.getVictoryCount() / static_cast<double>(total)};

    std::println("Win ratio: {}", winRatio);

    return 0;
}
