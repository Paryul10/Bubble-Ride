#include "main.h"

#ifndef DRAGON_H
#define DRAGON_H


class Dragon {
public:
    Dragon() {}
    Dragon(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float player_y);
    double speedy;
    int exist;
    int health;
    bounding_box_t b_box;

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;

};

#endif // Dragon_H
