module;

#include <string>

export module search.IFilter;


namespace wordlr::search
{
export class IFilter
{
public:
    /**
     * Allow copy use in sets and whatnot without move semantic shenanigans.
     *
     * This makes comparison a lot easier as well.
     *
     * In terms of a default, the null filter should do nothing, as in not filter
     * which means not excluding stuff.
     */
    virtual bool isTextValid(const std::string& text) const {return true;};
    virtual ~IFilter()  = default;
};
}
