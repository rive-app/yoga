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

static void test_grid_indefinite_container_size_percentage_tracks() {
  g_test = "grid_indefinite_container_size_percentage_tracks"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(40));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(80));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child2, YGEdgeAll, 30);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetMinWidth(root_child3, 40);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetBorder(root_child4, YGEdgeAll, 10);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(104, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(234, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(104, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(104, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(56, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(-234, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(156, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(104, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(26, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_definite_container_size_percentage_tracks() {
  g_test = "grid_definite_container_size_percentage_tracks"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(40));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(50));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(80));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 300);
  YGNodeStyleSetHeight(root, 300);
  YGNodeStyleSetGapPercent(root, YGGutterRow, 10);
  YGNodeStyleSetGapPercent(root, YGGutterColumn, 20);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetMinWidth(root_child0, 40);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetBorder(root_child1, YGEdgeAll, 40);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child2, YGEdgeAll, 40);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetMarginPercent(root_child3, YGEdgeAll, 10);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(12, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(122, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(96, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(216, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(-30, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(-390, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(192, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(122, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(96, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(216, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_init_track_intrinsic_sizing() {
  g_test = "init_track_intrinsic_sizing"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 150);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 120);
  YGNodeStyleSetHeight(root_child2, 70);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(70, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(70, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_init_track_flexible_sizing() {
  g_test = "init_track_flexible_sizing"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 200);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

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
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

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
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_init_track_mixed_sizing() {
  g_test = "init_track_mixed_sizing"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(2));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 80);
  YGNodeStyleSetHeight(root_child1, 60);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_resolve_intrinsic_single_span() {
  g_test = "resolve_intrinsic_single_span"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 120);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 140);
  YGNodeStyleSetHeight(root_child2, 70);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child3, 110);
  YGNodeStyleSetHeight(root_child3, 85);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child4, 130);
  YGNodeStyleSetHeight(root_child4, 95);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(185, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(70, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(185, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(170, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(70, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_resolve_intrinsic_multi_span() {
  g_test = "resolve_intrinsic_multi_span"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 250);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 80);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 110);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child3, 300);
  YGNodeStyleSetHeight(root_child3, 120);
  YGNodeStyleSetGridColumnStart(root_child3, 2);
  YGNodeStyleSetGridColumnEnd(root_child3, 4);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_resolve_intrinsic_flexible_tracks() {
  g_test = "resolve_intrinsic_flexible_tracks"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 300);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 120);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_resolve_intrinsic_progressive_spans() {
  g_test = "resolve_intrinsic_progressive_spans"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 110);
  YGNodeStyleSetHeight(root_child1, 85);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 90);
  YGNodeStyleSetHeight(root_child2, 75);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child3, 105);
  YGNodeStyleSetHeight(root_child3, 82);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child4, 250);
  YGNodeStyleSetHeight(root_child4, 90);
  YGNodeStyleSetGridColumnStart(root_child4, 1);
  YGNodeStyleSetGridColumnEnd(root_child4, 3);
  YGNodeStyleSetGridRowStart(root_child4, 2);
  YGNodeInsertChild(root, root_child4, 4);

  YGNodeRef root_child5 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child5, 230);
  YGNodeStyleSetHeight(root_child5, 95);
  YGNodeStyleSetGridColumnStart(root_child5, 3);
  YGNodeStyleSetGridColumnEnd(root_child5, 5);
  YGNodeStyleSetGridRowStart(root_child5, 2);
  YGNodeInsertChild(root, root_child5, 5);

  YGNodeRef root_child6 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child6, 380);
  YGNodeStyleSetHeight(root_child6, 100);
  YGNodeStyleSetGridColumnStart(root_child6, 1);
  YGNodeStyleSetGridColumnEnd(root_child6, 4);
  YGNodeStyleSetGridRowStart(root_child6, 3);
  YGNodeInsertChild(root, root_child6, 6);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(508, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(131, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(272, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(75, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(272, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(508, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(408, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(267, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(146, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(75, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(13, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(82, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(258, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child4));

  ASSERT_FLOAT_EQ(6, YGNodeLayoutGetLeft(root_child5));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetTop(root_child5));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetWidth(root_child5));
  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetHeight(root_child5));

  ASSERT_FLOAT_EQ(128, YGNodeLayoutGetLeft(root_child6));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child6));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root_child6));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child6));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_maximize_tracks_definite_size() {
  g_test = "maximize_tracks_definite_size"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 110);
  YGNodeStyleSetHeight(root_child2, 85);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(170, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_maximize_tracks_max_constraint() {
  g_test = "maximize_tracks_max_constraint"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetMaxWidth(root, 400);
  YGNodeStyleSetMaxHeight(root, 250);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 160);
  YGNodeStyleSetHeight(root_child1, 110);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 170);
  YGNodeStyleSetHeight(root_child2, 105);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(170, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(-80, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(170, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(105, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_expand_flexible_definite_free_space() {
  g_test = "expand_flexible_definite_free_space"; g_test_failures = 0;
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

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(133, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(233, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(267, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(367, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(133, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(267, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_expand_flexible_min_constraint() {
  g_test = "expand_flexible_min_constraint"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetMinWidth(root, 600);
  YGNodeStyleSetMinHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 50);
  YGNodeStyleSetHeight(root_child0, 50);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 60);
  YGNodeStyleSetHeight(root_child1, 60);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 55);
  YGNodeStyleSetHeight(root_child2, 55);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(550, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(60, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(95, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_expand_flexible_max_constraint() {
  g_test = "expand_flexible_max_constraint"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 800);
  YGNodeStyleSetHeight(root, 600);
  YGNodeStyleSetMaxWidth(root, 500);
  YGNodeStyleSetMaxHeight(root, 350);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(125, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(175, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(125, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(175, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(375, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(125, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(175, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(375, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(125, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(175, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(125, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(175, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(125, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(175, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_expand_flexible_flex_less_than_one() {
  g_test = "expand_flexible_flex_less_than_one"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(0.5f));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(0.3f));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(0.2f));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(0.6f));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(0.4f));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 300);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_expand_flexible_spanning_items() {
  g_test = "expand_flexible_spanning_items"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 450);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(225, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(375, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(225, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_stretch_auto_justify_content_stretch() {
  g_test = "stretch_auto_justify_content_stretch"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 200);
  YGNodeStyleSetJustifyContent(root, YGJustifyStretch);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 110);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(290, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_stretch_auto_align_content_stretch() {
  g_test = "stretch_auto_align_content_stretch"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 200);
  YGNodeStyleSetHeight(root, 600);
  YGNodeStyleSetAlignContent(root, YGAlignStretch);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 110);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(243, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(243, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_stretch_auto_both_axes() {
  g_test = "stretch_auto_both_axes"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 500);
  YGNodeStyleSetJustifyContent(root, YGJustifyStretch);
  YGNodeStyleSetAlignContent(root, YGAlignStretch);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 110);
  YGNodeStyleSetHeight(root_child2, 85);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(290, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_justify_self_auto_margin_left() {
  g_test = "justify_self_auto_margin_left"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 100);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeLeft);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeLeft);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_justify_self_auto_margin_right() {
  g_test = "justify_self_auto_margin_right"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 100);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeRight);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeRight);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_justify_self_auto_margin_both() {
  g_test = "justify_self_auto_margin_both"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 400);
  YGNodeStyleSetHeight(root, 100);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeLeft);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeRight);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeLeft);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeRight);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_align_self_auto_margin_top() {
  g_test = "align_self_auto_margin_top"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 100);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeTop);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeTop);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_align_self_auto_margin_bottom() {
  g_test = "align_self_auto_margin_bottom"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 100);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeBottom);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeBottom);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_align_self_auto_margin_both() {
  g_test = "align_self_auto_margin_both"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 100);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeTop);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeBottom);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeTop);
  YGNodeStyleSetMarginAuto(root_child1, YGEdgeBottom);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_minimum_contribution_auto() {
  g_test = "minimum_contribution_auto"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 120);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 150);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_minimum_contribution_definite() {
  g_test = "minimum_contribution_definite"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 120);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 150);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_minimum_contribution_percentage_definite() {
  g_test = "minimum_contribution_percentage_definite"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 30);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 40);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_minimum_contribution_min_size() {
  g_test = "minimum_contribution_min_size"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 120);
  YGNodeStyleSetMinWidth(root_child0, 150);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetMinWidth(root_child1, 180);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_content_based_min_definite_length() {
  g_test = "content_based_min_definite_length"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 180);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_content_based_min_aspect_ratio() {
  g_test = "content_based_min_aspect_ratio"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetAspectRatio(root_child0, 2);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeStyleSetAspectRatio(root_child1, 0.5f);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_content_based_min_content_size() {
  g_test = "content_based_min_content_size"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child0, YGEdgeAll, 20);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPadding(root_child1, YGEdgeAll, 15);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_content_based_min_fixed_track_clamp() {
  g_test = "content_based_min_fixed_track_clamp"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 300);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 250);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(-50, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_content_based_min_span_fixed_max() {
  g_test = "content_based_min_span_fixed_max"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 500);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(470, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(320, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(470, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(-30, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_max_content_contribution_basic() {
  g_test = "max_content_contribution_basic"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 180);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_max_content_contribution_margins() {
  g_test = "max_content_contribution_margins"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetMargin(root_child0, YGEdgeAll, 10);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 180);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeStyleSetMargin(root_child1, YGEdgeAll, 15);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(185, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(15, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(15, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(15, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_limited_min_content_fixed_limit() {
  g_test = "limited_min_content_fixed_limit"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 400);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(310, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(-90, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_limited_min_content_no_limit() {
  g_test = "limited_min_content_no_limit"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 400);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_percentage_tracks_definite_container() {
  g_test = "percentage_tracks_definite_container"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(20));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(30));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(50));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(40));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(60));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_percentage_tracks_indefinite_container() {
  g_test = "percentage_tracks_indefinite_container"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(20));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(30));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(40));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 120);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 110);
  YGNodeStyleSetHeight(root_child2, 85);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(66, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(165, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(330, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(144, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(55, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(85, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_percentage_tracks_mixed_fixed() {
  g_test = "percentage_tracks_mixed_fixed"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(30));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(40));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 400);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_percentage_gap_definite_container() {
  g_test = "percentage_gap_definite_container"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(150));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 300);
  YGNodeStyleSetGapPercent(root, YGGutterColumn, 10);
  YGNodeStyleSetGapPercent(root, YGGutterRow, 20);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(210, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(30, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_spanning_items_span_2() {
  g_test = "spanning_items_span_2"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 250);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 110);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(480, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(370, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(480, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_spanning_items_span_3() {
  g_test = "spanning_items_span_3"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 380);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 4);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(490, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(490, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(380, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_spanning_items_overlapping() {
  g_test = "spanning_items_overlapping"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 250);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 280);
  YGNodeStyleSetHeight(root_child1, 120);
  YGNodeStyleSetGridColumnStart(root_child1, 2);
  YGNodeStyleSetGridColumnEnd(root_child1, 4);
  YGNodeStyleSetGridRowStart(root_child1, 2);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(420, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(170, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_spanning_items_both_axes() {
  g_test = "spanning_items_both_axes"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetGap(root, YGGutterAll, 10);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 250);
  YGNodeStyleSetHeight(root_child0, 230);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child2, 110);
  YGNodeStyleSetHeight(root_child2, 110);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(370, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(115, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(370, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(115, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_auto_margins_inline_left() {
  g_test = "auto_margins_inline_left"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(300));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeLeft);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_auto_margins_inline_right() {
  g_test = "auto_margins_inline_right"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(300));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeRight);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_auto_margins_block_top() {
  g_test = "auto_margins_block_top"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(300));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 150);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeTop);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_auto_margins_block_bottom() {
  g_test = "auto_margins_block_bottom"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(300));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 150);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeBottom);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_auto_margins_overrides_justify_self() {
  g_test = "auto_margins_overrides_justify_self"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(300));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 150);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeLeft);
  YGNodeStyleSetJustifySelf(root_child0, YGJustifyStart);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_auto_margins_overrides_align_self() {
  g_test = "auto_margins_overrides_align_self"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(300));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 150);
  YGNodeStyleSetMarginAuto(root_child0, YGEdgeTop);
  YGNodeStyleSetAlignSelf(root_child0, YGAlignStart);
  YGNodeInsertChild(root, root_child0, 0);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_min_max_constraints_min_width() {
  g_test = "min_max_constraints_min_width"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 80);
  YGNodeStyleSetMinWidth(root_child0, 150);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 90);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_min_max_constraints_max_width() {
  g_test = "min_max_constraints_max_width"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(200));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetMaxWidth(root_child0, 120);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(280, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_min_max_constraints_min_height() {
  g_test = "min_max_constraints_min_height"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 80);
  YGNodeStyleSetMinHeight(root_child0, 150);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeight(root_child1, 90);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(90, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_min_max_constraints_max_height() {
  g_test = "min_max_constraints_max_height"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(200));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMaxHeight(root_child0, 120);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_min_max_constraints_both() {
  g_test = "min_max_constraints_both"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 80);
  YGNodeStyleSetMinWidth(root_child0, 100);
  YGNodeStyleSetMaxWidth(root_child0, 150);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 200);
  YGNodeStyleSetMinWidth(root_child1, 100);
  YGNodeStyleSetMaxWidth(root_child1, 130);
  YGNodeStyleSetHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(230, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(130, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_gaps_justify_space_between() {
  g_test = "gaps_justify_space_between"; g_test_failures = 0;
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
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 100);
  YGNodeStyleSetGap(root, YGGutterColumn, 20);
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceBetween);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_gaps_align_space_around() {
  g_test = "gaps_align_space_around"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(100));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 100);
  YGNodeStyleSetHeight(root, 500);
  YGNodeStyleSetGap(root, YGGutterRow, 20);
  YGNodeStyleSetAlignContent(root, YGAlignSpaceAround);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(27, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(373, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(27, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(373, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_gaps_both_space_evenly() {
  g_test = "gaps_both_space_evenly"; g_test_failures = 0;
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
  YGNodeStyleSetWidth(root, 500);
  YGNodeStyleSetHeight(root, 500);
  YGNodeStyleSetGap(root, YGGutterAll, 15);
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceEvenly);
  YGNodeStyleSetAlignContent(root, YGAlignSpaceEvenly);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(358, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(500, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(358, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(43, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_gaps_spanning_items() {
  g_test = "gaps_spanning_items"; g_test_failures = 0;
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
  YGNodeStyleSetGap(root, YGGutterAll, 20);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 3);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeStyleSetGridRowStart(root_child2, 2);
  YGNodeStyleSetGridRowEnd(root_child2, 4);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(340, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(120, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(220, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_complex_flexible_min_max_distribution() {
  g_test = "complex_flexible_min_max_distribution"; g_test_failures = 0;
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
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 600);
  YGNodeStyleSetHeight(root, 400);
  YGNodeStyleSetMinWidth(root, 400);
  YGNodeStyleSetMaxWidth(root, 800);
  YGNodeStyleSetGap(root, YGGutterAll, 15);
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceAround);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child0, 100);
  YGNodeStyleSetHeightPercent(root_child0, 100);
  YGNodeStyleSetMinWidth(root_child0, 150);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child1, 100);
  YGNodeStyleSetHeightPercent(root_child1, 100);
  YGNodeStyleSetMaxWidth(root_child1, 250);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeInsertChild(root, root_child2, 2);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(165, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(460, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetHeight(root_child2));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(400, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(185, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(250, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(140, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(193, YGNodeLayoutGetHeight(root_child2));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_complex_all_features_combined() {
  g_test = "complex_all_features_combined"; g_test_failures = 0;
  YGConfigRef config = YGConfigNew();

  YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root, YGPositionTypeAbsolute);
  YGNodeStyleSetDisplay(root, YGDisplayGrid);
  auto root_gridTemplateColumns = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPoints(100));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGFr(2));
  YGGridTrackListAddTrack(root_gridTemplateColumns, YGPercent(30));
  YGNodeStyleSetGridTemplateColumns(root, root_gridTemplateColumns);
  YGGridTrackListFree(root_gridTemplateColumns);
  auto root_gridTemplateRows = YGGridTrackListCreate();
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPoints(80));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGAuto());
  YGGridTrackListAddTrack(root_gridTemplateRows, YGFr(1));
  YGGridTrackListAddTrack(root_gridTemplateRows, YGPercent(40));
  YGNodeStyleSetGridTemplateRows(root, root_gridTemplateRows);
  YGGridTrackListFree(root_gridTemplateRows);
  YGNodeStyleSetWidth(root, 800);
  YGNodeStyleSetHeight(root, 600);
  YGNodeStyleSetGap(root, YGGutterAll, 10);
  YGNodeStyleSetJustifyContent(root, YGJustifySpaceEvenly);
  YGNodeStyleSetAlignContent(root, YGAlignSpaceBetween);
  YGNodeStyleSetJustifyItems(root, YGJustifyCenter);
  YGNodeStyleSetAlignItems(root, YGAlignCenter);

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 350);
  YGNodeStyleSetHeight(root_child0, 180);
  YGNodeStyleSetGridColumnStart(root_child0, 1);
  YGNodeStyleSetGridColumnEnd(root_child0, 4);
  YGNodeStyleSetGridRowStart(root_child0, 1);
  YGNodeStyleSetGridRowEnd(root_child0, 3);
  YGNodeStyleSetJustifySelf(root_child0, YGJustifyStart);
  YGNodeStyleSetAlignSelf(root_child0, YGAlignEnd);
  YGNodeStyleSetMargin(root_child0, YGEdgeLeft, 20);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 150);
  YGNodeStyleSetAspectRatio(root_child1, 2);
  YGNodeStyleSetMaxHeight(root_child1, 100);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child2, 100);
  YGNodeStyleSetHeightPercent(root_child2, 100);
  YGNodeStyleSetGridColumnStart(root_child2, 2);
  YGNodeStyleSetGridColumnEnd(root_child2, 4);
  YGNodeStyleSetMinWidth(root_child2, 200);
  YGNodeStyleSetMaxWidth(root_child2, 300);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetAspectRatio(root_child3, 1);
  YGNodeStyleSetMarginAuto(root_child3, YGEdgeAll);
  YGNodeInsertChild(root, root_child3, 3);

  YGNodeRef root_child4 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidthPercent(root_child4, 100);
  YGNodeStyleSetHeightPercent(root_child4, 100);
  YGNodeStyleSetJustifySelf(root_child4, YGJustifyStretch);
  YGNodeStyleSetAlignSelf(root_child4, YGAlignStretch);
  YGNodeInsertChild(root, root_child4, 4);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(800, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(20, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(390, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(3, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(75, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(110, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(465, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(560, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child4));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(800, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(600, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(450, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(350, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(180, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(3, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(75, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(430, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(260, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(335, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(270, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetHeight(root_child3));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child4));
  ASSERT_FLOAT_EQ(190, YGNodeLayoutGetTop(root_child4));
  ASSERT_FLOAT_EQ(240, YGNodeLayoutGetWidth(root_child4));
  ASSERT_FLOAT_EQ(160, YGNodeLayoutGetHeight(root_child4));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

static void test_grid_absolute_position_items() {
  g_test = "grid_absolute_position_items"; g_test_failures = 0;
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

  YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child0, 100);
  YGNodeStyleSetHeight(root_child0, 100);
  YGNodeInsertChild(root, root_child0, 0);

  YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetWidth(root_child1, 50);
  YGNodeStyleSetHeight(root_child1, 50);
  YGNodeInsertChild(root, root_child1, 1);

  YGNodeRef root_child2 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root_child2, YGPositionTypeAbsolute);
  YGNodeStyleSetWidth(root_child2, 100);
  YGNodeStyleSetHeight(root_child2, 100);
  YGNodeStyleSetPosition(root_child2, YGEdgeLeft, 50);
  YGNodeStyleSetPosition(root_child2, YGEdgeTop, 10);
  YGNodeInsertChild(root, root_child2, 2);

  YGNodeRef root_child3 = YGNodeNewWithConfig(config);
  YGNodeStyleSetPositionType(root_child3, YGPositionTypeAbsolute);
  YGNodeStyleSetWidth(root_child3, 100);
  YGNodeStyleSetHeight(root_child3, 100);
  YGNodeStyleSetPosition(root_child3, YGEdgeLeft, 80);
  YGNodeStyleSetPosition(root_child3, YGEdgeTop, 10);
  YGNodeInsertChild(root, root_child3, 3);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(300, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(200, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(150, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetLeft(root_child2));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child2));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child2));

  ASSERT_FLOAT_EQ(80, YGNodeLayoutGetLeft(root_child3));
  ASSERT_FLOAT_EQ(10, YGNodeLayoutGetTop(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetWidth(root_child3));
  ASSERT_FLOAT_EQ(100, YGNodeLayoutGetHeight(root_child3));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}

int main() {
  test_grid_indefinite_container_size_percentage_tracks();
  test_grid_definite_container_size_percentage_tracks();
  test_init_track_intrinsic_sizing();
  test_init_track_flexible_sizing();
  test_init_track_mixed_sizing();
  test_resolve_intrinsic_single_span();
  test_resolve_intrinsic_multi_span();
  test_resolve_intrinsic_flexible_tracks();
  test_resolve_intrinsic_progressive_spans();
  test_maximize_tracks_definite_size();
  test_maximize_tracks_max_constraint();
  test_expand_flexible_definite_free_space();
  test_expand_flexible_min_constraint();
  test_expand_flexible_max_constraint();
  test_expand_flexible_flex_less_than_one();
  test_expand_flexible_spanning_items();
  test_stretch_auto_justify_content_stretch();
  test_stretch_auto_align_content_stretch();
  test_stretch_auto_both_axes();
  test_justify_self_auto_margin_left();
  test_justify_self_auto_margin_right();
  test_justify_self_auto_margin_both();
  test_align_self_auto_margin_top();
  test_align_self_auto_margin_bottom();
  test_align_self_auto_margin_both();
  test_minimum_contribution_auto();
  test_minimum_contribution_definite();
  test_minimum_contribution_percentage_definite();
  test_minimum_contribution_min_size();
  test_content_based_min_definite_length();
  test_content_based_min_aspect_ratio();
  test_content_based_min_content_size();
  test_content_based_min_fixed_track_clamp();
  test_content_based_min_span_fixed_max();
  test_max_content_contribution_basic();
  test_max_content_contribution_margins();
  test_limited_min_content_fixed_limit();
  test_limited_min_content_no_limit();
  test_percentage_tracks_definite_container();
  test_percentage_tracks_indefinite_container();
  test_percentage_tracks_mixed_fixed();
  test_percentage_gap_definite_container();
  test_spanning_items_span_2();
  test_spanning_items_span_3();
  test_spanning_items_overlapping();
  test_spanning_items_both_axes();
  test_auto_margins_inline_left();
  test_auto_margins_inline_right();
  test_auto_margins_block_top();
  test_auto_margins_block_bottom();
  test_auto_margins_overrides_justify_self();
  test_auto_margins_overrides_align_self();
  test_min_max_constraints_min_width();
  test_min_max_constraints_max_width();
  test_min_max_constraints_min_height();
  test_min_max_constraints_max_height();
  test_min_max_constraints_both();
  test_gaps_justify_space_between();
  test_gaps_align_space_around();
  test_gaps_both_space_evenly();
  test_gaps_spanning_items();
  test_complex_flexible_min_max_distribution();
  test_complex_all_features_combined();
  test_grid_absolute_position_items();
  printf("%d checks, %d failures across 64 tests (4 unsupported skipped)\n", g_checks, g_failures);
  return g_failures == 0 ? 0 : 1;
}
