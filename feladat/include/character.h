#ifndef CHARACTER_H
#define CHARACTER_H

#include "utils.h"
#include "box.h"

#define STOP_SPEED 0
#define NORMAL_SPEED 0.6
#define TURBO_SPEED 1
#define VERTICAL_MAX_DEGREE 45

#define GEAR_AMOUNT 0.1
#define GEAR_MAX 2.5

typedef enum {NOT_CONTROLLED, CONTROLLED} character_controlled_type;
typedef enum {NOT, GEARING, THROW} character_throw_type;


struct Character
{
    int id;
    struct Point pos;
    float speed;
    float face; // degree
    float vertical_face;
    float geared_power;
    struct Color player_color;
    struct Character* next;
    struct Character* prev;
    linked_list_element_type linked_list_role;
    character_controlled_type is_controlled;
    character_throw_type throws;
    
    int points;
    int blink_down_counter;
};

void init_character_list(struct Character* characters_list);

void new_character( struct Character* characters_list,
              struct Point pos,
              float speed,
              float face,
              struct Color player_color
              );

void remove_character(struct Character* character);

void setup_standard_characters(struct Character* characters_list);

void setup_simple_character(struct Character* characters_list);

void get_axis_aligned_bounding_box(struct Character* character, struct Box* box);

#endif // CHARACTER_H

