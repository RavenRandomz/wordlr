module;

#include <print>
#include <iostream>

export module player.HumanPlayer;

import player.IPlayer;
import game.FiveWord;
import game.Feedback;

namespace wordlr::player
{
export class HumanPlayer : public IPlayer
{
public:
    game::FiveWord getGuess() override 
    {
        bool validInput{false};
        std::string guessText{};
        while(!validInput)
        {
            std::string guessText = promptForGuess();
            if(game::FiveWord::isRealWordleWord(guessText) && game::FiveWord::properlyFormatted(guessText))
            {
                validInput = true;
            }
            else
            {
                invalidWarning();
            }
        }
        return game::FiveWord(guessText);
    }


    void setRoundFeetback(const game::FeedbackList& feedback) override
    {
    }
private:

    std::string promptForGuess()
    {
        std::string guess{};
        std::print("Enter your guess which must be a lowercase 5 letter word: ");
        std::cin >> guess;

        return guess;
    }

    void invalidWarning() const
    {
        std::print("This input is invalid");
    }
    
};
}
