#include "coin.h"
#include "main.h"
#define PI 3.14159

Coin::Coin(float x, float y, int type) {
    this->position = glm::vec3(x, y, 0);
    // this->rotation = 0;
    // speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    types=type;
    ispresent=1;
    this->b_box.x=x;
    b_box.y=y;
    b_box.width=1.0;
    b_box.height=1.0;
    
    int n=100;
    float vertex_buffer_data[9*n];

    for(int i=0;i<n;i++)
    {
        vertex_buffer_data[9*i]=0.0f;
        vertex_buffer_data[9*i+1]=0.0f;
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=0.5*sin((2.0*PI*i)/n);
        vertex_buffer_data[9*i+4]=0.5*cos((2.0*PI*i)/n);
        vertex_buffer_data[9*i+5]=0.0f;

        vertex_buffer_data[9*i+6]=0.5*sin((2.0*PI*(i+1))/n);
        vertex_buffer_data[9*i+7]=0.5*cos((2.0*PI*(i+1))/n);
        vertex_buffer_data[9*i+8]=0.0f;
    }

    if(type==1)
    {
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_CADETBLUE, GL_FILL);
    }
    if(type==2)
    {
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_PINK, GL_FILL);
    }
    if(type==3)
    {
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_KHAKHI, GL_FILL);
    }
    if(type==4)
    {
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_ORANGERED, GL_FILL);
    }
}

void Coin::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Coin::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Coin::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

