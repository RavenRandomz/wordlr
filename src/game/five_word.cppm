module;
#include <algorithm>
#include <string>
#include <boost/algorithm/string.hpp>
#include <cassert>

export module game.FiveWord;

import game.WordleDictionary;

namespace wordlr::game
{
/**
 * This contains utilities for the 5 word, the basic unit of information
 * within Wordle. 5 words can also be compared with other 5 words. This also
 * has utilities to determine if a string is a valid word or valid 5 word.
 */
export class FiveWord
{
public:
    FiveWord(std::string text) : text_{text}
    {
        assert(properlyFormatted(text) && "All of input must be lower case");
        assert(isRealWordleWord(text) && "Word must be in wordle dictionary");
    }

    static bool properlyFormatted(const std::string& string)
    {
        const std::string kLowerCase{boost::algorithm::to_lower_copy(string)};
        return kLowerCase == string;
    }

    static bool isRealWordleWord(const std::string& text)
    {
        //https://www.geeksforgeeks.org/cpp/check-if-vector-contains-given-element-in-cpp/#using-stdfind
        auto iterator{std::find(kWordleDictionary.begin(),kWordleDictionary.end(), text.c_str())};
        return iterator != kWordleDictionary.end();
    }

private:
    const std::string text_;
};
}
