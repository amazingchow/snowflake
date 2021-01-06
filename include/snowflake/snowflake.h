#ifndef __PHOTON_DANCE_SNOWFLAKE_H__
#define __PHOTON_DANCE_SNOWFLAKE_H__

namespace photon_dance
{

class Snowflake final {

public:
    /* 构造函数 */
    explicit Snowflake();
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
    void print();

};

} // photon_dance


#endif /* __PHOTON_DANCE_SNOWFLAKE_H__ */
