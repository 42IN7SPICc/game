#ifndef SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include <string>
#include <map>
#include <queue>
#include "../../Structs/MapNode.hpp"


namespace game
{
    class EnemyMovementBehaviour : public spic::BehaviourScript
    {
        private:
            std::map<std::string, game::MapNode> _graph;
            std::queue<std::string> _path;

        public:
            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
