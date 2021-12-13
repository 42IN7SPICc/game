#ifndef SPIC_GAME_STATSSCENE_HPP
#define SPIC_GAME_STATSSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    /**
     * @brief A scene that contains a stats of the player
     */
    class StatsScene : public MenuScene
    {
        public:
            /**
             * @brief Constructs a new instance of a StatsScene.
             * @param audio The background audio.
             */
            explicit StatsScene(const std::shared_ptr<spic::GameObject>& audio);
    };
}

#endif //SPIC_GAME_STATSSCENE_HPP
