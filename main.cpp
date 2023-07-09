#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

int main()
{ // smaple for aayush
    /*
    int start_yellow[][4] ={{},..};
    */

    int yellow_piece[][4] = {{1, 0, 358, 298}, {2, 1, 402, 298}, {3, 2, 446, 298}, {4, 3, 490, 298}, {5, 4, 534, 298}, {6, 5, 578, 254}, {7, 6, 578, 210}, {8, 7, 578, 166}, {9, 8, 578, 122}, {10, 9, 578, 78}, {11, 10, 578, 34}, {12, 11, 622, 34}, {13, 12, 666, 34}, {14, 13, 666, 78}, {15, 14, 666, 122}, {16, 15, 666, 166}, {17, 16, 666, 210}, {18, 17, 666, 254}, {19, 18, 710, 298}, {20, 19, 754, 298}, {21, 20, 798, 298}, {22, 21, 842, 298}, {23, 22, 886, 298}, {24, 23, 930, 298}, {25, 24, 930, 342}, {26, 25, 930, 386}, {27, 26, 886, 386}, {28, 27, 842, 386}, {29, 28, 798, 386}, {30, 29, 754, 386}, {31, 30, 710, 386}, {32, 31, 666, 430}, {33, 32, 666, 474}, {34, 33, 666, 518}, {35, 34, 666, 562}, {36, 35, 666, 606}, {37, 36, 666, 650}, {38, 37, 622, 650}, {39, 38, 578, 650}, {40, 39, 578, 606}, {41, 40, 578, 562}, {42, 41, 578, 518}, {43, 42, 578, 474}, {44, 43, 578, 430}, {45, 44, 534, 386}, {46, 45, 490, 386}, {47, 46, 446, 386}, {48, 47, 402, 386}, {49, 48, 358, 386}, {50, 49, 314, 386}, {51, 50, 314, 342}, {52, 51, 358, 342}, {53, 52, 402, 342}, {54, 53, 446, 342}, {55, 54, 490, 342}, {56, 55, 534, 342}, {57, 56, 622, 342}};
    // co-ordinate of green piece similar structure as that of yellow.
    int green_piece[][4] = {{14, 0, 666, 78}, {15, 1, 666, 122}, {16, 2, 666, 166}, {17, 3, 666, 210}, {18, 4, 666, 254}, {19, 5, 710, 298}, {20, 6, 754, 298}, {21, 7, 798, 298}, {22, 8, 842, 298}, {23, 9, 886, 298}, {24, 10, 930, 298}, {25, 11, 930, 342}, {26, 12, 930, 386}, {27, 13, 886, 386}, {28, 14, 842, 386}, {29, 15, 798, 386}, {30, 16, 754, 386}, {31, 17, 710, 386}, {32, 18, 666, 430}, {33, 19, 666, 474}, {34, 20, 666, 518}, {35, 21, 666, 562}, {36, 22, 666, 606}, {37, 23, 666, 650}, {38, 24, 622, 650}, {39, 25, 578, 650}, {40, 26, 578, 606}, {41, 27, 578, 562}, {42, 28, 578, 518}, {43, 29, 578, 474}, {44, 30, 578, 430}, {45, 31, 534, 386}, {46, 32, 490, 386}, {47, 33, 446, 386}, {48, 34, 402, 386}, {49, 35, 358, 386}, {50, 36, 314, 386}, {51, 37, 314, 342}, {0, 38, 314, 298}, {1, 39, 358, 298}, {2, 40, 402, 298}, {3, 41, 446, 298}, {4, 42, 490, 298}, {5, 43, 534, 298}, {6, 44, 578, 254}, {7, 45, 578, 210}, {8, 46, 578, 166}, {9, 47, 578, 122}, {10, 48, 578, 78}, {11, 49, 578, 34}, {12, 50, 622, 34}, {58, 51, 622, 78}, {59, 52, 622, 122}, {60, 53, 622, 166}, {61, 54, 622, 210}, {62, 55, 622, 254}, {57, 56, 622, 342}};
    // red piece co-ordinates
    int red_piece[][4] = {{27, 0, 886, 386}, {28, 1, 842, 386}, {29, 2, 798, 386}, {30, 3, 754, 386}, {31, 4, 710, 386}, {32, 5, 666, 430}, {33, 6, 666, 474}, {34, 7, 666, 518}, {35, 8, 666, 562}, {36, 9, 666, 606}, {37, 10, 666, 650}, {38, 11, 622, 650}, {39, 12, 578, 650}, {40, 13, 578, 606}, {41, 14, 578, 562}, {42, 15, 578, 518}, {43, 16, 578, 474}, {44, 17, 578, 430}, {45, 18, 534, 386}, {46, 19, 490, 386}, {47, 20, 446, 386}, {48, 21, 402, 386}, {49, 22, 358, 386}, {50, 23, 314, 386}, {51, 24, 314, 342}, {0, 25, 314, 298}, {1, 26, 358, 298}, {2, 27, 402, 298}, {3, 28, 446, 298}, {4, 29, 490, 298}, {5, 30, 534, 298}, {6, 31, 578, 254}, {7, 32, 578, 210}, {8, 33, 578, 166}, {9, 34, 578, 122}, {10, 35, 578, 78}, {11, 36, 578, 34}, {12, 37, 622, 34}, {13, 38, 666, 34}, {14, 39, 666, 78}, {15, 40, 666, 122}, {16, 41, 666, 166}, {17, 42, 666, 210}, {18, 43, 666, 254}, {19, 44, 710, 298}, {20, 45, 754, 298}, {21, 46, 798, 298}, {22, 47, 842, 298}, {23, 48, 886, 298}, {24, 49, 930, 298}, {25, 50, 930, 342}, {63, 51, 886, 342}, {64, 52, 842, 342}, {65, 53, 798, 342}, {66, 54, 754, 342}, {67, 55, 710, 342}, {57, 56, 622, 342}};
    // blue piece coordinates
    int blue_piece[][4] = {{40, 0, 578, 606}, {41, 1, 578, 562}, {42, 2, 578, 518}, {43, 3, 578, 474}, {44, 4, 578, 430}, {45, 5, 534, 386}, {46, 6, 490, 386}, {47, 7, 446, 386}, {48, 8, 402, 386}, {49, 9, 358, 386}, {50, 10, 314, 386}, {51, 11, 314, 342}, {0, 12, 314, 298}, {1, 13, 358, 298}, {2, 14, 402, 298}, {3, 15, 446, 298}, {4, 16, 490, 298}, {5, 17, 534, 298}, {6, 18, 578, 254}, {7, 19, 578, 210}, {8, 20, 578, 166}, {9, 21, 578, 122}, {10, 22, 578, 78}, {11, 23, 578, 34}, {12, 24, 622, 34}, {13, 25, 666, 34}, {14, 26, 666, 78}, {15, 27, 666, 122}, {16, 28, 666, 166}, {17, 29, 666, 210}, {18, 30, 666, 254}, {19, 31, 710, 298}, {20, 32, 754, 298}, {21, 33, 798, 298}, {22, 34, 842, 298}, {23, 35, 886, 298}, {24, 36, 930, 298}, {25, 37, 930, 342}, {26, 38, 930, 386}, {27, 39, 886, 386}, {28, 40, 842, 386}, {29, 41, 798, 386}, {30, 42, 754, 386}, {31, 43, 710, 386}, {32, 44, 666, 430}, {33, 45, 666, 474}, {34, 46, 666, 518}, {35, 47, 666, 562}, {36, 48, 666, 606}, {37, 49, 666, 650}, {38, 50, 622, 650}, {68, 51, 622, 606}, {69, 52, 622, 562}, {70, 53, 622, 518}, {71, 54, 622, 474}, {72, 55, 622, 430}, {57, 56, 622, 342}};
    // safe position of ludo where first four are start position of YGRB and then star after 9 squares of respective starting position of
    // same order of colour i.e YGRB.
    int safe_position[][4] = {{1, 0, 358, 298}, {14, 0, 666, 78}, {27, 0, 886, 386}, {40, 0, 578, 606}, {9, 8, 578, 122}, {22, 8, 842, 298}, {35, 8, 666, 562}, {48, 8, 402, 386}};

    // Window_screen
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Play Ludo", sf::Style::Titlebar | sf::Style::Close);

    // background
    sf::Texture backgroundImage;
    if (!backgroundImage.loadFromFile(".\\assets\\ludo_mini.png"))
    {
        return -1;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundImage);

    // blue_piece
    sf::Texture Bluepiece;
    if (!Bluepiece.loadFromFile(".\\assets\\blue_disc.png"))
    {
        return -1;
    }
    sf::Sprite bpiece;
    bpiece.setTexture(Bluepiece);

    // red_piece
    sf::Texture Redpiece;
    if (!Redpiece.loadFromFile(".\\assets\\red_disc.png"))
    {
        return -1;
    }
    sf::Sprite rpiece;
    rpiece.setTexture(Redpiece);

    // green_piece
    sf::Texture Greenpiece;
    if (!Greenpiece.loadFromFile(".\\assets\\green_disc.png"))
    {
        return -1;
    }
    sf::Sprite gpiece;
    gpiece.setTexture(Greenpiece);

    // yellow_piece
    sf::Texture Yellowpiece;
    if (!Yellowpiece.loadFromFile(".\\assets\\yellow_disc.png"))
    {
        return -1;
    }
    sf::Sprite ypiece;
    ypiece.setTexture(Yellowpiece);

    // class for pieces

    class coordinate_system
    {
    public:
        int local;
        int global;
        int x_cord;
        int y_cord;
    };

    class pieces
    {
    public:
        std::string color;
        int id;
        int local;
        int global;
        pieces(std::string colour, int b, int c, int d) : color(colour), id(b), local(c), global(d) {}
    };

    pieces r1("red", 1, 0, 27);
    pieces b1("blue", 1, 0, 40);
    pieces g1("green", 1, 0, 14);
    pieces y1("yellow", 1, 0, 1);
    r1.local = 12;
    int dice;
    int mouse_tracker;

    int i = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!((sf::Mouse::isButtonPressed(sf::Mouse::Left))))
        {
            mouse_tracker = 1;
        }

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        if (mouse_tracker == 1 && localPosition.x < 1201 && localPosition.x > 1001 && localPosition.y < 673 && localPosition.y > 443 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {

            srand(time(0));
            dice = (rand() % 6) + 1;
            r1.local = r1.local + dice;
            if (((sf::Mouse::isButtonPressed(sf::Mouse::Left))))
            {
                mouse_tracker = 0;
            }
            else
            {
                mouse_tracker = 1;
            }
            std::cout << dice << std::endl;
        }

        window.clear();
        int k = 1;
        int g;

        window.draw(backgroundSprite);
        /*
        bpiece.setPosition(blue_piece[i][2], blue_piece[i][3]);
        rpiece.setPosition(red_piece[i][2], red_piece[i][3]);
        gpiece.setPosition(green_piece[i][2], green_piece[i][3]);
        ypiece.setPosition(yellow_piece[i][2], yellow_piece[i][3]);
        */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        {
            /***/
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            r1.local = 0;
            std::cout << "r1 has been reset" << std::endl;
        }

        rpiece.setPosition(red_piece[r1.local][2], red_piece[r1.local][3]);
        window.draw(rpiece);
        /*
        window.draw(bpiece);
        window.draw(gpiece);
        window.draw(ypiece);
        */
        window.display();
        i = i + 1;
        Sleep(10);
    }

    return 0;
}
