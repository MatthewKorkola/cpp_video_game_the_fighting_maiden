// NOTE THIS CLASS IS NOT BEING USED!!!!
/**
 * @brief Class that animates players walking
 *
 * This class animates the walking movement of the player.
 *
 * @author Xavier Hill Roy
 */
#include <SFML/Graphics.hpp>

#ifndef THEFIGHTINGMAIDEN_ANIMATION_H
#define THEFIGHTINGMAIDEN_ANIMATION_H


class Animation {

// Variables
private: // private variables

    sf::Vector2u imageCount; // stores num rows and col in image
    sf::Vector2u currentImage; // stores the current image to draw

    float totalTime; //time since last changed image
    float switchTime; // amount of time till switch till next image

public: // public variables
    sf::IntRect textureRect; // rect to use to display animation

// Methods
public:
    /**
     *@brief Constructor for animation class
     *
     * Sets all variables needed for animation (Number of images in sprite sheet, the switch time,
     * the total time elapsed of current frame, and the current image).
     * It also calculates the total width and height of each image based on the number of images in row and column of sprite sheet.
     * The width and height of each image are stored in a INT rect.
     *
     * @param texture pointer to sf::Texture of the image sheet
     * @param imageCount Structure of unsigned integer that store the x (num frames in row) and y (num frames in column) of the image sheet
     * @param switchTime float that stores the amount of time before switching to the next frame in the image sheet
     */
    Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);

    /**
     * @brief Destructor for animation class
     *
     * Destroys Animation object
     */
    ~Animation();

    /**
     * @brief This method iterates through the sprite sheet simulating a walking movement for the character
     *
     * The method iterates through a selected row of the sprite sheet, moving to the next frame in the row when the total time is more then the switch time.
     * A delta time gets
     * @param row
     * @param deltaTime
     */
    void update(int row,float deltaTime); // delta time is time between previous frame and current frame
};


#endif //THEFIGHTINGMAIDEN_ANIMATION_H
