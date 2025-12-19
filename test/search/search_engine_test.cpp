#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>

import search.HasLetter;
import search.MultiFilter;
import search.LetterHere;
import search.SearchEngine;

namespace wordlr::search::SearchEngineTest
{
TEST(SearchEngine, basicSearch)
{
    const std::vector<std::string> kBasicDictionary 
    {
        "apple",
        "zebra",
        "dog"
    };

    SearchEngine engine{kBasicDictionary};

    auto kAFilter{std::make_unique<HasLetter>('a')};
    engine.addFilter(std::move(kAFilter));

    const std::vector<std::string> kExpected 
    {
        "apple",
        "zebra"
    };

    const std::vector<std::string> kAOutput{engine.search()};

    EXPECT_EQ(kAOutput, kExpected);

    auto kZFilter{std::make_unique<HasLetter>('z')};
    engine.addFilter(std::move(kZFilter));

    const std::vector<std::string> kExpectedZ
    {
        "zebra"
    };
    const std::vector<std::string> kZOutput{engine.search()};

    EXPECT_EQ(kZOutput, kExpectedZ);
}
}
