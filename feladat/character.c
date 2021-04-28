#include "character.h"

int global_id_counter = 1;

void init_character_list(struct Character* characters_list)
{
    characters_list->linked_list_role = HEAD;
    characters_list->next = characters_list;
    characters_list->prev = characters_list;
}

void new_character( struct Character* characters_list,
              struct Point pos,
              float speed,
              float face,
              struct Color player_color
              )
{

    struct Character* baby_character;  
    baby_character = (struct Character*)malloc(sizeof(struct Character));
    
    baby_character->id = global_id_counter++;        
    baby_character->pos = pos;
    baby_character->speed = speed;
    baby_character->face = face;
    baby_character->vertical_face = 0;
    baby_character->geared_power = 0;
    baby_character->points = 0;
    
    baby_character->player_color = player_color;
    baby_character->linked_list_role = ELEMENT;
    

    baby_character->next = characters_list->next;
    characters_list->next->prev = baby_character;
    characters_list->next = baby_character;
    baby_character->prev = characters_list;
}


void remove_character(struct Character* character)
{
    character->prev->next = character->next;
    character->next->prev = character->prev;
    free(character);
}


void setup_standard_characters(struct Character* characters_list)
{
    init_character_list(characters_list);
    new_character(characters_list,
            (struct Point){10,10,0.1},
            NORMAL_SPEED,
            0,
            (struct Color){1,0,0,1}
            );
}


void setup_simple_character(struct Character* characters_list)
{
    init_character_list(characters_list);
    new_character(characters_list,
            (struct Point){10,10,0.1},
            NORMAL_SPEED,
            45,
            (struct Color){1,0,0,1}
            );
}

void get_axis_aligned_bounding_box(struct Character* character, struct Box* box)
{
    box->max.x = character->pos.x + 1.5;
    box->max.y = character->pos.y + 1.5;
    box->max.z = character->pos.z + 7.8;
    box->min.x = character->pos.x - 1.5;
    box->min.y = character->pos.y - 1.5;
    box->min.z = character->pos.z;
    
}

void randomize_movement(struct Character* character)
{
    if (character->speed == STOP_SPEED)
    {
        character->face = rand()%360;
        character->speed = NORMAL_SPEED;
    }
    else
    {
        if (rand()%2){
            character->face += rand()%4;
        }
        else
        {
            character->face -= rand()%4;
        }
    }
}

void randomize_throw(struct Character* character)
{
    character->geared_power = rand()%(int)(10*GEAR_MAX)/10.0;
    character->vertical_face = rand()%(VERTICAL_MAX_DEGREE*2)-VERTICAL_MAX_DEGREE;
}

void randomize_wether_to_throw(struct Character* character)
{
    if (rand()%100 > 95)
    {
        character->throws = THROW;
    }
}

void gear_throw(struct Character* character)
{
    if (character->geared_power + GEAR_AMOUNT < GEAR_MAX)
    {
        character->geared_power += GEAR_AMOUNT;
    }
    else
    {
        character->geared_power = GEAR_MAX;
    }
}

