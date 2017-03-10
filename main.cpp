/*
*
-COP3503
-Project Group 9 
-See report for names
-Description: Poker and Blackjack
-Used SFML for the GUI and is required to run the program
*
*
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <ctime>

#include "game.h"
using namespace std;

int main()
{   
    
    srand( time(NULL) ); //to get different seeds for random cards
    //Create some universal variables
    int tableBet = 0;
    int betValue = 0;
    int roundCounter = 0;
    int bufferCounter = 0;
    int pot = 0; //the table pot
    

    //Window and table ----------------------
    sf::RenderWindow menu(sf::VideoMode(500, 900), "Decide");
    sf::RenderWindow window;
    sf::RenderWindow blackJackWindow;
    sf::RectangleShape table(sf::Vector2f(1500,700));
    table.setFillColor(sf::Color(0,102,0));
    table.setPosition(50,50);
    window.setFramerateLimit(60);
    blackJackWindow.setFramerateLimit(60);
    menu.setFramerateLimit(30);

    //Font
    sf::Font theFont;
    if(!theFont.loadFromFile("tahoma.ttf"))
    {
        return -2;
    }

    //texture for back of cards-------------------------------
    sf::Texture cardBack;
    if(!cardBack.loadFromFile("cardBack.jpg"))
        return -1;

    //texture for pile of chips
    sf::Texture chipPile;
    if(!chipPile.loadFromFile("chipPile.png"))
        return -1;

    //deck Sprite
    sf::Sprite deckSprite;
    deckSprite.setOrigin(sf::Vector2f(70,99));
    deckSprite.setTexture(cardBack);
    deckSprite.setPosition(sf::Vector2f(480,400));
    deckSprite.setScale(sf::Vector2f(0.8f,0.8f));

    //Load the card textures from file
        sf::Texture c2;
        if(!c2.loadFromFile("2_of_clubs.png"))
            return -1;
        sf::Texture d2;
        if(!d2.loadFromFile("2_of_diamonds.png"))
            return -1;
        sf::Texture h2;
        if(!h2.loadFromFile("2_of_hearts.png"))
            return -1;
        sf::Texture s2;
        if(!s2.loadFromFile("2_of_spades.png"))
            return -1;
        sf::Texture c3;
        if(!c3.loadFromFile("3_of_clubs.png"))
            return -1;
        sf::Texture d3;
        if(!d3.loadFromFile("3_of_diamonds.png"))
            return -1;
        sf::Texture h3;
        if(!h3.loadFromFile("3_of_hearts.png"))
            return -1;
        sf::Texture s3;
        if(!s3.loadFromFile("3_of_spades.png"))
            return -1;
        sf::Texture c4;
        if(!c4.loadFromFile("4_of_clubs.png"))
            return -1;
        sf::Texture d4;
        if(!d4.loadFromFile("4_of_diamonds.png"))
            return -1;
        sf::Texture h4;
        if(!h4.loadFromFile("4_of_hearts.png"))
            return -1;
        sf::Texture s4;
        if(!s4.loadFromFile("4_of_spades.png"))
            return -1;
        sf::Texture c5;
        if(!c5.loadFromFile("5_of_clubs.png"))
            return -1;
        sf::Texture d5;
        if(!d5.loadFromFile("5_of_diamonds.png"))
            return -1;
        sf::Texture h5;
        if(!h5.loadFromFile("5_of_hearts.png"))
            return -1;
        sf::Texture s5;
        if(!s5.loadFromFile("5_of_spades.png"))
            return -1;
        sf::Texture c6;
        if(!c6.loadFromFile("6_of_clubs.png"))
            return -1;
        sf::Texture d6;
        if(!d6.loadFromFile("6_of_diamonds.png"))
            return -1;
        sf::Texture h6;
        if(!h6.loadFromFile("6_of_hearts.png"))
            return -1;
        sf::Texture s6;
        if(!s6.loadFromFile("6_of_spades.png"))
            return -1;
        sf::Texture c7;
        if(!c7.loadFromFile("7_of_clubs.png"))
            return -1;
        sf::Texture d7;
        if(!d7.loadFromFile("7_of_diamonds.png"))
            return -1;
        sf::Texture h7;
        if(!h7.loadFromFile("7_of_hearts.png"))
            return -1;
        sf::Texture s7;
        if(!s7.loadFromFile("7_of_spades.png"))
            return -1;
        sf::Texture c8;
        if(!c8.loadFromFile("8_of_clubs.png"))
            return -1;
        sf::Texture d8;
        if(!d8.loadFromFile("8_of_diamonds.png"))
            return -1;
        sf::Texture h8;
        if(!h8.loadFromFile("8_of_hearts.png"))
            return -1;
        sf::Texture s8;
        if(!s8.loadFromFile("8_of_spades.png"))
            return -1;
        sf::Texture c9;
        if(!c9.loadFromFile("9_of_clubs.png"))
            return -1;
        sf::Texture d9;
        if(!d9.loadFromFile("9_of_diamonds.png"))
            return -1;
        sf::Texture h9;
        if(!h9.loadFromFile("9_of_hearts.png"))
            return -1;
        sf::Texture s9;
        if(!s9.loadFromFile("9_of_spades.png"))
            return -1;
        sf::Texture c10;
        if(!c10.loadFromFile("10_of_clubs.png"))
            return -1;
        sf::Texture d10;
        if(!d10.loadFromFile("10_of_diamonds.png"))
            return -1;
        sf::Texture h10;
        if(!h10.loadFromFile("10_of_hearts.png"))
            return -1;
        sf::Texture s10;
        if(!s10.loadFromFile("10_of_spades.png"))
            return -1;
        sf::Texture c1;
        if(!c1.loadFromFile("ace_of_clubs.png"))
            return -1;
        sf::Texture d1;
        if(!d1.loadFromFile("ace_of_diamonds.png"))
            return -1;
        sf::Texture h1;
        if(!h1.loadFromFile("ace_of_hearts.png"))
            return -1;
        sf::Texture s1;
        if(!s1.loadFromFile("ace_of_spades.png"))
            return -1;
        sf::Texture c11;
        if(!c11.loadFromFile("jack_of_clubs.png"))
            return -1;
        sf::Texture d11;
        if(!d11.loadFromFile("jack_of_diamonds.png"))
            return -1;
        sf::Texture h11;
        if(!h11.loadFromFile("jack_of_hearts.png"))
            return -1;
        sf::Texture s11;
        if(!s11.loadFromFile("jack_of_spades.png"))
            return -1;
        sf::Texture c12;
        if(!c12.loadFromFile("queen_of_clubs.png"))
            return -1;
        sf::Texture d12;
        if(!d12.loadFromFile("queen_of_diamonds.png"))
            return -1;
        sf::Texture h12;
        if(!h12.loadFromFile("queen_of_hearts.png"))
            return -1;
        sf::Texture s12;
        if(!s12.loadFromFile("queen_of_spades.png"))
            return -1;
        sf::Texture c13;
        if(!c13.loadFromFile("king_of_clubs.png"))
            return -1;
        sf::Texture d13;
        if(!d13.loadFromFile("king_of_diamonds.png"))
            return -1;
        sf::Texture h13;
        if(!h13.loadFromFile("king_of_hearts.png"))
            return -1;
        sf::Texture s13;
        if(!s13.loadFromFile("king_of_spades.png"))
            return -1;

    //Unordered map of card value to texture
    //Used to link card.getRank() to a texture
    unordered_map< string , sf::Texture> cardMap = {
        {"c1", c1},
        {"d1", d1},
        {"h1", h1},
        {"s1", s1},
        {"c2", c2},
        {"d2", d2},
        {"h2", h2},
        {"s2", s2},
        {"c3", c3},
        {"d3", d3},
        {"h3", h3},
        {"s3", s3},
        {"c4", c4},
        {"d4", d4},
        {"h4", h4},
        {"s4", s4},
        {"c5", c5},
        {"d5", d5},
        {"h5", h5},
        {"s5", s5},
        {"c6", c6},
        {"d6", d6},
        {"h6", h6},
        {"s6", s6},
        {"c7", c7},
        {"d7", d7},
        {"h7", h7},
        {"s7", s7},
        {"c8", c8},
        {"d8", d8},
        {"h8", h8},
        {"s8", s8},
        {"c9", c9},
        {"d9", d9},
        {"h9", h9},
        {"s9", s9},
        {"c10", c10},
        {"d10", d10},
        {"h10", h10},
        {"s10", s10},
        {"c11", c11},
        {"d11", d11},
        {"h11", h11},
        {"s11", s11},
        {"c12", c12},
        {"d12", d12},
        {"h12", h12},
        {"s12", s12},
        {"c13", c13},
        {"d13", d13},
        {"h13", h13},
        {"s13", s13}
    };


    //Player hand sprites
    sf::Sprite userHand1;
    sf::Sprite userHand2;
    userHand1.setOrigin(sf::Vector2f(250,363));
    userHand2.setOrigin(sf::Vector2f(250,363));
    userHand1.setPosition(sf::Vector2f(700,750));
    userHand2.setPosition(sf::Vector2f(850,750));
    userHand1.setScale(sf::Vector2f(0.224f,0.224f));
    userHand2.setScale(sf::Vector2f(0.224f,0.224f));

    //ai SPRITES for poker-------------------------------------------------------
    sf::Sprite topHand1;
    sf::Sprite topHand2;
    topHand1.setOrigin(sf::Vector2f(250,363));
    topHand2.setOrigin(sf::Vector2f(250,363));
    topHand1.setPosition(sf::Vector2f(700,160));
    topHand2.setPosition(sf::Vector2f(850,160));
    topHand1.setScale(sf::Vector2f(0.224f,0.224f));
    topHand2.setScale(sf::Vector2f(0.224f,0.224f));
    sf::Sprite topCoverHand1;
    sf::Sprite topCoverHand2;
    topCoverHand1.setOrigin(sf::Vector2f(70,99));
    topCoverHand2.setOrigin(sf::Vector2f(70,99));
    topCoverHand1.setTexture(cardBack); 
    topCoverHand2.setTexture(cardBack);
    topCoverHand1.setPosition(sf::Vector2f(700,160));
    topCoverHand2.setPosition(sf::Vector2f(850,160));
    topCoverHand1.setScale(sf::Vector2f(0.8f,0.8f));
    topCoverHand2.setScale(sf::Vector2f(0.8f,0.8f));

    sf::Sprite leftHand1;
    sf::Sprite leftHand2;
    leftHand1.setOrigin(sf::Vector2f(250,363));
    leftHand2.setOrigin(sf::Vector2f(250,363));
    leftHand1.setRotation(90);
    leftHand2.setRotation(270);
    leftHand1.setPosition(sf::Vector2f(160,300));
    leftHand2.setPosition(sf::Vector2f(160,450));
    leftHand1.setScale(sf::Vector2f(0.224f,0.224f));
    leftHand2.setScale(sf::Vector2f(0.224f,0.224f));
    sf::Sprite leftCoverHand1;
    sf::Sprite leftCoverHand2;
    leftCoverHand1.setOrigin(sf::Vector2f(70,99));
    leftCoverHand2.setOrigin(sf::Vector2f(70,99));
    leftCoverHand1.setRotation(90);
    leftCoverHand2.setRotation(270);
    leftCoverHand1.setTexture(cardBack); 
    leftCoverHand2.setTexture(cardBack);
    leftCoverHand1.setPosition(sf::Vector2f(160,300));
    leftCoverHand2.setPosition(sf::Vector2f(160,450));
    leftCoverHand1.setScale(sf::Vector2f(0.8f,0.8f));
    leftCoverHand2.setScale(sf::Vector2f(0.8f,0.8f));

    sf::Sprite rightHand1;
    sf::Sprite rightHand2;
    rightHand1.setOrigin(sf::Vector2f(250,363));
    rightHand2.setOrigin(sf::Vector2f(250,363));
    rightHand1.setRotation(90);
    rightHand2.setRotation(270);
    rightHand1.setPosition(sf::Vector2f(1440,300));
    rightHand2.setPosition(sf::Vector2f(1440,450));
    rightHand1.setScale(sf::Vector2f(0.224f,0.224f));
    rightHand2.setScale(sf::Vector2f(0.224f,0.224f));
    sf::Sprite rightCoverHand1;
    sf::Sprite rightCoverHand2;
    rightCoverHand1.setOrigin(sf::Vector2f(70,99));
    rightCoverHand2.setOrigin(sf::Vector2f(70,99));
    rightCoverHand1.setRotation(90);
    rightCoverHand2.setRotation(270);
    rightCoverHand1.setTexture(cardBack); 
    rightCoverHand2.setTexture(cardBack);
    rightCoverHand1.setPosition(sf::Vector2f(1440,300));
    rightCoverHand2.setPosition(sf::Vector2f(1440,450));
    rightCoverHand1.setScale(sf::Vector2f(0.8f,0.8f));
    rightCoverHand2.setScale(sf::Vector2f(0.8f,0.8f));

    sf::Sprite river1;
    sf::Sprite river2;
    sf::Sprite river3;
    river1.setOrigin(sf::Vector2f(250,363));
    river2.setOrigin(sf::Vector2f(250,363));
    river3.setOrigin(sf::Vector2f(250,363));
    river1.setPosition(sf::Vector2f(600,400));
    river2.setPosition(sf::Vector2f(715,400));
    river3.setPosition(sf::Vector2f(830,400));
    river1.setScale(sf::Vector2f(0.224f,0.224f));
    river2.setScale(sf::Vector2f(0.224f,0.224f));
    river3.setScale(sf::Vector2f(0.224f,0.224f));

    sf::Sprite river4;
    sf::Sprite river5;
    river4.setOrigin(sf::Vector2f(250,363));
    river5.setOrigin(sf::Vector2f(250,363));
    river4.setPosition(sf::Vector2f(945,400));
    river5.setPosition(sf::Vector2f(1060,400));
    river4.setScale(sf::Vector2f(0.224f,0.224f));
    river5.setScale(sf::Vector2f(0.224f,0.224f));
    
    //Black Jack card sprites----------------------------------
    sf::Sprite topCardCover;
    sf::Sprite topCard1;
    sf::Sprite topCard2;
    sf::Sprite topCard3;
    sf::Sprite topCard4;
    sf::Sprite topCard5;
    sf::Sprite topCard6;
    sf::Sprite topCard7;
    sf::Sprite topCard8;
    sf::Sprite topCard9;
    sf::Sprite topCard10;
    sf::Sprite topCard11;
    sf::Sprite userCard1;
    sf::Sprite userCard2;
    sf::Sprite userCard3;
    sf::Sprite userCard4;
    sf::Sprite userCard5;
    sf::Sprite userCard6;
    sf::Sprite userCard7;
    sf::Sprite userCard8;
    sf::Sprite userCard9;
    sf::Sprite userCard10;
    sf::Sprite userCard11;

    topCardCover.setOrigin(sf::Vector2f(70,99));
    topCardCover.setTexture(cardBack); 
    topCardCover.setPosition(sf::Vector2f(500,160));
    topCardCover.setScale(sf::Vector2f(0.8f,0.8f));
    
    
    topCard1.setOrigin(sf::Vector2f(250,363));
    topCard2.setOrigin(sf::Vector2f(250,363));
    topCard3.setOrigin(sf::Vector2f(250,363));
    topCard4.setOrigin(sf::Vector2f(250,363));
    topCard5.setOrigin(sf::Vector2f(250,363));
    topCard6.setOrigin(sf::Vector2f(250,363));
    topCard7.setOrigin(sf::Vector2f(250,363));
    topCard8.setOrigin(sf::Vector2f(250,363));
    topCard9.setOrigin(sf::Vector2f(250,363));
    topCard10.setOrigin(sf::Vector2f(250,363));
    topCard11.setOrigin(sf::Vector2f(250,363));
    
    
    topCard1.setPosition(sf::Vector2f(500,160));
    topCard2.setPosition(sf::Vector2f(550,160));
    topCard3.setPosition(sf::Vector2f(600,160));
    topCard4.setPosition(sf::Vector2f(650,160));
    topCard5.setPosition(sf::Vector2f(700,160));
    topCard6.setPosition(sf::Vector2f(750,160));
    topCard7.setPosition(sf::Vector2f(800,160));
    topCard8.setPosition(sf::Vector2f(850,160));
    topCard9.setPosition(sf::Vector2f(900,160));
    topCard10.setPosition(sf::Vector2f(950,160));
    topCard11.setPosition(sf::Vector2f(1000,160));
    
    topCard1.setScale(sf::Vector2f(0.224f,0.224f));
    topCard2.setScale(sf::Vector2f(0.224f,0.224f));
    topCard3.setScale(sf::Vector2f(0.224f,0.224f));
    topCard4.setScale(sf::Vector2f(0.224f,0.224f));
    topCard5.setScale(sf::Vector2f(0.224f,0.224f));
    topCard6.setScale(sf::Vector2f(0.224f,0.224f));
    topCard7.setScale(sf::Vector2f(0.224f,0.224f));
    topCard8.setScale(sf::Vector2f(0.224f,0.224f));
    topCard9.setScale(sf::Vector2f(0.224f,0.224f));
    topCard10.setScale(sf::Vector2f(0.224f,0.224f));
    topCard11.setScale(sf::Vector2f(0.224f,0.224f));
    
    
    userCard1.setOrigin(sf::Vector2f(250,363));
    userCard2.setOrigin(sf::Vector2f(250,363));
    userCard3.setOrigin(sf::Vector2f(250,363));
    userCard4.setOrigin(sf::Vector2f(250,363));
    userCard5.setOrigin(sf::Vector2f(250,363));
    userCard6.setOrigin(sf::Vector2f(250,363));
    userCard7.setOrigin(sf::Vector2f(250,363));
    userCard8.setOrigin(sf::Vector2f(250,363));
    userCard9.setOrigin(sf::Vector2f(250,363));
    userCard10.setOrigin(sf::Vector2f(250,363));
    userCard11.setOrigin(sf::Vector2f(250,363));
    
    userCard1.setPosition(sf::Vector2f(500,750));
    userCard2.setPosition(sf::Vector2f(550,750));
    userCard3.setPosition(sf::Vector2f(600,750));
    userCard4.setPosition(sf::Vector2f(650,750));
    userCard5.setPosition(sf::Vector2f(700,750));
    userCard6.setPosition(sf::Vector2f(750,750));
    userCard7.setPosition(sf::Vector2f(800,750));
    userCard8.setPosition(sf::Vector2f(850,750));
    userCard9.setPosition(sf::Vector2f(900,750));
    userCard10.setPosition(sf::Vector2f(950,750));
    userCard11.setPosition(sf::Vector2f(1000,750));
    
    userCard1.setScale(sf::Vector2f(0.224f,0.224f));
    userCard2.setScale(sf::Vector2f(0.224f,0.224f));
    userCard3.setScale(sf::Vector2f(0.224f,0.224f));
    userCard4.setScale(sf::Vector2f(0.224f,0.224f));
    userCard5.setScale(sf::Vector2f(0.224f,0.224f));
    userCard6.setScale(sf::Vector2f(0.224f,0.224f));
    userCard7.setScale(sf::Vector2f(0.224f,0.224f));
    userCard8.setScale(sf::Vector2f(0.224f,0.224f));
    userCard9.setScale(sf::Vector2f(0.224f,0.224f));
    userCard10.setScale(sf::Vector2f(0.224f,0.224f));
    userCard11.setScale(sf::Vector2f(0.224f,0.224f));

    //Button Sprites
    sf::Texture buttonTexture;
    if (!buttonTexture.create(100, 50))
    {
        return -1;
    }

   // Creates button to choose Poker game
    sf::Sprite menuPoker;
    menuPoker.setOrigin(50,25);
    menuPoker.setTexture(buttonTexture);
    menuPoker.setPosition(250,375);
    menuPoker.setScale(sf::Vector2f(1.1f,1.0f));
    
    sf::RectangleShape rectanglePoker(sf::Vector2f(100,50));
    rectanglePoker.setOrigin(50,25);
    rectanglePoker.setPosition(sf::Vector2f(250,373));
    rectanglePoker.setScale(sf::Vector2f(1.1f,1.0f));
    rectanglePoker.setFillColor(sf::Color(255, 255, 255, 128));
    
    //Creates button to choose Black Jack game
    sf::Sprite menuBlackJack;
    menuBlackJack.setOrigin(50,25);
    menuBlackJack.setTexture(buttonTexture);
    menuBlackJack.setPosition(256,473);
    menuBlackJack.setScale(sf::Vector2f(1.1f,1.0f));
    
    sf::RectangleShape rectangleBlackJack(sf::Vector2f(100,50));
    rectangleBlackJack.setOrigin(50,25);
    rectangleBlackJack.setPosition(sf::Vector2f(256,473));
    rectangleBlackJack.setScale(sf::Vector2f(1.7f,1.0f));
    rectangleBlackJack.setFillColor(sf::Color(255, 255, 255, 128));

    //Create button to fold
    sf::Sprite foldSprite;
    foldSprite.setTexture(buttonTexture);
    foldSprite.setPosition(sf::Vector2f(160, 760));
    foldSprite.setScale(sf::Vector2f(1.1f,1.0f));;
    
    sf::RectangleShape rectangleFold(sf::Vector2f(100, 50));
    rectangleFold.setPosition(sf::Vector2f(160, 760));
    rectangleFold.setScale(sf::Vector2f(1.1f,1.0f));
    rectangleFold.setFillColor(sf::Color(255, 255, 255, 128));
    
    //Create button to call
    sf::Sprite callSprite;
    callSprite.setTexture(buttonTexture);
    callSprite.setPosition(sf::Vector2f(300, 760));
    callSprite.setScale(sf::Vector2f(.92f,1.0f));
    
    sf::RectangleShape rectangleCall(sf::Vector2f(100, 50));
    rectangleCall.setPosition(sf::Vector2f(300, 760));
    rectangleCall.setFillColor(sf::Color(255, 255, 255, 128));
    
    //Create button to raise
    sf::Sprite raiseSprite;
    raiseSprite.setTexture(buttonTexture);
    raiseSprite.setPosition(sf::Vector2f(430, 760));
    raiseSprite.setScale(sf::Vector2f(1.2f,.98f));

    sf::RectangleShape rectangleRaise(sf::Vector2f(100, 50));
    rectangleRaise.setPosition(sf::Vector2f(430, 760));
    rectangleRaise.setScale(sf::Vector2f(1.2f,.98f));
    rectangleRaise.setFillColor(sf::Color(255, 255, 255, 128));

    //Create poker chip pile sprite
    sf::Sprite pileSprite;
    pileSprite.setTexture(chipPile);
    pileSprite.setPosition(200,400);
    pileSprite.setScale(sf::Vector2f(0.1f,0.1f));

    //Create poker chip pile sprite
    sf::Sprite pileSprite2;
    pileSprite2.setTexture(chipPile);
    pileSprite2.setPosition(1300,400);
    pileSprite2.setScale(sf::Vector2f(0.1f,0.1f));

    //Create poker chip pile sprite
    sf::Sprite pileSprite3;
    pileSprite3.setTexture(chipPile);
    pileSprite3.setPosition(800,200);
    pileSprite3.setScale(sf::Vector2f(0.1f,0.1f));
    
    //Creates button to add 1 when betting
    sf::Sprite oneSprite;
    oneSprite.setTexture(buttonTexture);
    oneSprite.setPosition(sf::Vector2f(1200, 600));
    oneSprite.setScale(sf::Vector2f(0.90f,.98f));
    
    //Creates button to add 10 when betting
    sf::Sprite tenSprite;
    tenSprite.setTexture(buttonTexture);
    tenSprite.setPosition(sf::Vector2f(1290, 600));
    tenSprite.setScale(sf::Vector2f(1.2f,.98f));
    
    //Creates button to add 100 when betting
    sf::Sprite hundredSprite;
    hundredSprite.setTexture(buttonTexture);
    hundredSprite.setPosition(sf::Vector2f(1400, 600));
    hundredSprite.setScale(sf::Vector2f(1.2f,.98f));
    
    //Creates button to bet for Black Jack game
    sf::Sprite betSpriteBlackJack;
    betSpriteBlackJack.setTexture(buttonTexture);
    betSpriteBlackJack.setPosition(sf::Vector2f(400, 450));
    betSpriteBlackJack.setScale(sf::Vector2f(1.2f,.98f));
    
    sf::RectangleShape rectangleBetBlackJack(sf::Vector2f(100, 50));
    rectangleBetBlackJack.setPosition(sf::Vector2f(400, 450));
    rectangleBetBlackJack.setScale(sf::Vector2f(1.2f,.98f));
    rectangleBetBlackJack.setFillColor(sf::Color(255, 255, 255, 128));
    
    //Cover for bet button after user bets
    sf::RectangleShape rectangleBetBlackJackCover(sf::Vector2f(100, 50));
    rectangleBetBlackJackCover.setPosition(sf::Vector2f(400, 450));
    rectangleBetBlackJackCover.setScale(sf::Vector2f(1.2f,.98f));
    rectangleBetBlackJackCover.setFillColor(sf::Color(0,102,0));
    
    //Creates button to hit
    sf::Sprite hitSprite;
    hitSprite.setTexture(buttonTexture);
    hitSprite.setPosition(sf::Vector2f(700, 450));
    hitSprite.setScale(sf::Vector2f(1.2f,.98f));
    
    sf::RectangleShape rectangleHit(sf::Vector2f(100, 50));
    rectangleHit.setPosition(sf::Vector2f(700, 450));
    rectangleHit.setScale(sf::Vector2f(1.2f,.98f));
    rectangleHit.setFillColor(sf::Color(255, 255, 255, 128));

    //Cover for hit button after user stands
    sf::RectangleShape rectangleHitCover(sf::Vector2f(100, 50));
    rectangleHitCover.setPosition(sf::Vector2f(700, 450));
    rectangleHitCover.setScale(sf::Vector2f(1.2f,.98f));
    rectangleHitCover.setFillColor(sf::Color(0,102,0));
    
   //Creates button to stand
    sf::Sprite standSpriteBlackJack;
    standSpriteBlackJack.setTexture(buttonTexture);
    standSpriteBlackJack.setPosition(sf::Vector2f(1000, 450));
    standSpriteBlackJack.setScale(sf::Vector2f(1.2f,.98f));
    
    sf::RectangleShape rectangleStandBlackJack(sf::Vector2f(100, 50));
    rectangleStandBlackJack.setPosition(sf::Vector2f(1000, 450));
    rectangleStandBlackJack.setScale(sf::Vector2f(1.4f,.98f));
    rectangleStandBlackJack.setFillColor(sf::Color(255, 255, 255, 128));

    sf::RectangleShape rectangleStandBlackJackCover(sf::Vector2f(100, 50));
    rectangleStandBlackJackCover.setPosition(sf::Vector2f(1000, 450));
    rectangleStandBlackJackCover.setScale(sf::Vector2f(1.4f,.98f));
    rectangleStandBlackJackCover.setFillColor(sf::Color(0,102,0));

    //Text
    sf::Text Wallet;
    Wallet.setFont(theFont);
    Wallet.setString("Your wallet: ");
    Wallet.setCharacterSize(24);
    Wallet.setFillColor(sf::Color(0,0,0));
    Wallet.setPosition(sf::Vector2f(420,650));

    //Creates text to print out user's wallet for Black jack
    sf::Text blackJackWallet;
    blackJackWallet.setFont(theFont);
    blackJackWallet.setString("Your wallet: ");
    blackJackWallet.setCharacterSize(24);
    blackJackWallet.setFillColor(sf::Color(0,0,0));
    blackJackWallet.setPosition(sf::Vector2f(220,650));

    //Poker Chip
    sf::Texture pokerChip;
    if(!pokerChip.loadFromFile("pChip.png"))
        return -1;
    sf::Sprite chip;
    chip.setOrigin(sf::Vector2f(22.5,209.5));
    chip.setTexture(pokerChip);
    chip.setPosition(sf::Vector2f(980,775));
    chip.setScale(sf::Vector2f(0.33f,0.33f));

    //Total money
    sf::Text Dollar;
    Dollar.setFont(theFont);
    Dollar.setCharacterSize(24);
    Dollar.setFillColor(sf::Color(0,0,0));
    Dollar.setPosition(sf::Vector2f(480,680));

    //Creates text to display the amount of cash user has in wallet for Black jack
    sf::Text blackJackDollar;
    blackJackDollar.setFont(theFont);
    blackJackDollar.setCharacterSize(24);
    blackJackDollar.setFillColor(sf::Color(0,0,0));
    blackJackDollar.setPosition(sf::Vector2f(280,680));

    //Current bet value
    sf:: Text yourBet;
    yourBet.setFont(theFont);
    yourBet.setString("Your bet: ");
    yourBet.setCharacterSize(24);
    yourBet.setFillColor(sf::Color(0,0,0));
    yourBet.setPosition(sf::Vector2f(975,650));
    
    //Creates text to display user's bet value
    sf::Text Bet; 
    Bet.setFont(theFont);
    Bet.setCharacterSize(24);
    Bet.setString("$" + to_string(betValue));
    Bet.setFillColor(sf::Color(0,0,0));
    Bet.setPosition(sf::Vector2f(1040,750));
    
    //Text for fold button for Poker
    sf:: Text Fold;
    Fold.setFont(theFont);
    Fold.setString("FOLD");
    Fold.setCharacterSize(40);
    Fold.setFillColor(sf::Color(255,255,255));
    Fold.setPosition(sf::Vector2f(167, 760));
    
    //Text for call button for Poker
    sf:: Text Call;
    Call.setFont(theFont);
    Call.setString("CALL");
    Call.setCharacterSize(40);
    Call.setFillColor(sf::Color(255,255,255));
    Call.setPosition(sf::Vector2f(307, 760));
    
    //Text for raise button for Poker
    sf:: Text Raise;
    Raise.setFont(theFont);
    Raise.setString("RAISE");
    Raise.setCharacterSize(40);
    Raise.setFillColor(sf::Color(255,255,255));
    Raise.setPosition(sf::Vector2f(437, 760));

    //Text for adding $1 to user's bet
    sf::Text plusOne;
    plusOne.setFont(theFont);
    plusOne.setString("+1");
    plusOne.setCharacterSize(40);
    plusOne.setFillColor(sf::Color(255,255,255));
    plusOne.setPosition(sf::Vector2f(1200, 600));

     //Text for adding $10 to user's bet
    sf::Text plusTen;
    plusTen.setFont(theFont);
    plusTen.setString("+10");
    plusTen.setCharacterSize(40);
    plusTen.setFillColor(sf::Color(255,255,255));
    plusTen.setPosition(sf::Vector2f(1290, 600));
    
     //Text for adding $100 to user's bet
    sf::Text plusHundred;
    plusHundred.setFont(theFont);
    plusHundred.setString("+100");
    plusHundred.setCharacterSize(40);
    plusHundred.setFillColor(sf::Color(255,255,255));
    plusHundred.setPosition(sf::Vector2f(1400, 600));

    //Text for Menu title
    sf::Text menuTitle;
    menuTitle.setFont(theFont);
    menuTitle.setString("MENU");
    menuTitle.setCharacterSize(50);
    menuTitle.setFillColor(sf::Color(255,255,255));
    menuTitle.setPosition(sf::Vector2f(185,200));

    //Text for the pot
    sf::Text thePot;
    thePot.setFont(theFont);
    thePot.setString("The Pot: " + to_string(pot));
    thePot.setCharacterSize(34);
    thePot.setFillColor(sf::Color(255,255,255));
    thePot.setPosition(sf::Vector2f(1130,350));

    //Text for user's current bet'
    sf::Text currentBet;
    currentBet.setFont(theFont);
    currentBet.setString("Current bet: " + to_string(tableBet));
    currentBet.setCharacterSize(34);
    currentBet.setFillColor(sf::Color(255,255,255));
    currentBet.setPosition(sf::Vector2f(1150,150));

    //Text for Poker button to play Poker
    sf::Text pokerButton;
    pokerButton.setFont(theFont);
    pokerButton.setString("POKER");
    pokerButton.setCharacterSize(34);
    pokerButton.setFillColor(sf::Color(255,255,255));
    pokerButton.setPosition(sf::Vector2f(200,350));
    
    //Text for Black Jack button to play Black Jack
    sf::Text blackJackButton;
    blackJackButton.setFont(theFont);
    blackJackButton.setString("Black Jack");
    blackJackButton.setCharacterSize(34);
    blackJackButton.setFillColor(sf::Color(255,255,255));
    blackJackButton.setPosition(sf::Vector2f(180,450));
    
    //Text for bet button
    sf::Text betButton;
    betButton.setFont(theFont);
    betButton.setString("BET");
    betButton.setCharacterSize(34);
    betButton.setFillColor(sf::Color(255,255,255));
    betButton.setPosition(sf::Vector2f(430,450));
    
    //Text for hit button
    sf::Text hitButton;
    hitButton.setFont(theFont);
    hitButton.setString("HIT");
    hitButton.setCharacterSize(34);
    hitButton.setFillColor(sf::Color(255,255,255));
    hitButton.setPosition(sf::Vector2f(730,450));
    
    //Text for stand button
    sf::Text standButton;
    standButton.setFont(theFont);
    standButton.setString("STAND");
    standButton.setCharacterSize(34);
    standButton.setFillColor(sf::Color(255,255,255));
    standButton.setPosition(sf::Vector2f(1020,450));

    //Text for end of game
    sf::Text gameOver;
    gameOver.setFont(theFont);
    gameOver.setString("Game Over");
    gameOver.setCharacterSize(50);
    gameOver.setFillColor(sf::Color(255,255,255));
    gameOver.setPosition(sf::Vector2f(800,450));

    //Text for blackjack bust
    sf::Text Bust;
    Bust.setFont(theFont);
    Bust.setString("BUST!");
    Bust.setCharacterSize(70);
    Bust.setFillColor(sf::Color(255,255,255));
    Bust.setPosition(sf::Vector2f(630,530));

    //Text for stand button
    sf::Text gameOverBJ;
    gameOverBJ.setFont(theFont);
    gameOverBJ.setString("GAME OVER");
    gameOverBJ.setCharacterSize(100);
    gameOverBJ.setFillColor(sf::Color(255,255,255));
    gameOverBJ.setPosition(sf::Vector2f(500,250));

    //Text for youWin
    sf::Text youWin;
    youWin.setFont(theFont);
    youWin.setString("You Win!");
    youWin.setCharacterSize(70);
    youWin.setFillColor(sf::Color(255,255,255));
    youWin.setPosition(sf::Vector2f(600,500));

    bool isPoker = false;
    bool isBlackJack = false;
    int moveCount = 0;
    bool userFolded = false;
    bool yourTurn = false;
    bool youWon = false;

    /* 
    *------------------------------MENU----------------------------------
    *
    First the menu is opened and asks the user to play poker or blackjack 
    then once they pick, the appropriate window is opened and the menu is closed
    *
    *--------------------------------------------------------------------
    */

    while (menu.isOpen()) {  
        //Event handling for which button the player presses 
        sf::Event decision;
        while(menu.pollEvent(decision))
        {
            //If the menu is closed
            if (decision.type == sf::Event::Closed)
                menu.close();

            if (decision.type == sf::Event::MouseButtonPressed){
                if (decision.mouseButton.button == sf::Mouse::Left){
                    //If they press the poker button:
                    if (menuPoker.getGlobalBounds().contains(menu.mapPixelToCoords(sf::Mouse::getPosition(menu)))){
                        cout << "Presses Poker button" << std::endl;
                        isPoker = true;
                        menu.close();
                    }

                    //If they press the blackjack button:
                    if(menuBlackJack.getGlobalBounds().contains(menu.mapPixelToCoords(sf::Mouse::getPosition(menu)))){
                        isBlackJack = true;
                        cout << "Presses Black Jack button" <<std::endl;
                        menu.close();
                    }
                }
            }
        }
        //Draw the menu
        menu.clear();
        menu.draw(rectanglePoker);
        menu.draw(menuPoker);
        menu.draw(menuTitle);
        menu.draw(pokerButton);
        menu.draw(rectangleBlackJack);
        menu.draw(menuBlackJack);
        menu.draw(blackJackButton);
        menu.display();

    }
    /*
	*------------------- POKER ------------------------------------------------------------------------------------------		
	*
	*This first section will be for if the player picked poker.
	*The player will will be able to control their own actions that will repeat in a while loop until the game is done.
	*The type of game will go along with the standard rules of texas hold em where each player has their own two cards to 
	*play off as well as a communal five cards to make the highest possible hand.
	*At the end the beting money will be distributed to the winner's pot.
	*
	*---------------------------------------------------------------------------------------------------------------------
	*/
    if(isPoker) {
        window.create(sf::VideoMode(1600,900),"Poker Night!");
        bool gameGoing = true;
        int wallet = 1000;
        //------------- POKER GAME LOOP --------------------
        while(gameGoing){
            roundCounter = 0;
            bufferCounter = 0;
            //Create poker Players
            //And the deck
            Deck deck=*new Deck();
            Player user = *new Player(&deck,true);
            user.setCash(wallet);
            Player topAI = *new Player(&deck,true);
            Player leftAI = *new Player(&deck,true);
            Player rightAI = *new Player(&deck,true);
            Player riverA = *new Player(&deck,true);
            Player riverB = *new Player(&deck,true);
            Player riverC = *new Player(&deck,true);

            //Load card textures
            userHand1.setTexture(cardMap.at(user.getCardP(0).getName()));  
            userHand2.setTexture(cardMap.at(user.getCardP(1).getName()));
            rightHand1.setTexture(cardMap.at(rightAI.getCardP(0).getName())); 
            rightHand2.setTexture(cardMap.at(rightAI.getCardP(1).getName()));
            leftHand1.setTexture(cardMap.at(leftAI.getCardP(0).getName())); 
            leftHand2.setTexture(cardMap.at(leftAI.getCardP(1).getName()));
            topHand1.setTexture(cardMap.at(topAI.getCardP(0).getName())); 
            topHand2.setTexture(cardMap.at(topAI.getCardP(1).getName()));
            river1.setTexture(cardMap.at(riverA.getCardP(0).getName()));
            river2.setTexture(cardMap.at(riverA.getCardP(1).getName()));
            river3.setTexture(cardMap.at(riverB.getCardP(0).getName()));
            river4.setTexture(cardMap.at(riverB.getCardP(1).getName()));
            river5.setTexture(cardMap.at(riverC.getCardP(0).getName()));

        
            Dollar.setString("$" + to_string(user.displayCash()));
            //window loop
            while (window.isOpen())
            {
                //Game Over check
                if(roundCounter == 5) {
                    window.draw(gameOver);
                    this_thread::sleep_for(chrono::seconds(9));
                    userFolded = false;
                    
                    break;
                }
                //AI players go first and their bet value depends on the round they are on
                //If user folded, let the AI keep playing
                if(userFolded) 
                    roundCounter++;
                //AI bets:
                if((bufferCounter != roundCounter || (roundCounter == 0 && pot == 0)) && roundCounter < 4) {
                    this_thread::sleep_for(chrono::seconds(2));
                    if (roundCounter == 0) {
                        tableBet = 1 + (rand() % 20);
                        for(int i = 0; i < 3; i++) {
                            pot += tableBet;
                            thePot.setString("The Pot: " + to_string(pot));
                        }
                    }
                    if (roundCounter == 1) {
                        tableBet = 1 + (rand() % 40);
                        for(int i = 0; i < 3; i++) {
                            pot += tableBet;
                            thePot.setString("The Pot: " + to_string(pot));
                        }
                    }
                    if (roundCounter == 2) {
                        tableBet = 1 + (rand() % 50);
                        for(int i = 0; i < 3; i++) {
                            pot += tableBet;
                            thePot.setString("The Pot: " + to_string(pot));
                        }
                    }
                    if (roundCounter == 3) {
                        tableBet = 1 + (rand() % 100);
                        for(int i = 0; i < 3; i++) {
                            pot += tableBet;
                            thePot.setString("The Pot: " + to_string(pot));
                        }
                    }
                    currentBet.setString("Current bet: " + to_string(tableBet));
                    bufferCounter = roundCounter;
                    yourTurn = true;
                }

                //Start polling for event from player
                sf::Event event;
                while (window.pollEvent(event) && !userFolded)
                {
                    //Close window when pressing X
                    if (event.type == sf::Event::Closed)
                        window.close();

                    //Button handling starts here for betting and decision making
                    if (event.type == sf::Event::MouseButtonPressed){
                        if (event.mouseButton.button == sf::Mouse::Left){
                            //Bet values:
                            if (oneSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                                if(user.enoughCash(betValue+1)) {
                                betValue++; 
                                Bet.setString("$" + to_string(betValue));
                                }
                            }
                            else if (tenSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                                if(user.enoughCash(betValue+10)) {
                                    betValue+=10;
                                    Bet.setString("$" + to_string(betValue));
                                
                                }
                            }
                            else if (hundredSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                                if(user.enoughCash(betValue+100)) {
                                    betValue+=100;
                                    Bet.setString("$" + to_string(betValue));
                                
                                }
                            }
                            //Decision making:
                            if (foldSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && yourTurn){
                                cout << "Presses Fold button" << std::endl;
                                userFolded = true; //used to increment roundCounter without waiting for input
                                yourTurn = false; 
                                pileSprite.setPosition(200,400);
                                pileSprite2.setPosition(1300,400);
                                pileSprite3.setPosition(800,200);
                                moveCount = 0;
                                roundCounter++;
                            }
                            else if (callSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && yourTurn){
                                cout << "Presses Call button" << std::endl;
                                pot += tableBet;
                                user.makeBet(tableBet);
                                thePot.setString("The Pot: " + to_string(pot));
                                yourTurn = false;
                                pileSprite.setPosition(200,400);
                                pileSprite2.setPosition(1300,400);
                                pileSprite3.setPosition(800,200);
                                Dollar.setString("$" + to_string(user.displayCash()));
                                moveCount = 0;
                                //Reset the user's bet value
                                betValue = 0;
                                Bet.setString("$0");
                                roundCounter++;
                            }
                            else if (raiseSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && yourTurn){
                                cout << "Presses Raise button" << std::endl;
                                //Raise needs to be higher than the current highest bet for the round
                                if(betValue > tableBet) {
                                    user.makeBet(betValue);
                                    pot += betValue;
                                    int betDifference = betValue - tableBet;
                                    pot += betDifference * 3;
                                    thePot.setString("The Pot: " + to_string(pot));
                                    currentBet.setString("Current bet: " + to_string(tableBet));
                                    roundCounter++;
                                    Dollar.setString("$" + to_string(user.displayCash()));
                                    yourTurn = false;
                                    pileSprite.setPosition(200,400);
                                    pileSprite2.setPosition(1300,400);
                                    pileSprite3.setPosition(800,200);
                                    //Reset the user's bet value
                                    betValue = 0;
                                    Bet.setString("$0");
                                    moveCount = 0;
                                } else {
                                    cout << "Invalid raise" << endl;
                                }
                            
                            }
                        
                    }
                
                }
            }
            
            //------------------ Draw the window -------------------
            window.clear();
             //If we are the end, evaluate the hands along with river
             if(roundCounter == 4) {
                
                wallet = user.displayCash();
                Card River[] = {riverA.getCardP(0), riverA.getCardP(1), riverB.getCardP(0), riverB.getCardP(1), riverC.getCardP(0)};
                int plyrhand = evaluateHandP(&user, River);
                cout << plyrhand;
                int lefthand = evaluateHandP(&leftAI, River);
                cout << lefthand;
                int righthand = evaluateHandP(&rightAI, River);
                cout << righthand;
                int tophand = evaluateHandP(&topAI, River);
                cout << tophand;
                if(userFolded == false && plyrhand > lefthand && plyrhand > righthand && plyrhand > tophand){
                    wallet+=pot;
                    youWon = true;
                }
                else if(userFolded == false && plyrhand >= lefthand && plyrhand >= righthand && plyrhand >= tophand){
                    wallet += (pot/2); 
                }

                else
                    youWon = false;
                pot = 0;
                roundCounter++;
            }
            window.draw(table);
            window.draw(rectangleFold);
            window.draw(rectangleCall);
            window.draw(rectangleRaise);
            window.draw(deckSprite);
            window.draw(userHand1);
            window.draw(userHand2);
            window.draw(topHand1);
            window.draw(topHand2);
            window.draw(leftHand1);
            window.draw(leftHand2);
            window.draw(leftHand1);
            window.draw(leftHand2);
            window.draw(rightHand1);
            window.draw(rightHand2);
            window.draw(Wallet);
            window.draw(yourBet);
            if(yourTurn) {
                window.draw(Fold);
                window.draw(Call);
                window.draw(Raise);
            }
            window.draw(chip);
            window.draw(Dollar);
            window.draw(Bet);
            window.draw(plusOne);
            window.draw(plusTen);
            window.draw(plusHundred);
            window.draw(currentBet);
            window.draw(thePot);

            //Cover AI cards until last round
            if(roundCounter < 4) { 
                window.draw(topCoverHand1);
                window.draw(topCoverHand2);
                window.draw(leftCoverHand1);
                window.draw(leftCoverHand2);
                window.draw(rightCoverHand1);
                window.draw(rightCoverHand2);
            }

            //Draw river after first round
            if(roundCounter >=  1) {
            window.draw(river1);
            window.draw(river2);
            window.draw(river3);
            }

            //Continue drawing river according to round
            if(roundCounter >=  2) {
            window.draw(river4);
            }
            if(roundCounter >=  3) {
                
            window.draw(river5);
            }
            if(roundCounter == 5 && youWon && !userFolded)
                window.draw(youWin);
            //Animation for pile of chips sprite
            if(yourTurn) {
                window.draw(pileSprite);
                window.draw(pileSprite2);
                window.draw(pileSprite3);
                if(moveCount < 300) {
                    pileSprite.move(3,0);
        
                    if(moveCount < 180) {
                        pileSprite3.move(sf::Vector2f(2,1));
                    }
                    if(moveCount < 80) {
                        pileSprite2.move(-3,0);
                    }
                    moveCount++;
                }   
            }
            window.display();
            }   
        }    
    }

    /*
	*------------------- BLACKJACK ---------------------------------------------------------------------------------------
	*
	*The second section will be for blackjack.
	*The player will will be able to control their own actions that will repeat in a while loop until the game is done.
	*The type of game will go along with the standard rules of blackjack where each player has their own two cards to 
	*play off and can add cards to their hand to try to get as close to 21 as possible without going over.
	*At the end the beting money will be distributed to the winner's pot.
	*
	*----------------------------------------------------------------------------------------------------------------------
	*/

    if(isBlackJack){
        blackJackWindow.create(sf::VideoMode(1600,900),"Black Jack Night!");
        bool gameGoing = true;
        int wallet = 1000;
        unordered_map< int , int> valueMap = {
                {1,11},
                {2,2},
                {3,3},
                {4,4},
                {5,5},
                {6,6},
                {7,7},
                {8,8},
                {9,9},
                {10,10},
                {11,10},
                {12,10},
                {13,10}
        };
        //---------------------Blackjack game loop --------------------
        while(gameGoing){
            
            //Create deck and players
            Deck deck = *new Deck();
            Player user = *new Player(&deck,false);
            user.setCash(wallet);
            Player bjAI = *new Player(&deck,false);

            //Load the texture for blackjack AI and user
            topCard1.setTexture(cardMap.at(bjAI.getCardB(0).getName())); 
            topCard2.setTexture(cardMap.at(bjAI.getCardB(1).getName()));
            topCard3.setTexture(cardMap.at(bjAI.getCardB(2).getName()));
            topCard4.setTexture(cardMap.at(bjAI.getCardB(3).getName()));
            topCard5.setTexture(cardMap.at(bjAI.getCardB(4).getName()));
            topCard6.setTexture(cardMap.at(bjAI.getCardB(5).getName()));
            topCard7.setTexture(cardMap.at(bjAI.getCardB(6).getName()));
            topCard8.setTexture(cardMap.at(bjAI.getCardB(7).getName()));
            topCard9.setTexture(cardMap.at(bjAI.getCardB(8).getName()));
            topCard10.setTexture(cardMap.at(bjAI.getCardB(9).getName()));
            topCard11.setTexture(cardMap.at(bjAI.getCardB(10).getName()));
            userCard1.setTexture(cardMap.at(user.getCardB(0).getName()));
            userCard2.setTexture(cardMap.at(user.getCardB(1).getName()));
            userCard3.setTexture(cardMap.at(user.getCardB(2).getName()));
            userCard4.setTexture(cardMap.at(user.getCardB(3).getName()));
            userCard5.setTexture(cardMap.at(user.getCardB(4).getName()));
            userCard6.setTexture(cardMap.at(user.getCardB(5).getName()));
            userCard7.setTexture(cardMap.at(user.getCardB(6).getName()));
            userCard8.setTexture(cardMap.at(user.getCardB(7).getName()));
            userCard9.setTexture(cardMap.at(user.getCardB(8).getName()));
            userCard10.setTexture(cardMap.at(user.getCardB(9).getName()));
            userCard11.setTexture(cardMap.at(user.getCardB(10).getName()));

            //Unordered map mostly to make ace equal to 11 and faces equal to 10
            //Needed because get rank return a number 1-13
            
            
            //Calculate combinations of cards ahead of time to use in checking for winner
            //or to check for bust
            int firstTwo = valueMap.at(bjAI.getCardB(0).getRank()) + valueMap.at(bjAI.getCardB(1).getRank());
            int firstThree = firstTwo + valueMap.at(bjAI.getCardB(2).getRank());
            int firstFour = firstThree + valueMap.at(bjAI.getCardB(3).getRank());
            int firstFive = firstFour + valueMap.at(bjAI.getCardB(4).getRank());
            int firstSix = firstFive + valueMap.at(bjAI.getCardB(5).getRank());
            int firstSeven = firstSix + valueMap.at(bjAI.getCardB(6).getRank());
            int firstEight = firstSeven + valueMap.at(bjAI.getCardB(7).getRank());
            int firstNine = firstEight + valueMap.at(bjAI.getCardB(8).getRank());
            int firstTen = firstNine + valueMap.at(bjAI.getCardB(9).getRank());
            
            int userFirstTwo = valueMap.at(user.getCardB(0).getRank()) + valueMap.at(user.getCardB(1).getRank());
            int userFirstThree = userFirstTwo + valueMap.at(user.getCardB(2).getRank());
            int userFirstFour = userFirstThree + valueMap.at(user.getCardB(3).getRank());
            int userFirstFive = userFirstFour + valueMap.at(user.getCardB(4).getRank());
            int userFirstSix = userFirstFive + valueMap.at(user.getCardB(5).getRank());
            int userFirstSeven = userFirstSix + valueMap.at(user.getCardB(6).getRank());
            int userFirstEight = userFirstSeven + valueMap.at(user.getCardB(7).getRank());
            int userFirstNine = userFirstEight + valueMap.at(user.getCardB(8).getRank());
            int userFirstTen = userFirstNine + valueMap.at(user.getCardB(9).getRank());

            bool displayBet=true;
            bool displayHit=true;
            bool pressedStand=false;
            int hitCounter=0;

            blackJackDollar.setString("$" + to_string(user.displayCash()));

            //window loop
            while (blackJackWindow.isOpen()){
                //Event handling for user input        
                sf::Event event;
                while (blackJackWindow.pollEvent(event)){
    
                    //Window is closed
                    if (event.type == sf::Event::Closed) {
                        blackJackWindow.close();
                        return 0;
                    }
                    
                    //User button handling: 
                    if (event.type == sf::Event::MouseButtonPressed){
                        if (event.mouseButton.button == sf::Mouse::Left){
                            if (betSpriteBlackJack.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                cout << "Presses bet button" << std::endl;
                                user.makeBet(betValue);
                                blackJackDollar.setString("$" + to_string(user.displayCash()));
                                displayBet=false;
                                Bet.setString("$0");
                                break;
                            }
                            else if (oneSprite.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                if(user.enoughCash(betValue+1)) {
                                    betValue++;
                                    Bet.setString("$" + to_string(betValue));
                                    
                                }
                            }
                            else if (oneSprite.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                if(user.enoughCash(betValue+1)) {
                                    betValue++;
                                    Bet.setString("$" + to_string(betValue));
                                    
                                }
                            }
                            else if (tenSprite.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                if(user.enoughCash(betValue+10)) {
                                    betValue+=10;
                                    Bet.setString("$" + to_string(betValue));
                                    
                                }
                            }
                            else if (hundredSprite.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                if(user.enoughCash(betValue+100)) {
                                    betValue+=100;
                                    Bet.setString("$" + to_string(betValue));
                                    
                                }
                            }
                            //If they want to hit they must be below 21
                            else if (hitSprite.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                int userhand = user.evaluateBlackjackHand();
                                bool busted = userhand > 21;
                                //do not perform hit if user has busted or 
                                //if they already have 21 
                                if (busted || userhand == 21) {
                                    break;
                                }

                                user.incrementCardCount();

                                if(hitCounter==0 && userhand<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==1 && userhand<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==2 && userhand<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==3 && userhand<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==4 && userFirstSix<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==5 && userFirstSeven<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==6 && userFirstEight<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==7 && userFirstNine<21){
                                    hitCounter++;
                                }
                                else if(hitCounter==8 && userFirstTen<21){
                                    hitCounter++;
                                }
                                
                                
                            }
                            else if (standSpriteBlackJack.getGlobalBounds().contains(blackJackWindow.mapPixelToCoords(sf::Mouse::getPosition(blackJackWindow)))){
                                displayHit=false;
                                pressedStand=true;
                                cout << "Presses stand button" << std::endl;

                                break;
                            }
                            
                        }
                        
                    }
                    
                }
                
                //begin blackjack drawing
                blackJackWindow.clear();
                blackJackWindow.draw(table);
                blackJackWindow.draw(rectangleBetBlackJack);
                blackJackWindow.draw(betButton);
                if(displayBet==false){
                    blackJackWindow.draw(rectangleBetBlackJackCover);
                }
                
                blackJackWindow.draw(rectangleHit);
                blackJackWindow.draw(hitButton);   
                blackJackWindow.draw(standButton);
                blackJackWindow.draw(rectangleStandBlackJack);
                blackJackWindow.draw(standSpriteBlackJack);
                blackJackWindow.draw(topCard1);
                blackJackWindow.draw(topCardCover);
                blackJackWindow.draw(topCard2);
                

                if(displayBet==false){
                    blackJackWindow.draw(rectangleBetBlackJackCover);
                }

                blackJackWindow.draw(rectangleHit);
                blackJackWindow.draw(hitButton);
                
                if(displayHit==false){
                    blackJackWindow.draw(rectangleHitCover);
                }
                
                blackJackWindow.draw(standButton);
                blackJackWindow.draw(rectangleStandBlackJack);
                
                //If player stayed, the AI will start drawing
                if(pressedStand){
                    blackJackWindow.draw(rectangleStandBlackJackCover);
                    blackJackWindow.draw(topCard1);
                    blackJackWindow.draw(topCard2);
                    int dealerCounter = 2;
                    if(firstTwo < 17){
                        blackJackWindow.draw(topCard3);
                        dealerCounter++;
                    }
                    if(firstThree < 17){
                        blackJackWindow.draw(topCard4);
                        dealerCounter++;
                    }
                    if(firstFour < 17){
                        blackJackWindow.draw(topCard5);
                        dealerCounter++;
                    }
                    if(firstFive < 17){
                        blackJackWindow.draw(topCard6);
                        dealerCounter++;
                    }
                    if(firstSix < 17){
                        blackJackWindow.draw(topCard7);
                        dealerCounter++;
                    }
                    if(firstSeven < 17){
                        blackJackWindow.draw(topCard8);
                        dealerCounter++;
                    }
                    if(firstEight < 17){
                        blackJackWindow.draw(topCard9);
                        dealerCounter++;
                    }
                    if(firstNine < 17){
                        blackJackWindow.draw(topCard10);
                        dealerCounter++;
                    }
                    if(firstTen < 17){
                        blackJackWindow.draw(topCard11);
                        dealerCounter++;
                    }
                    blackJackWindow.draw(gameOverBJ);
                    wallet = user.displayCash();
                    int dealerHand = bjAI.evaluateBlackjackHand();
                    int userHand = user.evaluateBlackjackHand();
                    
                    bool youBusted = userHand > 21;

                    if ((!youBusted && dealerHand < 22 && userHand > dealerHand) || (!youBusted && dealerHand > 21)) {
                        wallet += betValue*2;
                        bool youWon = true;
                        betValue = 0;
                    }
                    user.setCash(wallet);

                }
                
                //For every hit, draw another card
                blackJackWindow.draw(userCard1);
                blackJackWindow.draw(userCard2);
                if(hitCounter>0){
                    blackJackWindow.draw(userCard3);
                }
                if(hitCounter>1){
                    blackJackWindow.draw(userCard4);
                }
                if(hitCounter>2){
                    blackJackWindow.draw(userCard5);
                }
                if(hitCounter>3){
                    blackJackWindow.draw(userCard6);
                }  
                if(hitCounter>4){
                    blackJackWindow.draw(userCard7);
                }
                if(hitCounter>5){
                    blackJackWindow.draw(userCard8);
                }  
                if(hitCounter>6){
                    blackJackWindow.draw(userCard9);
                }
                if(hitCounter>7){
                    blackJackWindow.draw(userCard10);
                }
                if(hitCounter>8){
                    blackJackWindow.draw(userCard11);
                }
                blackJackWindow.draw(blackJackWallet);
                blackJackWindow.draw(blackJackDollar);
                blackJackWindow.draw(plusOne);
                blackJackWindow.draw(plusTen);
                blackJackWindow.draw(plusHundred);
                blackJackWindow.draw(yourBet);
                blackJackWindow.draw(chip);
                blackJackWindow.draw(Bet);

                bool youBusted = user.evaluateBlackjackHand() > 21;

                if(youBusted) {
                    blackJackWindow.draw(Bust);
                    blackJackWindow.draw(gameOverBJ);
                    wallet = user.displayCash();
                }
                
                blackJackWindow.display();
                //Sleep to end the game and restart
                if(youBusted || pressedStand){
                    if(youWon)
                        window.draw(youWin);
                    this_thread::sleep_for(chrono::seconds(6));
                    break;
                }

            }
        }
    }
    return 0;
}