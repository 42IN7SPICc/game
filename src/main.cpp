#include "Api.hpp"

#include "Scenes/LoadingScene.hpp"
#include "Constants.hpp"

#include <exception>


#ifdef __linux__

#include <iostream>

#elif _WIN32

#include <windows.h>

#endif

using namespace game;
using namespace spic;

const std::string ErrorMessage = "An unknown error occurred while playing the game, please try again. If this keep happening contact the developers.";

void ShowMessage(const std::string& title, std::string message)
{
    if (message.empty()) message = ErrorMessage;

#ifdef __linux__
        std::cout << title << ": " << message;
#elif _WIN32
    MessageBox(nullptr, message.c_str(), title.c_str(), MB_ICONERROR | MB_OK);
#endif
}

int main(int argc, char* args[])
{
    try
    {
        Engine& engine = Engine::Instance();

        EngineConfig config{{"Avans Wars", ScreenWidth, ScreenHeight, true}};
#if !NDEBUG
        config.window.fullscreen = false;
#endif
        engine.Init(config);

        auto scene = std::make_shared<LoadingScene>();
        engine.PushScene(scene);

        engine.Start();
    }
    catch (const std::exception& e)
    {
        ShowMessage("Game Crashed", e.what());
    }
    catch (...)
    {
        ShowMessage("Game Crashed", ErrorMessage);
    }
}
