#ifndef SPIC_GAME_LEVEL_HPP
#define SPIC_GAME_LEVEL_HPP

#include <string>

namespace game
{
    struct Level
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Title, Description, UnlockThreshold);
        }

        std::string Title;
        std::string Description;
        int UnlockThreshold;
        std::string File{};
    };
}

#endif
