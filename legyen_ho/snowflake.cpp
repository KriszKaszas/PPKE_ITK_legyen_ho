#include "snowflake.h"

Snowflake::Snowflake(int xCor, int yCor, int size)
{
    this->xCor = xCor;
    this->yCor = yCor;
    setSize(size);
    setSpeed();
}

void Snowflake::setSize(int size)
{
    this->size = size;
}

void Snowflake::setSpeed()
{
    this->speed = QRandomGenerator64::global()->bounded(5, 10);
}

int Snowflake::getX()
{
    return xCor;
}

int Snowflake::getY()
{
    return yCor;
}

int Snowflake::getSize()
{
    return size;
}

void Snowflake::behavior()
{
    if(yCor > 470)
    {
       yCor = QRandomGenerator64::global()->bounded(-400, -60);
    }
    else
    {
        yCor += speed;
    }
}

void Snowflake::dieDown()
{
    if(yCor > 470)
    {
       yCor = 500;
    }
    else
    {
        yCor += speed;
    }
}

void Snowflake::moveToBottom()
{
    yCor = 500;
}
