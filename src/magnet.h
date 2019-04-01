#include "main.h"

#ifndef MAGNET_H
#define MAGNET_H


class Magnet {
public:
    Magnet() {}
    Magnet(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    float r1;
    float r2;
    int ispresent;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;

};

#endif // Magnet_H
