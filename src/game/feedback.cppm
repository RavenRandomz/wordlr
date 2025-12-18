module;

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
        kInWord,
        kInRightLocation
    };
    char letter;
    Type type;
    int position;
};
}
