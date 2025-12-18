module;

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
    using std::vector<LetterFeedback>::vector;
    static const char kNotInWordSymbol{'*'};
    static const char kInWrongLocationSymbol{'#'};
    static const char kInRightLocationSymbol{'@'};
};
}
