#include "main.h"

#ifndef SEMICIRCULARRING_H
#define SEMICIRCULARRING_H


class Semicircularring {
public:
    Semicircularring() {}
    Semicircularring(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double r1,r2;
    int exist;
private:
    VAO *object1;
    VAO *object2;
};

#endif // Semicircularring_H
