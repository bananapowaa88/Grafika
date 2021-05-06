#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "box.h"
#include "character.h"
#include "utils.h"

struct Universe
{
    struct Box box_list;
    struct Character character_list;
    struct Character* controlled_character;
};

void game_engine_update(struct Universe* universe);

void move_characters_and_check_collosions(struct Universe* universe);

void collosion_detect_man_box(struct Character* character, struct Universe* universe);

void move_man_back(struct Character* character);

void move_man(struct Character* character);

void inc_points(int id, struct Universe* universe);

#endif // GAME_ENGINE_H
