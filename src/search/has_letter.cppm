module;
#include <string>

export module search.HasLetter;

import search.IFilter;

namespace wordlr::search
{
export class HasLetter : public IFilter
{
public:
    HasLetter(char containedLetter) : kContainedLetter{containedLetter}
    {
    }

    bool isTextValid(const std::string& text) const override
    {
        return text.contains(kContainedLetter);
    }
private:
    const char kContainedLetter;
};
}
