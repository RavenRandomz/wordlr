#include <boost/algorithm/algorithm.hpp>
#include "default_dictionary.h"

namespace wordlr::game
{

    const char* getDefaultDictionaryString()
    {
        /**
        * Every possible wordle word
        */
        static const char kDefaultDictionaryString[] = 
        {
            #embed "../../res/valid-wordle-words.txt"
            ,'\0'
        };
        return kDefaultDictionaryString;
    }

    const char* getAnswerDictionaryString()
    {
        /**
        * Every possible wordle word
        */
        static const char kAnswerDictionaryString[] = 
        {
            #embed "../../res/valid-wordle-words.txt"
            ,'\0'
        };
        return kAnswerDictionaryString;
    }
    
}
