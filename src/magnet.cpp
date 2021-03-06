#include "magnet.h"
#include "main.h"
#define PI 3.14159


Magnet::Magnet(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int count=0;
    r1=1.5;
    r2=r1+1;
    ispresent=0;

    float vertex_buffer_data[2000];

    for(int i=0;i<100;i++)
    {
        vertex_buffer_data[9*i]=0.0f;
        vertex_buffer_data[9*i+1]=0.0f;
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=r2*sin((1.0*PI*i)/100);
        vertex_buffer_data[9*i+4]=r2*cos((1.0*PI*i)/100);
        vertex_buffer_data[9*i+5]=0.0f;

        vertex_buffer_data[9*i+6]=r2*sin((1.0*PI*(i+1))/100);
        vertex_buffer_data[9*i+7]=r2*cos((1.0*PI*(i+1))/100);
        vertex_buffer_data[9*i+8]=0.0f;
    }

    for(int i=100;i<200;i++)
    {
        vertex_buffer_data[9*i]=0.0f;
        vertex_buffer_data[9*i+1]=0.0f;
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=r1*sin((1.0*PI*(i-100)/100));
        vertex_buffer_data[9*i+4]=r1*cos((1.0*PI*(i-100))/100);
        vertex_buffer_data[9*i+5]=0.0f;

        vertex_buffer_data[9*i+6]=r1*sin((1.0*PI*(i-99))/100);
        vertex_buffer_data[9*i+7]=r1*cos((1.0*PI*(i-99))/100);
        vertex_buffer_data[9*i+8]=0.0f;
    }

    count = 1800;
    //uper rect
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=r2;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=r2;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=r1;
    vertex_buffer_data[count++]=0.0f;

    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=r2;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-0.0f;
    vertex_buffer_data[count++]=r1;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=r1;
    vertex_buffer_data[count++]=0.0f;

    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r2;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=-r2;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=0.0f;

    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r2;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=0.0f;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=-r1;
    vertex_buffer_data[count++]=0.0f;
    

    this->object1 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data, COLOR_DARKRED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data + 100*9, COLOR_LIGHT_GREY, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data + 200*9, COLOR_BLACK2, GL_FILL);


}

void Magnet::draw(glm::mat4 VP) {
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
    draw3DObject(this->object3);


}

void Magnet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Magnet::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

