#include "functions.h"

int main(int argc, char** argv) {

    char* response[2] = {NULL, NULL};
    char* separators;
    FILE* input;
    int len = 0;
    struct Node* tree;
    int length = 0;
    int i = 0;
    int reached = 0;
    int cmd_code = 0;
    char* word = NULL;
    int found = 0;
    int size = 0;
    char** words = NULL;
    int* amounts = NULL;

    if(argc < 2) { printf("no separators were given.\n"); return 0; }
    separators = (char*)malloc(sizeof(char) * (argc-1));
    if(separators == NULL)
    {
        printf("memory error\n");
        return 0;
    }
    input = fopen(argv[1], "r");
    for(int i = 2; i < argc; i++)
    {
        len = strlen(argv[i]);
        if(strlen(argv[i]) == 1 && i < argc - 1)
        {
            if(strlen(argv[i+1]) == 1)
            {
                if(argv[i][0] == '\'' && argv[i+1][0] == '\'')
                {
                    argc--;
                    argv[i+1] = argv[argc];
                    separators[i-2] = ' ';
                }
            }
        }
        if(!strcmp(argv[i], "'") && i <= argc - 1) { if(!strcmp(argv[i+1], "'")) {separators[i] = ' '; i++;} }
        else if(len > 4 || len < 3 || argv[i][0] != '\'' || argv[i][len-1] != '\'')
        {
            printf("Invalid separator input. Put the symbol in single quotes.\n");
            free(separators);
            return 0;
        }
        if(argv[i][1] == '\\')
        {
            switch(argv[i][2])
            {
                case 'n':
                {
                    separators[i-2] = '\n';
                    break;
                }
                case 't':
                {
                    separators[i-2] = '\t';
                    break;
                }
                default:
                {
                    printf("like... why\n");
                    free(separators);
                    return 0;
                }
            }
        }
        else separators[i-2] = argv[i][1];
    }
    separators[argc-2] = '\0';

    if(input == NULL)
    {
        printf("Couldn't open file for reading at %s\n", argv[1]);
        free(separators);
        return 0;
    }

    tree = (struct Node*)malloc(sizeof(struct Node));
    tree->word = NULL;

    if(read_from_file(input, tree, separators) == memory_error)
    {
        printf("Memory error, pardon.\n");
        free(separators);
        fclose(input);
        delete_tree(tree);
        return 0;
    }
    free(separators);
    fclose(input);
    printf("file was read successfully.\n");
    printf("available commands are:\n"
           "print - print\n"
           "find [word] - find word\n"
           "common [number] - first [number] common words in text\n"
           "shortest - shortest word in text\n"
           "longest - guess what\n"
           "quit - guess what??\n");
    fflush(stdout);

    response[0] = strdup("");

    while(strcmp(response[0], "quit"))
    {
        i = 1;

        reached = get_string(stdin, &response[0], &length, " \n");
        if(reached == memory_error)
        {
            printf("memory error\n");
            break;
        }
        if(reached == space_reached)
        {
            reached = get_string(stdin, &response[1], &length, " \n");
            i = 2;
        }
        if(reached == memory_error)
        {
            printf("memory error\n");
            break;
        }
        if(reached == space_reached)
        {
            printf("command unrecognized.\n");
            continue;
        }
        cmd_code = get_cmd_code(response[0]);
        switch (cmd_code)
        {
            case find:
            {
                if(i != 2) { printf("inappropriate input\n"); break; }
                word = response[1];
                found = find_word(tree, word);
                printf("Word '%s' occurs %d times in the tree.\n", response[1], found);
                break;
            }
            case common:
            {
                if(i != 2 || !is_number(response[1])) { printf("inappropriate input\n"); break; }
                size = atoi(response[1]);
                if(size < 1) { printf("inappropriate input\n"); break; }
                words = (char**)malloc(sizeof(char*)*size);
                if(words == NULL)
                {
                    printf("memory error\n");
                    delete_tree(tree);
                    tree = NULL;
                    free(response[0]);
                    free(response[1]);
                    return 0;
                }
                amounts = (int*)calloc(size, sizeof(int));
                if(amounts == NULL)
                {
                    printf("memory error\n");
                    delete_tree(tree);
                    tree = NULL;
                    free(words);
                    free(response[0]);
                    free(response[1]);
                    return 0;
                }

                find_n_most_often(tree, &amounts, &words, size);
                printf("Found %d most often words:\n",size);
                for(int k = 0; k < size; k++) printf("%d - %s\n", amounts[k], words[k]);
                free(words);
                free(amounts);
                break;
            }
            case shortest:
            {
                if(i != 1) { printf("inappropriate input\n"); break; }
                find_shortest(tree, &word, INT_MAX);
                printf("Shortest word found is '%s'\n", word);
                break;
            }

            case longest:
            {
                if(i != 1) { printf("inappropriate input\n"); break; }
                find_longest(tree, &word, 0);
                printf("Longest word found is '%s'\n", word);
                break;
            }
            case print:
            {
                print_tree(tree, 0);
                break;
            }
            case quit:
            {
                printf("GoodBye!\n");
                break;
            }
            case unknown:
            {
                printf("Unknown command\n");
                break;
            }
            default:
            {
                printf("man wtf");
                break;
            }
        }
        fflush(stdout);
    }
    if(tree != NULL) delete_tree(tree);
    if(response[0] != NULL) free(response[0]);
    if(response[1] != NULL) free(response[1]);
    if(word != NULL) free(word);
    return 0;
}