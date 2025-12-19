module;
#include <string>

export module search.LetterHere;
import search.IFilter;

namespace wordlr::search
{
export class LetterHere: public IFilter
{
public:
    /**
     * WARNING: If position exceeds bounds, there will be NO error
     * it will simply return false.
     *
     * It is hard for a filter to know the specific length of a word.
     *
     * This is orignating from a wordlr library but eh
     */
    LetterHere(char letter, int position) : kLetter_{letter}, kPosition_{position}
    {
    }

    bool isTextValid(const std::string& text) const override
    {
        const int kMaxIndex{static_cast<int>(text.length() - 1)};
        if(kMaxIndex < kPosition_) 
        {
            return false;
        }
        else
        {
            return text[kPosition_] == kLetter_;
        }
    }
private:
    const char kLetter_;
    const int kPosition_;
};
}
