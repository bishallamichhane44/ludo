#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using std::string;
int mouse_tracker;
int noOfPlayers = 4;
int playerTurn = 0;
int dice = 0;
int diceInfo = 0;
int step = 0;
int dice_turn = 1;
int piece_changed = 0;
int player_changed = 0;
string filename;
sf::Vector2i localPosition;

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

//coordinate of playlocal in first frame is (x,y)=(819,499) and (width,height)=(276,105) i.e x from 819 to 819+276 and y from 499 to 499+105
//coordinate of 2 in second frame is (x,y)=(256,308) and (width,height)=(95,105)
//coordinate of 3 in second frame is (x,y)=(593,308) and  (width,height)=(95,105)
//coordinate of 4 in second frame is (x,y)=(930,308) and (width,height)=(95,105)
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

    bool operator==(Coordinates c)
    {
        if (xPos == c.xPos && yPos == c.yPos)
            return true;
        return false;
    }
};

class Piece
{
private:
    sf::Texture piece_texture;
    sf::Sprite piece;
    Coordinates initialCoords;
    Coordinates coordinate;
    int score = -1;
    string colour;

public:
    bool is_locked = true;
    bool is_safe = true;
    bool reached_home = false;

    void set_piece(string filename, Coordinates c, string col)
    {
        if (!piece_texture.loadFromFile(filename))
        {
            std::cout << "The Piece Cannot be loaded from:" << filename;
            return;
        }
        piece.setTexture(piece_texture);
        coordinate = c;
        colour = col;
        piece.setPosition(coordinate.get_xcoords(), coordinate.get_ycoords());
        initialCoords = c;
    }

    void set_texture(string filename)
    {
        if (!piece_texture.loadFromFile(filename))
        {
            std::cout << "The Piece cannot be loaded from: " << filename;
            return;
        }
        piece.setTexture(piece_texture);
    }

    sf::Sprite get_piece()
    {
        return piece;
    }

    int get_score()
    {
        return score;
    }

    Coordinates get_coordinates()
    {
        return coordinate;
    }

    void set_score(int s)
    {
        score = s;
    }

    void set_coordinate(Coordinates c)
    {
        coordinate = c;
    }

    void set_position(Coordinates c)
    {
        piece.setPosition(c.get_xcoords(), c.get_ycoords());
    }

    void moveForward(int step)
    {
        if (colour == "yellow")
        {
            if (score == -1)
            {
                piece.setPosition(yellow_piece[0][2], yellow_piece[0][3]);
                set_coordinate(Coordinates(yellow_piece[0][2], yellow_piece[0][3]));
            }
            else
            {
                piece.setPosition(yellow_piece[step + score][2], yellow_piece[step + score][3]);
                set_coordinate(Coordinates(yellow_piece[step + score][2], yellow_piece[step + score][3]));
            }
        }
        else if (colour == "green")
        {
            if (score == -1)
            {
                piece.setPosition(green_piece[0][2], green_piece[0][3]);
                set_coordinate(Coordinates(green_piece[0][2], green_piece[0][3]));
            }
            else
            {
                piece.setPosition(green_piece[step + score][2], green_piece[step + score][3]);
                set_coordinate(Coordinates(green_piece[step + score][2], green_piece[step + score][3]));
            }
        }
        else if (colour == "red")
        {
            if (score == -1)
            {
                piece.setPosition(red_piece[0][2], red_piece[0][3]);
                set_coordinate(Coordinates(red_piece[0][2], red_piece[0][3]));
            }
            else
            {
                piece.setPosition(red_piece[step + score][2], red_piece[step + score][3]);
                set_coordinate(Coordinates(red_piece[step + score][2], red_piece[step + score][3]));
            }
        }
        else if (colour == "blue")
        {
            if (score == -1)
            {
                piece.setPosition(blue_piece[0][2], blue_piece[0][3]);
                set_coordinate(Coordinates(blue_piece[0][2], blue_piece[0][3]));
            }
            else
            {
                piece.setPosition(blue_piece[step + score][2], blue_piece[step + score][3]);
                set_coordinate(Coordinates(blue_piece[step + score][2], blue_piece[step + score][3]));
            }
        }

        for (int i = 0; i < 8; i++)
        {
            if (coordinate == Coordinates(safe_position[i][2], safe_position[i][3]))
            {
                is_safe = true;
                break;
            }
            else
                is_safe = false;
        }
        std::cout << "You are progressing ..." << std::endl;
    }

    void moveBackward()
    {
        piece.setPosition(initialCoords.get_xcoords(), initialCoords.get_ycoords());
        set_coordinate(Coordinates(initialCoords.get_xcoords(), initialCoords.get_ycoords()));
        is_locked = true;
        std::cout << "Amazing!! you killed one." << std::endl;
    }
};

class Player
{
private:
    string name;
    string colour;
    int total_score = 0;
    bool isActive = false;

public:
    Piece pieces[4];
    Player() {}
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

    // void roll(int &playerTurn, Player *players)
    void roll(int &playerTurn, Player *players, int step)
    {
        //****************************************************************************************
        filename = ".\\assets\\" + colour + "_disc_1.png";
        if (dice && mouse_tracker == 1 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            int lock = 4;
            for (int i = 0; i < 4; i++)
            {
                if (!players[playerTurn].pieces[i].is_locked)
                {
                    lock--;
                };
            }

            int piece_no;
            if (step == 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    pieces[i].set_texture(filename);
                }
                std::cout << "Press your piece to move/withdraw ( 1 2 3 4 )" << std::endl;

                for (int i = 0; i < 4; i++)
                {
                    localPosition = sf::Mouse::getPosition(window);
                    int pieceX = players[playerTurn].pieces[i].get_coordinates().get_xcoords();
                    int pieceY = players[playerTurn].pieces[i].get_coordinates().get_ycoords();
                    if (localPosition.x > pieceX && localPosition.x < pieceX + 40 && localPosition.y > pieceY && localPosition.y < pieceY + 40 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                    {
                        diceInfo = 0;
                        dice = 0;
                        dice_turn = 1;
                        piece_no = i;
                        std::cout << piece_no << std::endl;
                        players[playerTurn].pieces[piece_no].is_locked = false;
                        players[playerTurn].pieces[piece_no].moveForward(step);
                        filename = ".\\assets\\" + colour + "_disc.png";
                        piece_changed = 1;
                        players[playerTurn].pieces[piece_no].set_score(players[playerTurn].pieces[piece_no].get_score() + step);
                        break;
                    }
                }
                player_changed = 0;
            }
            else if (lock == 4)
            {
                std::cout << "Sorry!! All of your Pieces are locked " << std::endl;
                playerTurn++;
                player_changed = 1;
                std::cout << "Player changed 1" << std::endl;
                dice_turn = 1;
                dice = 0;
                diceInfo = 0;
            }
            else
            {

            jump:
                std::cout << "Press your unlocked piece number to move ( ";
                for (int i = 0; i < 4; i++)
                {
                    if (!players[playerTurn].pieces[i].is_locked)
                    {
                        std::cout << i + 1 << " ";
                        pieces[i].set_texture(filename);
                    }
                }
                std::cout << ")" << std::endl;

                for (int i = 0; i < 4; i++)
                {
                    localPosition = sf::Mouse::getPosition(window);
                    int pieceX = players[playerTurn].pieces[i].get_coordinates().get_xcoords();
                    int pieceY = players[playerTurn].pieces[i].get_coordinates().get_ycoords();
                    if (localPosition.x > pieceX && localPosition.x < pieceX + 40 && localPosition.y > pieceY && localPosition.y < pieceY + 40 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                    {
                        piece_no = i;
                        std::cout << piece_no << std::endl;
                        if (pieces[piece_no].is_locked)
                        {
                            std::cout << "Ohhh!! This piece is locked!!" << std::endl;
                            goto jump;
                        }
                        players[playerTurn].pieces[piece_no].moveForward(step);
                        piece_changed = 1;
                        filename = ".\\assets\\" + colour + "_disc.png";
                        players[playerTurn].pieces[piece_no].set_score(players[playerTurn].pieces[piece_no].get_score() + step);

                        if (step != 6)
                        {
                            playerTurn++;
                            player_changed = 1;
                            std::cout << "Player changed 2";
                        }
                        dice_turn = 1;
                        dice = 0;
                        diceInfo = 0;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    // Initial Coordinates of Pieces
    // Coordinates coord11(358 - 40, 298), coord12(468, 100), coord13(380, 188), coord14(468, 188);
    Coordinates coord11(380, 100), coord12(468, 100), coord13(380, 188), coord14(468, 188);
    Coordinates coord21(776, 100), coord22(864, 100), coord23(776, 188), coord24(864, 188);
    Coordinates coord31(776, 496), coord32(864, 496), coord33(776, 584), coord34(864, 584);
    Coordinates coord41(380, 496), coord42(468, 496), coord43(380, 584), coord44(468, 584);

    // Creating Pieces
    Piece p11, p12, p13, p14;
    Piece p21, p22, p23, p24;
    Piece p31, p32, p33, p34;
    Piece p41, p42, p43, p44;

    string colourOrder[] = {"yellow", "green", "red", "blue"};
    Coordinates coordArr[][4] = {{coord11, coord12, coord13, coord14}, {coord21, coord22, coord23, coord24}, {coord31, coord32, coord33, coord34}, {coord41, coord42, coord43, coord44}};
    Piece pieces[][4] = {{p11, p12, p13, p14}, {p21, p22, p23, p24}, {p31, p32, p33, p34}, {p41, p42, p43, p44}};
    do
    {
        std::cout << "Enter no of Players(2,3,4): ";
        std::cin >> noOfPlayers;
        if (noOfPlayers < 2 || noOfPlayers > 4)
            std::cout << "Invalid No of players!!" << std::endl;
    } while (noOfPlayers < 2 || noOfPlayers > 4);
    Player *players = new Player[noOfPlayers];
    for (int j = 0; j < noOfPlayers; j++)
    {
        string playerName = "Bipin";
        // std::cout << "Enter name of Player" << j + 1 << "(" << colourOrder[j] << "): ";
        // std::cin >> playerName;
        string filename = ".\\assets\\" + colourOrder[j] + "_disc.png";

        for (int i = 0; i < 4; i++)
        {
            pieces[j][i].set_piece(filename, coordArr[j][i], colourOrder[j]);
        }
        Player player(playerName, colourOrder[j], pieces[j]);
        players[j] = player;
    }

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
        for (int j = 0; j < noOfPlayers; j++)
        {
            players[j].draw();
        }
        if (!((sf::Mouse::isButtonPressed(sf::Mouse::Left))))
        {
            mouse_tracker = 1;
        }
        if (!diceInfo)
        {
            std::cout << "\n********** " << colourOrder[playerTurn] << "'s turn **************" << std::endl;
            std::cout << "Press dice to roll.." << std::endl;
            diceInfo = 1;
        }

        localPosition = sf::Mouse::getPosition(window);
        if (dice_turn && mouse_tracker == 1 && localPosition.x < 1201 && localPosition.x > 1001 && localPosition.y < 673 && localPosition.y > 443 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {

            dice_turn = 0;
            dice = 1;
            srand(time(0));
            step = ((rand() % 6) + 1);
            // std::cout << "Enter dice no: ";
            // std::cin >> step;
            std::cout << "Dice Rolled: " << step << std::endl;
            if (((sf::Mouse::isButtonPressed(sf::Mouse::Left))))
            {
                mouse_tracker = 0;
            }
            else
            {
                mouse_tracker = 1;
            }
        }

        //*****************************************************************************************
        if (dice && mouse_tracker == 1 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            players[playerTurn].roll(playerTurn, players, step);

            playerTurn = playerTurn % noOfPlayers;
            if (((sf::Mouse::isButtonPressed(sf::Mouse::Left))))
            {
                mouse_tracker = 0;
            }
            else
            {
                mouse_tracker = 1;
            }
        }
        if (piece_changed)
        { 
            if(playerTurn==0){
                int turn=playerTurn;
                std::cout<<player_changed<<std::endl;
                if(player_changed)
                 turn=3;
                for (int i = 0; i < 4; i++)
            {
                players[turn].pieces[i].set_texture(filename);
            }
            piece_changed = 0;
            player_changed = 0;
            }
            else{
            int turn = playerTurn;
            std::cout << player_changed << std::endl;
            if (player_changed)
                turn--;
            for (int i = 0; i < 4; i++)
            {
                players[turn].pieces[i].set_texture(filename);
            }
            piece_changed = 0;
            player_changed = 0;
            }
        }
        window.display();
    }

    return 0;
}