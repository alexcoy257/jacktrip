#include "keyboardhandler.h"

#include <QCoreApplication>
#include <QThread>
//#include <termios.h>
#include <unistd.h>
#include <stdio.h>


KeyboardReader::KeyboardReader(void)
{/*
  tcgetattr( STDIN_FILENO, &oldSet );
  newSet = oldSet;
  newSet.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newSet );
*/
}

KeyboardReader::~KeyboardReader(void)
{
  //tcsetattr( STDIN_FILENO, TCSANOW, &oldSet );
}

void KeyboardReader::run()
{
  while (true)
  {
    char key = getchar();
    emit KeyPressed(key);
  }
  return;
}

KeyboardHandler::KeyboardHandler(void)
{
  strString = "";
  uiAttempts = 3;
  kbUser = new KeyboardReader();
  QObject::connect (kbUser, SIGNAL (KeyPressed(char)), this, SLOT(OnKeyPressed(char)));
}

KeyboardHandler::~KeyboardHandler(void)
{
  kbUser->exit();
}

void KeyboardHandler::OnKeyPressed(char cCurrent)
{
  if (cCurrent == 10 ) // enter
  {
    if (strString == "lmnop")
    {
      // start process
      QCoreApplication::exit(0);
    }
    else
    {
      if (uiAttempts == 0)
        QCoreApplication::exit(1);
      uiAttempts--;
      strString.truncate(0);
    }
    // for testing
  }
  else
    strString.append(cCurrent);
  return;
}
