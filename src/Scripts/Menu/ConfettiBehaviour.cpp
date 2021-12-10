#include "ConfettiBehaviour.hpp"

#include "GameObject.hpp"
#include "../../Constants.hpp"
#include "../../Utils/RandomUtil.hpp"

using namespace game;

void ConfettiBehaviour::OnStart()
{
}

void ConfettiBehaviour::OnUpdate()
{
}

void ConfettiBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    if (!collider.GameObject().expired())
    {
        auto parent = collider.GameObject().lock();
        if (parent->Tag() == "confetti")
        {
            parent->Transform().position.y = -25;
            parent->Transform().position.x = game::RandomUtil::Next(ConfettiXRangeMin, ConfettiXRangeMax);
        }
    }
}

void ConfettiBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void ConfettiBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}
