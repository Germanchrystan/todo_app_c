#pragma once

#include <raylib.h>
#include "transform.h"

typedef struct
{
  int id;
  char* title;
  SqrTransform *transform;
} TodoColumn;

void DrawColumns(TodoColumn *columns, int length);
void InitializeColumnsPosition(TodoColumn *columns, int length);