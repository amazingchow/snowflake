#ifndef __PHOTON_DANCE_SNOWFLAKE_H__
#define __PHOTON_DANCE_SNOWFLAKE_H__

#include <cstdio>
#include <cstdint>
#include <cstdlib>

#include <chrono>
#include <mutex>
#include <thread>

#define TWITTER_SNOWFLAKE_EPOCH 1288834974657 // Nov 04 2010 01:42:54 UTC in milliseconds
#define BIT_MACHINE_ID          10            // 0 ~ 1023
#define BIT_SEQUENCE_ID         12            // 0 ~ 4095
#define SHIFT_TIMESTAMP         22
#define SHIFT_MACHINE_ID        12
#define MAX_MACHINE_ID          ((-1)^((-1) << BIT_MACHINE_ID))
#define MAX_SEQUENCE_ID         ((-1)^((-1) << BIT_SEQUENCE_ID))

class Snowflake final {

public:
    /* 构造函数 */
    explicit Snowflake(const int64_t &machine_id);
    /* 析构函数 */
    ~Snowflake();

private:
    /* 拷贝构造 */
    Snowflake(const Snowflake &) = delete;
    Snowflake(Snowflake &&) = delete;
    /* 赋值拷贝 */
    Snowflake& operator=(const Snowflake &) = delete;
    Snowflake& operator=(Snowflake &&) = delete;

public:
    // used for non-server-service
    int64_t next_uuid_v1();
    // used for server-service
    int64_t next_uuid_v2(const int64_t &mid);
    static int64_t now() {
        return (std::chrono::duration_cast<std::chrono::milliseconds>( \
            std::chrono::system_clock::now().time_since_epoch()).count() - TWITTER_SNOWFLAKE_EPOCH);        
    }

private:
    typedef std::mutex mutex_t;
    typedef std::lock_guard<mutex_t> lock_guard_t;
    mutable mutex_t m_mutex;

    int64_t timestamp;
    int64_t machine_id;
    int64_t sequence_id;
    int64_t sequence_id_mask;
    uint8_t timestamp_shift;
    uint8_t machine_id_shift;

};

#endif /* __PHOTON_DANCE_SNOWFLAKE_H__ */
