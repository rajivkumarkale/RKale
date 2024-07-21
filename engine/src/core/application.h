#pragma once

#include "defines.h"

struct game;

// Application Configuration
typedef struct application_config {
    // window starting position and dimensions, if applicable
    i16 start_pos_x;
    i16 start_pos_y;
    i16 start_width;
    i16 start_height;

    // The application name in windowing, if applicable
    char* name;
} application_config;

RAPI b8 application_create(struct game* game_inst);
RAPI b8 application_run();