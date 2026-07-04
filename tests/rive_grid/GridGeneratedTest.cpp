// Converted from gtest to standalone harness for the rive 2.x backport
#include <yoga/Yoga.h>
#include <yoga/YGGridTrackList.h>
#include <cmath>
#include <cstdio>

static int g_failures = 0;
static int g_checks = 0;
static const char* g_test = "";
static int g_test_failures = 0;

static void check_feq(float expected, float actual, int line) {
  g_checks++;
  bool ok = (std::isnan(expected) && std::isnan(actual)) ||
      std::fabs(expected - actual) < 0.01f;
  if (!ok) {
    if (g_test_failures == 0)
      printf("FAIL %s\n", g_test);
    if (g_test_failures < 4)
      printf("  line %d: expected %g, got %g\n", line, expected, actual);
    g_test_failures++;
    g_failures++;
  }
}
#define ASSERT_FLOAT_EQ(a, b) check_feq((a), (b), __LINE__)

static void test_grid_all_properties() {
  g_test = "grid_all_properties"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridAutoRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridAutoRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridAutoRows, YGPoints(200));
  YGNodeStyleSetGridAutoRows(root, root_gridAutoRows);
  YGGridTrackListFree(root_gridAutoRows);
  auto root_gridAutoColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridAutoColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridAutoColumns, YGPoints(200));
  YGNodeStyleSetGridAutoColumns(root, root_gridAutoColumns);
  YGGridTrackListFree(root_gridAutoColumns);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 5);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 4);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_auto_tracks() {
  g_test = "grid_auto_tracks"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  YGNodeStyleSetWidth(root, 220);
  YGNodeStyleSetHeight(root, 160);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetJustifyContent(root, YGJustifyStretch);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetHeight(root_child0, 50);
  YGNodeStyleSetPadding(root_child0, YGEdgeAll, 10);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_auto_tracks_with_gap() {
  g_test = "grid_auto_tracks_with_gap"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterColumn, 10);
  YGNodeStyleSetGap(root, YGGutterRow, 15);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 120);
  YGNodeStyleSetHeight(root_child0, 40);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeight(root_child1, 40);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child2, YGEdgeAll, 40);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(135, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(135, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_auto_tracks_with_margins() {
  g_test = "grid_auto_tracks_with_margins"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterColumn, 10);
  YGNodeStyleSetGap(root, YGGutterRow, 15);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 120);
  YGNodeStyleSetHeight(root_child0, 40);
  YGNodeStyleSetMargin(root_child0, YGEdgeTop, 10);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeight(root_child1, 40);
  YGNodeStyleSetMargin(root_child1, YGEdgeTop, 10);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child2, YGEdgeAll, 40);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(415, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(215, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(415, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(215, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_spanning_items() {
  g_test = "grid_spanning_items"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 6);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child1, YGEdgeAll, 40);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_holy_grail() {
  g_test = "grid_holy_grail"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(60));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 4);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 2);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidth(root_child1, 200);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 3);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 3);
  YGNodeStyleSetGridColumnEnd(root_child3, 4);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidth(root_child3, 200);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 4);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 4);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeight(root_child4, 60);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_sidebar_layout() {
  g_test = "grid_sidebar_layout"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(250));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 500);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 250);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_header_content_footer() {
  g_test = "grid_header_content_footer"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 600);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 2);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 1);
  YGNodeStyleSetGridColumnEnd(root_child2, 2);
  YGNodeStyleSetGridRowStart(root_child2, 3);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 80);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(520, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(520, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_card_layout() {
  g_test = "grid_card_layout"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(250));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(250));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 500);
  YGNodeStyleSetGap(root, YGGutterAll, 20);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 200);
  YGNodeStyleSetHeight(root_child0, 250);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidth(root_child1, 200);
  YGNodeStyleSetHeight(root_child1, 250);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 2);
  YGNodeStyleSetWidth(root_child2, 200);
  YGNodeStyleSetHeight(root_child2, 250);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 2);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidth(root_child3, 200);
  YGNodeStyleSetHeight(root_child3, 250);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 2);
  YGNodeStyleSetGridColumnEnd(root_child4, 3);
  YGNodeStyleSetGridRowStart(root_child4, 2);
  YGNodeStyleSetGridRowEnd(root_child4, 3);
  YGNodeStyleSetWidth(root_child4, 200);
  YGNodeStyleSetHeight(root_child4, 250);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 3);
  YGNodeStyleSetGridColumnEnd(root_child5, 4);
  YGNodeStyleSetGridRowStart(root_child5, 2);
  YGNodeStyleSetGridRowEnd(root_child5, 3);
  YGNodeStyleSetWidth(root_child5, 200);
  YGNodeStyleSetHeight(root_child5, 250);
  YGNodeInsertChild(root, root_child5, 5);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(440, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(440, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child5));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(-40, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(-40, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetHeight(root_child5));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_dashboard_layout() {
  g_test = "grid_dashboard_layout"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(220));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(70));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 600);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 4);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 70);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 2);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 4);
  YGNodeStyleSetWidth(root_child1, 220);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 3);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 3);
  YGNodeStyleSetGridColumnEnd(root_child3, 4);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 2);
  YGNodeStyleSetGridColumnEnd(root_child4, 4);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 4);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeightPercent(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(70, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(520, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(255, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(370, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(255, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(345, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(255, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(70, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(520, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(255, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(255, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(345, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(255, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_magazine_layout() {
  g_test = "grid_magazine_layout"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(2));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(300));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 900);
  YGNodeStyleSetHeight(root, 700);
  YGNodeStyleSetGap(root, YGGutterAll, 15);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 300);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 3);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 200);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 3);
  YGNodeStyleSetGridRowEnd(root_child3, 4);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 200);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(900, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(700, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(590, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(515, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(605, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(295, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(605, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(315, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(295, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(530, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(900, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(900, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(700, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(590, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(515, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(295, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(315, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(295, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(530, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(900, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_app_layout() {
  g_test = "grid_app_layout"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(60));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(60));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 600);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 60);
  YGNodeStyleSetHeight(root_child0, 60);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 60);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 1);
  YGNodeStyleSetGridColumnEnd(root_child2, 2);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidth(root_child2, 60);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 2);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 3);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 4);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeight(root_child4, 50);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(490, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(490, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(550, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(490, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(490, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(550, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_asymmetric_layout() {
  g_test = "grid_asymmetric_layout"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 600);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 200);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 3);
  YGNodeStyleSetGridColumnEnd(root_child1, 4);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 1);
  YGNodeStyleSetGridColumnEnd(root_child2, 2);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 2);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 200);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 2);
  YGNodeStyleSetGridColumnEnd(root_child4, 4);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 4);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeight(root_child4, 200);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(397, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(407, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(410, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(410, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(203, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(194, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(203, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(397, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(203, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(397, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(410, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(407, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(410, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(203, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(194, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(397, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_with_percentage_tracks() {
  g_test = "grid_with_percentage_tracks"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(20));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(40));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(20, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(-20, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(20, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_percentage_tracks_with_definite_size() {
  g_test = "grid_percentage_tracks_with_definite_size"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(20));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(40));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 300);
  YGNodeStyleSetHeight(root, 300);
  YGNodeStyleSetGapPercent(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(30, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(30, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_spanning_items_with_span() {
  g_test = "grid_spanning_items_with_span"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStartSpan(root_child0, 2);
  YGNodeStyleSetGridRowStartSpan(root_child0, 2);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_mixed_units() {
  g_test = "grid_mixed_units"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(2));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 400);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 4);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 80);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 4);
  YGNodeStyleSetGridColumnEnd(root_child2, 5);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 2);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 80);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 3);
  YGNodeStyleSetGridColumnEnd(root_child4, 5);
  YGNodeStyleSetGridRowStart(root_child4, 2);
  YGNodeStyleSetGridRowEnd(root_child4, 3);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeightPercent(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 1);
  YGNodeStyleSetGridColumnEnd(root_child5, 5);
  YGNodeStyleSetGridRowStart(root_child5, 3);
  YGNodeStyleSetGridRowEnd(root_child5, 4);
  YGNodeStyleSetWidthPercent(root_child5, 100);
  YGNodeStyleSetHeight(root_child5, 80);
  YGNodeInsertChild(root, root_child5, 5);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(233, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(243, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(357, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child5));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(367, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(233, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(357, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child5));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_overlapping_items() {
  g_test = "grid_overlapping_items"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 300);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 4);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 4);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_implicit_rows() {
  g_test = "grid_implicit_rows"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  auto root_gridAutoRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridAutoRows, YGPoints(80));
  YGNodeStyleSetGridAutoRows(root, root_gridAutoRows);
  YGGridTrackListFree(root_gridAutoRows);
  YGNodeStyleSetWidth(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 1);
  YGNodeStyleSetGridColumnEnd(root_child2, 2);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 80);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 2);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 80);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 2);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 4);
  YGNodeStyleSetWidth(root_child4, 100);
  YGNodeStyleSetHeight(root_child4, 80);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_implicit_columns() {
  g_test = "grid_implicit_columns"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  auto root_gridAutoColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridAutoColumns, YGPoints(80));
  YGNodeStyleSetGridAutoColumns(root, root_gridAutoColumns);
  YGGridTrackListFree(root_gridAutoColumns);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 2);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 3);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 2);
  YGNodeStyleSetWidth(root_child2, 80);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 2);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidth(root_child3, 80);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 3);
  YGNodeStyleSetGridColumnEnd(root_child4, 4);
  YGNodeStyleSetGridRowStart(root_child4, 1);
  YGNodeStyleSetGridRowEnd(root_child4, 2);
  YGNodeStyleSetWidth(root_child4, 80);
  YGNodeStyleSetHeight(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_complex_spanning() {
  g_test = "grid_complex_spanning"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 400);
  YGNodeStyleSetGap(root, YGGutterAll, 5);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 3);
  YGNodeStyleSetGridColumnEnd(root_child1, 5);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 4);
  YGNodeStyleSetGridColumnEnd(root_child3, 5);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 2);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 5);
  YGNodeStyleSetWidth(root_child4, 100);
  YGNodeStyleSetHeightPercent(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 2);
  YGNodeStyleSetGridColumnEnd(root_child5, 3);
  YGNodeStyleSetGridRowStart(root_child5, 3);
  YGNodeStyleSetGridRowEnd(root_child5, 4);
  YGNodeStyleSetWidth(root_child5, 100);
  YGNodeStyleSetHeight(root_child5, 100);
  YGNodeInsertChild(root, root_child5, 5);

  YGNodeRef root_child6 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child6, 2);
  YGNodeStyleSetGridColumnEnd(root_child6, 5);
  YGNodeStyleSetGridRowStart(root_child6, 4);
  YGNodeStyleSetGridRowEnd(root_child6, 5);
  YGNodeStyleSetWidthPercent(root_child6, 100);
  YGNodeStyleSetHeight(root_child6, 100);
  YGNodeInsertChild(root, root_child6, 6);

  YGNodeRef root_child7 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child7, 4);
  YGNodeStyleSetGridColumnEnd(root_child7, 5);
  YGNodeStyleSetGridRowStart(root_child7, 3);
  YGNodeStyleSetGridRowEnd(root_child7, 4);
  YGNodeStyleSetWidth(root_child7, 100);
  YGNodeStyleSetHeight(root_child7, 100);
  YGNodeInsertChild(root, root_child7, 7);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(315, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(315, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  ASSERT_FLOAT_EQ(315, YGNodeLayoutGetLeft(root_child7));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child7));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(195, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(-15, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(-15, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(205, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(195, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(-15, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(315, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  ASSERT_FLOAT_EQ(-15, YGNodeLayoutGetLeft(root_child7));
  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetTop(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child7));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_sparse_placement() {
  g_test = "grid_sparse_placement"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 3);
  YGNodeStyleSetGridColumnEnd(root_child1, 4);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 3);
  YGNodeStyleSetGridRowStart(root_child2, 3);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 4);
  YGNodeStyleSetGridColumnEnd(root_child3, 5);
  YGNodeStyleSetGridRowStart(root_child3, 1);
  YGNodeStyleSetGridRowEnd(root_child3, 2);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_negative_line_numbers() {
  g_test = "grid_negative_line_numbers"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 300);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, -1);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, -2);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, -2);
  YGNodeStyleSetGridColumnEnd(root_child2, -1);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, -1);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 2);
  YGNodeStyleSetGridRowStart(root_child3, -2);
  YGNodeStyleSetGridRowEnd(root_child3, -1);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_all_fractional_units() {
  g_test = "grid_all_fractional_units"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(2));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(3));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(2));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 600);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 2);
  YGNodeStyleSetGridRowStart(root_child4, 3);
  YGNodeStyleSetGridRowEnd(root_child4, 4);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeightPercent(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 2);
  YGNodeStyleSetGridColumnEnd(root_child5, 3);
  YGNodeStyleSetGridRowStart(root_child5, 3);
  YGNodeStyleSetGridRowEnd(root_child5, 4);
  YGNodeStyleSetWidthPercent(root_child5, 100);
  YGNodeStyleSetHeightPercent(root_child5, 100);
  YGNodeInsertChild(root, root_child5, 5);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child5));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child5));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_uniform_cells() {
  g_test = "grid_uniform_cells"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 2);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 4);
  YGNodeStyleSetGridColumnEnd(root_child3, 5);
  YGNodeStyleSetGridRowStart(root_child3, 1);
  YGNodeStyleSetGridRowEnd(root_child3, 2);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 2);
  YGNodeStyleSetGridRowStart(root_child4, 2);
  YGNodeStyleSetGridRowEnd(root_child4, 3);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeightPercent(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 2);
  YGNodeStyleSetGridColumnEnd(root_child5, 3);
  YGNodeStyleSetGridRowStart(root_child5, 2);
  YGNodeStyleSetGridRowEnd(root_child5, 3);
  YGNodeStyleSetWidthPercent(root_child5, 100);
  YGNodeStyleSetHeightPercent(root_child5, 100);
  YGNodeInsertChild(root, root_child5, 5);

  YGNodeRef root_child6 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child6, 3);
  YGNodeStyleSetGridColumnEnd(root_child6, 4);
  YGNodeStyleSetGridRowStart(root_child6, 2);
  YGNodeStyleSetGridRowEnd(root_child6, 3);
  YGNodeStyleSetWidthPercent(root_child6, 100);
  YGNodeStyleSetHeightPercent(root_child6, 100);
  YGNodeInsertChild(root, root_child6, 6);

  YGNodeRef root_child7 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child7, 4);
  YGNodeStyleSetGridColumnEnd(root_child7, 5);
  YGNodeStyleSetGridRowStart(root_child7, 2);
  YGNodeStyleSetGridRowEnd(root_child7, 3);
  YGNodeStyleSetWidthPercent(root_child7, 100);
  YGNodeStyleSetHeightPercent(root_child7, 100);
  YGNodeInsertChild(root, root_child7, 7);

  YGNodeRef root_child8 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child8, 1);
  YGNodeStyleSetGridColumnEnd(root_child8, 2);
  YGNodeStyleSetGridRowStart(root_child8, 3);
  YGNodeStyleSetGridRowEnd(root_child8, 4);
  YGNodeStyleSetWidthPercent(root_child8, 100);
  YGNodeStyleSetHeightPercent(root_child8, 100);
  YGNodeInsertChild(root, root_child8, 8);

  YGNodeRef root_child9 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child9, 2);
  YGNodeStyleSetGridColumnEnd(root_child9, 3);
  YGNodeStyleSetGridRowStart(root_child9, 3);
  YGNodeStyleSetGridRowEnd(root_child9, 4);
  YGNodeStyleSetWidthPercent(root_child9, 100);
  YGNodeStyleSetHeightPercent(root_child9, 100);
  YGNodeInsertChild(root, root_child9, 9);

  YGNodeRef root_child10 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child10, 3);
  YGNodeStyleSetGridColumnEnd(root_child10, 4);
  YGNodeStyleSetGridRowStart(root_child10, 3);
  YGNodeStyleSetGridRowEnd(root_child10, 4);
  YGNodeStyleSetWidthPercent(root_child10, 100);
  YGNodeStyleSetHeightPercent(root_child10, 100);
  YGNodeInsertChild(root, root_child10, 10);

  YGNodeRef root_child11 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child11, 4);
  YGNodeStyleSetGridColumnEnd(root_child11, 5);
  YGNodeStyleSetGridRowStart(root_child11, 3);
  YGNodeStyleSetGridRowEnd(root_child11, 4);
  YGNodeStyleSetWidthPercent(root_child11, 100);
  YGNodeStyleSetHeightPercent(root_child11, 100);
  YGNodeInsertChild(root, root_child11, 11);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child7));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child8));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child8));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child8));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child8));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child9));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child9));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child9));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child9));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child10));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child10));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child10));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child10));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child11));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child11));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child11));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child11));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child7));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child7));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child8));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child8));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child8));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child8));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child9));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child9));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child9));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child9));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child10));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child10));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child10));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child10));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child11));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child11));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child11));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child11));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_auto_placement_row() {
  g_test = "grid_auto_placement_row"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 300);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_large_spans() {
  g_test = "grid_large_spans"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 250);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 6);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 50);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 5);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 6);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 5);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_unequal_fractions() {
  g_test = "grid_unequal_fractions"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(3));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(2));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(2));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 2);
  YGNodeStyleSetGridRowEnd(root_child3, 3);
  YGNodeStyleSetWidthPercent(root_child3, 100);
  YGNodeStyleSetHeightPercent(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_single_cell() {
  g_test = "grid_single_cell"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(300));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 300);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 300);
  YGNodeStyleSetHeight(root_child0, 200);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_single_column() {
  g_test = "grid_single_column"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(120));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 200);
  YGNodeStyleSetHeight(root, 470);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 200);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 1);
  YGNodeStyleSetGridColumnEnd(root_child1, 2);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidth(root_child1, 200);
  YGNodeStyleSetHeight(root_child1, 150);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 1);
  YGNodeStyleSetGridColumnEnd(root_child2, 2);
  YGNodeStyleSetGridRowStart(root_child2, 3);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeStyleSetWidth(root_child2, 200);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 1);
  YGNodeStyleSetGridColumnEnd(root_child3, 2);
  YGNodeStyleSetGridRowStart(root_child3, 4);
  YGNodeStyleSetGridRowEnd(root_child3, 5);
  YGNodeStyleSetWidth(root_child3, 200);
  YGNodeStyleSetHeight(root_child3, 120);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(470, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(470, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_single_row() {
  g_test = "grid_single_row"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(120));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 470);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 200);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidth(root_child1, 150);
  YGNodeStyleSetHeight(root_child1, 200);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 3);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 2);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 200);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 4);
  YGNodeStyleSetGridColumnEnd(root_child3, 5);
  YGNodeStyleSetGridRowStart(root_child3, 1);
  YGNodeStyleSetGridRowEnd(root_child3, 2);
  YGNodeStyleSetWidth(root_child3, 120);
  YGNodeStyleSetHeight(root_child3, 200);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(470, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(470, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(370, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_tall_narrow() {
  g_test = "grid_tall_narrow"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(50));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 200);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 2);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 5);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 3);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 2);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 50);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 3);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 3);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 50);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 2);
  YGNodeStyleSetGridColumnEnd(root_child3, 3);
  YGNodeStyleSetGridRowStart(root_child3, 3);
  YGNodeStyleSetGridRowEnd(root_child3, 4);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 50);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 2);
  YGNodeStyleSetGridColumnEnd(root_child4, 3);
  YGNodeStyleSetGridRowStart(root_child4, 4);
  YGNodeStyleSetGridRowEnd(root_child4, 5);
  YGNodeStyleSetWidth(root_child4, 100);
  YGNodeStyleSetHeight(root_child4, 50);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 1);
  YGNodeStyleSetGridColumnEnd(root_child5, 3);
  YGNodeStyleSetGridRowStart(root_child5, 5);
  YGNodeStyleSetGridRowEnd(root_child5, 9);
  YGNodeStyleSetWidthPercent(root_child5, 100);
  YGNodeStyleSetHeightPercent(root_child5, 100);
  YGNodeInsertChild(root, root_child5, 5);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child5));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child5));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_wide_short() {
  g_test = "grid_wide_short"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(50));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 5);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 2);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child1, 5);
  YGNodeStyleSetGridColumnEnd(root_child1, 6);
  YGNodeStyleSetGridRowStart(root_child1, 1);
  YGNodeStyleSetGridRowEnd(root_child1, 3);
  YGNodeStyleSetWidth(root_child1, 50);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child2, 6);
  YGNodeStyleSetGridColumnEnd(root_child2, 7);
  YGNodeStyleSetGridRowStart(root_child2, 1);
  YGNodeStyleSetGridRowEnd(root_child2, 2);
  YGNodeStyleSetWidth(root_child2, 50);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child3, 7);
  YGNodeStyleSetGridColumnEnd(root_child3, 8);
  YGNodeStyleSetGridRowStart(root_child3, 1);
  YGNodeStyleSetGridRowEnd(root_child3, 2);
  YGNodeStyleSetWidth(root_child3, 50);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child4, 8);
  YGNodeStyleSetGridColumnEnd(root_child4, 9);
  YGNodeStyleSetGridRowStart(root_child4, 1);
  YGNodeStyleSetGridRowEnd(root_child4, 2);
  YGNodeStyleSetWidth(root_child4, 50);
  YGNodeStyleSetHeight(root_child4, 100);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child5, 1);
  YGNodeStyleSetGridColumnEnd(root_child5, 5);
  YGNodeStyleSetGridRowStart(root_child5, 2);
  YGNodeStyleSetGridRowEnd(root_child5, 3);
  YGNodeStyleSetWidthPercent(root_child5, 100);
  YGNodeStyleSetHeight(root_child5, 100);
  YGNodeInsertChild(root, root_child5, 5);

  YGNodeRef root_child6 = YGNodeNewWithConfig(config);
  YGNodeStyleSetGridColumnStart(root_child6, 6);
  YGNodeStyleSetGridColumnEnd(root_child6, 9);
  YGNodeStyleSetGridRowStart(root_child6, 2);
  YGNodeStyleSetGridRowEnd(root_child6, 3);
  YGNodeStyleSetWidthPercent(root_child6, 100);
  YGNodeStyleSetHeight(root_child6, 100);
  YGNodeInsertChild(root, root_child6, 6);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_gap_percentage_definite_size_2() {
  g_test = "grid_gap_percentage_definite_size_2"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(10));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(10));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(10));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGapPercent(root, YGGutterColumn, 70);
  YGNodeStyleSetGapPercent(root, YGGutterRow, 40);
  YGNodeStyleSetBorder(root, YGEdgeAll, 1);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child0, YGEdgeAll, 20);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 4);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child1, YGEdgeAll, 20);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child2, YGEdgeAll, 20);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 5);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(128, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(185, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(57, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(73, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(136, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(-47, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(128, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(-143, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(-111, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(73, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(136, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(40, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}
int main() {
  test_grid_all_properties();
  test_grid_auto_tracks();
  test_grid_auto_tracks_with_gap();
  test_grid_auto_tracks_with_margins();
  test_grid_spanning_items();
  test_grid_holy_grail();
  test_grid_sidebar_layout();
  test_grid_header_content_footer();
  test_grid_card_layout();
  test_grid_dashboard_layout();
  test_grid_magazine_layout();
  test_grid_app_layout();
  test_grid_asymmetric_layout();
  test_grid_with_percentage_tracks();
  test_grid_percentage_tracks_with_definite_size();
  test_grid_spanning_items_with_span();
  test_grid_mixed_units();
  test_grid_overlapping_items();
  test_grid_implicit_rows();
  test_grid_implicit_columns();
  test_grid_complex_spanning();
  test_grid_sparse_placement();
  test_grid_negative_line_numbers();
  test_grid_all_fractional_units();
  test_grid_uniform_cells();
  test_grid_auto_placement_row();
  test_grid_large_spans();
  test_grid_unequal_fractions();
  test_grid_single_cell();
  test_grid_single_column();
  test_grid_single_row();
  test_grid_tall_narrow();
  test_grid_wide_short();
  test_grid_gap_percentage_definite_size_2();
  printf("%d checks, %d failures across 34 tests\n", g_checks, g_failures);
  return g_failures == 0 ? 0 : 1;
}
