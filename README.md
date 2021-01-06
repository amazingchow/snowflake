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
