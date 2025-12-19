#include <gtest/gtest.h>
#include <string>

import search.HasLetter;

namespace wordlr::search::HasLetterTest
{
TEST(HasLetter, foundWord)
{
    const std::string kHasA {"argyle"};
    const std::string kHasZAndA {"zebra"};
    const std::string kHasZ{"zed"};
    const std::string kHasNone{"psychic"};

    const HasLetter kAFilter{'a'};
    const HasLetter kZFilter{'z'};

    EXPECT_TRUE(kAFilter.isTextValid(kHasA));
    EXPECT_TRUE(kAFilter.isTextValid(kHasZAndA));
    EXPECT_TRUE(kZFilter.isTextValid(kHasZAndA));
    EXPECT_TRUE(kZFilter.isTextValid(kHasZ));

    EXPECT_FALSE(kZFilter.isTextValid(kHasNone));
    EXPECT_FALSE(kAFilter.isTextValid(kHasNone));
    EXPECT_FALSE(kAFilter.isTextValid(kHasZ));
    EXPECT_FALSE(kZFilter.isTextValid(kHasA));
}
}
