module;
#include <span>
#include <vector>
#include <memory>
#include <string>

export module search.IncrementalSearch;
import search.MultiFilter;
import search.IFilter;

namespace wordlr::search
{
export class IncrementalSearch 
{
public:
    IncrementalSearch(std::span<const std::string> dictionary) : dictionary_{dictionary}, searchPool_{dictionary.begin(), dictionary.end()}
    {
    }

    void addFilter(std::unique_ptr<IFilter> filter)
    {
        searchFilter_.insert(std::move(filter));
    }

    void reset()
    {
        searchFilter_.clear();
        searchPool_ = std::vector<std::string>{dictionary_.begin(), dictionary_.end()};
    }

    /**
     * This narrows the searchPool. Whenever addFilter is called
     * and more searches are performed.
     */
    std::vector<std::string> search()
    {
        std::vector<std::string> matchResults{};
        for(const std::string& word : searchPool_)
        {
            if(searchFilter_.isTextValid(word))
            {
                matchResults.push_back(word);
            }
        }
        searchPool_ = matchResults;
        return std::move(matchResults);
    }
private:
    MultiFilter searchFilter_{};
    std::vector<std::string> searchPool_;
    std::span<const std::string> dictionary_{};
};
}
