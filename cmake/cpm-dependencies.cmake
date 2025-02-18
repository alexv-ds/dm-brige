include(CPM)


list(APPEND BOOST_LIBS
  "core"
  "json"
  "asio"
  "beast"
)
list(JOIN BOOST_LIBS "\\\;" BOOST_LIBS)

CPMAddPackage(
  NAME Boost
  VERSION "1.87.0"
  URL "https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.tar.xz"
  URL_HASH "SHA3_256=86e00a266696c0f855869ba4a73877d45b547192174eac8a42d9fa9db63c34a4"
  SYSTEM ON
  EXCLUDE_FROM_ALL ON
  OPTIONS
  "BOOST_ENABLE_CMAKE ON"
  "BOOST_SKIP_INSTALL_RULES ON"
  "BUILD_SHARED_LIBS OFF"
  "BOOST_INCLUDE_LIBRARIES ${BOOST_LIBS}"
)
