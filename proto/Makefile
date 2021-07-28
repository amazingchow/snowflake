# libprotoc 3.14.0
# grpc c++ v1.35.x

compile:
	/usr/local/bin/protoc -I ./protos --grpc_out=../include/snowflake/protos --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ./protos/service.proto
	/usr/local/bin/protoc -I ./protos --cpp_out=../include/snowflake/protos ./protos/service.proto
