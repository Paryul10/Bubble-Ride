#include "player.h"
#include "main.h"
// #include <iostream.h>
using namespace std;
#define PI 3.14159

Player::Player(float x, float y, color_t color)
{
    this->position = glm::vec3(x, y, 0);
    speedx = 0;
    speedy = 0;
    this->b_box.x = x;
    b_box.y = y;
    b_box.width = 3;
    b_box.height = 3;
    accx = 0;
    accy = 0.02;
    score = 0;
    water_baloons = 6;
    coins_collected = 0;
    float r = 0.8;
    isundersc=0;
    // float theta = PI/4;

    float vertex_buffer_data[100 * 9 + 100 * 9 + 2 * 9 + 100 * 9 + 2 * 9 + 4 * 9 + 4 * 9 + 2*9];
    int count = 0;
    // static const GLfloat vertex_buffer_data [] = {
    //     1.0f,1.0f,0.0f,
    //     -1.0f,1.0f,0.0f,
    //     1.0f,-1.0f,0.0f,

    //     -1.0f,-1.0f,0.0f,
    //     -1.0f,1.0f,0.0f,
    //     1.0f,-1.0f,0.0f,
    // };

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[9 * i] = -1.0f;
        vertex_buffer_data[9 * i + 1] = 0.8f;
        vertex_buffer_data[9 * i + 2] = 0.0f;

        vertex_buffer_data[9 * i + 3] = -1 + r * sin(-(1.0 * PI * i) / 100);
        vertex_buffer_data[9 * i + 4] = 0.8 + r * cos(-(1.0 * PI * i) / 100);
        vertex_buffer_data[9 * i + 5] = 0.0f;

        vertex_buffer_data[9 * i + 6] = -1 + r * sin(-(1.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[9 * i + 7] = 0.8 + r * cos(-(1.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[9 * i + 8] = 0.0f;
    }
    count = 900;

    r = 0.6;
    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = -1.0f;
        vertex_buffer_data[count + 9 * i + 1] = 0.8f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = -1 + r * sin(-(1.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = 0.8 + r * cos(-(1.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = -1 + r * sin(-(1.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = 0.8 + r * cos(-(1.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }
    count = 1800;

    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;

    r = 0.4;
    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 0.6f;
        vertex_buffer_data[count + 9 * i + 1] = 1.6f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = 0.6 + r * sin(-(2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = 1.6 + r * cos(-(2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = 0.6 + r * sin(-(2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = 1.6 + r * cos(-(2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }
    count += 900;

    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.7;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.4;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.6;
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.6;
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.3;
    vertex_buffer_data[count++] = 0.4;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 1.2;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.6;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = -0.8;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.8;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.8;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.0;

    this->object1 = create3DObject(GL_TRIANGLES, 100 * 3, vertex_buffer_data, COLOR_YELLOW, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 100 * 3, vertex_buffer_data + 100 * 9, COLOR_LIGHT_GREY, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 200 * 9, COLOR_BLACK2, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 100 * 3, vertex_buffer_data + 202 * 9, COLOR_ORANGE, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 302 * 9, COLOR_RED, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 4 * 3, vertex_buffer_data + 304 * 9, COLOR_BLACK2, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 4 * 3, vertex_buffer_data + 308 * 9, COLOR_BLACK2, GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 312 * 9, COLOR_MAROON, GL_FILL);

}

void Player::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);

    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    draw3DObject(this->object6);
    draw3DObject(this->object7);
    draw3DObject(this->object8);

}

void Player::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Player::tick(double sx, double sy)
{
    this->position.x += sx;
    this->position.y += sy;
    if ((this->position.y) > 18)
    {
        this->position.y = 18;
    }
    if ((this->position.y) < -10)
    {
        this->position.y = -10;
    }

    if ((this->position.x) < -10)
    {
        this->position.x = -10;
    }

    this->b_box.x = this->position.x;
    this->b_box.y = this->position.y;
}

void Player::falldown(int space)
{

    if (!space && ((this->position.y) > -10))
    {
        // cout << this->position.y << " -- ";
        speedy = speedy + (accy);
        // cout << speedy << '\n';
        this->position.y -= speedy;
        if ((this->position.y) < -10)
        {
            this->position.y = -10;
        }
        this->b_box.x = this->position.x;
        this->b_box.y = this->position.y;
    }
}