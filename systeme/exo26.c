#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **lines;
    int size;
    int capacity;
} LineBuffer;

LineBuffer* create_line_buffer(int capacity) {
    LineBuffer *buffer = (LineBuffer*)malloc(sizeof(LineBuffer));
    buffer->lines = (char**)malloc(capacity * sizeof(char*));
    buffer->size = 0;
    buffer->capacity = capacity;
    return buffer;
}

void destroy_line_buffer(LineBuffer *buffer) {
    for (int i = 0; i < buffer->size; ++i) {
        free(buffer->lines[i]);
    }
    free(buffer->lines);
    free(buffer);
}

void add_line(LineBuffer *buffer, const char *line) {
    if (buffer->size >= buffer->capacity) {
        free(buffer->lines[0]);
        memmove(buffer->lines, buffer->lines + 1, (buffer->size - 1) * sizeof(char*));
        buffer->size--;
    }
    buffer->lines[buffer->size] = strdup(line);
    buffer->size++;
}

void print_lines(LineBuffer *buffer) {
    for (int i = 0; i < buffer->size; ++i) {
        printf("%s", buffer->lines[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1], "-n") != 0) {
        fprintf(stderr, "Usage: %s -n <number> [file]\n", argv[0]);
        return 1;
    }

    int num_lines = atoi(argv[2]);
    if (num_lines <= 0) {
        fprintf(stderr, "Nombre de lignes invalide.\n");
        return 1;
    }

    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    LineBuffer *buffer = create_line_buffer(num_lines);

    while (fgets(line, sizeof(line), file) != NULL) {
        add_line(buffer, line);
    }

    print_lines(buffer);

    fclose(file);
    destroy_line_buffer(buffer);
    return 0;
}
