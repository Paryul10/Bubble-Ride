#include "main.h"

#ifndef FIREBEAM_H
#define FIREBEAM_H


class Firebeam {
public:
    Firebeam() {}
    Firebeam(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    float r1,r2;
    int up;
    bounding_box_t b_box;
    int exist;
private:
    VAO *object1;
    VAO *object2;

};

#endif // Firebeam_H
