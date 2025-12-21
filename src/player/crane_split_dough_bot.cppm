module;

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

export module player.CraneSplitDoughBot;
import player.SimpleEliminationBot;
import game.FiveWord;
import game.Dictionary;

namespace wordlr::player
{
export class CraneSplitDoughBot : public SimpleEliminationBot
{
public:
    using SimpleEliminationBot::SimpleEliminationBot;

    virtual game::FiveWord getGuess() override 
    {

        if(guessCount_ == std::clamp(guessCount_, 1, 3))
        {
            const std::string kGuess{craneSplitDoughElimination_[craneSplitDoughIndex_]};
            ++craneSplitDoughIndex_;
            std::cout << kGuess <<'\n';
            return game::FiveWord{kGuess};
        }
        else
        {
            return SimpleEliminationBot::getGuess();
        }

        ++guessCount_;
    }

    virtual void onNewRound() override
    {
        guessCount_ = 1;
        craneSplitDoughIndex_ = 0;
    }
private:
    static const int kMaxGuesses{6};
    int guessCount_{1};

    int craneSplitDoughIndex_{0};
    std::vector<std::string> craneSplitDoughElimination_{"crane", "split", "dough"};
};
}
