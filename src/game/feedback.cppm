module;

#include <string_view>
#include <vector>

export module game.Feedback;

/**
 *
 * Feedback types : letter is not in word, letter is in word, letter is in word in right location.
 */
namespace wordlr::game
{
export struct LetterFeedback
{
    /**
     * Kinda cursed to nest this but it's really context specific
     * so instead of naming this LetterFeedbackType
     */
    enum class Type 
    {
        kNotInWord,
        kInWrongLocation,
        kInRightLocation
    };
    char letter;
    Type type;
    int position;

};

export class FeedbackList : public std::vector<LetterFeedback>
{
public:
//using std::vector<LetterFeedback>::vector;

    /**
     *
     * Letter Status in order 
     * "plays"
     * "*#@@#"
     */
    FeedbackList(std::vector<LetterFeedback> vector) : std::vector<LetterFeedback>{vector}
    {
    }

    FeedbackList(std::string_view letterStatus, std::string_view word) : std::vector<LetterFeedback>{}
    {
        for(int i{0}; i <= word.length(); ++i)
        {
            const char kLetter{word[i]};
            const char kStatusSymbol{letterStatus[i]};
            LetterFeedback::Type feedBackType{};
            switch(kStatusSymbol)
            {
                case(kInRightLocationSymbol):
                    feedBackType = LetterFeedback::Type::kInRightLocation;
                    break;
                case(kInWrongLocationSymbol):
                    feedBackType = LetterFeedback::Type::kInWrongLocation;
                    break;
                case(kNotInWordSymbol):
                    feedBackType = LetterFeedback::Type::kNotInWord;
                    break;
            };
            push_back(
                LetterFeedback
                {
                    .letter = kLetter,
                    .type = feedBackType,
                    .position = i
                }
            );
        }
    }

    static const char kNotInWordSymbol{'*'};
    static const char kInWrongLocationSymbol{'#'};
    static const char kInRightLocationSymbol{'@'};
};
}
