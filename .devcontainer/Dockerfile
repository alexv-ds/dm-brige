
FROM mcr.microsoft.com/devcontainers/base:bookworm

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# hadolint ignore=DL3009
RUN \
  apt-get update && \
  apt-get install --no-install-recommends -y \
    ninja-build=1.11.1-2~deb12u1 \
    gdb=13.1-3 \
    gcc=4:12.2.0-3 \
    g++=4:12.2.0-3 \
  && \
  apt-get clean && \
  wget --progress=dot:giga -O /cmake.tar.gz https://github.com/Kitware/CMake/releases/download/v3.31.5/cmake-3.31.5-linux-x86_64.tar.gz && \
  echo "2984e70515ff60c5e4a41922b5d715a8168a696a89721e3b114e36f453244f72 /cmake.tar.gz" | sha256sum -c && \
  tar -xzhf /cmake.tar.gz -C / --strip-components=1 && \
  rm /cmake.tar.gz && \ 
  rsync -a /share/* /usr/share && \
  rm -r /share




  