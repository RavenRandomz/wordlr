module;

export module game.Feedback;

/**
 *
 * Feedback types : letter is not in word, letter is in word, letter is in word in right location.
 */
namespace wordlr::game
{
enum class LetterFeedbackType
{
    kNotInWord,
    kInWord,
    kInRightLocation
};
}
