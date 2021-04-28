#ifndef DRAW_SHAPES_H
#define DRAW_SHAPES_H

#include <GL/glut.h>
#include "game_engine.h"
#include "box.h"
#include "character.h"
#include "utils.h"
#include "texture.h"
#include "model.h"
#include "lights.h"

/*
 * Global character model.
 */
struct Character_model
{
    struct Model body;
    struct Model shirt;    
    struct Model shorts;
    struct Model shoes;          
    struct Model socks;
    struct Model eyes;          
    struct Model eyebrows;   
    struct Model beard;       
      
} character_model;

void init_models();

void init_character_model();



void draw_characters(struct Character* characters_list);


void draw_character(struct Character* character);

void draw_boxes(struct Box* boxes_list);

void draw_box(struct Box* box);

/*
 * Draw the model.
 */
void draw_model(const struct Model* model);

/*
 * Draw the triangles of the model.
 */
void draw_triangles(const struct Model* model);

/*
 * Draw the quads of the model.
 */
void draw_quads(const struct Model* model);

void draw_help();

//void draw_stats(struct Character* characters_list);

void draw_points(int points);

#endif // DRAW_SHAPES_H
