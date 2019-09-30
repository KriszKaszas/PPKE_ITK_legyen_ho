#ifndef SNOWSTORM_H
#define SNOWSTORM_H

#include <QRandomGenerator>
#include <vector>
#include "snowflake.h"

using namespace std;

class SnowStorm
{
public:
    SnowStorm(int yCor);

private:
    vector<Snowflake> snowfall;
    void populateSnowfall(int yCor);
};

#endif // SNOWSTORM_H
