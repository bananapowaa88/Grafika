#include "game_engine.h"
#include <stdio.h>
#include <stdlib.h>



void move_man(struct Character* character)
{
    character->pos.x += sin(degree_to_radian(character->face))*character->speed;
    character->pos.y -= cos(degree_to_radian(character->face))*character->speed;
}

void move_man_back(struct Character* character)
{
    character->pos.x -= sin(degree_to_radian(character->face))*character->speed;
    character->pos.y += cos(degree_to_radian(character->face))*character->speed;
}

void collosion_detect_man_box(struct Character* character, struct Universe* universe)
{
    struct Box b_box;
    get_axis_aligned_bounding_box(character,&b_box);
    struct Point b_center;
    struct Point b_halfsize;
    struct Point a_center;
    struct Point a_halfsize;
    b_halfsize.x = absolute_value((b_box.max.x-b_box.min.x)/2);
    b_halfsize.y = absolute_value((b_box.max.y-b_box.min.y)/2);
    b_halfsize.z = absolute_value((b_box.max.z-b_box.min.z)/2);
    b_center.x = b_box.min.x + b_halfsize.x;
    b_center.y = b_box.min.y + b_halfsize.y;
    b_center.z = b_box.min.z + b_halfsize.z;
    struct Box* a_box;
    a_box = universe->box_list.next;
    while (a_box->linked_list_role != HEAD)
    {
        a_halfsize.x = absolute_value((a_box->max.x-a_box->min.x)/2);
        a_halfsize.y = absolute_value((a_box->max.y-a_box->min.y)/2);
        a_halfsize.z = absolute_value((a_box->max.z-a_box->min.z)/2);
        a_center.x = a_box->min.x + a_halfsize.x;
        a_center.y = a_box->min.y + a_halfsize.y;
        a_center.z = a_box->min.z + a_halfsize.z;

        if((absolute_value(a_center.x -b_center.x) < (a_halfsize.x + b_halfsize.x))
           &&
           (absolute_value(a_center.y -b_center.y) < (a_halfsize.y + b_halfsize.y))
           &&
           (absolute_value(a_center.z -b_center.z) < (a_halfsize.z + b_halfsize.z))
           )
        {
            move_man_back(character);
            character->speed = STOP_SPEED;
        }
        a_box = a_box->next;
    }
    
}

void move_characters_and_check_collosions(struct Universe* universe)
{
    struct Character *character = universe->character_list.next;
    while (character->linked_list_role != HEAD) {
        move_man(character);
        collosion_detect_man_box(character,universe);
        if (character->is_controlled == NOT_CONTROLLED)
            { randomize_movement(character); }
        character = character->next;
    }    

}

void game_engine_update(struct Universe* universe)
{
    move_characters_and_check_collosions(universe);

}