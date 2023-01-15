////
//// Created by Xavier HIll Roy on 2022-10-18.
////
//
//#include "Game.h"
//
//int main() {
//    // setting window size
//    // Video mode just object that keep tracks of 2 int
//
//    // init game
//    Game game;
//
////    window.setFramerateLimit(60); // limits frame rate to 60
//
//    sf::RectangleShape rect; // basic rectangel
//    sf::Vector2f rectanglePosition(600,350); // vector for starting position of rectangle
//
//    rect.setPosition(rectanglePosition); // set position of rectangle to starting location
//    rect.setSize(sf::Vector2f(100,100));
//    // add this each frame to position of rectangle
//    float yVelocity = 3;// walking speed
//    float xVelocity = 3;
//
//
//    while(game.getWindowIsOpen()){ // MAIN EVENT LOOP WHAT WE WANT TO DO EACH FRAME
//        // Want to check for e each frame
//        sf::Event e;
//
//        // Event processing
//        while (window.pollEvent(e)){ // returns if you can get an e, and places e data into var e
//            // while we are getting an e from window save it into e var
//            switch (e.type) { // checks e tyoe
//
//                // if someone close window it closes
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//
//            }
//
//
//
//            if (sf::Event::KeyPressed){
//
//            };
//
//        }
//        // physics
//
//
//        if (rectanglePosition.x < 0|| rectanglePosition.x >1280 - 100 ) xVelocity*=-1;
//        if(rectanglePosition.y<0||rectanglePosition.y > 720 - 100) yVelocity*=-1;
//
//        rectanglePosition.x += xVelocity;
////        rectanglePosition.y += yVelocity;
//        rect.setPosition(rectanglePosition); // set position of rectangle to starting location
//
//
//        // render
//        window.clear();// clear old frame
//
//        window.draw(rect);
//
//        window.display(); // tell it its done drawing
//
//
//    }// e loop end ( END OF APP )
//
//}