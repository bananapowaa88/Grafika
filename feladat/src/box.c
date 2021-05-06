#include "box.h"
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

void init_box_list(struct Box* boxes_list)
{
    boxes_list->linked_list_role = HEAD;
    boxes_list->next = boxes_list;
    boxes_list->prev = boxes_list;
}


void new_box( struct Box* boxes_list,
              struct Point min,
              struct Point max,
              box_texture_type texture_type,
              box_texture_repeat_type texture_repeat,
              float texture_zoom,
              int box_is_main_wall)
{

    struct Box* baby_box;  
    baby_box = (struct Box*)malloc(sizeof(struct Box));
    
    if (min.x > max.x) SWAP(min.x,max.x,double);
    if (min.y > max.y) SWAP(min.y,max.y,double);
    if (min.z > max.z) SWAP(min.z,max.z,double);
        
    baby_box->min = min;
    baby_box->max = max;
    baby_box->linked_list_role = ELEMENT;
    baby_box->texture = texture_type;
    baby_box->texture_zoom = texture_zoom;
    baby_box->texture_repeat = texture_repeat;
    baby_box->box_is_main_wall = box_is_main_wall;
    
    baby_box->next = boxes_list->next;
    boxes_list->next->prev = baby_box;
    boxes_list->next = baby_box;
    baby_box->prev = boxes_list;
}


void remove_box(struct Box* box)
{
    box->prev->next = box->next;
    box->next->prev = box->prev;
    free(box);
}


void setup_standard_boxes(struct Box* boxes_list)
{
    const double size = 64.0;
    const double height_percent = 0.75;
    init_box_list(boxes_list);
    new_box(boxes_list,
            (struct Point){size,size,0.0},
            (struct Point){-1*size,-1*size,-4.0},
            GRASS,
            YES,
            4,
            TRUE);
    new_box(boxes_list,
            (struct Point){size,size+20,size*height_percent},
            (struct Point){-1*size,size,0.0},
            BRICK,
            YES,
            8,
            TRUE);
    new_box(boxes_list,
            (struct Point){size,-1*size-20,size*height_percent},
            (struct Point){-1*size,-1*size,0.0},
            BRICK,
            YES,
            8,
            TRUE);
    new_box(boxes_list,
            (struct Point){size+20,size,size*height_percent},
            (struct Point){size,-1*size,0.0},
            BRICK,
            YES,
            8,
            TRUE);
    new_box(boxes_list,
            (struct Point){-1*size-20,size,size*height_percent},
            (struct Point){-1*size,-1*size,0.0},
            BRICK,
            YES,
            8,
            TRUE);
        new_box(boxes_list,
            (struct Point){30,30,0},
            (struct Point){34,34,4},
            WOOD,
            NO,
            1,
            FALSE);
    
}