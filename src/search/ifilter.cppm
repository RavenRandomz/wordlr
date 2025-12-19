module;

#include <string>

export module search.IFilter;


namespace wordlr::search
{
export class IFilter
{
public:
    virtual bool textValid(const std::string& text) const = 0;
    ~IFilter()  = default;
};
}
