#include "snowstorm.h"

SnowStorm::SnowStorm(int yCor)
{
    populateSnowfall(yCor);
}

void SnowStorm::populateSnowfall(int yCor)
{
    for(int i = 0; i<200; i++)
    {
        int xCor = QRandomGenerator::global()->bounded(0,750);
        int size = QRandomGenerator::global()->bounded(2, 10);
        int speed = QRandomGenerator::global()->bounded(5, 30);
        Snowflake *snowflake = new Snowflake(xCor, yCor, size, size);
        snowfall.push_back(*snowflake);

    }
}
