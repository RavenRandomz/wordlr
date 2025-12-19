module;
#include <memory>
#include <string>
#include <unordered_set>

export module search.MultiFilter;
import search.IFilter;

namespace wordlr::search
{
export class MultiFilter: public std::unordered_set<std::unique_ptr<IFilter>>, public IFilter
{
public:
    using std::unordered_set<std::unique_ptr<IFilter>>::unordered_set;
    bool isTextValid(const std::string& text) const override
    {
        for(const auto& filter : *this)
        {
            if(!filter->isTextValid(text))
            {
                return false;
            }
        };
        return true;
    }
private:
};
}
