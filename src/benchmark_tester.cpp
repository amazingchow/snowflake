#include <benchmark/benchmark.h>

#include <snowflake/snowflake.h>

static void BM_NextUUID(benchmark::State& state)
{
    Snowflake* ticker = new Snowflake(8);
    for (auto _ : state)
    {
        ticker->next_uuid();
    }
    delete ticker;
}
BENCHMARK(BM_NextUUID)->Iterations(10000000);

BENCHMARK_MAIN();
