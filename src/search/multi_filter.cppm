module;
#include <string>
#include <set>

export module search.MultiFilter;
import search.IFilter;

namespace wordlr::search
{
export class MultiFilter: public std::set<IFilter>, public IFilter
{
public:
    bool isTextValid(const std::string& text) const override
    {
        for(const IFilter& filter : *this)
        {
            if(!filter.isTextValid(text))
            {
                return false;
            }
        };
        return true;
    }
private:
};
}
