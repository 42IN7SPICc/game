#ifndef SPIC_GAME_BULLETFACTORY_HPP
#define SPIC_GAME_BULLETFACTORY_HPP

#include "GameObject.hpp"

#include "../Enums/BulletType.hpp"

#include <memory>
#include <string>

namespace game
{
    /**
     * @brief Factory for bullets.
     */
    class BulletFactory
    {
        public:
            /**
             * @brief Create a bullet with given settings.
             * @param bulletType The type of the bullet.
             * @param position The position of the bullet.
             * @param targetTag The tag of game objects the bullet will target.
             * @param direction The direction the bullet will shoot in.
             * @param range The maximum range the bullet can travel.
             * @param damage The damage the bullet does on impact.
             * @param bombRadius The radius of the bomb on impact (only bulletType = bomb).
             * @return
             */
            static std::shared_ptr<spic::GameObject> CreateBullet(BulletType bulletType, const spic::Point& position, const std::string& targetTag, const spic::Point& direction, int range, int damage, double bombRadius = 0);

        private:
            /**
             * Get the path to the sprite for a given bullet.
             * @param bulletType The type of bullet.
             * @return The path to the sprite.
             */
            static std::string GetBulletSprite(BulletType bulletType);
    };
}

#endif //SPIC_GAME_BULLETFACTORY_HPP
