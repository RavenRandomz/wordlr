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
        player_{player}
    {
    }

    void run()
    {
        game::FiveWord wordToGuess{generateRandomWord()};
        for(int i{0}; i <= kWordleGuesses; ++i)
        {
            game::FiveWord guess{player_.getGuess()};
            if(guess == wordToGuess)
            {
                victory();
                return;
            }
            else
            {
                game::FeedbackList feedback{wordToGuess.compare(guess)};
                player_.setRoundFeetback(feedback);
            }
        }
        std::print("You lost");
    }

    void victory()
    {
        std::println("You won!");
    }

    game::FiveWord generateRandomWord()
    {
        const int kWordIndex {wordIndexGenerator_(randomNumberGenerator_)};
        const std::string kWordText{kWordleDictionary[kWordIndex]};

        return game::FiveWord(kWordText);
    }

private:
    boost::random::mt19937 randomNumberGenerator_{};
    boost::random::uniform_int_distribution<> wordIndexGenerator_{0, static_cast<int>(kWordleDictionary.size() - 1)};
    player::IPlayer& player_;
};
}
