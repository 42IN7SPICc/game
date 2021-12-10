#include "MapNode.hpp"

using namespace game;

bool MapNode::operator==(const MapNode& other) const {
    return ToString() == other.ToString();
}

std::string MapNode::ToString() const
{
    return std::to_string(X) + "-" + std::to_string(Y);
}
