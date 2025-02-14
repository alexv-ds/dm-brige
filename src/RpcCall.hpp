#pragma once
#include <string>
#include <optional>
#include <functional>
#include <boost/json/value.hpp>
#include <boost/noncopyable.hpp>

namespace dmbridge {

class RpcCall : public boost::noncopyable {
public:
  struct Request {
    std::string method;
    boost::json::value params;
  };

  struct Error {
    std::int32_t code = 0;
    std::string message;
  };

  struct Responce {
    boost::json::value result;
    std::optional<Error> error;
  };

  [[nodiscard]] const std::string& method() const noexcept;

  [[nodiscard]] bool resolved() const noexcept;

  [[nodiscard]] bool notification() const noexcept;

  [[nodiscard]] const Request& request() const noexcept;

  [[nodiscard]] const Responce& responce() const noexcept;

  void resolve(Responce&& responce);

  RpcCall(Request&& req, std::function<void(RpcCall&)> on_resolve) noexcept;
  RpcCall(RpcCall&& call) noexcept;
  RpcCall& operator=(RpcCall&& call) noexcept;

private:
  std::string method_;
  Request request_;
  Responce responce_;
  bool notification_;
  std::function<void(RpcCall&)> resolve_cb_;
};

// //////////////////////// //
// ///////// IMPL ///////// //
// //////////////////////// //

inline const std::string& RpcCall::method() const noexcept {
  return this->method_;
}

inline bool RpcCall::resolved() const noexcept {
  return this->resolve_cb_ == nullptr;
};

inline const RpcCall::Request& RpcCall::request() const noexcept {
  return this->request_;
}

inline const RpcCall::Responce& RpcCall::responce() const noexcept {
  return this->responce_;
}

inline bool RpcCall::notification() const noexcept {
  return this->notification_;
};

inline RpcCall::RpcCall(Request&& req, std::function<void(RpcCall&)> resolve_cb) noexcept
  : request_(std::move(req)), resolve_cb_(std::move(resolve_cb)) {
  this->notification_ = this->resolve_cb_ == nullptr;
}

inline RpcCall::RpcCall(RpcCall&& call) noexcept
  : method_(std::move(call.method_)),
    request_(std::move(call.request_)),
    responce_(std::move(call.responce_)),
    notification_(call.notification_),
    resolve_cb_(std::move(call.resolve_cb_))
{
  call.notification_ = false;
  call.resolve_cb_ = nullptr;
}

inline RpcCall& RpcCall::operator=(RpcCall&& call) noexcept {
  this->method_ = std::move(call.method_);
  this->request_ = std::move(call.request_);
  this->responce_ = std::move(call.responce_);
  this->notification_ = call.notification_;
  this->resolve_cb_ = std::move(call.resolve_cb_);
  call.notification_ = false;
  call.resolve_cb_ = nullptr;
  return *this;
}

} // namespace dmbridge