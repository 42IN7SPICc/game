#ifndef SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include <string>
#include <map>
#include "../../Structs/MapNode.hpp"


namespace game
{
    class EnemyMovementBehaviour : public spic::BehaviourScript
    {
        private:
            std::string _fromNode;
            std::string _currentNode;
            std::string _toNode;
            std::map<std::string, game::MapNode> _graph;

        public:
            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
