export module player.IPlayer;

import game.FiveWord;
import game.Feedback;

namespace wordlr::player
{
/**
 *
 * Generic interface fo all players that will slot into the game
 */
export class IPlayer
{
public:
    virtual game::FiveWord getGuess() = 0;
    virtual void setRoundFeetback(const game::FeedbackList& feedback) = 0;

    virtual ~IPlayer() = default;
};
}
