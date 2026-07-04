# Grid backport tests

Standalone (no gtest) tests for the CSS Grid backport (facebook/yoga #1893/#1894).

- `GridGeneratedTest.cpp` / `GridFlowsGeneratedTest.cpp` — converted from the
  browser-generated fixtures in facebook/yoga #1901 (`tests/generated/YGGridTest.cpp`
  and `YGGridTestFlows.cpp`). Four tests using `display: contents` and text
  measurement were dropped (not supported in 2.x).
- `GridApiTest.cpp` — style/API roundtrip tests for the #1893 backport.

Build and run (from the repo root):

    clang++ -std=c++17 -DYOGA_EXPORT= -fno-exceptions -I. -O1 \
        yoga/*.cpp yoga/event/*.cpp yoga/grid/*.cpp \
        tests/rive_grid/GridGeneratedTest.cpp -o /tmp/grid_test && /tmp/grid_test
