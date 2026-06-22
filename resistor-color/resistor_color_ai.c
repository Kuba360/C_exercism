#include "resistor_color.h"

int color_code(resistor_band_t color) {
    return color; 
}
// enum makes colors name just an integer, so if input is "RED" (2), then output should be the same. 
const resistor_band_t *colors(void) {
    static const resistor_band_t all_colors[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
    // It is better to add const, this way array wille be stored on FLASH. 
    return all_colors;
}