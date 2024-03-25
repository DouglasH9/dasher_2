//
// Created by dougl on 3/25/2024.
//

#ifndef DAPPER_DASHER_NEBULA_H
#define DAPPER_DASHER_NEBULA_H
#include <raylib.h>


class Nebula {
private:
    Texture2D neb_text = LoadTexture("../textures/12_nebula_spritesheet.png");
    Rectangle neb_rec{};
    Vector2 neb_pos{};

    float neb_vel;
public:
    Nebula();

    void set_neb_pos_y();

    void set_neb_pos_x();

    float get_neb_pos_y();

    float get_neb_pos_x();

    float get_neb_rec_height();

    float get_neb_rec_width();

    Texture2D get_neb_text();

    void set_neb_rec_x();

    void draw_neb();
};


#endif //DAPPER_DASHER_NEBULA_H
