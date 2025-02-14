#include <stdexcept>
#include "RpcCall.hpp"

namespace dmbridge {

void RpcCall::resolve(Responce&& responce) {
  if (this->notification()) {
    throw std::logic_error("cannot resolve notification call");
  }
  if (this->resolved()) {
    throw std::logic_error("already resolved");
  }
  this->responce_ = std::move(responce);
  this->resolve_cb_(*this);
}

} // namespace dmbridge