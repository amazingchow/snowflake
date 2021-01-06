#include <iostream>

#include "snowflake/snowflake.h"

int main(int argc, char *argv[])
{
    Snowflake* ticker = new Snowflake(8);
    std::cout << ticker->next_uuid() << std::endl;
}
