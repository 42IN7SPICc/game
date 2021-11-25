#ifndef SPIC_GAME_FILEMANAGER_HPP
#define SPIC_GAME_FILEMANAGER_HPP

#include "../Structs/FolderFile.hpp"

#include <string>
#include <vector>

namespace game
{
    class FileManager
    {
        public:
            static std::string Load(const std::string& file);

            static void Save(const std::string& file, const std::string& contents);

            static std::vector<FolderFile> GetFolderFiles(const std::string& path, const std::string& extension);
    };
}

#endif //SPIC_GAME_FILEMANAGER_HPP
