//
//  Player.cpp
//  COP3503 Final Project
//
//  Created by Nickolas Owens on 12/2/16.
//  Copyright © 2016 Nickolas Owens. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

/* Although I was not responsible for the Card class, I created a simplified version of the class in order to test the functionality of the Player class as they go hand in hand on many occasions. The one thing to take from this class is that a default constructor Card() MUST be created in order to initialize empty object arrays pokerHand and blackjackHand found below.
 */
class Card{
    
private:
    //Initialize member variables for Card class
    int number;
    char suit;
    
public:
    
    //Creates both a default constructor and one requiring the card value and suit to intialize.
    Card(){
        
    }
    Card(int number, char suit){
        this->number = number;
        this->suit = suit;
    }
    
    //These getter methods retrieve the encapsulated values for the card suit and value for any given instance of the Card class.
    int getNumber(){
        return this->number;
    }
    
    char getSuit(){
        return this->suit;
    }
};



// PLAYER CLASS STARTS HERE
class Player{
    
private:
    /* Initialize private member variables cashValue and numCards, which represent the current cash value and the number of cards in a game of blackjack, respectively, for each instance of Player. Initialize arrays of type Card to represent the poker and blackjack hands for each instance of Player. Poker hands have 5 cards and although blackjack hands start with 2, the most they can have is 11 because the lowest possible combination of cards is A,A,A,A,2,2,2,2,3,3,3 which is equal to 21, winning the game.
     */
    int cashValue;
    int numCards;
    Card pokerHand[5];
    Card blackjackHand[12];
    
    
public:
    /* Creates a constructor for the object Player in order to create mulitple instances, one for each player. The starting cashValue for each player is $1000. The constructor then checks if the game type is poker or blackjack in order to create the correct type of hand by checking the isPoker() method from the game class. If it is true, a hand of five cards is created by looping through the array and assigning a card value the current element. I used Card(int,char) to test my class but we will use drawCard() method from the Deck class to fill the card slots. If the game is blackjack, the first two slots of the blackjackHand array will be filled with drawCard() and the numCards value is set to 2.
     */
    Player(){
        this->cashValue = 1000;
        if (isPoker() == true){
            for (int i=0; i<5; i++){
                this->pokerHand[i] = Card(2,'c');
            }
        }
        else{
            for (int j=0; j<2; j++){
                this->blackjackHand[j] = Card(3,'d');
                this->numCards = 2;
            }
        }
    }
    
    /* This method takes a betValue as the input and outputs a boolean value in response to whether or not the player has the money to make a given bet. If the betValue is less than or equal to their current cashValue, the bet can be made. This will be implemented into main.
     */
    bool enoughCash(int betValue){
        if (betValue <= cashValue)
            return true;
        else
            return false;
    }
    
    /* This method wont normally exist in the Player class, I just created it to simulate the isPoker() method from the Game class. The real method should decide, based off of user input, if the value should be true or false. I arbitrarily picked both true and false to test both cases. True results in the creation of a poker hand, while false results in the creation of a blackjack hand.
     */
    bool isPoker(){
        return false;
    }
    
    /* This method takes a betValue, given that enoughCash(int betValue) is true, and subtracts it from the cashValue of the current Player instance. There is no output from this method, but it does change the value of cashValue for that particular instance of Player.
     */
    void makeBet(int betValue){
        this->cashValue = this->cashValue - betValue;
    }
    /* This method first checks to see if the number of cards in a player's blackjack hand is 11 or fewer. While that is the case, the method can add a new card to said hand. As I mentioned above, Card(int,char) was used to test my class, while drawCard() from the Deck class will be what actually puts a new, different card in the next available slot. The method also increments the variable numCards for the current instance of the Player class.
     */
    void addCard(){
       
            this->blackjackHand[this->numCards] = Card(4,'h');
            this->numCards +=1;
    }
    
    //This is a getter method to return the current cashValue of a particular player instance.
    int displayCash(){
        return this->cashValue;
    }
    
    /* Although the following two methods won't be in the final Player class, I created them to display the cards currently in a particular player's hand. These two methods can be used to extrapolate the card value and suit so that they can be passed to other classes such as Game and the GUI class.
     */
    void showPokerHand(){
        for (int k=0; k<5; k++){
            cout << this->pokerHand[k].getNumber() << this->pokerHand[k].getSuit() << "\n\n";
        }
    }
    
    void showBlackjackHand(){
        for (int a=0; a < this->numCards; a++){
            cout << this->blackjackHand[a].getNumber() << this-> blackjackHand[a].getSuit() << "\n\n";
        }
    }
    
    
};
// PLAYER CLASS ENDS HERE


/* Although main isn't appropriate here in the full view of our project, it was again created to test my class, making sure that the methods and constructors I created would translate to the proper output. It also showcases the functionality of the Player class and gives an example of how things should be coded in the actual main of our program.
 */
int main(){
    
    
    Player user = *new Player();
    Player p1 =  *new Player();
    cout << user.displayCash() << "\n\n";
    user.makeBet(100);
    cout << user.displayCash() << "\n\n";
    cout << p1.displayCash() << "\n\n";
    p1.makeBet(200);
    cout << p1.displayCash() << "\n\n";
    //user.showPokerHand(); This method is commented out because the poker hand is empty (isPoker currently arbitrarily set to false
    user.showBlackjackHand();
    cout << "\n\n";
    user.addCard();
    user.showBlackjackHand();
    cout << "\n\n";
    p1.showBlackjackHand();
    
    return 0;
}

/* The desired outputs are achieved, as making a bet for one player only affects the cashValue of that player. Furthermore, changing the card values or adding new cards to the blackjack hand only affect that instance of Player. I have tested my class thoroughly and found no issues. Please feel free to mess around with the main class, testing different scenarios and if you find any problems, let me know.
 */
