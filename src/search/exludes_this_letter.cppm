module;
#include <string>

export module search.ExcludesThisLetter;
import search.IFilter;

namespace wordlr::search
{
export class ExcludesThisLetter : public IFilter
{
public:
    ExcludesThisLetter(char excludedLetter) : kExcludedLetter{excludedLetter}
    {
    }

    bool isTextValid(const std::string& text) const override
    {
        return !text.contains(kExcludedLetter);
    }
private:
    const char kExcludedLetter;
};
}
