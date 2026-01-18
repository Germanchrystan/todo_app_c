#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "constants.h"
#include "colors.h"

void InitializeColumnsPosition(TodoColumn *columns, int length)
{
  int columnWidth = (int)WINDOW_WIDTH / length;

  for (int i = 0; i < length; i++)
  {
    TodoColumn *col = &columns[i];
    SqrTransform newTransform = {
      i * columnWidth,
      0,
      columnWidth,
      WINDOW_HEIGHT,
    };
    col->transform = &newTransform;
  }
}

void DrawColumns(TodoColumn *colummns, int length)
{
  Color* colors = GetCellColors();
  for (int i = 0; i < length; i++)
  {
    TodoColumn column = colummns[i];
    SqrTransform* transform = column.transform;
    DrawRectangle(
      transform->position.x,
      transform->position.y,
      transform->size.x,
      transform->size.y,
      colors[i]
    );
  }
}