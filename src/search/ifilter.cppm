module;

#include <string>

export module search.IFilter;


namespace wordlr::search
{
export class IFilter
{
public:
    virtual bool isTextValid(const std::string& text) const = 0;
    virtual ~IFilter()  = default;
};
}
