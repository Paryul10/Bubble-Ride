#include "main.h"

#ifndef THRUSTER_H
#define THRUSTER_H


class Thruster {
public:
    Thruster() {}
    Thruster(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speedy;
    int exist;
private:
    VAO *object1;
    VAO *object2;
};

#endif // Thruster_H
