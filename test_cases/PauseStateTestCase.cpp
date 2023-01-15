//
////Created by Yakup Tezcan on 2022-11-27.
//
//#include "PauseStateTestCase.h"
//#include "PauseState.h"
//int main(){
//    PauseState state;
//    // Creates a new window, then pass it to drawScreen.
//    sf::RenderWindow *window;
//    sf::VideoMode videoMode;
//    videoMode.height = 720;
//    // Setting width
//    videoMode.width = 1280;
//    window = new  sf::RenderWindow(videoMode, "The Fighting Maiden");
//    // Make max frame rate 60
//    window->setFramerateLimit(60);
//    // Turns off vsync
//    window->setVerticalSyncEnabled(false);
//    state.drawScreen(window);
//    //   After passing  window to drawScreen, if testCase returns the true, then it means the game pause screen works.
//    if(state.testCase() == true){
//        printf("Test passed");
//    }
//}