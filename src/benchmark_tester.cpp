#include <benchmark/benchmark.h>

#include <snowflake/snowflake.h>

static void BM_NextUUID(benchmark::State& state)
{
    Snowflake* snowflake = new Snowflake(8);
    for (auto _ : state)
    {
        snowflake->next_uuid();
    }
    delete snowflake;
}
BENCHMARK(BM_NextUUID)->Iterations(1e8)->Threads(4)->UseRealTime();

BENCHMARK_MAIN();
