ARG GIT_REPO=git@github.com:fideuardo/IPCBaseSytem.git

    FROM ubuntu:20.04

    # Instalar dependencias
    RUN apt-get update && apt-get install -y \
        build-essential \
        gcc-arm-linux-gnueabihf \
        cmake \
        git \
        openssh-client

    # Clona el repositorio
    RUN git clone $GIT_REPO /app

    # Compilar el código con CMake
    WORKDIR /app
    RUN mkdir build && cd build && \
        cmake .. -DCMAKE_C_COMPILER=arm-linux-gnueabihf-gcc && \
        make

    # Comando para copiar el binario fuera del contenedor
    CMD cp /app/build/IPCBaseSytem /salida/IPCBaseSytem

    # Limpieza (opcional)
    RUN rm -rf /app/build/* /var/lib/apt/lists/*