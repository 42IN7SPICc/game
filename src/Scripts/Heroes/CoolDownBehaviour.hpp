#ifndef SPIC_GAME_COOLDOWNBEHAVIOUR_HPP
#define SPIC_GAME_COOLDOWNBEHAVIOUR_HPP

#include <BehaviourScript.hpp>

namespace game
{
    class CoolDownBehaviour : public spic::BehaviourScript
    {
        private:
            double _coolDown;
            int _minCoolDown;
            bool _cooledDown;

        public:
            explicit CoolDownBehaviour(int coolDown);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            [[nodiscard]] bool CooledDown() const;

            void CooledDown(bool cooledDown);

            [[nodiscard]] double CoolDown() const;

            void CooledDown(double coolDown);
    };
}


#endif
