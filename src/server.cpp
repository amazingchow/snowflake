#include <iostream>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <snowflake/protos/service.grpc.pb.h>
#include <snowflake/snowflake.h>

namespace ss = photon_dance_snowflake_service;

class PhotonDanceSnowflakeServiceImpl final : public ss::PhotonDanceSnowflakeService::Service
{
  public:
    /* 构造函数 */
    PhotonDanceSnowflakeServiceImpl()
    {
        this->snowflake = new Snowflake(-1);
    }
    /* 析构函数 */
    ~PhotonDanceSnowflakeServiceImpl()
    {
        delete this->snowflake;
    }

    grpc::Status GetUUID(grpc::ServerContext* context, 
        const ss::PhotonDanceSnowflakeServiceRequest* request, ss::PhotonDanceSnowflakeServiceResponse* response) override 
    {
        response->set_uuid(this->snowflake->next_uuid_v2(request->machine_id()));
        return grpc::Status::OK;
    }

  private:
    Snowflake* snowflake;
};

void RunServer()
{
    std::string server_address("0.0.0.0:18888");
    PhotonDanceSnowflakeServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char const *argv[])
{
    RunServer();
    return 0;
}
