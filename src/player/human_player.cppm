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
            guessText = promptForGuess();
            if(game::FiveWord::isRealWordleWord(guessText) && game::FiveWord::properlyFormatted(guessText))
            {
                validInput = true;
            }
            else
            {
                invalidWarning();
            }
        }
        currentGuess_ = guessText;
        return game::FiveWord(guessText);
    }


    void setRoundFeetback(const game::FeedbackList& feedback) override
    {
        std::cout << feedback.getStatusString() << '\n';
    }
private:

    std::string currentGuess_{};
    std::string promptForGuess()
    {
        std::string guess;
        std::print("Enter your guess which must be a lowercase 5 letter word:\n");
        std::getline(std::cin, guess);

        return guess;
    }

    void invalidWarning() const
    {
        std::print("This input is invalid\n");
    }
    
};
}
