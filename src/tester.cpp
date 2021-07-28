#include <cstdio>

#include <mutex>
#include <thread>

#include <snowflake/snowflake.h>

int main(int argc, char const *argv[])
{
    printf("snowflake testing ...\n");

    Snowflake ticker(8);
    printf("current uuid: %ld\n", ticker.next_uuid_v1());
    std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    printf("current uuid: %ld\n", ticker.next_uuid_v1());
    std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    printf("current uuid: %ld\n", ticker.next_uuid_v1());
    std::this_thread::sleep_for(std::chrono::nanoseconds(100));
    printf("current uuid: %ld\n", ticker.next_uuid_v1());
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    printf("current uuid: %ld\n", ticker.next_uuid_v1());
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    printf("current uuid: %ld\n", ticker.next_uuid_v1());
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    printf("current uuid: %ld\n", ticker.next_uuid_v1());

    return 0;
}
