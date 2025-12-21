module;
#include <memory>
#include <vector>
#include <iostream>
#include <print>
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
    virtual game::FiveWord getGuess() override 
    {
        game::Dictionary possibleWords{search_.search()};
        assert(!possibleWords.empty() && "No possible guesses");
        std::string guess{possibleWords[0]};
        std::cout << guess << '\n';
        return game::FiveWord{guess};
    }

    virtual void setRoundFeetback(const game::FeedbackList& feedback) override
    {
        std::cout << feedback.getStatusString() << '\n';
        auto filter{std::make_unique<search::MultiFilter>(search::feedBackToFilter(feedback))};
        search_.addFilter(std::move(filter));
    }

    virtual void onNewRound() override
    {
        ++roundCount_;
        std::cout << "Round: " << roundCount_ << '\n';
        search_.reset();
    }

    virtual void onVictory() override
    {
        std::println("Victory!");
        ++victoryCount_;
    }

    virtual void onLoss() override
    {
        std::println("Loss!");
        ++lossCount_;
    }

    virtual int getVictoryCount() const
    {
        return victoryCount_;
    }

    virtual int getLossCount() const
    {
        return lossCount_;
    }

private:
    search::IncrementalSearch search_{game::kWordleDictionary};

    int victoryCount_{0};
    int lossCount_{0};
    int roundCount_{0};
};
}
