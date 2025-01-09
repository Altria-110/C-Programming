#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 1024
#define MAX_WORDS 1000
#define END_STRING "END"

typedef struct {
    char word[50]; // 假设单词长度不会超过50个字符
    int lineCounts[MAX_LINES];
    int totalCount;
} WordInfo;

int findWord(WordInfo *wordList, int wordCount, const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(WordInfo *wordList, int *wordCount, const char *word, int lineNumber) {
    int index = findWord(wordList, *wordCount, word);
    if (index == -1) {
        strncpy(wordList[*wordCount].word, word, sizeof(wordList[*wordCount].word) - 1);
        wordList[*wordCount].word[sizeof(wordList[*wordCount].word) - 1] = '\0'; // 确保字符串以空字符结尾
        for (int i = 0; i < MAX_LINES; i++) {
            wordList[*wordCount].lineCounts[i] = 0;
        }
        wordList[*wordCount].totalCount = 0;
        wordList[*wordCount].lineCounts[lineNumber] = 1;
        (*wordCount)++;
    } else {
        wordList[index].lineCounts[lineNumber]++;
        wordList[index].totalCount++;
    }
}

int main() {
    char *linesPtrs[MAX_LINES]; // 字符串指针数组
    WordInfo wordList[MAX_WORDS];
    int lineCount = 0;
    int wordCount = 0;
    char buffer[MAX_LENGTH];

    printf("Enter multiple lines of text. Enter 'END' to finish:\n");
    while (lineCount < MAX_LINES && fgets(buffer, MAX_LENGTH, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0; // 移除换行符

        if (strcmp(buffer, END_STRING) == 0) {
            break;
        }

        // 为新字符串分配内存，并复制内容
        linesPtrs[lineCount] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (linesPtrs[lineCount] == NULL) {
            perror("Failed to allocate memory");
            // 释放之前分配的内存并退出程序
            for (int i = 0; i < lineCount; i++) {
                free(linesPtrs[i]);
            }
            return 1;
        }
        strcpy(linesPtrs[lineCount], buffer);

        char *word = strtok(linesPtrs[lineCount], " ,.-!?;");
        while (word) {
            for (char *p = word; *p; p++) {
                *p = tolower(*p);
            }
            addWord(wordList, &wordCount, word, lineCount);
            word = strtok(NULL, " ,.-!?;");
        }

        lineCount++;
    }

    // 打印单词计数信息
    printf("\nWord Counts:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("Word: %s, Total Count: %d\n", wordList[i].word, wordList[i].totalCount+1);
        for (int j = 0; j < lineCount; j++) {
            if (wordList[i].lineCounts[j] > 0) {
                printf("  Line %d: %d\n", j + 1, wordList[i].lineCounts[j]);
            }
        }
    }

    // 释放分配的内存
    for (int i = 0; i < lineCount; i++) {
        free(linesPtrs[i]);
    }

    return 0;
}
