#include "main.h"

#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    Player() {}
    Player(float x, float y, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double sx,double sy);
    void falldown(int space);
    double speedx;
    double speedy; 
    double accx;
    double accy;   
    long long int score;
    long long int coins_collected;
    bounding_box_t b_box;
    long long int water_baloons;
    int isundersc;

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;

};

#endif // PLAYER_H
