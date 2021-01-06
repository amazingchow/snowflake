# photon-dance-snowflake

To efficiently generate 64-bit UUID for large-scale distributed application.

## What is Snowflake?

The UUID is made up of the following components

```text
+--------+-------------------+--------------+-------------------+
|  sign  |  delta timestamp  |  machine id  |  sequence number  |
+--------+-------------------+--------------+-------------------+
   1bit          41bits           10bits            12bits
```

* 1-bit sign flag

always be zero.

* 41-bit epoch timestamp in millisecond precision

not store current timestamp, but the delta timestamp.  

* 10-bit configured machine id

can be deployed on most up to 1024 nodes.

* 12-bit sequence number

counter within milliseconds, the 12-bit can support most up to 4096 sequence numbers per node (the same machine) and per millisecond (the same timestamp).

* the UUIDs are increasing in order by timestamp.

## Requirements

The following minimum versions are required to build the library

* CMake 3.5
* GCC 4.9
* Google Benchmark 1.5.2

## Installation

```text
# Check out the library.
$ git clone https://github.com/amazingchow/photon-dance-snowflake.git

# Go to the library root directory
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

use google benchmark framework, as shown below, we can generate 342 UUIDs per millisecond.

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

before execute photon_dance_snowflake_benchmark_tester, you should do

```shell
sudo cpupower frequency-set --governor performance
```

after then, you should do

```shell
sudo cpupower frequency-set --governor performance
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
