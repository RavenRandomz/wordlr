module;

#include "default_dictionary.h"
#include <boost/algorithm/string.hpp>

export module game.WordleDictionary;
import game.Dictionary;

namespace wordlr::game
{
Dictionary makeWordleDictionary()
{
    Dictionary wordleDictionary{};
    boost::algorithm::split(wordleDictionary, getDefaultDictionaryString(), boost::is_any_of("\n"));
    return wordleDictionary;
}

export const Dictionary kWordleDictionary{makeWordleDictionary()};
}
