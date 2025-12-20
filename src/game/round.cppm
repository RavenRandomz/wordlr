module;
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random.hpp>

#include <print>
export module game.Round;

import player.IPlayer;
import game.WordleDictionary;
import game.FiveWord;
import game.Feedback;

namespace wordlr::game
{
export class Round
{
public:
    static const int kWordleGuesses{5};

    Round(player::IPlayer& player)
        :
        player_{player},
        wordToGuess_{generateRandomWord()}
    {
    }

    Round(player::IPlayer& player, const game::FiveWord& word)
        :
        player_{player},
        wordToGuess_{word}
    {
    }

    void run()
    {
        player_.onNewRound();
        for(int i{0}; i <= kWordleGuesses; ++i)
        {
            game::FiveWord guess{player_.getGuess()};
            if(guess == wordToGuess_)
            {
                player_.onVictory();
                return;
            }
            else
            {
                game::FeedbackList feedback{wordToGuess_.compare(guess)};
                player_.setRoundFeetback(feedback);
            }
        }
        player_.onLoss();
    }

    game::FiveWord generateRandomWord()
    {
        const int kWordIndex {wordIndexGenerator_(randomNumberGenerator_)};
        const std::string kWordText{kWordleDictionary[kWordIndex]};

        return game::FiveWord(kWordText);
    }

private:
    static boost::random::mt19937 randomNumberGenerator_;
    boost::random::uniform_int_distribution<> wordIndexGenerator_{0, static_cast<int>(kWordleDictionary.size() - 1)};

    player::IPlayer& player_;
    game::FiveWord wordToGuess_;
};

boost::random::mt19937 Round::randomNumberGenerator_{};
}

