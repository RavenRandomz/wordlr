module;
#include <vector>
#include <memory>

export module search.FeedbackToFilter;
import search.IFilter;
import search.HasLetter;
import search.ExcludesThisLetter;
import search.LetterHere;
import search.LetterNotHere;
import search.MultiFilter;
import game.Feedback;
namespace wordlr::search
{

export MultiFilter feedBackToFilter(const game::FeedbackList& feedbackList)
{
    MultiFilter filter{};
    for(const game::LetterFeedback& feedback : feedbackList)
    {
        switch(feedback.type)
        {
            case(game::LetterFeedback::Type::kInRightLocation):
                {
                    auto locationFilter{std::make_unique<LetterHere>(feedback.letter, feedback.position)};
                    filter.insert(std::move(locationFilter));
                }
                break;
            case(game::LetterFeedback::Type::kInWrongLocation):
                {
                    auto hasLetterFilter{std::make_unique<HasLetter>(feedback.letter)};
                    auto antiLocationFilter{std::make_unique<LetterNotHere>(feedback.letter, feedback.position)};
                    filter.insert(std::move(antiLocationFilter));
                    filter.insert(std::move(hasLetterFilter));
                }
                break;
            case(game::LetterFeedback::Type::kNotInWord):
                {
                    auto letterExclusionFilter{std::make_unique<ExcludesThisLetter>(feedback.letter)};
                    filter.insert(std::move(letterExclusionFilter));
                }
                break;
        };
    }
    return filter;
}
}
