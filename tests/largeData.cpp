#include "../RTree.h"
#include "util.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest-matchers.h>
#include <gtest/gtest.h>

using namespace ::testing;

typedef RectTemplate<float> Rect;

Rect rects1[] =
{
  Rect(-165504234584830402149438989055033344.0f,0,0,0),
  Rect(0,0,0,0),
  Rect(0,0,0,-169601184587181609658320132097645215744.0f),
  Rect(-171755845806606337562467320443512553472.0f,0.000002f,-162256731624492592649732817688723456.0f,-171751221417216704981610660470219341824.0f),
  Rect(0,576601489791778816.0f,0,0),
  Rect(0,0.000007f,0,0),
  Rect(-4482491441084523606684867353378816.0f,0,0,0),
  Rect(0,0,0,-43227275904167492885693240287908855808.0f),
  Rect(-169908473233881734291078144928254001152.0f,0,0,-148873525386705775939391178777772949504.0f),
};

Rect rects2[] =
{
  Rect(-0.000487f,311158685411645789022377876652032.0f,0,0),
  Rect(-151115727451828646838272.0f,0,0,0),
  Rect(0,36893488147419103232.0f,0,0),
  Rect(0,0,36893488147419103232.0f,0),
  Rect(-107374176.0f,-36639756.0f,310688732424232076535519296618496.0f,0),
  Rect(-228296904656229410799616.0f,0,0,0),
  Rect(0,0,0,0),
  Rect(-326268824195173847682390548625982750720.0,0,311840674316413350549446522306560.0f,0),
  Rect(-0.453835f,303590248839277909200780151226368.0f,12.07855f,0),
};

TEST(LargeData, LargeData) {
  RTree<int, float, 2> tree;

  int data = 0;
  for (auto rect : rects1) {
    tree.Insert(rect.min, rect.max, data++);
  }
  for (auto rect : rects2) {
    tree.Insert(rect.min, rect.max, data++);
  }

  SUCCEED();
}