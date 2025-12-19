module;
#include <string>

export module search.LetterNotHere;
import search.LetterHere;
import search.IFilter;

namespace wordlr::search
{
export class LetterNotHere: public IFilter
{
public:
    /**
     * WARNING: If position exceeds bounds, there will be NO error
     * it will simply return true.
     *
     * It is hard for a filter to know the specific length of a word.
     *
     * This is orignating from a wordlr library but eh
     */
    LetterNotHere(char letter, int index) : letterLocator_{letter, index}
    {
    }

    bool isTextValid(const std::string& text) const override
    {
        return !letterLocator_.isTextValid(text);
    }
private:
    LetterHere letterLocator_;
};
}
