#ifndef SPIC_GAME_MOUSECOLLIDERSCRIPT_HPP
#define SPIC_GAME_MOUSECOLLIDERSCRIPT_HPP

#include <BehaviourScript.hpp>
#include <CircleCollider.hpp>

namespace game
{
    /**
     * @brief Adds a collider and rigid body to parent object that then transforms to the mouse position
     */
    class MouseColliderScript : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<spic::CircleCollider> _mouseCollider;

        public:
            /**
             * @brief Triggers when the scripts starts for the first time.
             */
            void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;

            /**
             * @brief Triggers when the script collides with a collider.
             * @param collider The collider that collided.
             */
            void OnTriggerEnter2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers when the script stopped colliding with a collider.
             * @param collider The collider that stop colliding.
             */
            void OnTriggerExit2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers while an collider is colliding with a collider.
             * @param collider The collider is colliding.
             */
            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_MOUSECOLLIDERSCRIPT_HPP
