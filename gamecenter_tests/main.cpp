#include <iostream>

#include "gtest/gtest.h"
#include "../gamecenter/game.h"
#include "../gamecenter/player.h"
#include "../gamecenter/gamehistory.h"
#include "../gamecenter/playergamehistory.h"

TEST(PlayerTest, AllMethod){
    Player *p;
    p = new Player();
    Game *g1, *g2;
    p->set_first_name("sujan");
    p->set_last_name("dhakal");
    p->set_address("usa");
    g1 = new Game(p, "game1", 100);
    g2 = new Game(p, "game2", 100);
    p->set_game(g1);
    ASSERT_TRUE(p->get_first_name()=="sujan");
    ASSERT_TRUE(p->get_last_name()=="dhakal");
    ASSERT_TRUE(p->get_address()=="usa");
    ASSERT_TRUE(p->get_game()->get_name()=="game1");
    p->add_game(g1);
    p->add_game(g2);
    ASSERT_TRUE(p->get_game()->get_name()=="game2");
    ASSERT_TRUE(p->get_game_history()->get_player()->get_first_name()=="sujan");
    ASSERT_TRUE(p->get_game_history()->get_player()->get_last_name()=="dhakal");
}

TEST(GameTest, AllMethod){
    Player *p;
    p = new Player();
    p->set_first_name("sujan");
    p->set_last_name("dhakal");
    p->set_address("usa");
    Game *g;
    g = new Game(p, "game1", 100);
    ASSERT_TRUE(g->get_score()==100);
    g->set_score(200);
    ASSERT_TRUE(g->get_score()==200);
    ASSERT_TRUE(g->get_name()=="game1");
    g->set_name("game2");
    ASSERT_TRUE(g->get_name()=="game2");
    ASSERT_TRUE(g->get_player()->get_first_name()=="sujan");
    ASSERT_TRUE(g->get_player()->get_last_name()=="dhakal");
    ASSERT_TRUE(g->get_player()->get_address()=="usa");
    ASSERT_TRUE(g->get_player()->get_game()->get_name()=="game2");
}

TEST(GameHistoryTest, AllMethod){
    Player *p1, *p2;
    p1 = new Player();
    p1->set_first_name("sujan");
    p1->set_last_name("dhakal");
    p1->set_address("usa");
    p2 = new Player();
    p2->set_first_name("trang");
    p2->set_last_name("le");
    p2->set_address("viet");
    Game *g1, *g2;
    g1 = new Game(p1, "game1", 100);
    g2 = new Game(p2, "game2", 200);
    GameHistory* gh;
    gh = new GameHistory(p1);
    ASSERT_TRUE(gh->get_player()->get_first_name()=="sujan");
    gh->add_game(g1);
    ASSERT_TRUE(gh->get_game(0)->get_name()=="game1");
    ASSERT_TRUE(gh->get_game(0)->get_score()==100);
    ASSERT_TRUE(gh->get_num_games()==1);
    gh->add_game(g2);
    ASSERT_TRUE(gh->get_game(1)->get_name()=="game2");
    ASSERT_TRUE(gh->get_game(1)->get_score()==200);
    ASSERT_TRUE(gh->get_num_games()==2);
}

TEST(PlayerGameHistoryTest, AllMethod){
    Player *p1;
    p1 = new Player();
    p1->set_first_name("sujan");
    p1->set_last_name("dhakal");
    p1->set_address("usa");
    Player *p2;
    p2 = new Player();
    p2->set_first_name("trang");
    p2->set_last_name("le");
    p2->set_address("viet");
    Game *g1, *g11, *g111, *g2, *g21, *g211;
    g1 = new Game(p1, "game1", 100);
    g11 = new Game(p1, "game12", 200);
    g111 = new Game(p1, "game13", 300);
    g2 = new Game(p2, "game2", 400);
    g21 = new Game(p2, "game22", 500);
    g211 = new Game(p2, "game23", 600);
    PlayerGameHistory *pgh;
    pgh = new PlayerGameHistory();
    pgh->add_player(p1);
    pgh->add_player(p2);
    pgh->add_game(g1);
    pgh->add_game(g11);
    pgh->add_game(g111);
    pgh->add_game(g2);
    pgh->add_game(g21);
    pgh->add_game(g211);
    ASSERT_TRUE(pgh->get_player(0)->get_first_name()=="sujan");
    ASSERT_TRUE(pgh->get_player(1)->get_last_name()=="le");
    ASSERT_TRUE(pgh->get_game(2)->get_name()=="game13");
    ASSERT_TRUE(pgh->get_game(5)->get_score()==600);
    ASSERT_TRUE(pgh->games_played()==6);
    ASSERT_TRUE(pgh->num_players()==2);
    ASSERT_TRUE((int)pgh->avg_games_per_player()==3);
    ASSERT_TRUE(pgh->top_score()==600);
    ASSERT_TRUE(pgh->avg_game_score()==350);
    ASSERT_TRUE(pgh->avg_score_for_player(p1)==200);
    ASSERT_TRUE(pgh->avg_score_for_player(p2)==500);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
