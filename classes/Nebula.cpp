//
// Created by dougl on 3/25/2024.
//

#include "Nebula.h"
#include "../constants.h"

Nebula::Nebula() {
    neb_rec.width = (float)neb_text.width/8;
    neb_rec.height = (float)neb_text.height/8;
    neb_rec.x = 0;
    neb_rec.y = 0;
    neb_pos.x = screen_width - neb_rec.width/2;
    neb_pos.y = screen_height - neb_rec.height;
}

void Nebula::set_neb_pos_y() {

}

void Nebula::set_neb_pos_x() {

}

float Nebula::get_neb_pos_y() {
    return 0;
}

float Nebula::get_neb_pos_x() {
    return 0;
}

float Nebula::get_neb_rec_height() {
    return 0;
}

float Nebula::get_neb_rec_width() {
    return 0;
}

Texture2D Nebula::get_neb_text() {
    return Texture2D();
}

void Nebula::set_neb_rec_x() {

}

void Nebula::draw_neb() {
    DrawTextureRec(neb_text, neb_rec, neb_pos, WHITE);
}
