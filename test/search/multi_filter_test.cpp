#include <gtest/gtest.h>
#include <string>
#include <memory>

import search.ExcludesThisLetter;
import search.MultiFilter;

namespace wordlr::search::HasLetterTest
{
TEST(MultiFilter, wordValidity)
{
    const std::string kHasA{"argyle"};
    const std::string kHasZAndA {"zebra"};
    const std::string kHasZ{"zed"};
    const std::string kHasNone{"psychic"};

    auto kAFilter{std::make_unique<ExcludesThisLetter>('a')};
    auto kZFilter{std::make_unique<ExcludesThisLetter>('z')};

    MultiFilter multiFilter{};
    multiFilter.insert(std::move(kAFilter));
    multiFilter.insert(std::move(kZFilter));

    EXPECT_FALSE(multiFilter.isTextValid(kHasA));
    EXPECT_FALSE(multiFilter.isTextValid(kHasZAndA));
    EXPECT_FALSE(multiFilter.isTextValid(kHasZAndA));
    EXPECT_FALSE(multiFilter.isTextValid(kHasZ));

    EXPECT_TRUE(multiFilter.isTextValid(kHasNone));
    EXPECT_TRUE(multiFilter.isTextValid(kHasNone));
}
}
