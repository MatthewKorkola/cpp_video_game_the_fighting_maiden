//
//// Created by Yakup Tezcan on 2022-11-28.
//
//#include "TitleScreenState.h"
//#include "TitleScreenTestCase.h"
//int main(){
//      // Creates a new window, then pass it to drawScreen.
//    TitleScreenState *state=new TitleScreenState();
//
//    sf::RenderWindow *window;
//    sf::VideoMode videoMode;
//    videoMode.height = 720;
//    videoMode.width = 1280;
//
//    window = new  sf::RenderWindow(videoMode, "The Fighting Maiden");
//    window->setFramerateLimit(60);
//    window->setVerticalSyncEnabled(false);
//    sf::Clock clock;
//    state->drawScreen(window, clock);
//    window->close();
// //After passing  window to drawScreen, if testCase returns the true, then it means the game over screen works.
//
//    printf("Test passed");
//
//    exit(0);
//}