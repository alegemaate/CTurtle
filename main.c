#include <allegro.h>
#include <math.h>

#include "turtle.h"

// Buffer
BITMAP *buffer;

// Draw buffer
BITMAP *pen_buffer;

// Boolean
typedef enum{
  false = 0, true
}bool;

// Random
int random( int min, int max){
  // Gen
  int random_number = rand()%(max-min) + min;
  return random_number;
}

// Make our turtle
turtle turt;

// Draws a koch curve with defined length
void koch( turtle *t, float length, float precision, float scale){
  t -> pencolor = makecol((getr(t -> pencolor) + 1) % 255, (getg(t -> pencolor) + 1) % 255, (getb(t -> pencolor) + 1) % 255);
	if( length >= precision){
		koch( t, length/3, precision, scale);
		lt( t, 60);
		koch( t, length/3, precision, scale);
		rt( t, 120);
		koch( t, length/3, precision, scale);
		lt( t, 60);
		koch( t, length/3, precision, scale);
	}
}

// Draws a tree with defined length
void tree( turtle *t, float length, float precision, float scale){
  t -> pencolor = makecol((getr(t -> pencolor) + 1) % 255, (getg(t -> pencolor) + 1) % 255, (getb(t -> pencolor) + 1) % 255);
	if( length >= precision){
    fd( t, length * scale);
    rt( t, 20);
    tree( t, length - 4, precision, scale);
    lt( t, 40);
    tree( t, length - 4, precision, scale);
    rt( t, 20);
    bk( t, length);
  }
}

// Draws a binary tree with defined length
void binary_tree( turtle *t, float length, float precision, float scale){
  t -> pencolor = makecol((getr(t -> pencolor) + 1) % 255, (getg(t -> pencolor) + 1) % 255, (getb(t -> pencolor) + 1) % 255);
	if( length >= precision){
    fd( t, length * scale);
    rt( t, 90);
    binary_tree( t, length * 0.7, precision, scale);
    lt( t, 180);
    binary_tree( t, length * 0.7, precision, scale);
    rt( t, 90);
    bk( t, length);
	}
}

// Sign check
int check_sign( int num){
  if( num < 0)
    return -1;
  else if( num > 0)
    return 1;
  return 0;
}

// Init
void init(){
  // Allegro
  allegro_init();
  install_keyboard();
  install_mouse();

  // Screen
  set_color_depth( 32);
  set_gfx_mode( GFX_AUTODETECT_WINDOWED, 1280, 960, 0, 0);

  // Window title
  set_window_title("Koch Curve");

  // Random
  srand( time(NULL));

  // Buffer
  buffer = create_bitmap( SCREEN_W, SCREEN_H);

  // Pen buffer (for turtles)
  pen_buffer = create_bitmap( SCREEN_W, SCREEN_H);
  clear_to_color( pen_buffer, 0x000000);

  // Setup our turtle
  turt.x = SCREEN_W / 2;
  turt.y = SCREEN_H / 2;
  turt.angle = -90;
  turt.pendown = 1;
  turt.penbuffer = pen_buffer;
  turt.pencolor = 0xFF2255;
}

// Update
void update(){
  turt.pencolor = makecol( random( 0, 255), random( 0, 255), random( 0, 255));

  if( key[KEY_R]){
    clear_to_color( pen_buffer, 0x000000);
    while( key[KEY_R]){}
  }

  if( key[KEY_Z]){
    binary_tree( &turt, 200, 3, 1);
    while( key[KEY_Z]){}
  }
  if( key[KEY_X]){
    tree( &turt, 50, 1, 1);
    while( key[KEY_X]){}
  }
}

// Draw
void draw(){
  // Fill screen
  clear_to_color( buffer, 0x000000);

  // Draw turtle buffer
  draw_sprite( buffer, pen_buffer, 0, 0);

  // Draw buffer
  draw_sprite( screen, buffer, 0, 0);
}

// Main
int main(){
  init();

  while( !key[KEY_ESC]){
    update();
    draw();
  }

  return 0;
}
END_OF_MAIN();
