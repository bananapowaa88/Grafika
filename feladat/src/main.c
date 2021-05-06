#include <GL/glut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>

#include "camera.h"
#include "game_engine.h"
#include "control.h"
#include "lights.h"

#define VIEWPORT_RATIO (16.0 / 9.0)
#define VIEWPORT_ASPECT 50.0

#define UPDATE_RATE 30
#define MODE_CHNAGE_SECS 1.0

int prev_time, now_time;
int mode_change_counter = 0;
int mode_change_done = FALSE;

struct Universe universe;

int time_break_done()
{
  now_time = glutGet(GLUT_ELAPSED_TIME);
  if( (now_time - prev_time)/1000.0 > 1.0 / UPDATE_RATE)
  {
      
      prev_time = now_time;
      return TRUE;
  }
  return FALSE;
}

void display_run()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

    glRotatef(180, 0, 0, 1);
    glTranslatef(0, 0, -1);
    glRotatef(180, 1, 0, 0);
    glScaled(-1,1,1);


    glPopMatrix();
    
    set_camera_on_character(&camera,universe.controlled_character);
    set_view_point(&camera);
    set_lights(&lights);
    draw_sky();
	draw_boxes( &(universe.box_list) );
    draw_characters( &(universe.character_list) );    
    glutSwapBuffers();
}

void display_help()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	gluLookAt(
            0.0, 0.0, -17, // eye
            0.0, 0.0, 0.0, // look at
            0.0, -1.0, 0.0  // up
    );
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    set_lights_help(&help_lights);
    draw_help();
    glPopMatrix();
    glutSwapBuffers();
}

void display()
{
    switch(game_mode)
    {
    case RUN:
        display_run();
        break;
    case TURN_TO_HELP:
        
        if (mode_change_counter/ (double)UPDATE_RATE > 2*MODE_CHNAGE_SECS)
        {
            game_mode = HELP;
            mode_change_done = FALSE;
            mode_change_counter = 0;
        }
        else
        {
        if (mode_change_counter/ (double)UPDATE_RATE > MODE_CHNAGE_SECS)
        {
            if (!mode_change_done){
                init_lights_help(&help_lights);
                mode_change_done = TRUE;
            }
            change_lights_by(&help_lights, 0.2,0,0,0);
            display_help();
        }
        else
        {
            change_lights_by(&lights, -0.13, -0.13, -0.13, -0.13);
            display_run();
        }
        }
        break;
    case TURN_FROM_HELP:
    
        if (mode_change_counter/ (double)UPDATE_RATE > 2*MODE_CHNAGE_SECS)
        {
            game_mode = RUN;
            mode_change_done = FALSE;
            mode_change_counter = 0;
        }
        else
        {
        if (mode_change_counter/ (double)UPDATE_RATE > MODE_CHNAGE_SECS)
        {
            if (!mode_change_done){
                reset_lights(&lights);
                mode_change_done = TRUE;
            }
            change_lights_by(&lights, 0.08, 0.13, 0.13, 0.025);
            display_run();
        }
        else
        {
            change_lights_by(&help_lights, -0.13,0,0,0);
            display_help();
        }
        }
        break;

    case HELP:
        display_help();
        break;
    }
  
}

void idle()
{
    switch(game_mode)
    {
    case TURN_FROM_HELP:
    case TURN_TO_HELP:
        if (time_break_done()){
            mode_change_counter++;
        }
    case RUN:
	    if (time_break_done()){
	        update_player_character(universe.controlled_character);
            game_engine_update(&universe);
            glutPostRedisplay();
        }
        break;
    }
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport (x, y, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLdouble)width / (GLdouble)height, 0.01, 10000.0);
}


void initialize()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);
    
    prev_time = 0;
    
    
    //setup_simple_box(&(universe.box_list));
    setup_standard_boxes(&(universe.box_list) );
    //setup_simple_character(&(universe.character_list));
    setup_standard_characters(&(universe.character_list));
    
    universe.controlled_character = universe.character_list.prev;
    universe.controlled_character->is_controlled = CONTROLLED;
    
    init_textures();
    init_models();
    init_lights(&lights);
    init_lights_help(&help_lights);
}

/**
 * Main function
 */
int main(int argc, char* argv[])
{
  
  
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    int window = glutCreateWindow("Ember");
    glutSetWindow(window);
  
  
    initialize();

  
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key_handler);
    glutKeyboardUpFunc(key_up_handler);
    glutMouseFunc(mouse_handler);
    glutMotionFunc(motion_handler);
    glutSpecialFunc(f1_handler);
    glutIdleFunc(idle);
    
    init_camera(&camera);

    glutMainLoop();

    return 0;
}

