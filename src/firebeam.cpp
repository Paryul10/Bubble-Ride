#include "firebeam.h"
#include "main.h"
#define PI 3.14159

Firebeam::Firebeam(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.2;
    exist=1;

    this->b_box.x = x;
    b_box.y = y;
    b_box.width = 20;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[1836];
    r1 = 2;
    b_box.height = r1;
    up = 1;
    // r2 = 1;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[9 * i] = -10.0f;
        vertex_buffer_data[9 * i + 1] = 0.0f;
        vertex_buffer_data[9 * i + 2] = 0.0f;

        vertex_buffer_data[9 * i + 3] = -10 + r1 * sin(-(1.0 * PI * i) / 100);
        vertex_buffer_data[9 * i + 4] = r1 * cos(-(1.0 * PI * i) / 100);
        vertex_buffer_data[9 * i + 5] = 0.0f;

        vertex_buffer_data[9 * i + 6] = -10 + r1 * sin(-(1.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[9 * i + 7] = r1 * cos(-(1.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[9 * i + 8] = 0.0f;
    }

    for (int i = 100; i < 200; i++)
    {
        vertex_buffer_data[9 * i] = 10.0f;
        vertex_buffer_data[9 * i + 1] = 0.0f;
        vertex_buffer_data[9 * i + 2] = 0.0f;

        vertex_buffer_data[9 * i + 3] = 10 + r1 * sin((1.0 * PI * (i - 100) / 100));
        vertex_buffer_data[9 * i + 4] = r1 * cos((1.0 * PI * (i - 100)) / 100);
        vertex_buffer_data[9 * i + 5] = 0.0f;

        vertex_buffer_data[9 * i + 6] = 10 + r1 * sin((1.0 * PI * (i - 99)) / 100);
        vertex_buffer_data[9 * i + 7] = r1 * cos((1.0 * PI * (i - 99)) / 100);
        vertex_buffer_data[9 * i + 8] = 0.0f;
    }

    int count = 1800;
    vertex_buffer_data[count++] = 10;
    vertex_buffer_data[count++] = r1 / 2;
    vertex_buffer_data[count++] = 0;
    vertex_buffer_data[count++] = 10;
    vertex_buffer_data[count++] = -r1 / 2;
    vertex_buffer_data[count++] = 0;
    vertex_buffer_data[count++] = -10;
    vertex_buffer_data[count++] = -r1 / 2;
    vertex_buffer_data[count++] = 0;

    vertex_buffer_data[count++] = 10;
    vertex_buffer_data[count++] = r1 / 2;
    vertex_buffer_data[count++] = 0;
    vertex_buffer_data[count++] = -10;
    vertex_buffer_data[count++] = r1 / 2;
    vertex_buffer_data[count++] = 0;
    vertex_buffer_data[count++] = -10;
    vertex_buffer_data[count++] = -r1 / 2;
    vertex_buffer_data[count++] = 0;

    this->object1 = create3DObject(GL_TRIANGLES, 200 * 3, vertex_buffer_data, COLOR_TEAL, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 200 * 9, COLOR_GREENYELLOW, GL_FILL);
}

void Firebeam::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Firebeam::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Firebeam::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    if (up == 1)
    {
        this->position.y += speed;
        if (this->position.y >= 15.5)
        {
            up = -1;
        }
    }

    if (up == -1)
    {
        this->position.y -= speed;
        if (this->position.y <= -10)
        {
            up = 1;
        }
    }
    this->b_box.x = this->position.x;
    this->b_box.y = this->position.y;
}
