//==============================
// Keyboard1.ino
//==============================

bool lastW = HIGH;
bool lastA = HIGH;
bool lastS = HIGH;
bool lastD = HIGH;

bool lastCopy = HIGH;
bool lastPaste = HIGH;

void HandleKeyboard()
{
  // ======================
  // W
  // ======================

  bool w = digitalRead(BTN_W);

  if (w != lastW)
  {
    if (!w)
      Keyboard.press('w');
    else
      Keyboard.release('w');

    lastW = w;
  }

  // ======================
  // A
  // ======================

  bool a = digitalRead(BTN_A);

  if (a != lastA)
  {
    if (!a)
      Keyboard.press('a');
    else
      Keyboard.release('a');

    lastA = a;
  }

  // ======================
  // S
  // ======================

  bool s = digitalRead(BTN_S);

  if (s != lastS)
  {
    if (!s)
      Keyboard.press('s');
    else
      Keyboard.release('s');

    lastS = s;
  }

  // ======================
  // D
  // ======================

  bool d = digitalRead(BTN_D);

  if (d != lastD)
  {
    if (!d)
      Keyboard.press('d');
    else
      Keyboard.release('d');

    lastD = d;
  }

  // ======================
  // COPY
  // ======================

  bool copy = digitalRead(BTN_COPY);

  if (!copy && lastCopy)
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(20);
    Keyboard.releaseAll();
  }

  lastCopy = copy;

  // ======================
  // PASTE
  // ======================

  bool paste = digitalRead(BTN_PASTE);

  if (!paste && lastPaste)
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(20);
    Keyboard.releaseAll();
  }

  lastPaste = paste;
}