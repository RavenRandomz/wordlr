module;

#include <print>
#include <memory>
#include <iostream>

export module search.SearchAgent;

import game.Feedback;
import game.WordleDictionary;

import search.IncrementalSearch;
import search.SearchEngine;
import search.FeedbackToFilter;
import search.MultiFilter;
import search.IFilter;

namespace wordlr::search
{
export class SearchAgent
{
public:
    void search() 
    {
        bool validInput{false};
        std::string guessText{};
        while(1)
        {
            game::FeedbackList currentFeedback{promptForFeedback()};
            auto filter{std::make_unique<MultiFilter>(feedBackToFilter(currentFeedback))};
            search_.addFilter(std::move(filter));
            printSearchResults();
        }
    }

private:
    SearchEngine search_{game::kWordleDictionary};

    game::FeedbackList promptForFeedback()
    {
        std::string guess;
        std::print("Enter your guess which must be a lowercase 5 letter word:\n");
        std::getline(std::cin, guess);
        std::string feedbackSymbols;
        std::print("Enter feeback string: @ correct location, * not in word, # wrong location\n");
        std::getline(std::cin, feedbackSymbols);

        game::FeedbackList feedback{feedbackSymbols, guess};

        return feedback;
    }

    void printSearchResults() 
    {
        std::print("VALID GUESSES\n");
        std::vector results{search_.search()};
        for(const auto& word : results) 
        {
            std::cout << word << '\n';
        }
    }
    
};
}
