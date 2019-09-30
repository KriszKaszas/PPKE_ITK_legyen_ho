#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QRandomGenerator64>
class Snowflake
{
public:
    Snowflake(int xCor, int yCor, int size);
    void behavior();
    void dieDown();
    void moveToBottom();
    int getX();
    int getY();
    int getSize();
    int getSpeed();


private:
    int xCor;
    int yCor;
    int size;
    int speed;
    void setSize(int size);
    void setSpeed();
};

#endif // SNOWFLAKE_H
