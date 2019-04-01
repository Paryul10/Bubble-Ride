#include "powerup2.h"
#include "main.h"
#define PI 3.14159


Powerup2::Powerup2(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    // speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    speedx = 0.2;
    speedy = 0.4;
    up = 1;
    exist=1;

    this->b_box.x = x;
    b_box.y = y;
    b_box.width = 2;
    b_box.height = 2;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[7218];
    int count = 0;
    float r = 0.15;

    int n = 100;

    vertex_buffer_data[count++] = 1.0f;
    vertex_buffer_data[count++] = 1.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -1.0f;
    vertex_buffer_data[count++] = 1.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.0f;
    vertex_buffer_data[count++] = -1.0f;
    vertex_buffer_data[count++] = 0.0f;

    vertex_buffer_data[count++] = -1.0f;
    vertex_buffer_data[count++] = -1.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -1.0f;
    vertex_buffer_data[count++] = 1.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.0f;
    vertex_buffer_data[count++] = -1.0f;
    vertex_buffer_data[count++] = 0.0f;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 0.0f;
        vertex_buffer_data[count + 9 * i + 1] = 0.0f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }
    count = 918;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = -0.4f;
        vertex_buffer_data[count + 9 * i + 1] = 0.0f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = -0.4 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = -0.4 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    count = 1818;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 0.4f;
        vertex_buffer_data[count + 9 * i + 1] = 0.0f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = 0.4 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = 0.4 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    count = 2718;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = -0.6f;
        vertex_buffer_data[count + 9 * i + 1] = +0.4f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = -0.6 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = +0.4 + r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = -0.6 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = +0.4 + r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    count = 3618;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 0.6f;
        vertex_buffer_data[count + 9 * i + 1] = +0.4f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = 0.6 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = +0.4 + r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = 0.6 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = +0.4 + r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    count = 4518;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = -0.2f;
        vertex_buffer_data[count + 9 * i + 1] = -0.4f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = -0.2 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = -0.4 + r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = -0.2 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = -0.4 + r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    count = 5418;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 0.2f;
        vertex_buffer_data[count + 9 * i + 1] = -0.4f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = 0.2 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = -0.4 + r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = 0.2 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = -0.4 + r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    count = 6318;

    for (int i = 0; i < 100; i++)
    {
        vertex_buffer_data[count + 9 * i] = 0.4f;
        vertex_buffer_data[count + 9 * i + 1] = 0.0f;
        vertex_buffer_data[count + 9 * i + 2] = 0.0f;

        vertex_buffer_data[count + 9 * i + 3] = 0.4 + r * sin((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 4] = r * cos((2.0 * PI * i) / 100);
        vertex_buffer_data[count + 9 * i + 5] = 0.0f;

        vertex_buffer_data[count + 9 * i + 6] = 0.4 + r * sin((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 7] = r * cos((2.0 * PI * (i + 1)) / 100);
        vertex_buffer_data[count + 9 * i + 8] = 0.0f;
    }

    this->object1 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 700 * 3, vertex_buffer_data + 2 * 9, COLOR_DARKVIOLET, GL_FILL);
}

void Powerup2::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);

}

void Powerup2::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Powerup2::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;

    if (up == 1)
    {
        this->position.y += speedy;
        if (this->position.y >= 12)
        {
            up = -1;
        }
    }

    if (up == -1)
    {
        this->position.y -= speedy;
        if (this->position.y <= -6)
        {
            up = 1;
        }
    }

    this->position.x += speedx;

    this->b_box.x = this->position.x;
    this->b_box.y = this->position.y;
}

