module;
#include <memory>
#include <vector>
#include <cassert>

export module player.SimpleEliminationBot;
import game.FiveWord;
import game.Feedback;
import player.IPlayer;
import search.IncrementalSearch;
import search.FeedbackToFilter;
import search.MultiFilter;
import game.Dictionary;
import game.WordleDictionary;

namespace wordlr::player
{
export class SimpleEliminationBot : public IPlayer
{
public:
    game::FiveWord getGuess() override 
    {
        game::Dictionary possibleWords{search_.search()};
        assert(!possibleWords.empty() && "No possible guesses");
        return game::FiveWord(possibleWords[0]);
    }

    void setRoundFeetback(const game::FeedbackList& feedback) override
    {
        auto filter{std::make_unique<search::MultiFilter>(search::feedBackToFilter(feedback))};
        search_.addFilter(std::move(filter));
    }

    void onNewRound() override
    {
        search_.reset();
    }

    void onVictory() override
    {
        ++victoryCount_;
    }

    void onLoss() override
    {
        ++lossCount_;
    }

    int getVictoryCount() const
    {
        return victoryCount_;
    }

    int getLossCount() const
    {
        return lossCount_;
    }

private:
    search::IncrementalSearch search_{game::kWordleDictionary};

    int victoryCount_{0};
    int lossCount_{0};
};
}
