#ifndef SPIC_GAME_BULLETFACTORY_HPP
#define SPIC_GAME_BULLETFACTORY_HPP

#include "GameObject.hpp"

#include "../Enums/BulletType.hpp"

#include <memory>
#include <string>

namespace game
{
    class BulletFactory
    {
        public:
            static std::shared_ptr<spic::GameObject> CreateBullet(BulletType bulletType, const spic::Point& position, const std::string& targetTag, const spic::Point& direction, double duration, int damage, double bombRadius = 0);

        private:
            static std::string GetBulletSprite(BulletType bulletType);
    };
}

#endif //SPIC_GAME_BULLETFACTORY_HPP
