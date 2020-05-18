#ifndef ENGINE_H
#define ENGINE_H


class Engine {
public:
    Engine();
    Engine(int r, int c);
    ~Engine();

    //methods
    int getROWS();
    int getCOLS();
    char** getGameboard();

protected:
     int ROWS;
     int COLS;
    char** gameboard;

};

#endif // ENGINE_H
