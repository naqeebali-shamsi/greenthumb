FROM gcc:latest

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    libsdl2-dev \
    libsdl2-ttf-dev \
    libsdl2-image-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the project files to the container
COPY . .

# Configure and build the project
RUN cmake -S . -B build
RUN cmake --build build

# Add the custom clean target
RUN cmake --build build --target clean-all

# Expose the port that your application listens on
EXPOSE 8000

# Start the application
CMD ["./build/greenthumb"]
