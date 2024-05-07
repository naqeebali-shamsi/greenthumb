# Use a base image that includes g++ and SDL2
FROM gcc:latest

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    libsdl2-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the project files to the container
COPY . .

# Build the project
RUN find . -name "*.cpp" -exec g++ -c -std=c++11 -I/usr/include/SDL2 -Iinclude {} \; && g++ -o greenthumb *.o -lSDL2

# Expose the port that your application listens on
EXPOSE 8000

# Start the application
CMD ["./greenthumb"]