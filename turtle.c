#include "turtle.h"

// Turtle functions
// Move forward
void fd( turtle *t, float amount){
  // Calc new x and y
  float new_x = (cos( t -> angle * (M_PI/180)) * amount) + t -> x;
  float new_y = (sin( t -> angle * (M_PI/180)) * amount) + t -> y;
  // Draw pen
  if( t -> pendown == 1)
    line( t -> penbuffer, t -> x, t -> y, new_x, new_y, t -> pencolor);
  // Move turtle to new position
  t -> x = new_x;
  t -> y = new_y;
}

// Backwords
void bk( turtle *t, float amount){
  // Just reverse
  fd( t, -amount);
}

// Right turn
void rt( turtle *t, float amount){
  t -> angle += amount;
}

// Left turn
void lt( turtle *t, float amount){
  rt( t, -amount);
}
