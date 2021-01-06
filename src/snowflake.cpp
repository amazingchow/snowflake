#include "snowflake/snowflake.h"

Snowflake::Snowflake(const int64_t &machine_id)
{
    if (0 > machine_id || MAX_MACHINE_ID < machine_id)
    {
        fprintf(stderr, "machine_id should be [0 ~ %d]", MAX_MACHINE_ID);
        exit(1);
    }

    this->timestamp = 0;
    this->machine_id = machine_id;
    this->sequence_id = 0;
    this->sequence_id_mask = MAX_SEQUENCE_ID;
    this->timestamp_shift = SHIFT_TIMESTAMP;
    this->machine_id_shift = SHIFT_MACHINE_ID;
}

Snowflake::~Snowflake()
{
}

int64_t Snowflake::next_uuid()
{
    lock_guard_t lk(this->m_mutex);

    int64_t cur_timestamp = this->now();

    if (this->timestamp == cur_timestamp)
    {
        // the same timestamp, we just increase the sequence id
        this->sequence_id = (this->sequence_id + 1) & this->sequence_id_mask;
        if (0 == this->sequence_id)
        {
            while (this->timestamp == cur_timestamp)
            {
                cur_timestamp = this->now();
            }
        }
    }
    else
    {
        // not the same timestamp, we just reset the sequence id
        this->sequence_id = 0;
    }

    this->timestamp = cur_timestamp;

    return (this->timestamp << this->timestamp_shift) | (this->machine_id << this->machine_id_shift) | (this->sequence_id);
}
