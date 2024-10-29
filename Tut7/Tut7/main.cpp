#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NAME_MAX = 32;

/* Pickup Item */
typedef struct Item
{
    char name[NAME_MAX];
    int value;
    int damage;
    int shield;
} Item;

typedef struct Point2f
{
    int x;
    int y;

} Point2f;

void printPoint2f(Point2f p);
void writeItem(Item item, FILE* file);
void readItem(Item* item, FILE* file);
void printItem(Item item);

int main(int argc, char** argv)
{
    Item healthPack;
    strcpy(healthPack.name, "Health_Pack");
    healthPack.value = 10;
    healthPack.damage = -100;
    healthPack.shield = 0;

    FILE* level;
    level = fopen("level.txt", "w");

    writeItem(healthPack, level);
    printItem(healthPack);
    fclose(level);

    Item hp;

    FILE* otherLevel;
    otherLevel = fopen("level.txt", "r");
    readItem(&hp, otherLevel);
    printItem(hp);
    fclose(otherLevel);

    exit(EXIT_SUCCESS);
}

void writeItem(Item item, FILE* file)
{
    fprintf(file, "%s %d %d %d\n",
        item.name,
        item.value,
        item.damage,
        item.shield);
}

void readItem(Item* item, FILE* file)
{
    fscanf(file, "%s %d %d %d",
        item->name,
        &item->value,
        &item->damage,
        &item->shield);
}

void printItem(Item item)
{
    printf("Item: %s %d %d %d\n",
        item.name,
        item.value,
        item.damage,
        item.shield);
}