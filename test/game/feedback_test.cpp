import game.Feedback;

#include <gtest/gtest.h>
#include <string>
#include <print>

namespace wordlr::game::feedbackTest
{
TEST(FeedbackList, stringConstructor)
{
    const std::string kText{"abc"};
    const std::string kStatusString{"@#*"};
    const FeedbackList kExpected
    {std::vector<LetterFeedback>{
        {
            .letter = 'a',
            .type = LetterFeedback::Type::kInRightLocation,
            .position = 0
        },
        {
            .letter = 'b',
            .type = LetterFeedback::Type::kInWrongLocation,
            .position = 1
        },
        {
            .letter = 'c',
            .type = LetterFeedback::Type::kNotInWord,
            .position = 2
        }
     }
    };

    const FeedbackList kList{kStatusString, kText};
    EXPECT_TRUE(kList == kExpected);
}
}
