#include <gtest/gtest.h>
#include <string>

import search.ExcludesThisLetter;

namespace wordlr::search::HasLetterTest
{
TEST(ExcludesThisLetter, wordValidity)
{
    const std::string kHasA{"argyle"};
    const std::string kHasZAndA {"zebra"};
    const std::string kHasZ{"zed"};
    const std::string kHasNone{"psychic"};

    const ExcludesThisLetter kAFilter{'a'};
    const ExcludesThisLetter kZFilter{'z'};

    EXPECT_FALSE(kAFilter.isTextValid(kHasA));
    EXPECT_FALSE(kAFilter.isTextValid(kHasZAndA));
    EXPECT_FALSE(kZFilter.isTextValid(kHasZAndA));
    EXPECT_FALSE(kZFilter.isTextValid(kHasZ));

    EXPECT_TRUE(kZFilter.isTextValid(kHasNone));
    EXPECT_TRUE(kAFilter.isTextValid(kHasNone));
    EXPECT_TRUE(kAFilter.isTextValid(kHasZ));
    EXPECT_TRUE(kZFilter.isTextValid(kHasA));
}
}
