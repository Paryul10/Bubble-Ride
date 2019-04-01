#include "thruster.h"
#include "main.h"
#define PI 3.14159


Thruster::Thruster(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speedy = 0.05;
    exist=1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[1800];
    float r=0.2;

    for(int i=0;i<100;i++)
    {
        vertex_buffer_data[9*i]=0.0f;
        vertex_buffer_data[9*i+1]=0.0f;
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=r*sin((2.0*PI*i)/100);
        vertex_buffer_data[9*i+4]=r*cos((2.0*PI*i)/100);
        vertex_buffer_data[9*i+5]=0.0f;

        vertex_buffer_data[9*i+6]=r*sin((2.0*PI*(i+1))/100);
        vertex_buffer_data[9*i+7]=r*cos((2.0*PI*(i+1))/100);
        vertex_buffer_data[9*i+8]=0.0f;
    }

    for(int i=100;i<200;i++)
    {
        vertex_buffer_data[9*i]=0.0f;
        vertex_buffer_data[9*i+1]=0.0f;
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=(0.9*r)*sin((2.0*PI*i)/100);
        vertex_buffer_data[9*i+4]=(0.9*r)*cos((2.0*PI*i)/100);
        vertex_buffer_data[9*i+5]=0.0f;

        vertex_buffer_data[9*i+6]=0.9*r*sin((2.0*PI*(i+1))/100);
        vertex_buffer_data[9*i+7]=0.9*r*cos((2.0*PI*(i+1))/100);
        vertex_buffer_data[9*i+8]=0.0f;
    }

    this->object1 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data + 100*9, COLOR_LIGHT_GREY, GL_FILL);

}

void Thruster::draw(glm::mat4 VP) {
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

void Thruster::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Thruster::tick() {
    // this->rotation += speedy;
    // this->position.x -= speed;
    this->position.y -= speedy;
}

