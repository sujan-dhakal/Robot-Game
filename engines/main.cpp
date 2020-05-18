#include <iostream>
#include "engine.h"
#include "robots.h"

using namespace std;

int main() {

    cout <<"Which game do you wanna play?"<<endl;           /// ask user which game to play
    cout << "1. robot"<<endl;
    cout << "Type here. (1): ";
    char game;
    cin >> game;
    if (game=='1'){                                 // 1 for robot
        cout<<'\n';
        cout << "ROBOT"<< endl;
        cout<<'\n';

        bool play=true;

        while (play) {
            cout<<'\n';
            Robots robots(5,5);
            if (robots.getGameboard()!=NULL) {
                for (int i=0; i<robots.getROWS(); i++){
                    if (robots.getGameboard()[i]!=NULL) {
                        for (int j=0; j<robots.getCOLS(); j++){
                            cout<< " " << robots.getGameboard()[i][j];
                        }
                    }
                    cout << endl;
                }
            }

            while (!robots.gameLost && !robots.gameWon()) {
                cout<<'\n';
                cout <<"Number of Safe Teleportation: "<< robots.ST<<endl;
                cout<<'\n';
                cout << "Enter the command: ";
                char input;
                cin >> input;
                robots.input(input);
                cout<<'\n';
                if (robots.getGameboard()!=NULL){
                    for (int i=0; i<robots.getROWS(); i++){
                        if (robots.getGameboard()[i]!=NULL) {
                            for (int j=0; j<robots.getCOLS(); j++){
                                cout<< " " << robots.getGameboard()[i][j];
                            }
                        }
                        cout << endl;
                    }
                }
            }
            cout<<'\n';
            cout<<'\n';
            cout<<"Do you want to play again? y-yes n-no: ";
            char enter;
            cin >> enter;
            if (enter=='y'){
                play=true;
            } else if (enter=='n') {
                play=false;
            } else {
                cout << "Invalid Command. The program ended.";
                play=false;
            }
        }
    }
    return 0;
}
