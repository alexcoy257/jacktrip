#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H


#include <QCoreApplication>
#include <QObject>
#include <QThread>
class KeyboardReader: public QThread
{
  Q_OBJECT
  public:
    KeyboardReader(void);
    ~KeyboardReader(void);
    void run();
  signals:
    void KeyPressed(char);
};

class KeyboardHandler: public QObject
{
  Q_OBJECT
  public:
    KeyboardHandler(void);
    ~KeyboardHandler(void);
    QString strString;
    quint16 uiAttempts;
    KeyboardReader *kbUser;
  public slots:
    void OnKeyPressed(char);
};
#endif // KEYBOARDHANDLER_H
