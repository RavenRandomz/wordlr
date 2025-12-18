#include <string>
#include <gtest/gtest.h>

import game.FiveWord;

namespace wordlr::game::fiveWordTest
{
TEST(FiveWord, properlyFormatted_bool)
{
    std::string invalid{"True"};
    std::string valid{"true"};
    EXPECT_FALSE(FiveWord::properlyFormatted(invalid));
    EXPECT_TRUE(FiveWord::properlyFormatted(valid));
}

TEST(FiveWord, isRealWordleWord)
{
    std::string valid{"crane"};
    std::string valid2{"bites"};
    std::string valid3{"bytes"};
    std::string invalid{"crrrr"};
    std::string invalid2{"byyts"};

    EXPECT_TRUE(FiveWord::isRealWordleWord(valid));
    EXPECT_TRUE(FiveWord::isRealWordleWord(valid2));
    EXPECT_TRUE(FiveWord::isRealWordleWord(valid3));
    EXPECT_FALSE(FiveWord::isRealWordleWord(invalid));
    EXPECT_FALSE(FiveWord::isRealWordleWord(invalid2));
}
}
