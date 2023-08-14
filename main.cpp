#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using std::string;
int noOfPlayers = 4;
int playerTurn = 0;
int dice = 0;
int diceInfo = 0;
int step = 6;
int dice_turn = 1;
int piece_changed = 0;
int player_changed = 0;
string filename;
sf::Vector2i localPosition;
sf::Sprite diceSprite;
string dice_order[] = {"1", "2", "3", "4", "5", "6"};
int computerishere=0;

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
int safe_position[][4] = {{1, 0, 358, 298}, {14, 0, 666, 78}, {27, 0, 886, 386}, {40, 0, 578, 606}, {9, 8, 578, 122}, {22, 8, 842, 298}, {35, 8, 666, 562}, {48, 8, 402, 386},{57,56,622,342}};

int frame_position[4][2] = {{308, 28}, {706, 29}, {704, 425}, {308, 425}};
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

class Dice
{
private:
    sf::Texture dice_texture[6];
    sf::Sprite dice[6];
    Coordinates coordinate;

public:
    void set_dice(string *filenames, Coordinates c)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!dice_texture[i].loadFromFile(filenames[i]))
            {
                std::cout << "File cannot be loaded from: " << filenames[i] << std::endl;
                return;
            }
            dice[i].setTexture(dice_texture[i]);
            coordinate = c;
            dice[i].setPosition(coordinate.get_xcoords(), coordinate.get_ycoords());
        }
    }

    void dice_roll()
    {
        for (int i = 0; i < 6; i++)
        {
            window.draw(dice[i]);
            window.display();
            Sleep(100);
        }
        srand(time(0));
        step = ((rand() % 6) + 1);
        //std::cout<<"Enter dice number:";std::cin>>step;
        diceSprite = dice[step - 1];
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
    bool is_at_base = true;

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
        coordinate = c;
    }
    // int getlocalpos(){
    //     int a;
    //     for(int i=0;i<58;i++){
    //         if(colour=="yellow"){
    //             if(yellow_piece[i][2]==coordinate.get_xcoords() && yellow_piece[i][3]==coordinate.get_ycoords()){
    //                 a=yellow_piece[i][1];
    //                 break;
    //             }
    //         }
    //         else if(colour=="green"){
    //              if(green_piece[i][2]==coordinate.get_xcoords() && green_piece[i][3]==coordinate.get_ycoords()){
    //                 a=green_piece[i][1];
    //                 break;
    //              }
    //         }
    //         else if(colour=="red"){
    //              if(red_piece[i][2]==coordinate.get_xcoords() && red_piece[i][3]==coordinate.get_ycoords()){
    //                 a=red_piece[i][1];
    //                 break;
    //              }
    //         }
    //         else if(colour=="blue"){
    //              if(blue_piece[i][2]==coordinate.get_xcoords() && blue_piece[i][3]==coordinate.get_ycoords()){
    //                 a=blue_piece[i][1];
    //                 break;
    //              }
    //         }
    //     }
    //     return a;
    // }
    void moveForward(int step)
    {
        Coordinates center1(622,342);
        if (colour == "yellow")
        {
            if (score == -1)
            {
                piece.setPosition(yellow_piece[0][2], yellow_piece[0][3]);
                set_coordinate(Coordinates(yellow_piece[0][2], yellow_piece[0][3]));
            }
            else
            {
                // piece.setPosition(yellow_piece[step + score][2], yellow_piece[step + score][3]);
                // set_coordinate(Coordinates(yellow_piece[step + score][2], yellow_piece[step + score][3]));
            
                for (int i = 1; i <= step; i++)
                {
                    piece.setPosition(yellow_piece[i + score][2], yellow_piece[i + score][3]);
                    set_coordinate(Coordinates(yellow_piece[i + score][2], yellow_piece[i + score][3]));
                    window.draw(piece);
                    window.display();
                    Sleep(60);
                    
                } 
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
                // piece.setPosition(green_piece[step + score][2], green_piece[step + score][3]);
                // set_coordinate(Coordinates(green_piece[step + score][2], green_piece[step + score][3]));

                for (int i = 1; i <= step; i++)
                {
                    piece.setPosition(green_piece[i + score][2], green_piece[i + score][3]);
                    set_coordinate(Coordinates(green_piece[i + score][2], green_piece[i + score][3]));
                    window.draw(piece);
                    window.display();
                    Sleep(60);
                     
                }
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
                // piece.setPosition(red_piece[step + score][2], red_piece[step + score][3]);
                // set_coordinate(Coordinates(red_piece[step + score][2], red_piece[step + score][3]));

                for (int i = 1; i <= step; i++)
                {
                    piece.setPosition(red_piece[i + score][2], red_piece[i + score][3]);
                    set_coordinate(Coordinates(red_piece[i + score][2], red_piece[i + score][3]));
                    window.draw(piece);
                    window.display();
                    Sleep(60);
                }       
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
                // piece.setPosition(blue_piece[step + score][2], blue_piece[step + score][3]);
                // set_coordinate(Coordinates(blue_piece[step + score][2], blue_piece[step + score][3]));

                for (int i = 1; i <= step; i++)
                {
                    piece.setPosition(blue_piece[i + score][2], blue_piece[i + score][3]);
                    set_coordinate(Coordinates(blue_piece[i + score][2], blue_piece[i + score][3]));
                    window.draw(piece);
                    window.display();
                    Sleep(60);
                }
                 
            }   
        }
        if(coordinate==center1){
                        reached_home = true;
                        is_locked = true;
                        is_safe=true;
                     } 
        for (int i = 0; i < 9; i++)
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
        set_score(-1);
        is_locked = true;
        is_at_base=true;
        std::cout << "Amazing!! you killed one." << std::endl;
    }
};
class homereachednum
{
     private:
    sf::Texture num_texture[4];
    sf::Sprite home_piece[4];
    sf::Sprite wwindow;
    sf::Texture wtex;
    sf::Sprite dicecolourbox;
    sf::Texture dcb;
    //Coordinates coordinate_ofstore[4]={Coordinates(1017,168),Coordinates(1017,221),Coordinates(1017,62),Coordinates(1017,115)};
    string colour;
    string number[4] = {"1","2","3","4"};
    public:
    void setnumber(string col){
    colour=col;
    string filename,wwin,dicebox;
      if(colour=="yellow"){
        wwin=".\\assets\\yellowwin.png";
        dicebox=".\\assets\\yellowbox.png";
        }
      else if(colour=="green"){
        wwin=".\\assets\\greenwin.png";
        dicebox=".\\assets\\greenbox.png";
        }
      else if(colour=="red"){
        wwin=".\\assets\\redwin.png";
        dicebox=".\\assets\\redbox.png";
        }
      else if(colour=="blue"){
        wwin=".\\assets\\bluewin.png";
        dicebox=".\\assets\\bluebox.png";
        }
        if (!wtex.loadFromFile(wwin))
        {
          std::cout<<"file cannot be loaded"<<std::endl;
        }
        if(!dcb.loadFromFile(dicebox)){
            std::cout<<"file cannot be loaded"<<std::endl;
        }
    wwindow.setTexture(wtex);
    wwindow.setPosition(393,263);
    dicecolourbox.setTexture(dcb);
    dicecolourbox.setPosition(991,437);
    for(int i=0;i<4;i++){
        filename =".\\assets\\"+ number[i] +".png";
        if (!num_texture[i].loadFromFile(filename))
        {
        std::cout<<"file cannot be loaded"<<std::endl;
        }
    home_piece[i].setTexture(num_texture[i]);
    if(colour=="yellow"){
        home_piece[i].setPosition(1020,178);
    }
    else if(colour=="green"){
        home_piece[i].setPosition(1020,231);
    }
    else if(colour=="red"){
        home_piece[i].setPosition(1020,72);
    }
    else if(colour=="blue"){
        home_piece[i].setPosition(1020,125);
    }
      }
    }
    void draw_(int num){
    if(num!=0){
      window.draw(home_piece[num-1]); 
    }
    }
    void draw_winwindow(){
        window.draw(wwindow);
    }
    void draw_dicecolour(){
        window.draw(dicecolourbox);
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
    int number_of_piece_home=0;
    homereachednum home_gotti;
    int allhome=0;
    int imComputer=0;
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
    void checkComputer(Player *players){
            for(int i=0;i<(noOfPlayers-1);i++){
              players[i+1].imComputer=1;
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
        Coordinates center1(622,342);
        int pt = playerTurn;
        int checkPoint = 0;
        filename = ".\\assets\\" + colour + "_disc_1.png";

        int lock = 4;
        for (int i = 0; i < 4; i++)
        {
            if (!players[playerTurn].pieces[i].is_locked)
            {
                if(!players[playerTurn].pieces[i].reached_home)
                  lock--;
            };
        }
        for(int i=0;i<4;i++){
        // if(players[playerTurn].pieces[i].get_coordinates()==center1){
        //                   players[playerTurn].pieces[i].reached_home = true;
        //                   players[playerTurn].pieces[i].is_locked = true;
        //                   players[playerTurn].pieces[i].is_safe = true;
        //                   //std::cout<<"center one is locked!!!"<<std::endl;
        //              }
        if(!players[playerTurn].pieces[i].is_at_base){   
        if((players[playerTurn].pieces[i].get_score()+step) > 56){
             players[playerTurn].pieces[i].is_locked = true;
             //std::cout<<"This piece is locked."<<std::endl;             
        }
        else{
            players[playerTurn].pieces[i].is_locked = false;
        }
        }
        }
        int piece_no;
        if (step == 1)
        {
            hello:
            for (int i = 0; i < 4; i++)
            {
                if(!players[playerTurn].pieces[i].reached_home){
                     pieces[i].set_texture(filename);
                }
         
            }
            //std::cout << "Press your piece to move/withdraw " << std::endl;

            for (int i = 0; i < 4; i++)
            {
                localPosition = sf::Mouse::getPosition(window);
                int pieceX = players[playerTurn].pieces[i].get_coordinates().get_xcoords();
                int pieceY = players[playerTurn].pieces[i].get_coordinates().get_ycoords();
                if ((localPosition.x > pieceX && localPosition.x < pieceX + 40 && localPosition.y > pieceY && localPosition.y < pieceY + 40 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) || players[playerTurn].imComputer==1)
                {
                    diceInfo = 0;
                    dice = 0;
                    dice_turn = 1;
                    piece_no = i;
                    if (pieces[piece_no].reached_home)
                    {   
                        std::cout << " This piece is already home!! " << std::endl;
                        if(!players[playerTurn].imComputer)
                           goto hello;
                        else
                           continue;    
                           
                    }
                    std::cout << piece_no << std::endl;
                    players[playerTurn].pieces[piece_no].is_locked = false;
                    players[playerTurn].pieces[piece_no].is_at_base = false;  
                    players[playerTurn].pieces[piece_no].moveForward(step);
                    checkPoint = 1;
                    filename = ".\\assets\\" + colour + "_disc.png";
                    piece_changed = 1;
                    players[playerTurn].pieces[piece_no].set_score(players[playerTurn].pieces[piece_no].get_score() + step);
                    if(players[playerTurn].pieces[piece_no].reached_home){
                        players[playerTurn].number_of_piece_home+=1;
                        if(players[playerTurn].number_of_piece_home==4){
                            players[playerTurn].allhome=1;
                        }
                    }
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
            //std::cout << "Press your unlocked piece number to move ( ";
            for (int i = 0; i < 4; i++)
            {
                if (!players[playerTurn].pieces[i].is_locked)
                {   
                    if(!players[playerTurn].pieces[i].reached_home){
                    //std::cout << i + 1 << " ";
                    pieces[i].set_texture(filename);
                    }
                }
            }
            //std::cout << ")" << std::endl;

            for (int i = 0; i < 4; i++)
            {
                localPosition = sf::Mouse::getPosition(window);
                int pieceX = players[playerTurn].pieces[i].get_coordinates().get_xcoords();
                int pieceY = players[playerTurn].pieces[i].get_coordinates().get_ycoords();
                if ((localPosition.x > pieceX && localPosition.x < pieceX + 40 && localPosition.y > pieceY && localPosition.y < pieceY + 40 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) || players[playerTurn].imComputer==1)
                {
                    piece_no = i;
                    std::cout << piece_no << std::endl;
                    if (pieces[piece_no].is_locked)
                    {
                        std::cout << "Ohhh!! This piece is locked!!" << std::endl;
                        if(!players[playerTurn].imComputer)
                           goto jump;
                        else
                           continue;
                        
                    }
                    players[playerTurn].pieces[piece_no].moveForward(step);
                    piece_changed = 1;
                    checkPoint = 1;
                    filename = ".\\assets\\" + colour + "_disc.png";
                    players[playerTurn].pieces[piece_no].set_score(players[playerTurn].pieces[piece_no].get_score() + step);
                    player_changed = 0;
                    if (step != 6)
                    {
                        if(!players[playerTurn].pieces[piece_no].reached_home){
                        playerTurn++;
                        player_changed = 1;
                        std::cout << "Player changed 2";
                        }
                        else{
                        players[playerTurn].number_of_piece_home+=1;
                        if(players[playerTurn].number_of_piece_home==4){
                            players[playerTurn].allhome=1;
                        }
                        }

                    }
                    if(step==6){
                        if(players[playerTurn].pieces[piece_no].reached_home){
                        players[playerTurn].number_of_piece_home+=1;
                        if(players[playerTurn].number_of_piece_home==4){
                            players[playerTurn].allhome=1;
                        }
                    }
                    }
                    dice_turn = 1;
                    dice = 0;
                    diceInfo = 0;
                    break;
                }
            }
        }

        if (checkPoint)
        {
            checkPoint = 0;
            std::cout << "Checkpoint entered" << std::endl;
            if (pieces[piece_no].is_safe)
                return;
            for (int i = 0; i < noOfPlayers; i++)
            {
                std::cout << "Checking started for" << i << " " << (i != pt) << std::endl;
                for (int j = 0; j < 4; j++)
                {
                    if ((i != pt) && players[i].pieces[j].get_coordinates() == pieces[piece_no].get_coordinates())
                    {
                        std::cout << "Found" << std::endl;
                        players[i].pieces[j].moveBackward();
                        if (step != 1 && step != 6)
                        {
                            playerTurn--;
                            player_changed = 0;
                        }
                    }
                }
            }
        }
    }
    // }
};

int main()
{
    Coordinates coord11(380, 100), coord12(468, 100), coord13(380, 188), coord14(468, 188);
    Coordinates coord21(776, 100), coord22(864, 100), coord23(776, 188), coord24(864, 188);
    Coordinates coord31(776, 496), coord32(864, 496), coord33(776, 584), coord34(864, 584);
    Coordinates coord41(380, 496), coord42(468, 496), coord43(380, 584), coord44(468, 584);
    int ww=0,player_turn_skipped=0,count=0;
    int computernote=0;
    // Creating dice
    Dice d1;
    string filenames[6];
    for (int i = 0; i < 6; i++)
    {
        string filename = ".\\assets\\Dice_" + dice_order[i] + ".png";
        filenames[i] = filename;
    }
    Coordinates c(1039, 490);
    d1.set_dice(filenames, c);

    // Creating Pieces
    Piece p11, p12, p13, p14;
    Piece p21, p22, p23, p24;
    Piece p31, p32, p33, p34;
    Piece p41, p42, p43, p44;

    string colourOrder[] = {"yellow", "green", "red", "blue"};
    Coordinates coordArr[][4] = {{coord11, coord12, coord13, coord14}, {coord21, coord22, coord23, coord24}, {coord31, coord32, coord33, coord34}, {coord41, coord42, coord43, coord44}};
    Piece pieces[][4] = {{p11, p12, p13, p14}, {p21, p22, p23, p24}, {p31, p32, p33, p34}, {p41, p42, p43, p44}};

    Player *players = new Player[noOfPlayers];
    for (int j = 0; j < noOfPlayers; j++)
    {
        string playerName = "Bipin";
        string filename = ".\\assets\\" + colourOrder[j] + "_disc.png";

        for (int i = 0; i < 4; i++)
        {
            pieces[j][i].set_piece(filename, coordArr[j][i], colourOrder[j]);
        }
        Player player(playerName, colourOrder[j], pieces[j]);
        players[j] = player;
        players[j].home_gotti.setnumber(colourOrder[j]);
    }

    sf::Texture firstInterface;
    sf::Texture secondInterface;
    sf::Texture secondComputerinterface;
    sf::Texture ludoBoard;
    sf::Texture frame;

    if (!firstInterface.loadFromFile(".\\assets\\Frame_1.png"))
    {
        return -1;
    }

    if (!secondInterface.loadFromFile(".\\assets\\Frame_2.png"))
    {
        return -1;
    }

    if(!secondComputerinterface.loadFromFile(".\\assets\\Frame_2comp.png"))
    {
        return -1;
    }

    if (!ludoBoard.loadFromFile(".\\assets\\ludo_mini.png"))
    {
        return -1;
    }

    if (!frame.loadFromFile(".\\assets\\frame.png"))
    {
        return -1;
    }

    // Set the position of the sprite
    sf::Sprite firstInterfaceSprite;
    firstInterfaceSprite.setTexture(firstInterface);

    sf::Sprite secondInterfaceSprite;
    secondInterfaceSprite.setTexture(secondInterface);

    sf::Sprite secondComputerinterfaceSprite;
    secondComputerinterfaceSprite.setTexture(secondComputerinterface);

    sf::Sprite ludoBoardSprite;
    ludoBoardSprite.setTexture(ludoBoard);

    sf::Sprite frameSprite;
    frameSprite.setTexture(frame);
    frameSprite.setPosition(308, 28);

    // variables for Interface display
    int firstInt = 1;
    int secondInt = 0;
    int ludoBoardInt = 0;

    string file = ".\\assets\\Dice_" + dice_order[step - 1] + ".png";
    sf::Texture diceTexture;
    if (!diceTexture.loadFromFile(file))
    {
        std::cout << "File cant be loaded: " << file << std::endl;
        return -1;
    }
    diceSprite.setTexture(diceTexture);
    diceSprite.setPosition(1039, 490);
    int dice_display = 0;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      
        window.clear();
        if (firstInt)
        {
            dice_display = 0;
            window.draw(firstInterfaceSprite);
            localPosition = sf::Mouse::getPosition(window);
            if (localPosition.x > 46 && localPosition.x < 366 && localPosition.y > 462 && localPosition.y < 563 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                firstInt = 0;
                secondInt = 1;
            }
            if (localPosition.x > 46 && localPosition.x < 366 && localPosition.y > 337 && localPosition.y < 438 && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                firstInt = 0;
                secondInt = 1;
                computerishere=1;
            }
        }

        if (secondInt)
        {
            dice_display = 0;
            if(computerishere)
            {
                window.draw(secondComputerinterfaceSprite);
            }
            else
            {
                window.draw(secondInterfaceSprite);
            }

            localPosition = sf::Mouse::getPosition(window);
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                computernote=1;
            }
            
            if (localPosition.x > 138 && localPosition.x < 229 && localPosition.y > 351 && localPosition.y < 452 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))&&computernote==1)
            {
                secondInt = 0;
                ludoBoardInt = 1;
                noOfPlayers = 2;
            }
           
            if (localPosition.x > 229 && localPosition.x < 319 && localPosition.y > 351 && localPosition.y < 452 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))&&computernote==1)
            {
                secondInt = 0;
                ludoBoardInt = 1;
                noOfPlayers = 3;
            }
            if (localPosition.x > 319 && localPosition.x < 409 && localPosition.y > 351 && localPosition.y < 452 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))&&computernote==1)
            {
                secondInt = 0;
                ludoBoardInt = 1;
                noOfPlayers = 4;
            }
        }
      
        if (ludoBoardInt)
        {
            window.draw(ludoBoardSprite);
            window.draw(frameSprite);
            players[playerTurn].home_gotti.draw_dicecolour();
            dice_display = 1;
            if(computerishere){
                players[playerTurn].checkComputer(players);
                computerishere=0;
            }
            for (int i=0,j=(playerTurn+1)%noOfPlayers; i < noOfPlayers; i++,j++)
            {   
                if(j>(noOfPlayers-1)){
                    j=j%noOfPlayers;
                }
                players[j].draw();
                players[j].home_gotti.draw_(players[j].number_of_piece_home);
            }
            
            if (!diceInfo)
            {
                std::cout << "\n********** " << colourOrder[playerTurn] << "'s turn **************" << std::endl;
                std::cout << "Press dice to roll.." << std::endl;
                diceInfo = 1;
            }

            localPosition = sf::Mouse::getPosition(window);
            if ((dice_turn  == 1 && localPosition.x < 1201 && localPosition.x > 1001 && localPosition.y < 673 && localPosition.y > 443 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) || (players[playerTurn].imComputer  && dice_turn==1))
            {

                dice_turn = 0;
                dice = 1;
                d1.dice_roll();

                std::cout << "Dice Rolled: " << step << std::endl;
                
            }

            //*****************************************************************************************
            if (dice == 1)
            {   
                
                players[playerTurn].roll(playerTurn, players, step);   
                playerTurn = playerTurn % noOfPlayers;
                frameSprite.setPosition(frame_position[playerTurn][0], frame_position[playerTurn][1]);
            }
             if(players[playerTurn].number_of_piece_home==4 && players[playerTurn].allhome==0){
                    int i=playerTurn-1;
                    if(i==-1)
                     { i=noOfPlayers-1;}
                    filename = ".\\assets\\" + colourOrder[i] + "_disc.png";
                    playerTurn++;
                    player_turn_skipped=1;
                    playerTurn = playerTurn % noOfPlayers;
                    frameSprite.setPosition(frame_position[playerTurn][0], frame_position[playerTurn][1]);
                   
                }
               
            if (piece_changed)
            {
                int turn = playerTurn;
                std::cout << player_changed << std::endl;
                if(player_changed==1 && player_turn_skipped==1){
                    turn=turn-2;
                }
                else if (player_changed)
                      turn--;
                if (turn == -1)
                    turn = noOfPlayers - 1;
                if(turn==-2)
                    turn=noOfPlayers-2;    
                    
                for (int i = 0; i < 4; i++)
                {
                    players[turn].pieces[i].set_texture(filename);
                }
                piece_changed = 0;
                player_changed = 0;
                ww=turn;
            }
            for(int i=0;i<noOfPlayers;i++){
               if(players[i].number_of_piece_home==4){
                        count++;
               }
            }
            if(count == noOfPlayers){
                std::cout<<"GAME OVER!!"<<std::endl;
                window.close();
            }  
            if(players[ww].allhome){
                    players[ww].home_gotti.draw_winwindow();
                    localPosition=sf::Mouse::getPosition(window);
                    if (localPosition.x > 422 && localPosition.x < 523 && localPosition.y > 380 && localPosition.y < 422 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                        players[ww].allhome=0;
                    }
                    else if(localPosition.x > 758 && localPosition.x < 859 && localPosition.y > 382 && localPosition.y < 424 && (sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                        window.close();
                    }
                    
                }
            
        }

        if (dice_display)
            window.draw(diceSprite);

        window.display();
        
    }

    return 0;
}