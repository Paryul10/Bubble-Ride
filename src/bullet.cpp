#include "bullet.h"
#include "main.h"

Bullet::Bullet(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.2;
    exist = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[18];
    int count = 0;
    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;
    this->object = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data, COLOR_INDIGO, GL_FILL);
}

void Bullet::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Bullet::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Bullet::tick(float player_x,float player_y)
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    this->position.x += speed;

    if(abs(player_x-this->position.x)>8)
    {
        this->exist=0;
    }

    this->b_box.x = this->position.x;
    this->b_box.y = this->position.y;
}
