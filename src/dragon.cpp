#include "dragon.h"
#include "main.h"
#define PI 3.14159

Dragon::Dragon(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 45;
    speedy = 1;
    exist = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[154 + 900];
    int count = 0;
    float r = 0.3;
    this->health = 100;
    this->b_box.x = x;
    b_box.y = y;
    b_box.width = 8;
    b_box.height = 6;

    //body

    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = -2.5;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -2.5;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -2.5;
    vertex_buffer_data[count++] = -1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -1.5;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = -1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -3.0;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = -1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = -2.0;
    vertex_buffer_data[count++] = 0.0;

    //// mouth
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.8;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 1.8;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 1.5;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = 2.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.4;
    vertex_buffer_data[count++] = 3.0;
    vertex_buffer_data[count++] = 0.0;

    // wings
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 4.0;
    vertex_buffer_data[count++] = -1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 2.0;
    vertex_buffer_data[count++] = -4.0;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 1.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 4.0;
    vertex_buffer_data[count++] = -4.0;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 6.0;
    vertex_buffer_data[count++] = -0.8;
    vertex_buffer_data[count++] = 0.0;

    // eye
    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 1.5f;
        vertex_buffer_data[count + 9 * i + 1] = 2.3f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = 1.5 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = 2.3 + r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = 1.5 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = 2.3 + r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    this->object1 = create3DObject(GL_TRIANGLES, 10 * 3, vertex_buffer_data, COLOR_FORESTGREEN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 5 * 3, vertex_buffer_data + 10 * 9, COLOR_FORESTGREEN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 15 * 9, COLOR_DARKGREEN, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 100 * 3, vertex_buffer_data + 17 * 9, COLOR_RED, GL_FILL);
}

void Dragon::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}

void Dragon::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Dragon::tick(float player_y)
{
    if (abs(this->position.y - player_y) > 2)
    {
        if (this->position.y > player_y)
        {
            speedy = -0.2;
        }
        if (this->position.y < player_y)
        {
            speedy = +0.2;
        }
    }

    this->position.y += speedy;
    if (this->position.y >= 14)
    {
        this->position.y = 14;
    }

    if (this->position.y < -8)
    {
        this->position.y = -8;
    }

    this->b_box.x = this->position.x;
    this->b_box.y = this->position.y;
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
