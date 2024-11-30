#pragma once
#ifndef _GRPCDISTRIBUTEDCHATTINGSERVICE_HPP_
#define _GRPCDISTRIBUTEDCHATTINGSERVICE_HPP_
#include <grpc/BalanceServicePool.hpp>
#include <grpc/DistributedChattingServicePool.hpp>
#include <network/def.hpp>
#include <optional>
#include <unordered_map>

class gRPCDistributedChattingService
    : public Singleton<gRPCDistributedChattingService> {
  friend class Singleton<gRPCDistributedChattingService>;
  gRPCDistributedChattingService();

public:
  virtual ~gRPCDistributedChattingService() = default;
  message::AddNewFriendResponse
  sendFriendRequest(const std::string &server_name,
                    const message::AddNewFriendRequest &req);
  message::AuthoriseResponse
  confirmFriendRequest(const std::string &server_name,
                       const message::AuthoriseRequest &req);

private:
  std::optional<std::shared_ptr<stubpool::DistributedChattingServicePool>>
  getTargetChattingServer(const std::string &server_name);

private:
  std::unordered_map<
      /*server_name*/ std::string,
      /*DistributedChattingServicePool*/ std::shared_ptr<
          stubpool::DistributedChattingServicePool>>
      m_pools;
};

#endif //_GRPCDISTRIBUTEDCHATTINGSERVICE_HPP_
