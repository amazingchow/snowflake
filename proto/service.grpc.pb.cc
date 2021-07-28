// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto

#include "service.pb.h"
#include "service.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace photon_dance_snowflake_service {

static const char* PhotonDanceSnowflakeService_method_names[] = {
  "/photon_dance_snowflake_service.PhotonDanceSnowflakeService/GetUUID",
};

std::unique_ptr< PhotonDanceSnowflakeService::Stub> PhotonDanceSnowflakeService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< PhotonDanceSnowflakeService::Stub> stub(new PhotonDanceSnowflakeService::Stub(channel));
  return stub;
}

PhotonDanceSnowflakeService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_GetUUID_(PhotonDanceSnowflakeService_method_names[0], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>* PhotonDanceSnowflakeService::Stub::GetUUIDRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>::Create(channel_.get(), rpcmethod_GetUUID_, context);
}

void PhotonDanceSnowflakeService::Stub::experimental_async::GetUUID(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest,::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest,::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetUUID_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>* PhotonDanceSnowflakeService::Stub::AsyncGetUUIDRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>::Create(channel_.get(), cq, rpcmethod_GetUUID_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>* PhotonDanceSnowflakeService::Stub::PrepareAsyncGetUUIDRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>::Create(channel_.get(), cq, rpcmethod_GetUUID_, context, false, nullptr);
}

PhotonDanceSnowflakeService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PhotonDanceSnowflakeService_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< PhotonDanceSnowflakeService::Service, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse>(
          [](PhotonDanceSnowflakeService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse,
             ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest>* stream) {
               return service->GetUUID(ctx, stream);
             }, this)));
}

PhotonDanceSnowflakeService::Service::~Service() {
}

::grpc::Status PhotonDanceSnowflakeService::Service::GetUUID(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceResponse, ::photon_dance_snowflake_service::PhotonDanceSnowflakeServiceRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace photon_dance_snowflake_service

