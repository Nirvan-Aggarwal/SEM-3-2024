#include <fcntl.h>      // For open()
#include <stdio.h>      // For printf(), perror()
#include <string.h>     // For strlen()
#include <sys/stat.h>   // For file permission macros
#include <sys/types.h>  // For ssize_t
#include <unistd.h>     // For read(), write(), close(), lseek()

#define BUFFER_SIZE 100  // Define buffer size before usage

int file_descriptor;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

int main() {
    // Open the file (create it if it does not exist, with read and write permissions)
    file_descriptor = open("example_file.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (file_descriptor < 0) {
        perror("Error opening file");
        return 1;
    }

    // Write to the file
    const char *text_to_write = "Hello, world! This is a test.";
    size_t text_length = strlen(text_to_write);  // Get the length of the string without null terminator

    bytes_written = write(file_descriptor, text_to_write, text_length);
    if (bytes_written < 0) {
        perror("Error writing to file");
        close(file_descriptor);
        return 1;
    }

    // Move the file offset to the beginning
    lseek(file_descriptor, 0, SEEK_SET);

    // Read from the file
    bytes_read = read(file_descriptor, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading from file");
        close(file_descriptor);
        return 1;
    }

    // Null-terminate the buffer and print its content
    buffer[bytes_read] = '\0';
    printf("File contents: %s\n", buffer);

    // Close the file
    if (close(file_descriptor) < 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}