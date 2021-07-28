# photon-dance-snowflake

To efficiently generate 64-bit UUID for large-scale distributed application.

## What is Snowflake?

The snowflake UUID is comprised of

```text
+--------+-------------------+--------------+-------------------+
|  sign  |  delta timestamp  |  machine id  |  sequence number  |
+--------+-------------------+--------------+-------------------+
   1bit          41bits           10bits            12bits
```

* 1-bit sign flag

Always be zero.

* 41-bits epoch timestamp in millisecond precision

Not current timestamp, but the delta timestamp, so we can use it for a long long long time.  

* 10-bits machine id

The snowflake UUID service can be deployed on most up to 1024 nodes.

* 12-bits sequence number

Counter within milliseconds, the 12-bits can support most up to 4096 sequence numbers per (node + millisecond).

The UUIDs are increased in order by timestamp.

## Requirements

The following minimum versions are required to build the library

* CMake 3.5+
* GCC 7.5+
* Google Benchmark 1.5.5+

## Installation

```text
# Check out the library.
$ git clone https://github.com/amazingchow/photon-dance-snowflake.git

# Go to the library root directory.
$ cd photon-dance-snowflake

# Make a build directory to place the build output.
$ cmake -E make_directory "build"

# Generate build system files with cmake.
$ cmake -E chdir "build" cmake -DCMAKE_BUILD_TYPE=Release ../

# Build the library.
$ cmake --build "build" --config Release

# Install the library globally.
$ sudo cmake --build "build" --config Release --target install
```

## Benchmark

As google benchmark framework shows, we can generate 342 UUIDs per millisecond.

```text
Run on (12 X 4600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 0.52, 0.48, 0.55
--------------------------------------------------------------------------
Benchmark                                Time             CPU   Iterations
--------------------------------------------------------------------------
BM_NextUUID/iterations:10000000        244 ns          244 ns     10000000
```

### Tips

Before execute photon_dance_snowflake_benchmark_tester, please record current CPU governor, for instance, current CPU governor is ``powersave``.

```
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
```

You better set CPU governor mode as ``performance``.

```shell
sudo cpupower frequency-set --governor performance
```

If you meet the "cpupower: command not found", just install the linux-tools

```shell
sudo apt-get install -y linux-tools-$(uname -r)
```

After benchmark, you better set CPU governor mode back to ``powersave``

```shell
sudo cpupower frequency-set --governor powersave
```

## Contributing

### Step 1

* 🍴 Fork this repo!

### Step 2

* 🔨 HACK AWAY!

### Step 3

* 🔃 Create a new PR using https://github.com/amazingchow/photon-dance-snowflake/compare!

## Support

* Reach out to me at <jianzhou42@163.com>.

## License

* This project is licensed under the MIT License - see the **[MIT license](http://opensource.org/licenses/mit-license.php)** for details.
