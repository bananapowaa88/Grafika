#ifndef BOX_H
#define BOX_H

#include "utils.h"

typedef enum {BRICK ,GRASS, IRON, WOOD} box_texture_type;
typedef enum {NO ,YES} box_texture_repeat_type;

struct Box
{
    struct Point min;
    struct Point max;
    struct Box* next;
    struct Box* prev;
    linked_list_element_type linked_list_role;
    box_texture_type texture;
    box_texture_repeat_type texture_repeat;
    float texture_zoom;
    int box_is_main_wall;
};

void init_box_list(struct Box* boxes_list);

void new_box( struct Box* boxes_list,
              struct Point min,
              struct Point max,
              box_texture_type texture_type,
              box_texture_repeat_type texture_repeat,
              float textrue_zoom,
              int box_is_main_wall);


void remove_box(struct Box* box);


void setup_standard_boxes(struct Box* boxes_list);


#endif // BOX_H

