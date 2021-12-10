#include "EnemyValue.hpp"

game::EnemyValue::EnemyValue(int value) : _value(value)
{

}

void game::EnemyValue::OnStart()
{
    //
}

void game::EnemyValue::OnUpdate()
{
    //
}

void game::EnemyValue::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::EnemyValue::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::EnemyValue::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

const int& game::EnemyValue::Value() const
{
    return _value;
}
