#include "main.h"

#ifndef WATERBALOON_H
#define WATERBALOON_H


class Waterbaloon {
public:
    Waterbaloon() {}
    Waterbaloon(float x, float y,color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    void tick2();
    double xspeed;
    double yspeed;
    int exist;
    bounding_box_t b_box;
private:
    VAO *object;
};

#endif // Waterbaloon_H
