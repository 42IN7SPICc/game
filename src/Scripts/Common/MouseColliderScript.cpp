#include <Debug.hpp>
#include <Input.hpp>
#include <RigidBody.hpp>
#include "MouseColliderScript.hpp"
#include "GameObject.hpp"
#include "Utils/GameObjectUtil.hpp"

void game::MouseColliderScript::OnStart()
{
    spic::Debug::Log("Started mouse collider");
    auto parent = GameObject().lock();

    _mouseCollider = std::make_shared<spic::CircleCollider>(10);
    spic::GameObjectUtil::LinkComponent(parent, _mouseCollider);

    auto rigidBody = std::make_shared<spic::RigidBody>(1, 0, spic::BodyType::staticBody);
    spic::GameObjectUtil::LinkComponent(parent, rigidBody);
}

void game::MouseColliderScript::OnUpdate()
{
    auto parent = GameObject().lock();
    auto mousePosition = spic::Input::MousePosition();
    parent->Transform().position.x = mousePosition.x;
    parent->Transform().position.y = mousePosition.y;
}

void game::MouseColliderScript::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::MouseColliderScript::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::MouseColliderScript::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}
