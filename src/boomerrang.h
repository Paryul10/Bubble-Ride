#include "main.h"

#ifndef BOOMERRANG_H
#define BOOMERRANG_H


class Boomerrang {
public:
    Boomerrang() {}
    Boomerrang(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double player_x,double player_y);
    double xspeed;
    double yspeed;
    int sense;
    int isrotating;
    double ascent;
    double descent;
    bounding_box_t b_box;
    int exist;

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;

};

#endif // Boomerrang_H
