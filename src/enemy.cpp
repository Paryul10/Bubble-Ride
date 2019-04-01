#include "enemy.h"
#include "main.h"
#define PI 3.14159

Enemy::Enemy(float x, float y, float shift_x, float shift_y, color_t color)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = (shift_y/shift_x)*50;
    this->ishot=1;

    


    // speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int n = 200;
    float vertex_buffer_data[9 * n + 20];

    // int shift_x = 2.5;

    int len = abs(shift_x)+abs(shift_y);
    float r = 0.5;
    len = len % 4 + 2;


    this->b_box.x=x;
    b_box.y=y;
    b_box.width= len;
    b_box.height=r;

    for (int i = 0; i < n / 2; i++)
    {
        vertex_buffer_data[9 * i] = 0.0f;
        vertex_buffer_data[9 * i + 1] = 0.0f;
        vertex_buffer_data[9 * i + 2] = 0.0f;

        vertex_buffer_data[9 * i + 3] = r * sin((2.0 * PI * i) / (n / 2));
        vertex_buffer_data[9 * i + 4] = r * cos((2.0 * PI * i) / (n / 2));
        vertex_buffer_data[9 * i + 5] = 0.0f;

        vertex_buffer_data[9 * i + 6] = r * sin((2.0 * PI * (i + 1)) / (n / 2));
        vertex_buffer_data[9 * i + 7] = r * cos((2.0 * PI * (i + 1)) / (n / 2));
        vertex_buffer_data[9 * i + 8] = 0.0f;
    }

    for (int i = n / 2; i < n; i++)
    {
        vertex_buffer_data[9 * i] = len;
        vertex_buffer_data[9 * i + 1] = 0.0;
        vertex_buffer_data[9 * i + 2] = 0.0f;

        vertex_buffer_data[9 * i + 3] = len + r * sin((2.0 * PI * i) / (n / 2));
        vertex_buffer_data[9 * i + 4] =  r * cos((2.0 * PI * i) / (n / 2));
        vertex_buffer_data[9 * i + 5] = 0.0f;

        vertex_buffer_data[9 * i + 6] = len + r * sin((2.0 * PI * (i + 1)) / (n / 2));
        vertex_buffer_data[9 * i + 7] =  r * cos((2.0 * PI * (i + 1)) / (n / 2));
        vertex_buffer_data[9 * i + 8] = 0.0f;
    }

    vertex_buffer_data[9*n] = 0;
    vertex_buffer_data[9*n+1] = r/2;
    vertex_buffer_data[9*n+2] = 0;

    vertex_buffer_data[9*n+3] = len;
    vertex_buffer_data[9*n+4] = r/2;
    vertex_buffer_data[9*n+5] = 0;

    vertex_buffer_data[9*n+6] = 0;
    vertex_buffer_data[9*n+7] = -r/2;
    vertex_buffer_data[9*n+8] = 0;

    vertex_buffer_data[9*n+9] = len;
    vertex_buffer_data[9*n+10] = r/2;
    vertex_buffer_data[9*n+11] = 0;

    vertex_buffer_data[9*n+12] = len;
    vertex_buffer_data[9*n+13] = -r/2;
    vertex_buffer_data[9*n+14] = 0;

    vertex_buffer_data[9*n+15] = 0;
    vertex_buffer_data[9*n+16] = -r/2;
    vertex_buffer_data[9*n+17] = 0;




    this->object = create3DObject(GL_TRIANGLES, (n+2) * 3, vertex_buffer_data, color, GL_FILL);
}

void Enemy::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Enemy::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Enemy::tick()
{
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
