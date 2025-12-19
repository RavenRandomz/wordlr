#include <gtest/gtest.h>
#include <string>

import search.LetterHere;

namespace wordlr::search::HasLetterTest
{
TEST(LetterHere, wordValidity)
{
    const std::string kHasAat1{"argyle"};
    const std::string kHasAat3{"plane"};
    const std::string kHasZat2{"tzar"};

    // Note that positions are index
    const LetterHere kAat1Filter{'a', 0};
    const LetterHere kAat3Filter{'a', 2};
    const LetterHere kZat2Filter{'z', 1};


    EXPECT_TRUE(kAat1Filter.isTextValid(kHasAat1));
    EXPECT_FALSE(kAat1Filter.isTextValid(kHasAat3));
    EXPECT_FALSE(kZat2Filter.isTextValid(kHasAat1));

    EXPECT_TRUE(kZat2Filter.isTextValid(kHasZat2));
    EXPECT_FALSE(kZat2Filter.isTextValid(kHasAat1));
    EXPECT_FALSE(kZat2Filter.isTextValid(kHasAat3));

    EXPECT_FALSE(kAat3Filter.isTextValid(kHasAat1));
    EXPECT_TRUE(kAat3Filter.isTextValid(kHasAat3));
    EXPECT_TRUE(kAat3Filter.isTextValid(kHasZat2)); // Also has a at 3
}
}
