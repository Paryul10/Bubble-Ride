#include "boomerrang.h"
#include "main.h"
using namespace std;
Boomerrang::Boomerrang(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    xspeed = -0.1;
    yspeed = 0.0;
    sense = -1;
    isrotating = 0;

    ascent = 0.1;
    descent = -0.1;
    exist=1;

    this->b_box.x = x;
    b_box.y = y;
    b_box.width = 4.2;
    b_box.height = 2.4;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[108];

    int count = 0;
    // triangle 1;
    //rectangle tri 1
    vertex_buffer_data[count++] = -1.2f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -1.2f;
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;

    // rect tri 2
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -1.2f;
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;

    // first inverted tri
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -0.3f;
    vertex_buffer_data[count++] = 0.3f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -0.3f;
    vertex_buffer_data[count++] = -0.3f;
    vertex_buffer_data[count++] = 0.0f;

    // second inverted tri
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -0.9f;
    vertex_buffer_data[count++] = 0.3f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -0.9f;
    vertex_buffer_data[count++] = -0.3f;
    vertex_buffer_data[count++] = 0.0f;

    vertex_buffer_data[count++] = -1.2f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -1.2f;
    vertex_buffer_data[count++] = -1.2f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = -2.4f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 0.0f;

    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.9f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;

    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = -0.9f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;

    // fire tail
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 2.4f;
    vertex_buffer_data[count++] = 0.6f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.3f;
    vertex_buffer_data[count++] = 0.0f;

    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = 0.15f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 2.4f;
    vertex_buffer_data[count++] = 0.15f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = -0.15f;
    vertex_buffer_data[count++] = 0.0f;

    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = -0.3f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 2.4f;
    vertex_buffer_data[count++] = -0.3f;
    vertex_buffer_data[count++] = 0.0f;
    vertex_buffer_data[count++] = 1.2f;
    vertex_buffer_data[count++] = -0.6f;
    vertex_buffer_data[count++] = 0.0f;

    this->object1 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data, COLOR_YELLOW, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 2 * 9, COLOR_CYAN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data + 4 * 9, COLOR_DARKVIOLET, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 2 * 3, vertex_buffer_data + 5 * 9, COLOR_OLIVE, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 3 * 3, vertex_buffer_data + 7 * 9, COLOR_ORANGERED, GL_FILL);
}

void Boomerrang::draw(glm::mat4 VP)
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
    draw3DObject(this->object5);
}

void Boomerrang::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Boomerrang::tick(double player_x, double player_y)
{
    // this->rotation += this->rotation;
    this->position.x += xspeed;
    this->position.y += yspeed;

    if ((this->position.x < (player_x - 10)))
    {
        isrotating = 1;
    }

    if (this->position.x > (player_x + 55))
    {
        isrotating = 2;
    }

    if (isrotating == 1)
    {
        if (sense == -1)
        {
            // cout << ascent << '\n';
            this->rotation += -2;
            this->position.y += ascent;
            if (this->position.y > 15)
            {
                this->position.y = 15;
            }
            if (abs(this->rotation) < 90)
            {
                xspeed = -ascent;
            }

            if (abs(this->rotation) > 90 && abs(this->rotation) < 180)
            {
                xspeed = ascent;
            }

            if (this->rotation <= -180)
            {
                // cout << " now is the change\n";
                this->rotation = -180;
                sense = 1;
                xspeed = 0.1;
                isrotating = 0;
                ascent = rand() % 2 ;
                ascent = (double)ascent;
                ascent/=10;
                // if (this->position.y > 3)
                // {
                //     ascent = -ascent;
                // }
            }
        }
        // this->position.y += 0.1;
    }

    if (isrotating == 2)
    {
        if (sense == 1)
        {
            this->rotation += -2;
            this->position.y -= 0.1;
            if (this->position.y < -9)
            {
                this->position.y = -9;
            }
            if (abs(this->rotation) < 270)
            {
                xspeed = +0.1;
            }

            if (abs(this->rotation) < 360 && abs(this->rotation) > 270)
            {
                xspeed = -0.1;
            }

            if (this->rotation < -360)
            {
                this->rotation = 0;
                sense = -1;
                xspeed = -0.1;
                isrotating = 0;
            }
        }
        // this->position.y += 0.1;
    }
    this->b_box.x = this->position.x;
    this->b_box.y = this->position.y;
}
