#include "main.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
  public:
    Enemy() {}
    Enemy(float x, float y, float shift_x, float shift_y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    int ishot;
    bounding_box_t b_box;

  private:
    VAO *object;
};

#endif // Enemy_H
