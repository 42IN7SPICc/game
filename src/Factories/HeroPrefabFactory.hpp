#ifndef SPIC_GAME_HEROPREFABFACTORY_HPP
#define SPIC_GAME_HEROPREFABFACTORY_HPP

#include "GameObject.hpp"

namespace game {
    class HeroPrefabFactory {
    public:
    static std::shared_ptr<spic::GameObject> CreateHero(std::string name);
    };
}


#endif //SPIC_GAME_HEROPREFABFACTORY_HPP
