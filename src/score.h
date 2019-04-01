#include "main.h"

#ifndef SCORE_H
#define SCORE_H


class Score {
public:
    Score() {}
    Score(float x, float y,int o1,int o2,int o3,int o4,int o5,int o6,int o7);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    int p1,p2,p3,p4,p5,p6,p7;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
};

#endif // Score_H
