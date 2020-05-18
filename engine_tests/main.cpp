#include <iostream>

#include "gtest/gtest.h"
#include "../engines/engine.h"
#include "../engines/robots.h"

TEST(RobotsTest, MethodInitiateGB) {
    Robots r;
    int noOfRobots=0;
    ASSERT_EQ(r.getOldData(r.getROWS()/2, r.getCOLS()/2), 'h') <<"position of the hero";
    for (int i=0; i<r.getROWS(); i++){
        for (int j=0; j<r.getCOLS(); j++){
            if (r.getOldData(i, j)=='r'){
                noOfRobots++;
            }
        }
    }
    ASSERT_EQ(noOfRobots, 5);
}

TEST(RobotsTest, MethodInputCheckq) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x-1, y-1);
    r.input('q');
    ASSERT_NE(r.getOldData(x-1, y-1), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputCheckw) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x-1, y);
    r.input('w');
    ASSERT_NE(r.getOldData(x-1, y), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputChecke) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x-1, y+1);
    r.input('e');
    ASSERT_NE(r.getOldData(x-1, y+1), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputChecka) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x, y-1);
    r.input('a');
    ASSERT_NE(r.getOldData(x, y-1), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputChecks) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x, y);
    r.input('s');
    ASSERT_NE(r.getOldData(x, y), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputCheckd) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x, y+1);
    r.input('d');
    ASSERT_NE(r.getOldData(x, y+1), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputCheckz) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x+1, y-1);
    r.input('z');
    ASSERT_NE(r.getOldData(x+1, y-1), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputCheckx) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x+1, y);
    r.input('x');
    ASSERT_NE(r.getOldData(x+1, y), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputCheckc) {
    Robots r;
    int x=r.getROWS()/2;
    int y=r.getCOLS()/2;
    char oc= r.getOldData(x+1, y+1);
    r.input('c');
    ASSERT_NE(r.getOldData(x+1, y+1), ' ');
    if (oc=='r' || oc=='j'){
        ASSERT_TRUE(r.getGameLost());
    }
}

TEST(RobotsTest, MethodInputCheckt) {
    Robots r;
    int noOfRobots=0;
    int noOfHero=0;
    r.input('t');
    for (int i=0; i<r.getROWS(); i++){
        for (int j=0; j<r.getCOLS(); j++){
            if (r.getOldData(i, j)=='r'){
                noOfRobots++;
            } if (r.getOldData(i,j)=='h'){
                noOfHero++;
            }
        }
    }
    ASSERT_EQ(noOfRobots, 5);
    ASSERT_EQ(noOfHero, 1);
}

TEST(RobotsTest, MethodInputCheckf) {
    Robots r;
    r.input('f');
    for (int i=0; i<r.getROWS(); i++){
        for (int j=0; j<r.getCOLS(); j++){
            if (r.getOldData(i, j)=='h'){
                ASSERT_TRUE(r.gameWon());
            } else {
                ASSERT_TRUE(r.getGameLost());
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
