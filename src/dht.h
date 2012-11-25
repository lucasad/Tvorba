#ifndef DHT_H
#define DHT_H

#include <vector>

#include "node.h"

class DHT
{
public:
    DHT();

private:
    std::vector<Node*> *nodes;
};

#endif // DHT_H
