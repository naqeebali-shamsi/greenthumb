FROM gcc:latest

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    python3-pip \
    libsdl2-dev \
    libsdl2-ttf-dev \
    libsdl2-image-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install Conan
RUN pip3 install conan

# Set the working directory
WORKDIR /app

# Copy the project files to the container
COPY . .

# Install Conan dependencies
RUN conan install . --build=missing --output-folder=build

# Configure and build the project
RUN cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release && cmake --build .

# Expose the port that your application listens on
EXPOSE 8000

# Start the application
CMD ["./build/Debug/GreenThumb.exe"]
