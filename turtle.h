#ifndef TURTLE_H
#define TURTLE_H

#include <allegro.h>
#include <math.h>

// Struct turtle
typedef struct{
  // Screen position
  float x;
  float y;

  // Angle in degrees
  float angle;

  // Draw or naw?
  char pendown;

  // Color
  int pencolor;

  // Draw to this
  BITMAP *penbuffer;
}turtle;

void fd( turtle *t, float amount);
void bk( turtle *t, float amount);
void lt( turtle *t, float amount);
void rt( turtle *t, float amount);

#endif
