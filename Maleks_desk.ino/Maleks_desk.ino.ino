#include <USB.h>
#include <USBHIDKeyboard.h>
#include <USBHIDMouse.h>

USBHIDKeyboard Keyboard;
USBHIDMouse Mouse;

// ========= GPIO =========

#define BTN_W      10
#define BTN_A      11
#define BTN_S      12
#define BTN_D      13

#define BTN_COPY   14
#define BTN_PASTE  15

#define JOY_X       4
#define JOY_Y       5
#define JOY_SW     40

// ========================

void setup()
{
  USB.begin();

  Keyboard.begin();
  Mouse.begin();

  pinMode(BTN_W, INPUT_PULLUP);
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_S, INPUT_PULLUP);
  pinMode(BTN_D, INPUT_PULLUP);

  pinMode(BTN_COPY, INPUT_PULLUP);
  pinMode(BTN_PASTE, INPUT_PULLUP);

  pinMode(JOY_SW, INPUT_PULLUP);

  setupMouse();
}

void loop()
{
  HandleMouse();
  HandleKeyboard();
}