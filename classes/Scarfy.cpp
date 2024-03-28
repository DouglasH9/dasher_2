//
// Created by dougl on 3/22/2024.
//
#include "Scarfy.h"
#include <raylib.h>
#include "../constants.h"



Scarfy::Scarfy() {
    this->scarfy_rec.width = (float)scarfy_text.width/6.0f;
    this->scarfy_rec.height = (float)scarfy_text.height;
    this->scarfy_rec.x = 0;
    this->scarfy_rec.y = 0;
    this->scarfy_pos.x = screen_width/2.0 - scarfy_rec.width/2.0;
    this->scarfy_pos.y = screen_height - scarfy_rec.height;
    this->velocity_y = 0.0;
    this->frame = 0;
    this->running_time = 0.0;
}

void Scarfy::set_scarfy_pos_y(float val) {
    Scarfy::scarfy_pos.y += val;
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

bool Scarfy::get_is_in_air() const {
    return this->is_in_air;
}

void Scarfy::set_is_in_air(bool val) {
    this->is_in_air = val;
}

void Scarfy::jump() {
    this->is_in_air = true;
    this->scarfy_pos.y += jump_velocity;
}

void Scarfy::set_velocity_y(float val) {
    this->velocity_y = val;
}

void Scarfy::set_run_time(float val) {
    this->running_time = val;
}

void Scarfy::increment_vel_y(float val) {
    this->velocity_y += val;
}

float Scarfy::get_run_time() const {
    return this->running_time;
}

void Scarfy::increment_run_time(float val) {
    this->running_time += val;
}

int Scarfy::get_frame() const {
    return this->frame;
}

void Scarfy::reset_frame() {
    this->frame = 0;
}

void Scarfy::increment_frame() {
    this->frame++;
}

float Scarfy::get_vel_y() const {
    return this->velocity_y;
}

float Scarfy::get_scarfy_pos_x() const {
    return scarfy_pos.x;
}


