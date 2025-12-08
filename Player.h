// Imported Libraries 
#include <string>

// Recognized as "include guards"
// Prevent the board header file from being used more than once
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
    private:
        string playerName;
        string playerAdvisor;
        int playerPath;

        int experience;
        int accuracy;
        int efficiency;
        int insight;
        int discoveryPoints;

    public:
        // Constructor
        Player(string name, string advisor, int path);

        // Getters
        string getName(){
            return playerName;
        }
        string getAdvisor(){
            return playerAdvisor;
        }
        int getPath(){
            return playerPath;
        }
        int getExperience(){
            return experience;
        }
        int getAccuracy(){
            return accuracy;
        }
        int getEfficiency(){
            return efficiency;
        }
        int getInsight(){
            return insight;
        }
        int getDiscoveryPoints(){
            return discoveryPoints;
        }

        //Setters
        void setPlayerName(string name){
            playerName = name;
        }
        void setAdvisor(string advisor){
            playerAdvisor = advisor;
        }
        void setPath(int path){
            playerPath = path;
        }
        void setExperience(int exp){
            experience = exp;
        }
        void setAccuracy(int acc){
            accuracy = acc;
        }
        void setEfficiency(int eff){
            efficiency = eff;
        }
        void setInsight(int ins){
            insight = ins;
        }
        void setDiscoveryPoints(int dp){
            discoveryPoints = dp;
        }
};

#endif