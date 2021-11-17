#include "GameObjectUtil.hpp"

void game::GameObjectUtil::LinkComponent(std::shared_ptr<spic::GameObject> gameObject, std::shared_ptr<spic::Component> component)
{
    gameObject->AddComponent(component);
    component->GameObject(gameObject);
}
