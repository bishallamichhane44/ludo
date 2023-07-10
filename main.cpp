#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using std::string;

sf::RenderWindow window(sf::VideoMode(1280, 720), "Play Ludo", sf::Style::Titlebar | sf::Style::Close);

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

class Coordinates
{
private:
    int xPos, yPos;

public:
    Coordinates() {}
    Coordinates(int x, int y)
    {
        xPos = x;
        yPos = y;
    }
    int get_xcoords()
    {
        return xPos;
    }

    int get_ycoords()
    {
        return yPos;
    }

    void set_coords(int x, int y)
    {
        xPos = x;
        yPos = y;
    }
};

class Dice
{
private:
    Coordinates dice_coords;
    // int score;
public:
    Dice(Coordinates c)
    {
        dice_coords = c;
    }
    void display_dice(int s)
    {
    }
    // Piece get_piece() {}
    // void roll(Player p)
    // {
    //     int score = ((rand() % 6) + 1);
    //     display_dice(score);
    //     Piece piece = get_piece();
    //     piece.move(score);
    //     piece.set_score(piece.get_score() + score);
    // }
};

class Piece
{
private:
    sf::Texture piece_texture;
    sf::Sprite piece;
    Coordinates coordinate;
    int score = 0;

public:
    void set_piece(string filename, Coordinates c)
    {
        if (!piece_texture.loadFromFile(filename))
        {
            std::cout << "The Piece Cannot be loaded from:";
            // return;
        }
        piece.setTexture(piece_texture);
        coordinate = c;
        piece.setPosition(coordinate.get_xcoords(), coordinate.get_ycoords());
    }

    sf::Sprite get_piece()
    {
        return piece;
    }

    int get_score()
    {
        return score;
    }

    void set_score(int s)
    {
        score = s;
    }

    void set_position(Coordinates c)
    {
        piece.setPosition(c.get_xcoords(), c.get_ycoords());
    }

    void move(int step)
    {
        for (int i = 1; i <= step; i++)
        {
            piece.setPosition(blue_piece[i][2], blue_piece[i][3]);
            window.draw(piece);
            Sleep(500);
        }
    }
};

class Player
{
private:
    string name;
    string colour;
    Piece pieces[4];
    int total_score = 0;

public:
    Player(string nam, string col, Piece p[])
    {
        name = nam;
        colour = col;
        for (int i = 0; i < 4; i++)
        {
            pieces[i] = p[i];
        }
    }

    void draw()
    {
        for (int i = 0; i < 4; i++)
        {
            window.draw(pieces[i].get_piece());
        }
    }
};

// Player createPlayer(Coordinates coordArr[],string filename,string name,string colour){
//     Piece p1, p2, p3, p4;
//     Piece pieces[4]={p1,p2,p3,p4};
//      for (int i = 0; i < 4; i++)
//     {
//         pieces[i].set_piece(filename, coordArr[i]);
//     }
//     Player player1(name, colour, pieces);

// }

int main()
{
    // creating dice obj

    Coordinates diceCoords(15, 17);
    Dice dice(diceCoords);

    // Creating Player1(YELLOW)
    Coordinates coord11(358, 298), coord12(666, 78), coord13(886, 386), coord14(578, 606);
    Coordinates carr1[4] = {coord11, coord12, coord13, coord14};
    string filename = ".\\assets\\yellow_disc.png";
    Piece p11, p12, p13, p14;
    Piece pieces1[4] = {p11, p12, p13, p14};
    for (int i = 0; i < 4; i++)
    {
        pieces1[i].set_piece(filename, carr1[i]);
    }

    Player player1("Bipin", "Yellow", pieces1);

    // creating Player2(GREEN)
    Coordinates coord21(358, 298), coord22(666, 78), coord23(886, 386), coord24(578, 606);
    Coordinates carr2[4] = {coord21, coord22, coord23, coord24};
    filename = ".\\assets\\green_disc.png";
    Piece p21, p22, p23, p24;
    Piece pieces2[4] = {p21, p22, p23, p24};
    for (int i = 0; i < 4; i++)
    {
        pieces2[i].set_piece(filename, carr2[i]);
    }

    Player player2("Ayush", "Green", pieces2);

    // creating Player3(RED)

    Coordinates coord31(358, 298), coord32(666, 78), coord33(886, 386), coord34(578, 606);
    Coordinates carr3[4] = {coord31, coord32, coord33, coord34};
    filename = ".\\assets\\red_disc.png";
    Piece p31, p32, p33, p34;
    Piece pieces3[4] = {p31, p32, p33, p34};
    for (int i = 0; i < 4; i++)
    {
        pieces3[i].set_piece(filename, carr3[i]);
    }

    Player player3("Bishal", "Red", pieces3);

    // Creating Player4(BLUE)

    Coordinates coord41(358, 298), coord42(666, 78), coord43(886, 386), coord44(578, 606);
    Coordinates carr4[4] = {coord41, coord42, coord43, coord44};
    filename = ".\\assets\\blue_disc.png";
    Piece p41, p42, p43, p44;
    Piece pieces4[4] = {p41, p42, p43, p44};
    for (int i = 0; i < 4; i++)
    {
        pieces4[i].set_piece(filename, carr4[i]);
    }

    Player player4("Lammi", "Blue", pieces4);

    sf::Texture backgroundImage;
    if (!backgroundImage.loadFromFile(".\\assets\\ludo_mini.png"))
    {
        return -1;
    }

    // Set the position of the sprite

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundImage);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundSprite);
        player2.draw();
        window.display();
    }

    return 0;
}