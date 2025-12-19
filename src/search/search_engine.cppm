module;
#include <span>
#include <vector>
#include <memory>
#include <string>

export module search.SearchEngine;
import search.MultiFilter;
import search.IFilter;

namespace wordlr::search
{
export class SearchEngine
{
public:
    SearchEngine(std::span<const std::string> dictionary) : dictionary_{dictionary}
    {
    }

    void addFilter(std::unique_ptr<IFilter> filter)
    {
        searchFilter_.insert(std::move(filter));
    }

    std::vector<std::string> search()
    {
        std::vector<std::string> matchResults{};
        for(const std::string& word : dictionary_)
        {
            if(searchFilter_.isTextValid(word))
            {
                matchResults.push_back(word);
            }
        }
        return std::move(matchResults);
    }
private:
    MultiFilter searchFilter_{};
    std::span<const std::string> dictionary_{};
};
}
