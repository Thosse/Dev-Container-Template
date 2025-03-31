FROM mcr.microsoft.com/devcontainers/base:bookworm

# Define versions as build arguments
ARG CLANG_VERSION="1:14.0-55.7~deb12u1"
ARG CMAKE_VERSION="3.25.1-1"
ARG MAKE_VERSION="4.3-4.1"

# Install development tools
RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    gdb \
    clang=${CLANG_VERSION} \
    clang-tools=${CLANG_VERSION} \
    clang-format=${CLANG_VERSION} \
    clang-tidy=${CLANG_VERSION} \
    lldb=${CLANG_VERSION} \
    cmake=${CMAKE_VERSION} \
    make=${MAKE_VERSION} \
    build-essential

# Install Google Test
RUN apt-get install -y libgtest-dev \
    && cd /usr/src/googletest/googletest \
    && cmake . \
    && make \
    && cp lib/libgtest*.a /usr/lib/

# Install additional tools
RUN apt-get install -y \
    python3 \
    python3-pip \
    inkscape \
    graphviz

# Set clang as the default compiler
ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++