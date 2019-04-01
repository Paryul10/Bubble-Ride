#include "score.h"
#include "main.h"

Score::Score(float x, float y,int o1,int o2,int o3,int o4,int o5,int o6,int o7)
{   
    // o1-> centre
    // o2-> up
    // o3-> down
    // o4-> right up
    // o5-> left up
    // o6-> right down
    // o7->  left down


    // 0 = 0,1,1,1,1,1,1

    // 1 = 0,0,0,0,1,0,1

    // 2 = 1,1,1,1,0,0,1

    // 3 = 1,1,1,1,0,1,0

    // 4 = 1,0,0,1,1,1,0

    // 5 = 1,1,1,0,1,1,0

    // 6 = 1,1,1,0,1,1,1

    // 7 = 0,1,0,1,0,1,0 

    // 8 = 1,1,1,1,1,1,1
    
    // 9 = 1,1,1,1,1,1,0




    p1=o1;
    p2=o2;
    p3=o3;
    p4=o4;
    p5=o5;
    p6=o6;
    p7=o7;

    
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[14*9*9];
    int count = 0;

    // centre wala
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

    // up wala
    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = 0.7;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = 0.7;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 0.7;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;

    // down wala
    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = -0.7;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -0.7;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.2;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.2;
    vertex_buffer_data[count++] = -0.7;
    vertex_buffer_data[count++] = 0.0;
    
    // right up
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;

    // left up
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.1;
    vertex_buffer_data[count++] = 0.0;

    // right down
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = 0.3;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = 0.5;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;

    // left down
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;

    vertex_buffer_data[count++] = -0.3;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = 0.0;
    vertex_buffer_data[count++] = -0.5;
    vertex_buffer_data[count++] = -0.1;
    vertex_buffer_data[count++] = 0.0;


    this->object1 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data, COLOR_BLACK2, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 2*9, COLOR_BLACK2, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 4*9, COLOR_BLACK2, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 6*9, COLOR_BLACK2, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 8*9, COLOR_BLACK2, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 10*9, COLOR_BLACK2, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 12*9, COLOR_BLACK2, GL_FILL);

}

void Score::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(this->p1)    draw3DObject(this->object1);
    if(this->p2)    draw3DObject(this->object2);
    if(this->p3)    draw3DObject(this->object3);
    if(this->p4)    draw3DObject(this->object4);
    if(this->p5)    draw3DObject(this->object5);
    if(this->p6)    draw3DObject(this->object6);
    if(this->p7)    draw3DObject(this->object7);

}

void Score::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Score::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
