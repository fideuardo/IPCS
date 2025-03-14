# Etapa de construcción
FROM ubuntu:20.04 as builder

# Argumentos configurables
ARG GIT_REPO=https://github.com/fideuardo/IPCBaseSytem.git
ARG GIT_BRANCH=init  # Nuevo argumento para el branch

# Instalación de dependencias
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-arm-linux-gnueabihf \
    cmake \
    git \
 && rm -rf /var/lib/apt/lists/*

# Clonamos el repositorio especificando el branch
RUN git clone --branch ${GIT_BRANCH} --depth 1 ${GIT_REPO} /app  # Clona solo el branch init

# Compilación del proyecto
WORKDIR /app
RUN mkdir build && cd build && \
    cmake .. -DCMAKE_C_COMPILER=arm-linux-gnueabihf-gcc && \
    make

# Etapa final minimalista
FROM alpine:latest
RUN mkdir /salida
COPY --from=builder /app/build/IPCBaseSytem /salida/
CMD ["sleep", "infinity"]