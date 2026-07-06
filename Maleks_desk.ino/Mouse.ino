//==============================
// Mouse.ino
//==============================

int centerX = 0;
int centerY = 0;

bool leftPressed = false;
bool rightLock = false;

unsigned long lastClickTime = 0;
byte clickCount = 0;
bool lastSW = false;

//==============================

void setupMouse()
{
  delay(800);

  long sx = 0;
  long sy = 0;

  for (int i = 0; i < 50; i++)
  {
    sx += analogRead(JOY_X);
    sy += analogRead(JOY_Y);
    delay(5);
  }

  centerX = sx / 50;
  centerY = sy / 50;
}

//==============================

void HandleMouse()
{
  int x = analogRead(JOY_X);
  int y = analogRead(JOY_Y);

  if (abs(x - centerX) < 60)
    centerX = (centerX * 99 + x) / 100;

  if (abs(y - centerY) < 60)
    centerY = (centerY * 99 + y) / 100;

  int dx = x - centerX;
  int dy = y - centerY;

  int mx = 0;
  int my = 0;

  if (abs(dx) > 250)
  {
    mx = dx / 350;
    if (mx > 4) mx = 4;
    if (mx < -4) mx = -4;
  }

  if (abs(dy) > 250)
  {
    my = -(dy / 350);
    if (my > 4) my = 4;
    if (my < -4) my = -4;
  }

  Mouse.move(mx, my);

  bool sw = !digitalRead(JOY_SW);
  bool w = !digitalRead(BTN_W);
  bool s = !digitalRead(BTN_S);
  bool d = !digitalRead(BTN_D);

  // Triple Click = Middle

  if (sw && !lastSW)
  {
    if (millis() - lastClickTime < 350)
      clickCount++;
    else
      clickCount = 1;

    lastClickTime = millis();

    if (clickCount == 3)
    {
      Mouse.click(MOUSE_MIDDLE);
      clickCount = 0;
    }
  }

  // Right Click

  if (sw && d)
  {
    if (!rightLock)
    {
      Mouse.click(MOUSE_RIGHT);
      rightLock = true;
    }
  }
  else
  {
    rightLock = false;
  }

  // Scroll Up

  if (sw && w)
  {
    Mouse.move(0, 0, 1);
    delay(20);
  }

  // Scroll Down

  if (sw && s)
  {
    Mouse.move(0, 0, -1);
    delay(20);
  }

  // Left Hold

  if (sw && !w && !s && !d)
  {
    if (!leftPressed)
    {
      Mouse.press(MOUSE_LEFT);
      leftPressed = true;
    }
  }
  else
  {
    if (leftPressed)
    {
      Mouse.release(MOUSE_LEFT);
      leftPressed = false;
    }
  }

  lastSW = sw;

  delay(5);
}