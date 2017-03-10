#include<iostream>
#include <string>
using namespace std;

class Card{
    
private:
    //Initialize member variables for Card class
    int rank;
    string suit;
    string name;
    
public:
    
    //Creates both a default constructor and one requiring the card value and suit to intialize.
    Card(){
        
    }
    Card(int rank, string suit){
        this->rank = rank;
        this->suit = suit;
        this->name = suit + to_string(rank);
		}
    
    //These getter methods retrieve the encapsulated values for the card suit and value for any given instance of the Card class.
    int getRank(){
        return this-> rank;
    }
    
    string getSuit(){
        return this->suit;
    }
    string getName() {
        return this->name;
    }
};

class Deck{
    
private:
    int maxSize;
    Card cardDeck[52];
    int cardsDrawn;
    
    
public:
    Deck() {
        maxSize=52;
        cardsDrawn=0;
        int cardCount = 0;
        string suits[] = {"c", "d", "h", "s"};
        
        //this for block is for suits
        for (int i = 0; i < 4; i++) {
            
            for (int j = 1; j <= 13; j++) {
                this->cardDeck[cardCount] = Card(j,suits[i]);
                cardCount++;
            }
        }
        Deck::shuffle();
      //  for (int z=0;z<52;z++){
           // cout<< cardDeck[z].getName() << endl;
      //  }
    }
    // randomly shuffles cards by swapping cards in the deck
    
    void shuffle() {
        srand(time(0)); // random seed
        //int s = (rand() % 4); //random scaler for loop shuffle length
        for (int i = 0; i < maxSize; i++) {
            
            int index = rand() % maxSize;
            Card temp = cardDeck[i];
            int r = rand() % maxSize;
            cardDeck[i] = cardDeck[r];
            cardDeck[r] = temp;
            
        }
        
    }
    
    Card drawCard() {
        int cardToDraw = (maxSize - 1) - cardsDrawn; // gets element to draw from
        if (cardToDraw < 0){
            return Card(0,"z");
        }
        
        else {
            
            Card draw = cardDeck[cardToDraw];
            cardsDrawn++;
            return draw;
        }
        
    }
};


class Player{
    
private:
    /* Initialize private member variables cashValue and numCards, which represent the current cash value and the number of cards in a game of blackjack, respectively, for each instance of Player. Initialize arrays of type Card to represent the poker and blackjack hands for each instance of Player. Poker hands have 5 cards and although blackjack hands start with 2, the most they can have is 11 because the lowest possible combination of cards is A,A,A,A,2,2,2,2,3,3,3 which is equal to 21, winning the game.
     */
    int cashValue;
    unsigned int numCards;
    Card pokerHand[2];
    Card blackjackHand[11];
    
    
public:
    /* Creates a constructor for the object Player in order to create mulitple instances, one for each player. The starting cashValue for each player is $1000. The constructor then checks if the game type is poker or blackjack in order to create the correct type of hand by checking the isPoker() method from the game class. If it is true, a hand of five cards is created by looping through the array and assigning a card value the current element. I used Card(int,char) to test my class but we will use drawCard() method from the Deck class to fill the card slots. If the game is blackjack, the first two slots of the blackjackHand array will be filled with drawCard() and the numCards value is set to 2.
     */
    Player(Deck *deck, bool isPoker){
        this->cashValue = 1000;
        if (isPoker){
            for (int i=0; i<2; i++){
                this->pokerHand[i] =deck->drawCard();
            }
        }
        else{
			this->numCards = 2;
            for (unsigned int j=0; j<11; j++){
                this->blackjackHand[j] = deck->drawCard();
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
    
    /* This method takes a betValue, given that enoughCash(int betValue) is true, and subtracts it from the cashValue of the current Player instance. There is no output from this method, but it does change the value of cashValue for that particular instance of Player.
     */
    void makeBet(int betValue){
        this->cashValue = this->cashValue - betValue;
    }
    /* This method first checks to see if the number of cards in a player's blackjack hand is 11 or fewer. While that is the case, the method can add a new card to said hand. As I mentioned above, Card(int,char) was used to test my class, while drawCard() from the Deck class will be what actually puts a new, different card in the next available slot. The method also increments the variable numCards for the current instance of the Player class.
     */
	 void incrementCardCount() {
		 this->numCards++;
	 }

    void addCard(Deck *deck){
        
        this->blackjackHand[this->numCards] = deck->drawCard();;
        this->numCards +=1;
    }
    
    //This is a getter method to return the current cashValue of a particular player instance.
    int displayCash(){
        return this->cashValue;
    }
    void setCash(int wallet){
		this->cashValue = wallet;
	}
    Card getCardP(int i){
        return this -> pokerHand[i];
    }
    
    Card getCardB(int j){
        return this -> blackjackHand[j];
    }
    
	unsigned int evaluateBlackjackHand() {
		int score = 0;
		int aces = 0;
		for(unsigned int i = 0; i < this->numCards; i++) {
			int rank = this->blackjackHand[i].getRank();
			
			if(rank == 1) {
				aces++;
				continue;
			}
			if(rank > 10) {
				rank = 10;
			}
			score += rank;
		}

		while (aces > 0 && score + 11 < 22) {
			aces--;
			score += 11;
		}
		score += aces;
		cout << score << endl;
		return score;
	}
    
};

Card* cardSort(int i, Card cards[]){
	//This method is used to take the cards from the table and in the players hand and sorts them
	//either by rank, suit or both so that it makes it easier to test for the different possible hands
	Card cardHolder[] = {Card(cards[0].getRank(), cards[0].getSuit()), Card(cards[1].getRank(), cards[1].getSuit()), 
	Card(cards[2].getRank(), cards[2].getSuit()), Card(cards[3].getRank(), cards[3].getSuit()),  Card(cards[4].getRank(), cards[4].getSuit()),
	Card(cards[5].getRank(), cards[5].getSuit()), Card(cards[6].getRank(), cards[6].getSuit())};
	//the carholder variable os used to save the values of the cards on the table so that they can be used again to 
	//evaluate other hands in case they get lost in the method
	Card* newCards = new Card[7];
	//This will be sorted with cards ordered by suit or rank
	switch(i){
		//the switch statement chooses between sorting by rank or by suit
		case 0:{
			//case 0 is for sorting by rank
			for(int i = 0; i < 7; i++){
				//The for loop will run through all of the cards the player could use to make a hand
				int lowestRank = cards[0].getRank();
				//Lowest rank will keep track of what the next lowest ranked card is in the list of cards
				//Sets the first variable as the first "lowest" ranked card for comparison
				int location = 0;
				//Location will save where the next lowest 
				for (int j = 1; j < 7; j++){
					//checks each possible card 
					if(cards[j].getRank() < lowestRank && cards[j].getRank() != 0){
						//if the card we are checking is lower and not 0 than the card saved as the current lowest card 
						lowestRank = cards[j].getRank();
						location = j;
					}
					else if(cards[j].getRank() > 0 && lowestRank == 0){
						//in case the first location is 0 we find the first one with a value
						lowestRank = cards[j].getRank();
						location = j;
					} 
				}
				newCards[i] = cards[location];
				//sets the next lowest card into the list of cards
				Card blankCard = Card(0,"s");
				//creates a blank card to go in the lowest card's spot
				cards[location] = blankCard;
				//sets that value in the list we are picking from to 0 so that we don't pick it again				
				}
			break;
		}
		case 1:{
			//case 1 is for sorting by suit
			//sorting by suit, since it is not a number, will be done in alphabetical order going from clubs to spades
			//first it will take all the clubs, then diamonds, then hearts and finally spades
			int location = 0;
			//sets the starting indexas 0;
			string suit = "c";
			//sets the first suit to check for as clubs
			for(int i = 0; i < 4; i++){
				//for loop that runs through all of the different types of suits
				for(int j = 0; j < 7; j++){
					//for loop that runs through every card in the list of cards
					if(cards[j].getSuit() == suit)
					//if the card we are looking at is the suit we are currently looking for
					{
						newCards[location] = cards[j];
						//we add the cards to the list
						location++;
						//we increase location so that the next card is added after
					}
				}		
				if(i==0){
					//if we are finished looking for clubs we will now check for diamonds
					suit = "d";
				}
				else if(i==1){
					//if we are finished looking for diamonds we will now check for hearts
					suit = "h";
				}
				else if(i==2){
					//if we are finsihed checking for hearts we will now check for spades
					suit = "s";
				}
			}
			break;
		}

	}
	for (int i = 0; i < 7; i++){
		//this refills card with it's original values in cased they were changed in the method
		cards[i] = cardHolder[i];
	}
	return newCards;
	//returns the set of sorted cards
}

int evaluateHandP(Player* plyr, Card table[]){	
	//add the cards on the table to the players had and organize by rank
	//go through from highest hand to lowest hand until one is used with the default being high card
	//may want to make the return type an array to solve ties
	int value = 0;
	//value will be based off how strong of a hand you have
	//the type of hand you have will determine the hundreth's place
	//If there is a tie amongst two players then we will use either the highest card, or the rank of the cards in the hand to determine the winner
	Card* cards = new Card[7];
	// I will combine all of the cards from the table and hand into one hand to determine the best hand
	for (int i = 0; i < 2; i++){
		//this for loop will add both of the players cards to a list to create a hand
		cards[i] = plyr->getCardP(i);
	}
	for (int i = 2; i < 7; i++){
		//this for loop adds all of the cards on the table to the same list to determine the hand
		//the for loop starts at 2 since we already have the first two cards from player
		cards[i] = table[i-2];
	}
	Card* suited = cardSort(1, cards);
	//This array of cards will take all the cards and sort them by their suit alphabetically
	Card* ranked = cardSort(0, cards);
	//This array of cards will take all the cards and sort them by their rank
	Card* RandS = cardSort(1, ranked);
	//This array takes the cards already sorted by rank and then sorts them by suit
	//RandS will be used to make testing for a straight flush easier to check for
	/*cout << endl << " Ranked ";
	//This shows the list of cards in order by rank
	for(int z = 0; z < 7; z++){
		cout << ranked[z].getRank() << ranked[z].getSuit() << " ";
	}
	cout << endl << " Suited ";
	//This shows the list of cards in order by suit
	for(int z = 0; z < 7; z++){
		cout << suited[z].getRank() << suited[z].getSuit() << " ";
	}
	cout << endl << " Ranked and Suited ";
	//This shows the list of cards in order by rank and suit
	for(int z = 0; z < 7; z++){
		cout << RandS[z].getRank() << RandS[z].getSuit() << " ";
	}*/
	
	//9) Straight Flush
	for (int i = 0; i < 3; i++){
		//out of the list there are three possible linear sets: first five, middle five, last five
		if((RandS[i].getSuit() == RandS[i+4].getSuit()) && ((RandS[i].getRank() + 4) == (RandS[i+1].getRank() + 3) && (RandS[i].getRank() + 4) == 
		(RandS[i+2].getRank() + 2) && (RandS[i].getRank() + 4) == (RandS[i+3].getRank() + 1) && (RandS[i].getRank() + 4) == RandS[i+4].getRank())){
			//This large if statement first makes sure that both the ends are the same suit. This works since we order the entire list by suit 
			//at the end so we know if both ends are the same then the middle ones are too
			//Then it checks to make sure that the cards go in ascending order. We don't have to worry about duplicated messing this up
			//since we ordered it by suit second and there can not be two cards with the same rank and suit
			value += 900;
			//adds 900 to the hand's value making straight flush the most powerful hand
			value += RandS[i+4].getRank();
			//adds the highest ranked card in the straight in case of a tie
			return value;
			//returns the value of the hand
		}
		else if(RandS[i].getRank() == 1){
			//This else if is to check if there is a royal flush
			if(RandS[i+1].getRank() == 10){
				if ((RandS[i].getSuit() == RandS[i+4].getSuit()) && (RandS[i+1].getRank() + 3) == (RandS[i+2].getRank() + 2) 
				&& (RandS[i+1].getRank() + 3) == (RandS[i+3].getRank() + 1) && (RandS[i+1].getRank() + 3) == RandS[i+4].getRank()){
					value += 900;
					//adds 900 to the hand's value making straight flush the most powerful hand
					value += 14;
					//adds 14 since the highest card is always ace in a royal flush
					return value;
					//returns the value of the hand
				}
			}
			else if(RandS[i+2].getRank() == 10){
				if ((RandS[i].getSuit() == RandS[i+5].getSuit()) && (RandS[i+2].getRank() + 3) == (RandS[i+3].getRank() + 2) 
				&& (RandS[i+2].getRank() + 3) == (RandS[i+4].getRank() + 1) && (RandS[i+2].getRank() + 3) == RandS[i+5].getRank()){
					value += 900;
					//adds 900 to the hand's value making straight flush the most powerful hand
					value += 14;
					//adds 14 since the highest card is always ace in a royal flush
					return value;
					//returns the value of the hand
				}
			}
			else if(RandS[i+3].getRank() == 10){
				if ((RandS[i].getSuit() == RandS[i+6].getSuit()) && (RandS[i+3].getRank() + 3) == (RandS[i+4].getRank() + 2) 
				&& (RandS[i+3].getRank() + 3) == (RandS[i+5].getRank() + 1) && (RandS[i+3].getRank() + 3) == RandS[i+6].getRank()){
					value += 900;
					//adds 900 to the hand's value making straight flush the most powerful hand
					value += 14;
					//adds 14 since the highest card is always ace in a royal flush
					return value;
					//returns the value of the hand
				}
			}
		}
	}
	
	//8) 4 of a kind
	for (int i = 0; i < 4; i++){
		//out of the list there are four possible linear sets
		if(ranked[i].getRank() == ranked[i+1].getRank() && ranked[i].getRank() == ranked[i+2].getRank() 
		 && ranked[i].getRank() == ranked[i+3].getRank()){
		 	//compares each card to the first card. If they are all true then we have a four of a kind
			value += 800;
			//adds 800 to the hand's value
			value += ranked[i].getRank();
			//adds the rank of the cards in the four of a kind
			return value;
			//returns the value of the hand
		}
	}
	
	//7) Full House
	for (int i = 0; i < 5; i++){
		//This first loop checks for a three of a kind
		if(ranked[i].getRank() == ranked[i+1].getRank() && ranked[i].getRank() == ranked[i+2].getRank()){
			//if a three of a kind is found
			for(int j = 0; j < 6; j++){
				//The second loop checks for a pair that is not within the three of a kind
				if(j < i || j < (i+2)){
					//makes sure that it is not using any of the cards in the three of a kind
					if(ranked[j].getRank() == ranked[j+1].getRank()){
						//checks to see if the current card and the next card make a pair and if so you have a full house
						value += 700;
						//add 700 to the hand's value
						value += ranked[i].getRank();
						//adds the rank of the three of a kind cards to the value
						return value;
						//returns the value of the hand
					}
				}
			}
		}
	}
	
	//6) Flush
	for(int i = 0; i < 3; i++){
		//This method will use the suited cards
		//like the straight there are three possible linear options
		if(suited[i].getSuit() == suited[i+4].getSuit()){
			//if the last card is the same suit as the first card we can assume all the cards inbetween are the same and it's a flush
			value += 600;
			//adds 600 to the value of the hand
			if(plyr->getCardP(0).getRank()>plyr->getCardP(1).getRank()){
				//this if statement checks to see what the highest card the player has is
				value += plyr->getCardP(0).getRank();
			}
			else if(plyr->getCardP(1).getRank()>plyr->getCardP(0).getRank()){
				//this else if checks to make sure that if the first isn't the largest rank then you add the second card in the player's hand
				value += plyr->getCardP(1).getRank();
			}
			return value;
			//returns the value of the hand
		}
	}
	
	//5) Straight
	Card* straightCheck = new Card[7];
	//creates a new array of cards that I will use to remove duplicates
	int straightCtr = 1;
	//The ctr will be used so I don't go out of bounds when looking for items in an array
	//cout << endl << " Removing duplicates: ";
	//This prints out the list of cards removing any duplicates
	for(int i = 0; i < 7; i++){
		if (i == 0){
			straightCheck[i] = ranked[i];
			//The first card is defaultly added to the list
			//cout << straightCheck[i].getRank() << straightCheck[i].getSuit() << " ";
		}
		else{
			//if it is not the first card we check to see if the card has the same value as the card before it
			if(ranked[i].getRank() == straightCheck[i-straightCtr].getRank()){
				//if they are the same we add to the the ctr
				straightCtr++;
			}
			else{
				//if they aren't the same we keep the card and add it to the list
				straightCheck[i-straightCtr+1] = ranked[i];
			}
			//cout << straightCheck[i].getRank() << straightCheck[i].getSuit() << " ";
		}
	}
	for(int i = 0; i < 4 - straightCtr; i++){
		//goes through every linear set of five within the cards that are left
		if((straightCheck[i].getRank() + 4) == (straightCheck[i+1].getRank() + 3) && (straightCheck[i].getRank() + 4) == (straightCheck[i+2].getRank() + 2)
		&& (straightCheck[i].getRank() + 4) == (straightCheck[i+3].getRank() + 1) && (straightCheck[i].getRank() + 4)  == (straightCheck[i+4].getRank()) &&
			straightCheck[i+4].getRank() != 0){
			//checks to make sure that the cards go in ascending order starting from the card that we are looking at
			value += 500;
			//adds 500 to the value
			value += straightCheck[i+4].getRank();
			//adds the rank of the highest card in the straight
			return value;
			//returns the value of the hand
		}
		else if(straightCheck[i].getRank() == 1){
			//This else if is to check if there is an ace which potentially means a 10,J,Q,K,A straight
			if(straightCheck[i+1].getRank() == 10 && straightCheck[4].getRank() != 0){
				//makes sure that the last card needed to make a straight is not null and that we are starting at a 10 after the ace
				if ((straightCheck[i+1].getRank() + 3) == (straightCheck[i+2].getRank() + 2) && (straightCheck[i+1].getRank() + 3)
				 == (straightCheck[i+3].getRank() + 1) && (straightCheck[i+1].getRank() + 3) == straightCheck[i+4].getRank()){
				 	//Checks that the cards from 10 on are in ascending order
					value += 500;
					//adds 500 to the hand's value
					value += 14;
					//adds 14 since the highest card is always ace 
					return value;
					//returns the value of the hand
				}
			}
			else if(straightCheck[i+2].getRank() == 10 && straightCheck[5].getRank() != 0){
				//makes sure that the last card needed to make a straight is not null and that we are starting at a 10 after the ace
				if ((straightCheck[i+2].getRank() + 3) == (straightCheck[i+3].getRank() + 2) && (straightCheck[i+2].getRank() + 3) 
				== (straightCheck[i+4].getRank() + 1) && (straightCheck[i+2].getRank() + 3) == straightCheck[i+5].getRank()){
					//Checks that the cards from 10 on are in ascending order
					value += 500;
					//adds 500 to the hand's value
					value += 14;
					//adds 14 since the highest card is always ace 
					return value;
					//returns the value of the hand
				}
			}
			else if(straightCheck[i+3].getRank() == 10 && straightCheck[6].getRank() != 0){
				//makes sure that the last card needed to make a straight is not null and that we are starting at a 10 after the ace
				if ((straightCheck[i+3].getRank() + 3) == (straightCheck[i+4].getRank() + 2) && (straightCheck[i+3].getRank() + 3)
				 == (straightCheck[i+5].getRank() + 1) && (straightCheck[i+3].getRank() + 3) == straightCheck[i+6].getRank()){
				 	//Checks that the cards from 10 on are in ascending order
					value += 500;
					//adds 500 to the hand's value
					value += 14;
					//adds 14 since the highest card is always ace 
					return value;
					//returns the value of the hand
				}
			}
		}
	}
	
	//4) 3 of a kind
	for (int i = 0; i < 5; i++){
		//checks for all of the linear sets of three in the ranked cards
		if(ranked[i].getRank() == ranked[i+1].getRank() && ranked[i].getRank() == ranked[i+2].getRank()){
			//if three cards are found to have the same value
			value += 400;
			//adds 400 to the hand's value
			value += ranked[i].getRank();
			//adds the rank of the cards in the three of a kind
			return value;
			//returns the value of the hand
		}
	}
	
	//3) 2 pair
	for (int i = 0; i < 6; i++){
		//checks for all of the linear pairs
		if(ranked[i].getRank() == ranked[i+1].getRank()){
			//checks to make sure that the ranks are equal
			for(int j = 0; j < 6; j++){
				//starts to check for a second pair and makes sure that it isn't the same as the first
				if(j < i || j < (i+1)){
					if(ranked[j].getRank() == ranked[j+1].getRank() && ranked[j].getRank() != ranked[i].getRank()){
						//if there is another pair and if their value is not the same as the first pair
						value += 300;
						//adds 300 to the hand's value 
						value += ranked[j].getRank();
						//adds the value of the higher pair to the value
						return value;
						//returns the value of the hand
					}
				}
			}
		}
	}
	
	//2) pair
	for(int i = 0; i < 6; i++){
		//checks for every linear pair
		if(ranked[i].getRank() == ranked[i+1].getRank()){
			//if the ranks of two cards are the same
			value += 200;
			//adds 200 to the hand's value
			value += ranked[i].getRank();
			//adds the rank of the pair to the value
			return value;
			//returns the value of the hand
		}
	}
	
	//1) high card
	if(plyr->getCardP(0).getRank()>plyr->getCardP(1).getRank()){
		//this checks to see if the first card is the highest card
		value += plyr->getCardP(0).getRank();
		//adds the rank of the first card to value
	}
	else if(plyr->getCardP(1).getRank()>plyr->getCardP(0).getRank()){
		//this checks if the second card is the highest card in the players hand
		value += plyr->getCardP(1).getRank();
		//adds the rank of the second card to value
	}
	if(value % 100 == 1)
	{
		value += 13;
	}
	return value;
	//returns the value of the hand
}
/*void newGameP(){
	//look to seeing if you can jump to a line of code randomly, maybe call main?
	cout << "12";
}*/
