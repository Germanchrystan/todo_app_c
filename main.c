#include <stdio.h>
#include <raylib.h>
#include "constants.h"
#include "column.h"

typedef struct
{
  int id;
  char *title;
  char *description;
  int row;
} TodoItem;


TodoColumn defaultColumns[] = {
  {
    0, "Pending", NULL,
  },
  {
    1, "In Progress", NULL
  },
  {
    2, "Done", NULL
  }
};


int main(int argc, char **argv)
{
  Color darkGreen = {44, 44, 127, 255};
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "TODO app");
  Vector2 pos;
  InitializeColumnsPosition(defaultColumns, 3);
  
  while (!WindowShouldClose())
  {
    pos = GetMousePosition();
    // Draw
    BeginDrawing();
    ClearBackground(darkGreen);
    InitializeColumnsPosition(defaultColumns, 3);
    DrawColumns(defaultColumns, 3);
    EndDrawing();

  }
  CloseWindow();
  return 0;
}