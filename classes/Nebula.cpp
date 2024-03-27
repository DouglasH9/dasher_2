//
// Created by dougl on 3/25/2024.
//

#include "Nebula.h"
#include "../constants.h"

Nebula::Nebula(float pos_x) {
    neb_rec.width = (float)neb_text.width/8;
    neb_rec.height = (float)neb_text.height/8;
    neb_rec.x = 0;
    neb_rec.y = 0;
    neb_pos.x = pos_x;
    neb_pos.y = screen_height - neb_rec.height;
    neb_frame = 0;
    neb_running_time = 0;
}

void Nebula::set_neb_pos_x(float val) {
    this->neb_pos.x += val;
}

float Nebula::get_neb_rec_width() const {
    return this->neb_rec.width;
}

Texture2D Nebula::get_neb_text() {
    return Texture2D();
}

void Nebula::set_neb_rec_x(float val) {
    this->neb_rec.x = val;
}

void Nebula::draw_neb() {
    DrawTextureRec(neb_text, neb_rec, neb_pos, WHITE);
}

float Nebula::get_neb_vel() const {
    return this->neb_vel;
}

float Nebula::get_neb_run_time() const {
    return this->neb_running_time;
}

void Nebula::set_neb_run_time(float val) {
    this->neb_running_time = val;
}

void Nebula::increment_run_time(float val) {
    this->neb_running_time += val;
}

int Nebula::get_frame() const {
    return this->neb_frame;
}

void Nebula::increase_frame() {
    this->neb_frame++;
}

void Nebula::reset_frame() {
    this->neb_frame = 0;
}
