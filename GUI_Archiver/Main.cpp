#pragma warning(disable : 4996)

#include "LoadingScreen.h"
#include "Menu Screen.h"

int main()
{
    sf::RenderWindow window;
    LoadingScreen(window);
    MenuScreen(window);
    return 0;
}