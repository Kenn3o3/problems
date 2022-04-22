#include<iostream>
#include<cstring>
using namespace std;
class Card
{
public:
    Card();
    void setSuit(char* n){
        suit = n;
    };
    void setValue(int v){
        value = v;
    };
    void setNum(int num){
        number = num;
    };
    void setCheck(int c){
        check = c;
    };

    char* getSuit(){
        return suit;
    };
    int getVal(){
        return value;
    };
    int getNum(){
        return number;
    };
    int getCheck(){
        return check;
    };
private:
    bool check; //whether the card has been played
    char *suit;   //Heart, Diamond, Club, Spade
    int value; //1, 2, 3, 4
    int number;   //1(A), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11(J), 12(Q), and 13(K).

};
void initSequence(Card* cardSeq, char suitName[][10], int* j, int* num);
void printSequence(Card* cardSeq);
void printValid(Card* cardSeq);
void printCard(Card card);
Card::Card(){
    suit = new char[10];
    value = 0;
    number = 0;
    check = false;
}
int main() {
    Card cardSeq[13];
    Card ComcardSeq[13];  //card sequence for the computer
    char suitName[][10] = { "Heart","Diamond","Club","Spade" };
    int seed;
    cout << "Enter the seed for random number generation: " << endl;
    cin >> seed;
    int j[13]; //value -> suit
    int num[13]; //num of card
    switch (seed) {
        case 1:
            j[0] = 4; j[1] = 3; j[2] = 2, j[3] = 1, j[4] = 1, j[5] = 2; j[6] = 4; j[7]
                                                                                          = 3; j[8] = 3; j[9] = 2; j[10] = 2; j[11] = 2; j[12] = 3;
            num[0] = 12; num[1] = 11; num[2] = 10; num[3] = 11; num[4] = 4; num[5] =
                                                                                    11; num[6] = 11; num[7] = 13; num[8] = 3; num[9] = 7; num[10] = 2; num[11] = 5;
            num[12] = 9;
            break;
        case 2:
            j[0] = 2; j[1] = 2; j[2] = 3, j[3] = 1, j[4] = 3, j[5] = 4; j[6] = 4;
            j[7] = 4; j[8] = 3; j[9] = 4; j[10] = 4; j[11] = 2; j[12] = 4;
            num[0] = 3; num[1] = 5; num[2] = 7; num[3] = 8; num[4] = 11; num[5] = 4;
            num[6] = 10; num[7] = 2; num[8] = 12; num[9] = 9; num[10] = 11; num[11] = 12;
            num[12] = 3;
            break;
        case 3:
            j[0] = 4; j[1] = 3; j[2] = 2, j[3] = 1, j[4] = 2, j[5] = 4; j[6] = 2; j[7]
                                                                                          = 1; j[8] = 3; j[9] = 3; j[10] = 3; j[11] = 1; j[12] = 3;
            num[0] = 11; num[1] = 10; num[2] = 10; num[3] = 10; num[4] = 1; num[5] =
                                                                                    13; num[6] = 7; num[7] = 7; num[8] = 9; num[9] = 6; num[10] = 12; num[11] = 4;
            num[12] = 11;
            break;
        case 4:
            j[0] = 4; j[1] = 4; j[2] = 2, j[3] = 1, j[4] = 3, j[5] = 3; j[6] = 3;
            j[7] = 1; j[8] = 1; j[9] = 3; j[10] = 4; j[11] = 4; j[12] = 4;
            num[0] = 10; num[1] = 7; num[2] = 9; num[3] = 4; num[4] = 10; num[5] = 12;
            num[6] = 3; num[7] = 13; num[8] = 5; num[9] = 13; num[10] = 4; num[11] = 1; num[12]
                                                                                                = 11;
            break;
        case 5:
            j[0] = 4; j[1] = 3; j[2] = 3, j[3] = 4, j[4] = 4, j[5] = 2; j[6] = 3;
            j[7] = 4; j[8] = 1; j[9] = 1; j[10] = 1; j[11] = 1; j[12] = 1;
            num[0] = 5; num[1] = 4; num[2] = 13; num[3] = 1; num[4] = 3; num[5] = 7;
            num[6] = 12; num[7] = 11; num[8] = 10; num[9] = 13; num[10] = 7; num[11] = 5;
            num[12] = 4;
            break;
        case 6:
            j[0] = 3; j[1] = 4; j[2] = 4, j[3] = 4, j[4] = 1, j[5] = 4; j[6] = 2;
            j[7] = 1; j[8] = 3; j[9] = 4; j[10] = 4; j[11] = 3; j[12] = 3;
            num[0] = 7; num[1] = 3; num[2] = 11; num[3] = 4; num[4] = 13; num[5] = 2;
            num[6] = 12; num[7] = 10; num[8] = 3; num[9] = 10; num[10] = 6; num[11] = 10;
            num[12] = 9;
            break;
        case 7:
            j[0] = 2; j[1] = 1; j[2] = 4, j[3] = 4, j[4] = 1, j[5] = 2; j[6] = 1;
            j[7] = 4; j[8] = 3; j[9] = 2; j[10] = 4; j[11] = 4; j[12] = 2;
            num[0] = 5; num[1] = 3; num[2] = 1; num[3] = 9; num[4] = 4; num[5] = 12;
            num[6] = 11; num[7] = 2; num[8] = 12; num[9] = 2; num[10] = 11; num[11] = 13;
            num[12] = 9;
            break;
        case 8:
            j[0] = 3; j[1] = 1; j[2] = 4, j[3] = 2, j[4] = 4, j[5] = 4; j[6] = 1;
            j[7] = 2; j[8] = 4; j[9] = 1; j[10] = 3; j[11] = 2; j[12] = 4;
            num[0] = 3; num[1] = 8; num[2] = 2; num[3] = 11; num[4] = 3; num[5] = 9;
            num[6] = 5; num[7] = 2; num[8] = 5; num[9] = 4; num[10] = 12; num[11] = 10; num[12]
                                                                                                = 7;
            break;
        case 9:
            j[0] = 4; j[1] = 3; j[2] = 2, j[3] = 3, j[4] = 2, j[5] = 3; j[6] = 4;
            j[7] = 4; j[8] = 3; j[9] = 3; j[10] = 1; j[11] = 2; j[12] = 1;
            num[0] = 11; num[1] = 12; num[2] = 12; num[3] = 4; num[4] = 10; num[5] = 7;
            num[6] = 6; num[7] = 1; num[8] = 6; num[9] = 13; num[10] = 13; num[11] = 5; num[12]
                                                                                                = 4;
            break;
        case 10:
            j[0] = 3; j[1] = 3; j[2] = 4, j[3] = 4, j[4] = 2, j[5] = 4; j[6] = 3;
            j[7] = 2; j[8] = 4; j[9] = 2; j[10] = 2; j[11] = 3; j[12] = 1;
            num[0] = 10; num[1] = 6; num[2] = 7; num[3] = 12; num[4] = 9; num[5] = 6;
            num[6] = 11; num[7] = 11; num[8] = 5; num[9] = 5; num[10] = 1; num[11] = 13;
            num[12] = 4;
            break;
        case 11:
            j[0] = 1; j[1] = 2; j[2] = 1, j[3] = 4, j[4] = 1, j[5] = 3; j[6] = 4;
            j[7] = 2; j[8] = 1; j[9] = 4; j[10] = 3; j[11] = 4; j[12] = 3;
            num[0] = 11; num[1] = 2; num[2] = 4; num[3] = 5; num[4] = 13; num[5] = 3;
            num[6] = 7; num[7] = 7; num[8] = 3; num[9] = 1; num[10] = 12; num[11] = 10; num[12]
                                                                                                = 4;
            break;
        case 12:
            j[0] = 1; j[1] = 1; j[2] = 3, j[3] = 4, j[4] = 4, j[5] = 4; j[6] = 3;
            j[7] = 2; j[8] = 1; j[9] = 4; j[10] = 2; j[11] = 1; j[12] = 2;
            num[0] = 3; num[1] = 4; num[2] = 3; num[3] = 4; num[4] = 5; num[5] = 13;
            num[6] = 11; num[7] = 11; num[8] = 5; num[9] = 2; num[10] = 5; num[11] = 13;
            num[12] = 12;
            break;
        case 13:
            j[0] = 3; j[1] = 4; j[2] = 4, j[3] = 4, j[4] = 1, j[5] = 3; j[6] = 1;
            j[7] = 2; j[8] = 2; j[9] = 1; j[10] = 2; j[11] = 4; j[12] = 4;
            num[0] = 10; num[1] = 10; num[2] = 5; num[3] = 6; num[4] = 7; num[5] = 9;
            num[6] = 8; num[7] = 10; num[8] = 2; num[9] = 11; num[10] = 12; num[11] = 4;
            num[12] = 2;
            break;
        case 14:
            j[0] = 2; j[1] = 1; j[2] = 2, j[3] = 2, j[4] = 3, j[5] = 4; j[6] = 1;
            j[7] = 2; j[8] = 4; j[9] = 1; j[10] = 2; j[11] = 1; j[12] = 4;
            num[0] = 7; num[1] = 13; num[2] = 12; num[3] = 1; num[4] = 6; num[5] = 1;
            num[6] = 7; num[7] = 2; num[8] = 2; num[9] = 4; num[10] = 5; num[11] = 5; num[12] =
                                                                                              9;
            break;
        case 15:
            j[0] = 3; j[1] = 3; j[2] = 2, j[3] = 4, j[4] = 4, j[5] = 1; j[6] = 2;
            j[7] = 4; j[8] = 3; j[9] = 4; j[10] = 3; j[11] = 2; j[12] = 2;
            num[0] = 7; num[1] = 10; num[2] = 3; num[3] = 9; num[4] = 12; num[5] = 5;
            num[6] = 1; num[7] = 5; num[8] = 6; num[9] = 3; num[10] = 3; num[11] = 9; num[12] =
                                                                                              2;
            break;
        case 16:
            j[0] = 4; j[1] = 4; j[2] = 4, j[3] = 4, j[4] = 4, j[5] = 2; j[6] = 4;
            j[7] = 1; j[8] = 2; j[9] = 2; j[10] = 4; j[11] = 3; j[12] = 2;
            num[0] = 5; num[1] = 9; num[2] = 2; num[3] = 11; num[4] = 3; num[5] = 7;
            num[6] = 1; num[7] = 4; num[8] = 12; num[9] = 9; num[10] = 12; num[11] = 7; num[12]
                                                                                                = 10;
            break;
        case 17:
            j[0] = 4; j[1] = 3; j[2] = 3, j[3] = 3, j[4] = 4, j[5] = 4; j[6] = 3;
            j[7] = 4; j[8] = 2; j[9] = 1; j[10] = 3; j[11] = 2; j[12] = 1;
            num[0] = 9; num[1] = 13; num[2] = 9; num[3] = 12; num[4] = 6; num[5] = 10;
            num[6] = 7; num[7] = 4; num[8] = 10; num[9] = 13; num[10] = 6; num[11] = 8; num[12]
                                                                                                = 4;
            break;
        case 18:
            j[0] = 3; j[1] = 3; j[2] = 3, j[3] = 3, j[4] = 1, j[5] = 3; j[6] = 3;
            j[7] = 4; j[8] = 2; j[9] = 1; j[10] = 4; j[11] = 2; j[12] = 2;
            num[0] = 3; num[1] = 4; num[2] = 12; num[3] = 9; num[4] = 11; num[5] = 13;
            num[6] = 11; num[7] = 4; num[8] = 12; num[9] = 4; num[10] = 13; num[11] = 5;
            num[12] = 9;
            break;
        case 19:
            j[0] = 2; j[1] = 1; j[2] = 1, j[3] = 3, j[4] = 1, j[5] = 4; j[6] = 2;
            j[7] = 3; j[8] = 4; j[9] = 4; j[10] = 4; j[11] = 2; j[12] = 2;
            num[0] = 2; num[1] = 4; num[2] = 13; num[3] = 13; num[4] = 5; num[5] = 1;
            num[6] = 5; num[7] = 3; num[8] = 2; num[9] = 4; num[10] = 5; num[11] = 12; num[12]
                                                                                               = 7;
            break;
        case 20:
            j[0] = 2; j[1] = 3; j[2] = 3, j[3] = 4, j[4] = 4, j[5] = 1; j[6] = 2;
            j[7] = 3; j[8] = 2; j[9] = 2; j[10] = 4; j[11] = 3; j[12] = 2;
            num[0] = 7; num[1] = 3; num[2] = 9; num[3] = 13; num[4] = 9; num[5] = 3;
            num[6] = 9; num[7] = 10; num[8] = 5; num[9] = 3; num[10] = 3; num[11] = 13; num[12]
                                                                                                = 1;
            break;
    }

    // TODO: generate and print card sequence for the player
    cout << "Your card sequence:" << endl;
    initSequence(cardSeq, suitName, j, num);
    printSequence(cardSeq);
    cout << endl;
    j[0] = 1; j[1] = 3; j[2] = 1, j[3] = 2, j[4] = 4, j[5] = 1; j[6] = 3; j[7] = 2;
    j[8] = 3; j[9] = 1; j[10] = 1; j[11] = 2; j[12] = 3;
    num[0] = 12; num[1] = 8; num[2] = 9; num[3] = 6; num[4] = 8; num[5] = 1; num[6] = 1; num[7] = 13; num[8] = 2; num[9] = 6; num[10] = 2; num[11] = 4; num[12] = 5;
    //generate card sequence for the computer

    initSequence(ComcardSeq, suitName, j, num);
    cout << "Computer's card sequence:"<<endl;
    printSequence(ComcardSeq);
    cout << endl;
    //sort ComcardSeq by number:
    for(int i =0;i<13;i++){
        if(ComcardSeq[i].getNum()==1){
            ComcardSeq[i].setNum(20);
        }
    }

    int i,jj;
    for(i=0;i<12;i++){
        for(jj=0;jj<12-i;jj++){
            if(ComcardSeq[jj].getNum()>ComcardSeq[jj+1].getNum()){
                Card temp = ComcardSeq[jj];
                ComcardSeq[jj] = ComcardSeq[jj+1];
                ComcardSeq[jj+1] = temp;
            }
        }
    }
    for(int i = 0; i < 13 ; i++){
        if(ComcardSeq[i].getNum() == 20){
            ComcardSeq[i].setNum(1);
        }
    }
    // TODO: play the game
//1: heart, 2: diamond, 3: club, 4: spade
// computer's cards array: ComcardSeq | player's cards array: cardSeq
int round = 1;
int player_point = 0, computer_point = 0;
bool win = true;
int value, number;
Card Player_Card;
Card Computer_Card;
while(round <= 13){
    cout << "========== Round " << round <<" ==========" << endl;
    if(win){
        cout << "Please input two integers to represent the card you plan to play:" << endl;
        //check if the card is in seq -> take the card
        bool inSeq = false;
        bool sameSuit = false;
        while(!inSeq){
            cin >> value >> number;
            for(int i=0; i<13;i++){
                if(cardSeq[i].getVal() == value && cardSeq[i].getNum() == number && cardSeq[i].getCheck() == false){
                    inSeq = true;
                    cardSeq[i].setCheck(true);
                    Player_Card = cardSeq[12];
                    break;
                }
            }
            if(!inSeq){
                cout << "Selected card is not in card sequence" << endl;
            }
        }
        inSeq = false;
        for(int i = 12; i >= 0 ; i--){
            if(ComcardSeq[i].getVal() == value && ComcardSeq[i].getCheck() == false){
                sameSuit = true;
                inSeq = true;
                Computer_Card = ComcardSeq[i];
                ComcardSeq[i].setCheck(true);
                break;
            }
        }
        if(!inSeq){
            for(int i = 0; i < 13 ; i++){
                if(ComcardSeq[i].getCheck() == false){
                    inSeq = true;
                    Computer_Card = ComcardSeq[i];
                    ComcardSeq[i].setCheck(true);
                    break;
                }
            }
        }
        cout << "The computer plays ";
        printCard(Computer_Card);
        cout << endl;
        if(sameSuit){
            if(Computer_Card.getNum() == 1){
                win = false;
            } else if (Player_Card.getNum() == 1){
                win = true;
            } else if (Player_Card.getNum() > Computer_Card.getNum()){
                win = true;
            } else {
                win = false;
            }
        } else{
            win = true;
        }
        if(win){
            player_point++;
            cout << "Player won this round" << endl;
        } else {
            cout << "Computer won this round" << endl;
            computer_point++;
        }
        cout << "Your card sequence:" << endl;
        printValid(cardSeq);
        cout << endl;
        round++;
    } else {
        //computer goes first
        bool hasA = false;
        for(int i = 0; i< 13 ; i++){
            if(ComcardSeq[i].getCheck() == false && ComcardSeq[i].getNum() == 1){
                hasA = true;
                Computer_Card = ComcardSeq[i];
                ComcardSeq[i].setCheck(true);
                break;
            }
        }
        if(!hasA){
            for(int i = 12; i >= 0 ; i--){
                if(ComcardSeq[i].getCheck() == false){
                    Computer_Card = ComcardSeq[i];
                    ComcardSeq[i].setCheck(true);
                    break;
                }
            }
        }
        cout << "The computer plays ";
        printCard(Computer_Card);
        cout << endl;
        bool valid = false;
        bool inSeq = false;
        bool hasSuit = false;
        bool isSuit = false;
        while(!valid){
            valid = false; inSeq = false; hasSuit = false; isSuit = false;
            cout << "Please input two integers to represent the card you plan to play:" << endl;
            cin >> value >> number;
            //check if in seq
            for(int i=0; i<13;i++){
                if(cardSeq[i].getVal() == value && cardSeq[i].getNum() == number && cardSeq[i].getCheck() == false){
                    inSeq = true;
                    break;
                }
            }
            //check if has suit
            for(int i=0; i<13;i++){
                if(cardSeq[i].getVal() == Computer_Card.getVal() && cardSeq[i].getCheck() == false){
                    hasSuit = true;
                    break;
                }
            }
            //check if is suit 1: heart, 2: diamond, 3: club, 4: spade
            if(value == Computer_Card.getVal()){
                isSuit = true;
            }
            if(!inSeq){
                valid = false;
                cout << "Selected card is not in card sequence" << endl;
            } else if(hasSuit && !isSuit){
                valid = false; //1: heart, 2: diamond, 3: club, 4: spade
                cout << "Playing against the rules." << endl;
            } else if(!hasSuit && !isSuit){
                valid = true;
            } else if(hasSuit && isSuit){
                valid = true;
            }
        }
        for(int i = 0; i<13 ; i++){
            if(cardSeq[i].getVal() == value && cardSeq[i].getNum() == number){
                Player_Card = cardSeq[i];
                cardSeq[i].setCheck(true);
                break;
            }
        }
        if(isSuit){ //1: heart, 2: diamond, 3: club, 4: spade
            if(Player_Card.getNum() == 1){
                win = true;
            } else if (Computer_Card.getNum() == 1){
                win = false;
            } else if (Player_Card.getNum() > Computer_Card.getNum()){
                win = true;
            } else {
                win = false;
            }
        } else{
            win = false;
        }
        if(win){
            player_point++;
            cout << "Player won this round" << endl;
        } else {
            cout << "Computer won this round" << endl;
            computer_point++;
        }
        cout << "Your card sequence:" << endl;
        printValid(cardSeq);
        round++;
        cout << endl;
    }

}
cout << "Player got " << player_point << " points, Computer got " << computer_point << " points" << endl;
if(player_point > computer_point){
    cout << "Player win" << endl;
} else {
    cout << "Computer win" << endl;
}


    return 0;
}
void initSequence(Card* cardSeq, char suitName[][10], int* j, int* num) {
    for (int i = 0; i < 13; i++) {
        cardSeq[i].setSuit(suitName[j[i] - 1]);
        cardSeq[i].setValue(j[i]);
        cardSeq[i].setNum(num[i]);
    }
}
void printSequence(Card* cardSeq) {
    for (int i = 0; i < 13; i++) {
        printCard(cardSeq[i]);
    }

}

void printValid(Card* cardSeq) {
    for (int i = 0; i < 13; i++) {
        if (cardSeq[i].getCheck() == false) {
            printCard(cardSeq[i]);
        }
    }
}

void printCard(Card card) {
    if (card.getNum() == 1)
        cout << card.getSuit() << 'A' << " ";
    else if (card.getNum() == 11)
        cout << card.getSuit() << 'J' << " ";
    else if (card.getNum() == 12)
        cout << card.getSuit() << 'Q' << " ";
    else if (card.getNum() == 13)
        cout << card.getSuit() << 'K' << " ";
    else
        cout << card.getSuit() << card.getNum() << " ";
}