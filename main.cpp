
#include "Board.cpp"
#include "Player.cpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//declaring functions
string convertCharecterType(int charecterNum);
string convertAdvisorType(int advisorNum);
void setDefualtAttributes(Player& player);
void mainMenu(string playerName, int player1Pos, int playerNum, int player1DP, int accPoints, int effPoints, int insPoints, string playerAdvisor, int player2DP, int player2Pos);
int playTurn();

// Before the game starts
int main(){
    srand(time(0));

    cout << "Welcome to Journey Though Genome.\nThrough this journey it is your goal to collect more dicovery points than your other scientist counterpart.\n" << endl;

    cout << "There are two types of journeys you can go on." << endl;
    cout << "A Training Fellowship, where you are equipped with essential traits like (accuracy, efficiency, and insight) needed for future challenges.\nThe training requires an initial investment of -5,000 Discover Points but, you are given an additional 500 Accuracy Points, 500 Efficiency Points, and 1,000 Insight Points" << endl;
    cout << "A Direct Lab Assignment, where You jump directly into the life of DNA sequencing with an additional 5,000 Discover Points.\nIn addition, this path provides an additional 200 Accuracy Points, 200 Efficiency Points, and 200 Insight Points. However you will not get an initial advisor if you choose this journey.\n" << endl;

    cout << "Player 1, which type of journey would you like to embark on (enter the number)?: " << endl;
    cout << "1. Training Fellowship" << endl;
    cout << "2. Direct Lab Assignment" << endl;
    int player1Journey;
    cin >> player1Journey;

    cout << "Player 1, What charecter would you like to play as (enter the number): " << endl;
    cout << "1. Dr.Leo|5|500|500|1000|20000" << endl;
    cout << "2. Dr.Helix|8|900|600|600|20000" << endl;
    cout << "3. Dr.Panthera|12|900|700|500|20000" << endl;
    cout << "4. Dr.Adenine|7|600|500|900|20000" << endl;
    cout << "5. Dr.K-mer|18|1000|500|500|20000" << endl;
    int player1Charecter;
    cin >> player1Charecter;
    string player1Name = convertCharecterType(player1Charecter);

    string player1Advisor;
        if (player1Journey == 1){
            cout << player1Name << ", which advisor would you like to support you (enter the number)?" << endl;
            cout << "1. Dr. Aliquot - A master of the \"wet lab\", assisting in avoiding contamination." << endl;
            cout << "2. Dr. Assembler - An expert who helps improve efficiency and streamlines pipelines." << endl;
            cout << "3. Dr. Pop-Gen - A genetics specialist with insight for identifying rare genetic variants." << endl;
            cout << "4. Dr. Bio-Script - The genius behind the data analysis, helps debug code." << endl;
            cout << "5. Dr. Loci - Your biggest supporter assisting you in learning the equipment." << endl;
            int advisor1Num;
            cin >> advisor1Num;
            player1Advisor = convertAdvisorType(advisor1Num);
        } else {
            cout << player1Name << ", you have chosen the Direct Lab Assignment, therefore, you do not get an advisor" << endl;
            player1Advisor = "No Advisor";
        }


    cout << "Player 2, which type of journey would you like to embark on (enter the number)?: " << endl;
    cout << "1. Training Fellowship" << endl;
    cout << "2. Direct Lab Assignment" << endl;
    int player2Journey;
    cin >> player2Journey;

    cout << "Player 2, What charecter would you like to play as (enter the number): " << endl;
    cout << "1. Dr.Leo|5|500|500|1000|20000" << endl;
    cout << "2. Dr.Helix|8|900|600|600|20000" << endl;
    cout << "3. Dr.Panthera|12|900|700|500|20000" << endl;
    cout << "4. Dr.Adenine|7|600|500|900|20000" << endl;
    cout << "5. Dr.K-mer|18|1000|500|500|20000" << endl;
    int player2Charecter;
    cin >> player2Charecter;
    string player2Name = convertCharecterType(player2Charecter);

    string player2Advisor;
    if (player2Journey == 1){
        cout << player2Name << ", which advisor would you like to support you (enter the number)?" << endl;
        cout << "1. Dr. Aliquot - A master of the \"wet lab\", assisting in avoiding contamination." << endl;
        cout << "2. Dr. Assembler - An expert who helps improve efficiency and streamlines pipelines." << endl;
        cout << "3. Dr. Pop-Gen - A genetics specialist with insight for identifying rare genetic variants." << endl;
        cout << "4. Dr. Bio-Script - The genius behind the data analysis, helps debug code." << endl;
        cout << "5. Dr. Loci - Your biggest supporter assisting you in learning the equipment." << endl;
        int advisor2Num;
        cin >> advisor2Num;
        string player2Advisor = convertAdvisorType(advisor2Num);
    } else {
        cout << player2Name << ", you have chosen the Direct Lab Assignment, therefore, you do not get an advisor" << endl;
        player2Advisor = "No Advisor";
    }
    

    Board mainBoard(player1Journey, player2Journey);
    Player player1(player1Name, player1Advisor, player1Journey);
    Player player2(player2Name, player2Advisor, player2Journey);
    setDefualtAttributes(player1);
    setDefualtAttributes(player2);

    // Acutal Repeated Part of game
    // Win Condition
    bool player1End = false;
    bool player2End = false;

    //loop runs until both players are at the end
    while (!(player1End && player2End)){
        // Player 1's Turn
        mainBoard.displayBoard();
        mainMenu(player1Name, mainBoard.getPlayerPosition(0), 0, player1.getDiscoveryPoints(), player1.getAccuracy(), player1.getEfficiency(), player1.getInsight(), player1.getAdvisor(), player2.getDiscoveryPoints(), mainBoard.getPlayerPosition(1));
        if (!player1End){
            for (int i = 0; i < playTurn(); i++){
                if (mainBoard.movePlayer(0)){
                    player1End = true;
                    break;
                }
            }
            // check the tile were on
        } else {
            cout << player1Name << " you have reached the end and have to wait for the other player" << endl;
        }
    
        // Player 2's Turn
        mainBoard.displayBoard();
        mainMenu(player2Name, mainBoard.getPlayerPosition(1), 1, player2.getDiscoveryPoints(), player2.getAccuracy(), player2.getEfficiency(), player2.getInsight(), player2.getAdvisor(), player1.getDiscoveryPoints(), mainBoard.getPlayerPosition(0));
        if (!player2End){
            for (int i = 0; i < playTurn(); i++){
                if (mainBoard.movePlayer(1)){
                    player2End = true;
                    break;
                }
            }
            // check the tile were on
        } else {
            cout << player2Name << " you have reached the end and have to wait for the other player" << endl;
        }
    
    }
    mainBoard.displayBoard();
    cout << "You\'ve both reached the end. Congradulations, tallying up the points now."<< endl;

    //Post game stats to discovery point conversion
    int additionalDiscoveryPoints = ((player1.getAccuracy() / 100)*1000) + ((player1.getEfficiency() / 100)*1000) + ((player1.getInsight() / 100)*1000);
    player1.setDiscoveryPoints(player1.getDiscoveryPoints() + additionalDiscoveryPoints);

    additionalDiscoveryPoints = ((player2.getAccuracy() / 100)*1000) + ((player2.getEfficiency() / 100)*1000) + ((player2.getInsight() / 100)*1000);
    player2.setDiscoveryPoints(player2.getDiscoveryPoints() + additionalDiscoveryPoints);

    //Displaying the winner
    string winner;
    if (player1.getDiscoveryPoints() > player2.getDiscoveryPoints()){
        cout << "The winner is: " << player1Name << "!" << endl;
        winner = player1Name;
    } else if (player2.getDiscoveryPoints() > player1.getDiscoveryPoints()){
        cout << "The winner is: " << player2Name << "!" << endl;
        winner = player2Name;
    } else {
        cout << "The game was a tie." << endl;
        winner = "Tie";
    }

    // Appends to a file to keep track of final scores over time
    ofstream postGameFile("GameScores.txt", ios::app);
    if (postGameFile.is_open()) {
        postGameFile << "The winner was " << winner << "| " << player1Name << " had " << player1.getDiscoveryPoints() << " Discovery Points| " << player2Name << " had " << player2.getDiscoveryPoints() << " Discovery Points" << endl;
    }
    postGameFile.close();
}

void mainMenu(string playerName, int player1Pos, int playerNum, int player1DP, int accPoints, int effPoints, int insPoints, string playerAdvisor, int player2DP, int player2Pos){
    string temp;
    int userInput;
    cout << "Main Menu" << endl;
    cout << "Hello, " << playerName << ", What would you like to do (Enter the number)?" << endl;
    cout << "1. Check your progress" << endl;
    cout << "2. Check your board position" << endl;
    cout << "3. See your advisor" << endl;
    cout << "4. Check your opponents score" << endl;
    cout << "5. Proceed with your turn, spin the wheel" << endl;
    cin >> userInput;

    switch (userInput) {
        case 1:
            cout << "Do you want to 1. review your discover points, or 2. Review your stats (type the number)."<< endl;
            cin >> userInput;
            if (userInput == 1){
                cout << "Discovery Points: " <<  player1DP << endl;
            } else if (userInput == 2){
                cout << "Charecter Name: " << playerName << endl;
                cout << "Accuracy: " << accPoints << endl;
                cout << "Efficiency: " << effPoints << endl;
                cout << "Insight: " << insPoints << endl;
            }
            cout << "press 1 to go back" << endl;
            cin >> userInput;
            mainMenu(playerName, player1Pos, playerNum, player1DP, accPoints, effPoints, insPoints, playerAdvisor, player2DP, player2Pos);
            break;
        case 2:
            cout << "You have " << 52-player1Pos << " more tiles to go" << endl;
            cout << "press 1 to go back" << endl;
            cin >> userInput;
            mainMenu(playerName, player1Pos, playerNum, player1DP, accPoints, effPoints, insPoints, playerAdvisor, player2DP, player2Pos);
            break;
        case 3:
            if (playerAdvisor == "Dr.Aliquot"){
                cout << "Dr. Aliquot - A master of the \"wet lab\", assisting in avoiding contamination." << endl;
            } else if (playerAdvisor == "Dr.Assembler"){
                cout << "Dr. Assembler - An expert who helps improve efficiency and streamlines pipelines." << endl;
            } else if (playerAdvisor == "Dr.Pop-Gen"){
                cout << "Dr. Pop-Gen - A genetics specialist with insight for identifying rare genetic variants." << endl;
            } else if (playerAdvisor == "Bio-Script"){
                cout << "Dr. Bio-Script - The genius behind the data analysis, helps debug code." << endl;
            } else if (playerAdvisor == "Dr.Loci"){
                cout << "Dr. Loci - Your biggest supporter assisting you in learning the equipment." << endl;
            } else {
                cout << "you do not have an advisor" << endl;
            }
            cout << "press 1 to go back" << endl;
            cin >> userInput;
            mainMenu(playerName, player1Pos, playerNum, player1DP, accPoints, effPoints, insPoints, playerAdvisor, player2DP, player2Pos);
            break;
        case 4:
        cout << "Do you want to 1. review their discover points, or 2. check their board position (type the number)."<< endl;
            cin >> userInput;
            if (userInput == 1){
                cout << "Your opponent has " << player2DP << " Discovery Points." << endl;
            } else if (userInput == 2){
                cout << "Your opponent has " << 52-player1Pos << " more tiles to go" << endl;
            }
            cout << "press 1 to go back" << endl;
            cin >> userInput;
            mainMenu(playerName, player1Pos, playerNum, player1DP, accPoints, effPoints, insPoints, playerAdvisor, player2DP, player2Pos);
            break;
        case 5:
            break;
    }
}

//Essentially rolls a dice
int playTurn(){
    cout << "spinning wheel..." << endl;
    return ((rand() % 6) + 1);
}

//converts the number associated with each charecter to the name
string convertCharecterType(int charecterNum){
    string charecterName;
    switch (charecterNum) {
        case 1:
            charecterName = "Dr.Leo";
            break;
        case 2:
            charecterName = "Dr.Helix";
            break;
        case 3:
            charecterName = "Dr.Panthera";
            break;
        case 4:
            charecterName = "Dr.Adenine";
            break;
        case 5:
            charecterName = "Dr.K-mer";
            break;
    }

    return charecterName;
}

//converts the number associated with each advisor to the name
string convertAdvisorType(int advisorNum){
    string advisorName;
    switch (advisorNum) {
        case 1:
            advisorName = "Dr.Aliquot";
            break;
        case 2:
            advisorName = "Dr.Assembler";
            break;
        case 3:
            advisorName = "Dr.Pop-Gen";
            break;
        case 4:
            advisorName = "Dr.Bio-Script";
            break;
        case 5:
            advisorName = "Dr.Loci";
            break;
    }

    return advisorName;
}

void setDefualtAttributes(Player& player){
    fstream charecterFile;
    int delimIndex1;
    int delimIndex2;
    int delimIndex3;
    int delimIndex4;
    int delimIndex5;

    string charecterName;
    string experience;
    string accuracy;
    string efficiency;
    string insight;
    string discoveryPoints;


    string delim = "|";
    charecterFile.open("characters.txt");
    if (charecterFile.is_open()) {
        string line;
        while (getline(charecterFile, line)) {
            delimIndex1 = line.find(delim);
            delimIndex2 = line.substr(delimIndex1+1).find(delim) + delimIndex1 + 1;
            delimIndex3 = line.substr(delimIndex2+1).find(delim) + delimIndex2 + 1;
            delimIndex4 = line.substr(delimIndex3+1).find(delim) + delimIndex3 + 1;
            delimIndex5 = line.substr(delimIndex4+1).find(delim) + delimIndex4 + 1;

            charecterName = line.substr(0, delimIndex1);
            experience = line.substr(delimIndex1+1, delimIndex2 - delimIndex1-1);
            accuracy = line.substr(delimIndex2+1, delimIndex3 - delimIndex2-1);
            efficiency = line.substr(delimIndex3+1, delimIndex4-delimIndex3-1);
            insight = line.substr(delimIndex4+1, delimIndex5-delimIndex4-1);
            discoveryPoints = line.substr(delimIndex5+1);

            if (charecterName == player.getName()){
                player.setExperience(stoi(experience));
                player.setAccuracy(stoi(accuracy));
                player.setEfficiency(stoi(efficiency));
                player.setInsight(stoi(insight));
                player.setDiscoveryPoints(stoi(discoveryPoints));
            }
       }
    }
    charecterFile.close();
    if (player.getPath() == 1){
        player.setAccuracy(player.getAccuracy() + 500);
        player.setEfficiency(player.getEfficiency() + 500);
        player.setInsight(player.getInsight() + 1000);
        player.setDiscoveryPoints(player.getDiscoveryPoints() - 5000);

    } else if (player.getPath() == 2){
        player.setAccuracy(player.getAccuracy() + 200);
        player.setEfficiency(player.getEfficiency() + 200);
        player.setInsight(player.getInsight() + 200);
        player.setDiscoveryPoints(player.getDiscoveryPoints() + 5000);
    }
}