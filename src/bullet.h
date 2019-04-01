#include "main.h"

#ifndef BULLET_H
#define BULLET_H


class Bullet {
public:
    Bullet() {}
    Bullet(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float player_x,float player_y);
    double speed;
    bounding_box_t b_box;
    int exist;
private:
    VAO *object;
};

#endif // Bullet_H
