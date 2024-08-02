# FullStackChattingDemo

## Description

### Client

1. Libraries: using QT6

   Q::Widgets 

   Qt::Network

### Server

1. Libraries: 

   boost-1.84(contains beast asio uuid)

   jsoncpp

   ada(url parsing)

   grpc-1.65.2  -> FetchContent

   

2. Functions: accept both GET and POST methods

   Handling GET: /get_test

   Handling POST:/get_verification, client sends a json form to the server and server will parse the form and return a json form back to the client

## Requirements

The project is self-contained and it has no dependency on both Windows and Linux/Unix-like systems.

## Developer Quick Start

### Platform Support

~~Windows~~, Linux, ~~MacOS~~

Currently, MacOS with APPLE SILLICON is not supported yet

### Building  FullStackChattingDemo

```bash
git clone https://github.com/Liupeter01/FullStackChattingDemo
cd FullStackChattingDemo/servwe
cmake -B build
cmake --build build --parallel x
```

### Error Handling

1. Handling missing CMAKE_ASM_MASM_COMPILE_OBJECT issue on windows

   ```bash
   add that folder to the PATH and set another env variable ASM_NASM with the name of nasm.exe.
   ```

   Referring Url

   https://stackoverflow.com/questions/73214824/missing-cmake-asm-nasm-compiler-when-compiling-grpc-with-ms-visual-studio

   

2. Handling gRPC issue

   Issue description

   ```bash
   CMake Error: install(EXPORT "protobuf-targets" ...) includes target "libprotobuf-lite" which requires target "absl_node_hash_map" that is not in any export set.
   ```

   Problem Solving

   ```cmake
   set(ABSL_ENABLE_INSTALL ON)
   ```

   Referring Url

    https://github.com/protocolbuffers/protobuf/issues/12185 

    https://github.com/protocolbuffers/protobuf/issues/12185#issuecomment-1594685860



