module;

#include "default_dictionary.h"
#include <boost/algorithm/string.hpp>
#include <cassert>

export module game.WordleDictionary;
import game.Dictionary;

namespace wordlr::game
{
Dictionary makeWordleDictionary()
{
    Dictionary wordleDictionary{};
    boost::algorithm::split(wordleDictionary, getDefaultDictionaryString(), boost::is_any_of("\n"));
    // HACK: For some reason boost is adding an empty word despite the text file not having an empty line
    wordleDictionary.pop_back();

    for(auto& word : wordleDictionary)
    {
        assert(!word.empty()&& "Every word needs to be a word!");
    }
    return wordleDictionary;
}

export const Dictionary kWordleDictionary{makeWordleDictionary()};

Dictionary makeAnswerDictionary()
{
    Dictionary answerDictionary{};
    boost::algorithm::split(answerDictionary, getDefaultDictionaryString(), boost::is_any_of("\n"));
    // HACK: For some reason boost is adding an empty word despite the text file not having an empty line
    answerDictionary.pop_back();

    for(auto& word : answerDictionary)
    {
        assert(!word.empty()&& "Every word needs to be a word!");
    }
    return answerDictionary;
}

export const Dictionary kAnswerDictionary{makeAnswerDictionary()};


}
