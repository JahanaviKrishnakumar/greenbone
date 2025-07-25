# Reference: https://github.com/greenbone/gvm-libs/blob/main/.docker/prod.Dockerfile
FROM  debian:stable-slim AS base
ENV DEBIAN_FRONTEND=noninteractive
COPY ./docker/dependant_libraries.txt /tmp/

RUN apt-get update && \
    xargs -a /tmp/dependant_libraries.txt apt-get install -y --no-install-recommends && \
    rm -rf /var/lib/apt/lists/* /tmp/dependant_libraries.txt

# GTest
RUN cd /usr/src/googletest && \
    cmake . && \
    cmake --build . --target install

# build gvm_libs required for decoder functionality
RUN git clone https://github.com/greenbone/gvm-libs.git && \
    cd gvm-libs && \
    mkdir build && cd build && \
    cmake .. && make -j$(nproc) && make install && \
    cd / && rm -rf /gvm-libs

# Update linker cache
RUN ldconfig

# Copy your C source code into the image
COPY ./CMakeLists.txt      /decoder/CMakeLists.txt
COPY ./inc                 /decoder/inc
COPY ./src                 /decoder/src
COPY ./test                /decoder/test

WORKDIR /decoder
# building decoder 
RUN mkdir build && cd build && \
    cmake .. && make -j$(nproc)

CMD ["/decoder/build/decoder"]

