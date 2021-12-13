#ifndef SPIC_GAME_MAINSCENE_HPP
#define SPIC_GAME_MAINSCENE_HPP

#include "MenuScene.hpp"

#include "Text.hpp"

namespace game
{
    /**
     * @brief A scene that show the title of the game and some information.
     */
    class MainScene : public MenuScene
    {
        private:
            std::shared_ptr<spic::Text> _heroNameText;
            std::shared_ptr<spic::Text> _heroAbilityText;

        public:
            /**
             * @brief Constructs a new instance of a MainScene.
             * @param audio the audio source to use as background music
             */
            explicit MainScene(const std::shared_ptr<spic::GameObject>& audio);

        private:
            void HeroSwapper(int amount);

            void CreateHero();
    };
}

#endif //SPIC_GAME_MAINSCENE_HPP
