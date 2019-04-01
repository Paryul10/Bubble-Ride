#include "main.h"
#include "timer.h"
#include "player.h"
#include "platform.h"
#include "coin.h"
#include "enemy.h"
#include "boomerrang.h"
#include "magnet.h"
#include "waterbaloon.h"
#include "firebeam.h"
#include "semicircularring.h"
#include "powerup1.h"
#include "powerup2.h"
#include "dragon.h"
#include "score.h"
#include "thruster.h"
#include "bullet.h"
#include "stdlib.h"
// #include <irrklang/irrKlang.h>
// #include <irrKlang.h>
// using namespace irrklang;

using namespace std;

#define PI 3.14159

GLMatrices Matrices;
GLuint programID;
GLFWwindow *window;

time_t seconds;
// time_t end;

/**************************
* Customizable functions *
**************************/

long long int g_start;
long long int start;
long long int present;
long long int duration = 5;
long long int num_bal = -1;
long long int num_fire = -1;
long long int num_bul = -1;

int ccc = 0;
int ddd = 0;
int eee = 0;
// Ball ball1;
Player player1;
Platform plat[1000];
Platform ciels[1000];
vector<Enemy> enemy;
vector<Boomerrang> boom;
Magnet magnet;
Firebeam fb[50];
vector<Powerup1> pu1;
vector<Powerup2> pu2;
vector<Semicircularring> scring;
vector<Waterbaloon> waterbaloons;
vector<Score> ssd_static;
vector<Score> ssd_dynamic;
vector<Thruster> thrusters;
vector<Dragon> dragons;
vector<Waterbaloon> firebaloons;
vector<Bullet> bullets;
// vector<int> vals;
int vals[6];

vector<Coin> coins;

float screen_zoom = .2, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
glm::vec3 camera_position, camera_center, camera_up;

float mag_x_chg = 0;
float mag_y_chg = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw()
{
    // clear the color and depth in the frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram(programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye(5 * cos(camera_rotation_angle * M_PI / 180.0f), 0, 5 * sin(camera_rotation_angle * M_PI / 180.0f));
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target(0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up(0, 1, 0);

    // Compute Camera matrix (view)
    // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    Matrices.view = glm::lookAt(camera_position, camera_center, camera_up); // ssd_static camera for 2D (ortho) in XY plane
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // ssd_static camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP; // MVP = Projection * View * Model

    // Scene render
    // ball1.draw(VP);
    for (int i = 0; i < 1000; i++)
    {
        plat[i].draw(VP);
    }
    for (int i = 0; i < 1000; i++)
    {
        ciels[i].draw(VP);
    }

    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i].ispresent)
        {
            coins[i].draw(VP);
        }
    }

    for (int i = 0; i < enemy.size(); i++)
    {
        if (enemy[i].ishot)
        {
            enemy[i].draw(VP);
        }
    }

    for (int i = 0; i < boom.size(); i++)
    {
        if (boom[i].exist)
        {
            boom[i].draw(VP);
        }
    }

    if (magnet.ispresent)
    {
        magnet.draw(VP);
    }

    for (int i = 0; i < 50; i++)
    {
        if (fb[i].exist)
        {
            fb[i].draw(VP);
        }
    }

    for (int i = 0; i < pu1.size(); i++)
    {
        if (pu1[i].exist)
        {
            pu1[i].draw(VP);
        }
    }

    for (int i = 0; i < pu2.size(); i++)
    {
        if (pu2[i].exist)
        {
            pu2[i].draw(VP);
        }
    }

    for (int i = 0; i < 1; i++)
    {
        if (scring[i].exist)
        {
            scring[i].draw(VP);
        }
    }

    for (int i = 0; i < waterbaloons.size(); i++)
    {
        if (waterbaloons[i].exist)
        {
            waterbaloons[i].draw(VP);
        }
    }

    for (int i = 0; i < ssd_static.size(); i++)
    {
        ssd_static[i].draw(VP);
    }

    for (int i = 0; i < ssd_dynamic.size(); i++)
    {
        ssd_dynamic[i].draw(VP);
    }

    for (int i = 0; i < thrusters.size(); i++)
    {
        if (thrusters[i].exist)
        {
            thrusters[i].draw(VP);
        }
    }

    for (int i = 0; i < dragons.size(); i++)
    {
        if (dragons[i].exist)
        {
            dragons[i].draw(VP);
        }
    }

    for (int i = 0; i < firebaloons.size(); i++)
    {
        if (dragons[0].exist)
        {
            if (firebaloons[i].exist)
            {
                firebaloons[i].draw(VP);
            }
        }
    }

    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].exist)
        {
            bullets[i].draw(VP);
        }
    }

    player1.draw(VP);
}

void tick_input(GLFWwindow *window)
{
    int left = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int baloon = glfwGetKey(window, GLFW_KEY_B);
    int bullet = glfwGetKey(window, GLFW_KEY_W);

    // if (player1.isundersc == 0)
    // {
    if (left)
    {
        player1.tick(-0.4, 0);
        if (player1.position.x > -12)
        {
            if (player1.position.x < camera_center.x - 8)
            {
                camera_center += glm::vec3(-0.4, 0, 0);
                camera_position += glm::vec3(-0.4, 0, 0);
            }
        }
    }
    // }

    // if (player1.isundersc == 0)
    // {
    if (right)
    {
        player1.tick(0.4, 0);
        if (player1.position.x > camera_position.x + 7)
        {
            camera_center += glm::vec3(0.4, 0, 0);
            camera_position += glm::vec3(0.4, 0, 0);
        }
    }
    // }

    // if(down) {
    //     player1.speedx=0;
    //     player1.speedy=-0.2;
    //     player1.tick();
    //     player1.speedy=0;
    // }

    if (player1.isundersc == 0)
    {
        if (space)
        {
            Thruster thru;
            player1.tick(0, 0.2);
            int dom = rand() % 3;
            if (dom == 0)
            {
                thru = Thruster(player1.position.x - 0.6, player1.position.y, COLOR_RED);
            }
            if (dom == 1)
            {
                thru = Thruster(player1.position.x - 0.6, player1.position.y, COLOR_GREEN);
            }
            if (dom == 2)
            {
                thru = Thruster(player1.position.x - 0.6, player1.position.y, COLOR_BLUE);
            }
            thrusters.push_back(thru);

            player1.speedy = 0;
        }
    }

    if (baloon)
    {
        cout << num_bal << '\n';
        Waterbaloon water;

        if (num_bal <= -1 && ccc == 0)
        {
            water = Waterbaloon(player1.position.x, player1.position.y, COLOR_DEEPSKYBLUE);
            waterbaloons.push_back(water);
            num_bal++;
            ccc = 1;
            player1.water_baloons--;
        }
        else
        {
            double dx = abs(player1.position.x - waterbaloons[waterbaloons.size() - 1].position.x);
            double dy = abs(player1.position.y - waterbaloons[waterbaloons.size() - 1].position.y);
            double dist = sqrt((dx * dx + dy * dy));

            if (dist > 10 && num_bal < 10)
            {
                water = Waterbaloon(player1.position.x, player1.position.y, COLOR_DEEPSKYBLUE);
                waterbaloons.push_back(water);
                num_bal++;
                player1.water_baloons--;
            }
        }
    }

    if (bullet)
    {
        // cout << num_bal << '\n';
        Bullet water;

        if (num_bul <= -1 && eee == 0)
        {
            water = Bullet(player1.position.x + 2, player1.position.y);
            bullets.push_back(water);
            num_bul++;
            // ccc = 1;
            // player1.water_baloons--;
        }
        else
        {
            double dx = abs(player1.position.x - bullets[bullets.size() - 1].position.x);
            double dy = abs(player1.position.y - bullets[bullets.size() - 1].position.y);
            double dist = sqrt((dx * dx + dy * dy));

            if (dist > 6)
            {
                water = Bullet(player1.position.x + 2, player1.position.y);
                bullets.push_back(water);
                num_bul++;
                // player1.water_baloons--;
            }
        }
    }
}

void set_ssd(int i, int value)
{
    if (value == 0)
    {
        ssd_dynamic[i].p1 = 0;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 1)
    {
        ssd_dynamic[i].p1 = 0;
        ssd_dynamic[i].p2 = 0;
        ssd_dynamic[i].p3 = 0;
        ssd_dynamic[i].p4 = 0;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 0;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 2)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 0;
        ssd_dynamic[i].p6 = 0;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 3)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 0;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 4)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 0;
        ssd_dynamic[i].p3 = 0;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 5)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 0;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 6)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 0;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 7)
    {
        ssd_dynamic[i].p1 = 0;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 0;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 0;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 8)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 9)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }
}

void tick_elements()
{
    // if (time(NULL) % 7 == 0)
    // {
    //     // system("play /home/paryul/SPRING19/GRAPHICS/ASSIGNMENTS/ASSIGNMENT1/jetpackV1.0/src/JazzTrio.wav");
    //     // system("canebrake-gtk-play -f /home/paryul/SPRING19/GRAPHICS/ASSIGNMENTS/ASSIGNMENT1/jetpackV1.0/src/JazzTrio.wav");
    //     // anberra-gtk-play -f audio.ogg
    //     // system("canberra-gtk-play -f /home/paryul/SPRING19/GRAPHICS/ASSIGNMENTS/ASSIGNMENT1/jetpackV1.0/src/JazzTrio.wav");
    //     // PlaySound("sleep_away.wav", NULL, SND_FILENAME|SND_LOOP);
    // }
    for (int i = 0; i < 6; i++)
    {
        vals[i] = 0;
    }
    // ball1.tick();
    // player1.tick();
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    // cout << "space=" << space << '\n';
    if (player1.isundersc == 0)
    {
        player1.falldown(space);
    }
    for (int i = 0; i < boom.size(); i++)
    {
        boom[i].tick(player1.position.x, player1.position.y);
    }
    for (int i = 0; i < 50; i++)
    {
        fb[i].tick();
    }

    if (player1.isundersc == 0)
    {
        if (magnet.ispresent)
        {

            if (abs(magnet.position.x - player1.position.x) < 10 && abs(magnet.position.y - player1.position.y) < 6)
            {

                // magent comes into effect;
                // set accleration of player
                if (player1.position.x > magnet.position.x)
                {
                    // cout << "player is aage\n";
                    mag_x_chg -= 0.02;
                }
                else if (player1.position.x < magnet.position.x)
                {
                    // cout << "player is peeche\n";
                    mag_x_chg += 0.02;
                }

                if (player1.position.y > magnet.position.y)
                {
                    // cout << "player is upar\n";

                    mag_y_chg -= 0.02;
                }
                else if (player1.position.y < magnet.position.y)
                {
                    // cout << "player is neeche\n";

                    mag_y_chg += 0.02;
                }

                // if(abs(player1.position.x+mag_x_chg-magnet.position.x) > 10 || abs((player1.position.y+mag_y_chg-magnet.position.y)>6))
                // {
                //     mag_x_chg=0;
                //     mag_y_chg=0;
                // }

                // if(mag_x_chg > 3 || mag_y_chg >3)
                // {
                //     mag_x_chg=0;
                //     mag_y_chg=0;
                // }
                player1.tick(mag_x_chg, mag_y_chg);

                // if(player1.position.x>=(magnet.position.x-2.5) && player1.position.x <= (magnet.position.x+magnet.r2+1) && player1.position.y>=(magnet.position.y-magnet.r2) && player1.position.y<=(magnet.position.y+magnet.r2))
                // {
                //     if(abs(player1.position.x-(magnet.position.x-2.5)) < abs(player1.position.x <= (magnet.position.x+magnet.r2+1)))
                //     {
                //         player1.position.x = magnet.position.x-0.5;
                //         player1.position.y = magnet.position.y-magnet.r1+0.2;
                //     }
                //     else
                //     {
                //         player1.position.x = magnet.position.x+magnet.r2+1;
                //         player1.position.y = magnet.position.y;
                //     }

                // }

                // cout << mag_x_chg  << " " << mag_y_chg << '\n';
            }

            if (abs(magnet.position.x - player1.position.x) > 10 || abs(magnet.position.y - player1.position.y) > 6)
            {
                // magent no  effect;
                mag_x_chg = 0;
                mag_y_chg = 0;
            }
        }
    }

    seconds = time(NULL);
    present = seconds;
    if ((time(NULL) - g_start) % 15 == 0 && magnet.ispresent == 0)
    {
        int lalu = rand() % 20;
        magnet.ispresent = 1;
        magnet.position.x = player1.position.x + 8;
        magnet.position.y = lalu - 8;
        start = time(NULL);
    }

    if ((time(NULL) - start) == 5)
    {
        magnet.ispresent = 0;
    }

    for (int i = 0; i < pu1.size(); i++)
    {
        pu1[i].tick();
    }

    for (int i = 0; i < pu2.size(); i++)
    {
        pu2[i].tick();
    }

    for (int i = 0; i < waterbaloons.size(); i++)
    {
        waterbaloons[i].tick();
    }

    for (int i = 0; i < thrusters.size(); i++)
    {
        thrusters[i].tick();
        double dx = abs(player1.position.x - thrusters[i].position.x);
        double dy = abs(player1.position.y - thrusters[i].position.y);
        double dist = sqrt((dx * dx + dy * dy));
        if (dist > 7)
        {
            thrusters[i].exist = 0;
        }
    }

    for (int i = 0; i < dragons.size(); i++)
    {
        if (dragons[i].health < 0)
        {
            dragons[i].exist = 0;
        }
        if (dragons[i].exist != 0)
        {
            dragons[i].tick(player1.position.y);
        }
    }

    if (time(NULL) % 3 == 0)
    {
        Waterbaloon fire;

        if (num_fire <= -1 && ddd == 0)
        {
            fire = Waterbaloon(dragons[0].position.x - 2, player1.position.y + 1.5, COLOR_DARKVIOLET);
            firebaloons.push_back(fire);
            num_fire++;
            ddd = 1;
            // player1.water_baloons--;
        }
        else
        {
            double dx = abs(dragons[0].position.x - firebaloons[firebaloons.size() - 1].position.x);
            double dy = abs(dragons[0].position.y - firebaloons[firebaloons.size() - 1].position.y);
            double dist = sqrt((dx * dx + dy * dy));

            if (dist > 15)
            {
                fire = Waterbaloon(dragons[0].position.x - 2, player1.position.y + 1.5, COLOR_DARKVIOLET);
                firebaloons.push_back(fire);
                num_fire++;
                // player1.water_baloons--;
            }
        }
    }

    for (int i = 0; i < firebaloons.size(); i++)
    {
        firebaloons[i].tick2();
    }

    for (int i = 0; i < firebaloons.size(); i++)
    {
        if (abs(firebaloons[i].position.x - dragons[0].position.x) > 30)
        {
            firebaloons[i].exist = 0;
        }
    }

    // cout << "y_pos=" << player1.position.y << '\n';

    /*
        for start of score and balloons
        ssd_static[i].position.x = camera_center.x + 15;
        ssd_static[i].position.y = camera_center.y + 19;*/

    for (int i = 0; i < ssd_static.size(); i++)
    {
        if (i == 0)
        {
            // set_ssd(i, vals[i]);
            ssd_static[i].position.x = camera_center.x + 12;
            ssd_static[i].position.y = camera_center.y + 19;
        }
        if (i == 1)
        {
            ssd_static[i].position.x = camera_center.x + 12;
            ssd_static[i].position.y = camera_center.y + 16;
        }
        if (i == 2)
        {
            ssd_static[i].position.x = camera_center.x + 13;
            ssd_static[i].position.y = camera_center.y + 19;
        }
        if (i == 3)
        {
            ssd_static[i].position.x = camera_center.x + 13;
            ssd_static[i].position.y = camera_center.y + 16;
        }
    }

    long long int store1 = player1.score;
    long long int store2 = player1.water_baloons;

    int c1 = 2;
    while (store1 > 0)
    {
        long long int digit = store1 % 10;
        vals[c1--] = digit;
        store1 /= 10;
    }

    int c2 = 5;
    while (store2 > 0)
    {
        long long int digit = store2 % 10;
        vals[c2--] = digit;
        store2 /= 10;
    }

    for (int i = 0; i < ssd_dynamic.size(); i++)
    {
        set_ssd(i, vals[i]);
        if (i == 0)
        {
            ssd_dynamic[i].position.x = camera_center.x + 14.5;
            ssd_dynamic[i].position.y = camera_center.y + 19;
        }
        if (i == 1)
        {
            ssd_dynamic[i].position.x = camera_center.x + 16;
            ssd_dynamic[i].position.y = camera_center.y + 19;
        }
        if (i == 2)
        {
            ssd_dynamic[i].position.x = camera_center.x + 17.5;
            ssd_dynamic[i].position.y = camera_center.y + 19;
        }

        if (i == 3)
        {
            ssd_dynamic[i].position.x = camera_center.x + 14.5;
            ssd_dynamic[i].position.y = camera_center.y + 16;
        }
        if (i == 4)
        {
            ssd_dynamic[i].position.x = camera_center.x + 16;
            ssd_dynamic[i].position.y = camera_center.y + 16;
        }
        if (i == 5)
        {
            ssd_dynamic[i].position.x = camera_center.x + 17.5;
            ssd_dynamic[i].position.y = camera_center.y + 16;
        }
    }

    for (int i = 0; i < 1; i++)
    {
        // cout << "p=" << player1.position.x << "  " << player1.position.y << '\n';
        // cout << "sc=" << scring[0].position.x << "  " << scring[0].position.y << '\n';
        if ((player1.position.x >= scring[i].position.x - 5) && (player1.position.x <= scring[i].position.x + 5) && (player1.position.y >= scring[i].position.y - 0.5) && (player1.position.y <= scring[i].position.y + 6))
        {
            // cout << "YES effect\n";
            player1.isundersc = 1;
            // player1.position.x += 0.2;
            double d1, d2, d3, d4, d5, d6;
            d1 = scring[0].position.y;
            d2 = 3.75 * 3.75;
            d3 = (player1.position.x - scring[0].position.x);
            d4 = d3 * d3;
            d5 = d1 + sqrt(abs(d4 - d2));
            // d6 = d1 - sqrt(d2-d4);

            player1.position.y = d5 + 1.5;

            player1.b_box.x = player1.position.x;
            player1.b_box.y = player1.position.y;
        }
        else
        {
            // cout << "no effect\n";
            player1.isundersc = 0;
        }
    }

    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].tick(player1.position.x ,player1.position.y);
    }

    // camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    // ball1       = Ball(0, 0, COLOR_RED);
    // PlaySound("starwars.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    player1 = Player(-8, -6, COLOR_RED);

    for (int i = 0; i < 1000; i++)
    {
        double xc = -25 + 6 * i;
        plat[i] = Platform(xc, -17, COLOR_BLACK);
    }

    for (int i = 0; i < 1000; i++)
    {
        double xc = -25 + 6 * i;
        ciels[i] = Platform(xc, 20, COLOR_BLACK);
    }

    double lsp = -20;
    for (int i = 0; i < 10; i++)
    {
        double sp = lsp + 25 + rand() % 15;
        double height = -10 + rand() % 26;
        int len = rand() % 6 + 1;

        for (int j = 0; j < len; j++)
        {
            Coin coin;
            int type = rand() % 4 + 1;

            int xh = rand() % 6;
            xh = height - xh;
            if (xh < -10)
            {
                xh = -10;
            }
            coin = Coin((sp + (j * 4)), xh, type);
            coins.push_back(coin);
        }
        lsp = sp;
    }

    lsp = 0;
    for (int i = 0; i < 10; i++)
    {
        double sp = lsp + rand() % 30 + 10;
        double height = -11 + rand() % 26;
        double x_shift = -4 + rand() % 6;
        double y_shift = -4 + rand() % 6;

        if (x_shift == 0 && y_shift == 0)
        {
            int ran = rand() % 2;
            if (ran)
            {
                x_shift = 3;
                y_shift = 0;
            }
            else
            {
                x_shift = 0;
                y_shift = 3;
            }
        }

        if (abs(x_shift) < 2)
        {
            x_shift = 2;
        }

        if (abs(y_shift) < 2)
        {
            y_shift = 2;
        }

        if (height < -11)
        {
            height = -11;
        }

        if (height + y_shift < -11)
        {
            y_shift = height + 11;
        }

        Enemy ene;
        ene = Enemy(sp, height, x_shift, y_shift, COLOR_YELLOW);
        enemy.push_back(ene);
        lsp = sp;
    }

    magnet = Magnet(8, -8);

    // enemy = Enemy(-4,-8,-2,3,COLOR_GOLDEN);
    for (int i = 0; i < 1; i++)
    {
        Boomerrang brng;
        brng = Boomerrang(40, -4);
        boom.push_back(brng);
    }

    for (int i = 0; i < 50; i++)
    {
        int rnd = rand() % 24 - 9;
        float ht = (float)rnd;
        fb[i] = Firebeam((i + 1) * 100, rnd);
    }

    for (int i = 0; i < 5; i++)
    {
        Powerup1 p1;
        long long int x, y;
        x = (i)*80;
        y = rand() % 20 - 10;
        double xx, yy;
        xx = (double)x;
        yy = (double)y;
        p1 = Powerup1(xx, yy, COLOR_GOLDEN);
        pu1.push_back(p1);
    }

    for (int i = 0; i < 5; i++)
    {
        Powerup2 p2;
        long long int x, y;
        x = (i)*40;
        y = rand() % 20 - 6;
        double xx, yy;
        xx = (double)x;
        yy = (double)y;
        p2 = Powerup2(xx, yy, COLOR_AQUAMARINE);
        pu2.push_back(p2);
    }

    // pu2 = Powerup2(80, 4, COLOR_AQUAMARINE);

    for (int i = 0; i < 5; i++)
    {
        Semicircularring sc;
        double x, y;
        // x = (i + 1) * 30;
        x = 20;
        if (i % 2 == 0)
        {
            y = 6;
        }
        else
        {
            y = -6;
        }
        y = -8;
        sc = Semicircularring(x, y);
        scring.push_back(sc);
    }

    Score inst[4];
    inst[0] = Score(camera_center.x + 12, camera_center.y + 19, 1, 1, 0, 1, 1, 0, 1);
    inst[1] = Score(camera_center.x + 12, camera_center.y + 16, 1, 1, 1, 1, 1, 1, 1);
    inst[2] = Score(camera_center.x + 13, camera_center.y + 19, 1, 0, 0, 0, 0, 0, 0);
    inst[3] = Score(camera_center.x + 13, camera_center.y + 16, 1, 0, 0, 0, 0, 0, 0);

    for (int i = 0; i < 4; i++)
    {
        ssd_static.push_back(inst[i]);
    }

    Score inst2[6];

    inst2[0] = Score(camera_center.x + 14.5, camera_center.y + 19, 0, 1, 1, 1, 1, 1, 1);
    inst2[1] = Score(camera_center.x + 16, camera_center.y + 19, 0, 1, 1, 1, 1, 1, 1);
    inst2[2] = Score(camera_center.x + 17.5, camera_center.y + 19, 0, 1, 1, 1, 1, 1, 1);

    inst2[3] = Score(camera_center.x + 14.5, camera_center.y + 16, 0, 1, 1, 1, 1, 1, 1);
    inst2[4] = Score(camera_center.x + 16, camera_center.y + 16, 0, 1, 1, 1, 1, 1, 1);
    inst2[5] = Score(camera_center.x + 17.5, camera_center.y + 16, 0, 1, 1, 1, 1, 1, 1);

    for (int i = 0; i < 6; i++)
    {
        ssd_dynamic.push_back(inst2[i]);
    }

    Dragon dungeon;
    dungeon = Dragon(260, 6);
    dragons.push_back(dungeon);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow(window, width, height);

    // Background color of the scene
    glClearColor(COLOR_LIGHT_GREY.r / 256.0, COLOR_LIGHT_GREY.g / 256.0, COLOR_LIGHT_GREY.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main(int argc, char **argv)
{
    srand(time(0));
    int width = 1260;
    int height = 1260; // 19 is top most in co-ordinates

    window = initGLFW(width, height);

    initGL(window, width, height);

    camera_position = glm::vec3(0, 0, 3);
    camera_center = glm::vec3(0, 0, 0);
    camera_up = glm::vec3(0, 1, 0);

    seconds = time(NULL);
    g_start = time(NULL);
    // cout << "since some=" << begin << '\n';
    int count = 0;
    /* Draw in loop */
    while (!glfwWindowShouldClose(window))
    {
        // Process timers

        if (t60.processTick())
        {
            // 60 fps
            draw();
            // OpenGL Draw commands
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            for (int i = 0; i < 50; i++)
            {
                if (fb[i].exist)
                {
                    if (detect_collision(player1.b_box, fb[i].b_box))
                    {
                        if (player1.isundersc == 0)
                        {
                            cout << "collision with fb" << '\n';
                            fb[i].exist = 0;
                            player1.score -= 50;
                        }
                    }
                }
            }

            for (int i = 0; i < coins.size(); i++)
            {
                if (coins[i].ispresent)
                {
                    if (detect_collision(coins[i].b_box, player1.b_box))
                    {
                        // cout << "COllison\n";
                        coins[i].ispresent = 0;
                        player1.coins_collected++;
                        player1.score += (coins[i].types * 5);
                        cout << "score=" << player1.score << '\n';
                        cout << "coins=" << player1.coins_collected << '\n';
                    }
                }
            }

            for (int i = 0; i < boom.size(); i++)
            {

                if (boom[i].exist)
                {
                    if (detect_collision(player1.b_box, boom[i].b_box))
                    {
                        if (player1.isundersc == 0)
                        {
                            player1.score -= 100;
                            boom[i].exist = 0;
                        }
                    }
                }
            }

            for (int i = 0; i < pu1.size(); i++)
            {
                if (pu1[i].exist)
                {
                    if (detect_collision(player1.b_box, pu1[i].b_box))
                    {
                        // cout << "detected\n";
                        pu1[i].exist = 0;
                        player1.score += 50;
                    }
                }
            }

            for (int i = 0; i < pu2.size(); i++)
            {
                if (pu2[i].exist)
                {
                    if (detect_collision(player1.b_box, pu2[i].b_box))
                    {
                        // cout << "detected\n";
                        pu2[i].exist = 0;
                        // player1.score += 50;
                        player1.water_baloons += 5;
                        num_bal -= 5;
                    }
                }
            }

            for (int i = 0; i < firebaloons.size(); i++)
            {
                if (dragons[0].exist)
                {
                    if (firebaloons[i].exist)
                    {
                        if (detect_collision(player1.b_box, firebaloons[i].b_box))
                        {
                            if (player1.isundersc == 0)
                            {
                                firebaloons[i].exist = 0;
                                player1.score -= 5;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < enemy.size(); i++)
            {
                if (enemy[i].ishot)
                {
                    if (detect_collision_with_fire(player1.b_box, enemy[i].b_box, enemy[i].rotation))
                    {
                        if (player1.isundersc == 0)
                        {
                            enemy[i].ishot = 0;
                            player1.score -= 10;
                        }
                    }
                }
            }

            // long long int skr = player1.score;
            // long long int cns = player1.coins_collected;

            for (int i = 0; i < enemy.size(); i++)
            {
                for (int j = 0; j < waterbaloons.size(); j++)
                {
                    if (waterbaloons[j].exist && enemy[i].ishot)
                    {
                        if (detect_collision_with_fire(enemy[i].b_box, waterbaloons[j].b_box, enemy[i].rotation))
                        {
                            enemy[i].ishot = 0;
                            waterbaloons[j].exist = 0;
                        }
                    }
                }
            }

            for (int i = 0; i < bullets.size(); i++)
            {
                if (dragons[0].exist && bullets[i].exist)
                {
                    if (detect_collision(dragons[0].b_box, bullets[i].b_box))
                    {
                        // cout << "Draqagpn\n";x
                        dragons[0].health -= 10;
                        if (dragons[0].health < 0)
                        {
                            dragons[0].exist = 0;
                        }
                        bullets[i].exist = 0;
                    }
                }
            }

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision_with_fire(bounding_box_t a, bounding_box_t b, float angle)
{
    float left_x = a.x - a.width / 2;
    float right_x = a.x + a.width / 2;

    // return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
    //        (abs(a.y - b.y) * 2 < (a.height + b.height));

    float x1 = b.x;
    float y1 = b.y;

    float up_y = a.y + a.height / 2;
    float low_y = a.y - a.height / 2;

    float x2 = x1 + b.width * cos(angle * PI / (180.0));
    float y2 = y1 + b.width * sin(angle * PI / (180.0));

    float line[3];

    line[0] = y2 - y1;
    line[1] = x1 - x2;
    line[2] = line[0] * x1 + line[1] * y1;

    // float poi[4];
    pair<float, float> poi[4];

    poi[0].first = (line[2] - line[1] * up_y) / line[0];
    poi[0].second = up_y;

    poi[1].first = (line[2] - line[1] * low_y) / line[0];
    poi[1].second = low_y;

    poi[2].first = left_x;
    poi[2].second = (line[2] - line[0] * left_x) / line[1];

    poi[3].first = right_x;
    poi[3].second = (line[2] - line[0] * right_x) / line[1];

    if (poi[0].first >= left_x && poi[0].first <= right_x)
    {
        if (poi[0].first >= min(x1, x2) && poi[0].first <= max(x1, x2))
        {
            return true;
        }
    }

    if (poi[1].first >= left_x && poi[1].first <= right_x)
    {
        if (poi[1].first >= min(x1, x2) && poi[1].first <= max(x1, x2))
        {
            return true;
        }
    }

    if (poi[2].second >= low_y && poi[2].second <= up_y)
    {
        if (poi[2].second >= min(y1, y2) && poi[2].second <= max(y1, y2))
        {
            return true;
        }
    }

    if (poi[3].second >= low_y && poi[3].second <= up_y)
    {
        if (poi[3].second >= min(y1, y2) && poi[3].second <= max(y1, y2))
        {
            return true;
        }
    }

    return false;
}

bool detect_collision(bounding_box_t a, bounding_box_t b)
{
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen()
{
    float top = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left = screen_center_x - 4 / screen_zoom;
    float right = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
