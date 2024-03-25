//
// Created by dougl on 3/22/2024.
//
#include "Scarfy.h"
#include <raylib.h>
#include "../constants.h"



Scarfy::Scarfy() {
    scarfy_rec.width = (float)scarfy_text.width/6.0f;
    scarfy_rec.height = (float)scarfy_text.height;
    scarfy_rec.x = 0;
    scarfy_rec.y = 0;
    scarfy_pos.x = screen_width/2.0 - scarfy_rec.width/2.0;
    scarfy_pos.y = screen_height - scarfy_rec.height;
}

void Scarfy::set_scarfy_pos_y(float velocity_y) {
    Scarfy::scarfy_pos.y += velocity_y;
}

void Scarfy::draw_scarfy() {
    DrawTextureRec(scarfy_text, scarfy_rec, scarfy_pos, WHITE);
}

float Scarfy::get_scarfy_pos_y() const {
    return scarfy_pos.y;
}

void Scarfy::set_scarfy_velocity_y_zero() {
    scarfy_pos.y = screen_height - scarfy_rec.height;
}

float Scarfy::get_rec_height() const {
    return Scarfy::scarfy_rec.height;
}

Texture2D Scarfy::get_scarfy_text() const {
    return Scarfy::scarfy_text;
}

void Scarfy::set_scarfy_rec_x(float val) {
    scarfy_rec.x = val;
}

float Scarfy::get_scarfy_rec_width() const {
    return scarfy_rec.width;
}
