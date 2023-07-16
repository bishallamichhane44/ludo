#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

// Path coordinats
int red_piece[][4] = {{27, 0, 886, 386}, {28, 1, 842, 386}, {29, 2, 798, 386}, {30, 3, 754, 386}, {31, 4, 710, 386}, {32, 5, 666, 430}, {33, 6, 666, 474}, {34, 7, 666, 518}, {35, 8, 666, 562}, {36, 9, 666, 606}, {37, 10, 666, 650}, {38, 11, 622, 650}, {39, 12, 578, 650}, {40, 13, 578, 606}, {41, 14, 578, 562}, {42, 15, 578, 518}, {43, 16, 578, 474}, {44, 17, 578, 430}, {45, 18, 534, 386}, {46, 19, 490, 386}, {47, 20, 446, 386}, {48, 21, 402, 386}, {49, 22, 358, 386}, {50, 23, 314, 386}, {51, 24, 314, 342}, {0, 25, 314, 298}, {1, 26, 358, 298}, {2, 27, 402, 298}, {3, 28, 446, 298}, {4, 29, 490, 298}, {5, 30, 534, 298}, {6, 31, 578, 254}, {7, 32, 578, 210}, {8, 33, 578, 166}, {9, 34, 578, 122}, {10, 35, 578, 78}, {11, 36, 578, 34}, {12, 37, 622, 34}, {13, 38, 666, 34}, {14, 39, 666, 78}, {15, 40, 666, 122}, {16, 41, 666, 166}, {17, 42, 666, 210}, {18, 43, 666, 254}, {19, 44, 710, 298}, {20, 45, 754, 298}, {21, 46, 798, 298}, {22, 47, 842, 298}, {23, 48, 886, 298}, {24, 49, 930, 298}, {25, 50, 930, 342}, {63, 51, 886, 342}, {64, 52, 842, 342}, {65, 53, 798, 342}, {66, 54, 754, 342}, {67, 55, 710, 342}, {57, 56, 622, 342}};
int blue_piece[][4] = {{40, 0, 578, 606}, {41, 1, 578, 562}, {42, 2, 578, 518}, {43, 3, 578, 474}, {44, 4, 578, 430}, {45, 5, 534, 386}, {46, 6, 490, 386}, {47, 7, 446, 386}, {48, 8, 402, 386}, {49, 9, 358, 386}, {50, 10, 314, 386}, {51, 11, 314, 342}, {0, 12, 314, 298}, {1, 13, 358, 298}, {2, 14, 402, 298}, {3, 15, 446, 298}, {4, 16, 490, 298}, {5, 17, 534, 298}, {6, 18, 578, 254}, {7, 19, 578, 210}, {8, 20, 578, 166}, {9, 21, 578, 122}, {10, 22, 578, 78}, {11, 23, 578, 34}, {12, 24, 622, 34}, {13, 25, 666, 34}, {14, 26, 666, 78}, {15, 27, 666, 122}, {16, 28, 666, 166}, {17, 29, 666, 210}, {18, 30, 666, 254}, {19, 31, 710, 298}, {20, 32, 754, 298}, {21, 33, 798, 298}, {22, 34, 842, 298}, {23, 35, 886, 298}, {24, 36, 930, 298}, {25, 37, 930, 342}, {26, 38, 930, 386}, {27, 39, 886, 386}, {28, 40, 842, 386}, {29, 41, 798, 386}, {30, 42, 754, 386}, {31, 43, 710, 386}, {32, 44, 666, 430}, {33, 45, 666, 474}, {34, 46, 666, 518}, {35, 47, 666, 562}, {36, 48, 666, 606}, {37, 49, 666, 650}, {38, 50, 622, 650}, {68, 51, 622, 606}, {69, 52, 622, 562}, {70, 53, 622, 518}, {71, 54, 622, 474}, {72, 55, 622, 430}, {57, 56, 622, 342}};
int yellow_piece[][4] = {{1, 0, 358, 298}, {2, 1, 402, 298}, {3, 2, 446, 298}, {4, 3, 490, 298}, {5, 4, 534, 298}, {6, 5, 578, 254}, {7, 6, 578, 210}, {8, 7, 578, 166}, {9, 8, 578, 122}, {10, 9, 578, 78}, {11, 10, 578, 34}, {12, 11, 622, 34}, {13, 12, 666, 34}, {14, 13, 666, 78}, {15, 14, 666, 122}, {16, 15, 666, 166}, {17, 16, 666, 210}, {18, 17, 666, 254}, {19, 18, 710, 298}, {20, 19, 754, 298}, {21, 20, 798, 298}, {22, 21, 842, 298}, {23, 22, 886, 298}, {24, 23, 930, 298}, {25, 24, 930, 342}, {26, 25, 930, 386}, {27, 26, 886, 386}, {28, 27, 842, 386}, {29, 28, 798, 386}, {30, 29, 754, 386}, {31, 30, 710, 386}, {32, 31, 666, 430}, {33, 32, 666, 474}, {34, 33, 666, 518}, {35, 34, 666, 562}, {36, 35, 666, 606}, {37, 36, 666, 650}, {38, 37, 622, 650}, {39, 38, 578, 650}, {40, 39, 578, 606}, {41, 40, 578, 562}, {42, 41, 578, 518}, {43, 42, 578, 474}, {44, 43, 578, 430}, {45, 44, 534, 386}, {46, 45, 490, 386}, {47, 46, 446, 386}, {48, 47, 402, 386}, {49, 48, 358, 386}, {50, 49, 314, 386}, {51, 50, 314, 342}, {52, 51, 358, 342}, {53, 52, 402, 342}, {54, 53, 446, 342}, {55, 54, 490, 342}, {56, 55, 534, 342}, {57, 56, 622, 342}};
int green_piece[][4] = {{14, 0, 666, 78}, {15, 1, 666, 122}, {16, 2, 666, 166}, {17, 3, 666, 210}, {18, 4, 666, 254}, {19, 5, 710, 298}, {20, 6, 754, 298}, {21, 7, 798, 298}, {22, 8, 842, 298}, {23, 9, 886, 298}, {24, 10, 930, 298}, {25, 11, 930, 342}, {26, 12, 930, 386}, {27, 13, 886, 386}, {28, 14, 842, 386}, {29, 15, 798, 386}, {30, 16, 754, 386}, {31, 17, 710, 386}, {32, 18, 666, 430}, {33, 19, 666, 474}, {34, 20, 666, 518}, {35, 21, 666, 562}, {36, 22, 666, 606}, {37, 23, 666, 650}, {38, 24, 622, 650}, {39, 25, 578, 650}, {40, 26, 578, 606}, {41, 27, 578, 562}, {42, 28, 578, 518}, {43, 29, 578, 474}, {44, 30, 578, 430}, {45, 31, 534, 386}, {46, 32, 490, 386}, {47, 33, 446, 386}, {48, 34, 402, 386}, {49, 35, 358, 386}, {50, 36, 314, 386}, {51, 37, 314, 342}, {0, 38, 314, 298}, {1, 39, 358, 298}, {2, 40, 402, 298}, {3, 41, 446, 298}, {4, 42, 490, 298}, {5, 43, 534, 298}, {6, 44, 578, 254}, {7, 45, 578, 210}, {8, 46, 578, 166}, {9, 47, 578, 122}, {10, 48, 578, 78}, {11, 49, 578, 34}, {12, 50, 622, 34}, {58, 51, 622, 78}, {59, 52, 622, 122}, {60, 53, 622, 166}, {61, 54, 622, 210}, {62, 55, 622, 254}, {57, 56, 622, 342}};

// Initial Positions
int initial_pos[][4] = {{85, 57, 776, 496}, {86, 58, 864, 496}, {87, 59, 776, 584}, {88, 60, 864, 584}, {81, 57, 380, 496}, {82, 58, 468, 496}, {83, 59, 380, 584}, {84, 60, 468, 584}, {73, 57, 380, 100}, {74, 58, 468, 100}, {75, 59, 380, 188}, {76, 60, 468, 188}, {77, 57, 776, 100}, {78, 58, 864, 100}, {79, 59, 776, 188}, {80, 60, 864, 188}};

// Safe Positions
int safe_position[][4] = {{1, 0, 358, 298}, {14, 0, 666, 78}, {27, 0, 886, 386}, {40, 0, 578, 606}, {9, 8, 578, 122}, {22, 8, 842, 298}, {35, 8, 666, 562}, {48, 8, 402, 386}};

// Available colors
std::string piece_colour[] = {"red", "blue", "yellow", "green"};

// Textures
sf::Texture Redpiece, Bluepiece, Yellowpiece, Greenpiece, backgroundImage;
sf::Texture texture_name[] = {Redpiece, Bluepiece, Yellowpiece, Greenpiece, backgroundImage};
std::string file_name[] = {".\\assets\\red_disc.png", ".\\assets\\blue_disc.png", ".\\assets\\yellow_disc.png", ".\\assets\\green_disc.png", ".\\assets\\ludo_mini.png"};

// Piece Sprites
sf::Sprite r1, r2, r3, r4, b1, b2, b3, b4, ye1, ye2, ye3, ye4, g1, g2, g3, g4;
sf::Sprite sprite_array[] = {r1, r2, r3, r4, b1, b2, b3, b4, ye1, ye2, ye3, ye4, g1, g2, g3, g4};

int map_texture()
{
    int size_of_array = (sizeof(texture_name) / sizeof(*texture_name));
    for (int i = 0; i < size_of_array; i++)
    {
        if (!texture_name[i].loadFromFile(file_name[i]))
        {
            return -1;
        }
    }

    for (int i = 0; i < 16; i++)
    {
        int num = i / 4;
        sprite_array[i].setTexture(texture_name[num]);
    }
    return 0;
}

class Player
{
public:
    std::string name;
    int player_id;
    int piece_colour;
    bool is_active;
    bool turn_repeat;
    bool is_turn = false;
    bool is_completed;
    sf::Sprite pieces[4];

    Player(std::string nam, int a, int b) : name(nam), player_id(a), piece_colour(b)
    {
        is_active = true;
    };
};

Player p1("Aayush", 0, 0);
Player p2("Bishal", 1, 1);
Player p3("Miles", 2, 2);
Player p4("Bipin", 3, 3);

Player player_array[] = {p1, p2, p3, p4};

class pieces
{
public:
    int piece_colour;
    bool is_trapped;
    bool is_locked = true;
    bool is_safe;
    bool is_completed;
    bool is_killed;
    int piece_id;
    int local = 0;
    int global;

    // Initial coordinates
    int i_x_cord;
    int i_y_cord;

    // Coordinates after game starts
    int x_cord;
    int y_cord;

    pieces(int id) : piece_id(id)
    {
        x_cord = initial_pos[piece_id][2];
        y_cord = initial_pos[piece_id][3];
    };

    int get_global()
    {
        if (piece_id >= 0 && piece_id < 4)
        {
            return (red_piece[local][0]);
        }
        if (piece_id >= 4 && piece_id < 8)
        {
            return (blue_piece[local][0]);
        }
        if (piece_id >= 8 && piece_id < 12)
        {
            return (yellow_piece[local][0]);
        }
        if (piece_id >= 12 && piece_id < 16)
        {
            return (green_piece[local][0]);
        }
    }

    int set_position()
    {
        if (local >= 0)
        {

            if (piece_id >= 0 && piece_id < 4)
            {
                x_cord = red_piece[local][2];
                y_cord = red_piece[local][3];
            }

            if (piece_id >= 4 && piece_id < 8)
            {
                x_cord = blue_piece[local][2];
                y_cord = blue_piece[local][3];
            }

            if (piece_id >= 8 && piece_id < 12)
            {
                x_cord = yellow_piece[local][2];
                y_cord = yellow_piece[local][3];
            }

            if (piece_id >= 12 && piece_id < 16)
            {
                x_cord = green_piece[local][2];
                y_cord = green_piece[local][3];
            }
        }
        return 0;
    }
};

// All pieces
pieces rp1(0), rp2(1), rp3(2), rp4(3), bp1(4), bp2(5), bp3(6), bp4(7), yp1(8), yp2(9), yp3(10), yp4(11), gp1(12), gp2(13), gp3(14), gp4(15);

// Array of all pieces
pieces piece_array[] = {rp1, rp2, rp3, rp4, bp1, bp2, bp3, bp4, yp1, yp2, yp3, yp4, gp1, gp2, gp3, gp4};

int dice;
int playing;

int turn_output()
{
    for (int i = 0; i < 4; i++)
    {
        if (player_array[i].is_turn == true)
        {
            playing = i;
        }
    }
    return 0;
};

int turn_passer()
{
    turn_output();
    int i = playing;
    player_array[i].is_turn = false;
    int k = 0;
    if (i < 3)
    {
        k = i + 1;
    }
    else if (i == 3)
    {
        k = 0;
    }

    player_array[k].is_turn = true;
    turn_output();
    return 0;
}

int total_piece[4] = {0};
int manage[4] = {0};
int piece_id = 200;
int color;
int kk = 0;
int player;
int repeat = 0;
bool all_unlocked;
int counter = 0;

int piece_selector(int dice)
{
    turn_output();
    piece_id = 100;
    std::cout << std::endl
              << "Dice::" << dice << std::endl;
    std::cout << "turn of player::" << playing << std::endl;
    player = playing;
    color = player;
    int k = player * 4;
    for (int i = 0; i < 4; i++)
    {
        total_piece[i] = k;
        k = k + 1;
    }

    if (dice == 6)
    {
        repeat = 1;
        std::cout << "six" << std::endl;
    }

    if (dice == 1)
    {
        repeat = 1;
        std::cout << "one" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            manage[i] = total_piece[i];
            kk = 4;
        }
    }

    if (dice > 1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (piece_array[total_piece[i]].is_locked == false)
            {
                std::cout << "loop entered" << std::endl;
                manage[kk] = total_piece[i];
                kk = kk + 1;
            }
        }
        if (kk == 0)
        {
            std::cout << "All pieces are locked for player::" << playing << std::endl;
        }
    }
    int gg = 0;
    if (kk > 0)
    {
        std::cout << std::endl
                  << "Enter the ID of piece that you want to select :: ";
        for (int i = 0; i < kk; i++)
        {
            std::cout << " " << manage[i] << " ";
        }
        std::cin >> piece_id;
        for (int i = 0; i < kk; i++)
        {
            if (piece_id == manage[i])
            {
                gg = gg + 1;
            }
        }
        if (gg = 0)
        {
            piece_id = 100;
        }
        // piece_array[piece_id].is_locked=false;
    }
    else if (kk = 0)
    {
        piece_id = 100;
        std::cout << "Piece ID set to 100" << std::endl;
    }
    kk = 0;
    if (repeat == 1)
    {
        repeat = 0;
    }
    else
    {
        std::cout << "Calling Turn Passer" << std::endl;
        turn_passer();
        std::cout << "****************" << std::endl
                  << std::endl;
    }
    return 0;
}

int main()
{

    map_texture();
    player_array[1].is_turn = true;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Play Ludo", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(texture_name[4]);

    // Set position

    int mouse_tracker;
    int player_tracker = 0;
    int key = 2;

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

            piece_selector(dice);
            int k = piece_id;

            if (piece_array[k].is_locked == true)
            {
                piece_array[k].is_locked = false;
                std::cout << "Working here" << std::endl;
                piece_array[k].local = 0;
                dice = 0;
                piece_array[k].set_position();
            }

            if (piece_id < 100)
            {
                piece_array[k].local = piece_array[k].local + dice;
                piece_array[k].set_position();
            }

            if (((sf::Mouse::isButtonPressed(sf::Mouse::Left))))
            {
                mouse_tracker = 0;
            }
            else
            {
                mouse_tracker = 1;
            }
        }

        // Update positions of all pieces.
        for (int i = 0; i < 16; i++)
        {
            sprite_array[i].setPosition(piece_array[i].x_cord, piece_array[i].y_cord);
        }

        window.clear();
        window.draw(backgroundSprite);

        // Draw all sprites
        for (int i = 0; i < 16; i++)
        {
            window.draw(sprite_array[i]);
        }
        window.display();
    }

    return 0;
}