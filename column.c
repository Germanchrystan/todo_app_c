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
    col->transform = (SqrTransform){
      .position = { i * columnWidth, 0 },
      .size = {columnWidth, WINDOW_HEIGHT}
    };
  }
}

void DrawColumns(TodoColumn *colummns, int length)
{
  Color* colors = GetCellColors();
  for (int i = 0; i < length; i++)
  {
    TodoColumn column = colummns[i];
    SqrTransform transform = column.transform;
    DrawRectangle(
      transform.position.x,
      transform.position.y,
      transform.size.x,
      transform.size.y,
      colors[i]
    );
  }
}