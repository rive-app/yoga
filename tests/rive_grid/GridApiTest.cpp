#include <yoga/YGNode.h>
#include <yoga/Yoga.h>
#include <cstdio>

#define CHECK(cond)                                    \
    do                                                 \
    {                                                  \
        if (!(cond))                                   \
        {                                              \
            printf("FAIL line %d: %s\n", __LINE__, #cond); \
            failures++;                                \
        }                                              \
    } while (0)

int main()
{
    int failures = 0;

    // grid item placement roundtrip
    YGNodeRef n = YGNodeNew();
    YGNodeStyleSetGridColumnStart(n, 2);
    CHECK(YGNodeStyleGetGridColumnStart(n) == 2);
    YGNodeStyleSetGridColumnStartAuto(n);
    CHECK(YGNodeStyleGetGridColumnStart(n) == 0);
    YGNodeStyleSetGridRowEndSpan(n, 3);
    CHECK(YGNodeStyleGetGridRowEnd(n) == 0); // span reads back as 0
    CHECK(n->getStyle().gridRowEnd().isSpan());
    CHECK(n->getStyle().gridRowEnd().integer == 3);

    // justify items/self defaults and roundtrip
    CHECK(YGNodeStyleGetJustifyItems(n) == YGJustifyStretch);
    CHECK(YGNodeStyleGetJustifySelf(n) == YGJustifyAuto);
    YGNodeStyleSetJustifySelf(n, YGJustifyCenter);
    CHECK(YGNodeStyleGetJustifySelf(n) == YGJustifyCenter);

    // track templates
    YGNodeStyleSetGridTemplateColumnsCount(n, 3);
    YGNodeStyleSetGridTemplateColumn(n, 0, YGGridTrackTypePoints, 100);
    YGNodeStyleSetGridTemplateColumn(n, 1, YGGridTrackTypeFr, 1);
    YGNodeStyleSetGridTemplateColumnMinMax(
        n, 2, YGGridTrackTypePoints, 50, YGGridTrackTypePercent, 30);
    const auto& cols = n->getStyle().gridTemplateColumns();
    CHECK(cols.size() == 3);
    CHECK(cols[0].minSizingFunction.isPoints());
    CHECK(cols[0].maxSizingFunction.resolve(0).unwrap() == 100.0f);
    CHECK(cols[1].minSizingFunction.isAuto());
    CHECK(cols[1].maxSizingFunction.isStretch());
    CHECK(cols[2].minSizingFunction.resolve(0).unwrap() == 50.0f);
    CHECK(cols[2].maxSizingFunction.isPercent());
    CHECK(cols[2].maxSizingFunction.resolve(200).unwrap() == 60.0f);

    // out-of-bounds index: flags error, no crash, no write
    CHECK(!n->getHasError());
    YGNodeStyleSetGridTemplateColumn(n, 7, YGGridTrackTypePoints, 1);
    CHECK(n->getHasError());
    CHECK(n->getStyle().gridTemplateColumns().size() == 3);

    // display grid enum
    YGNodeStyleSetDisplay(n, YGDisplayGrid);
    CHECK(YGNodeStyleGetDisplay(n) == YGDisplayGrid);

    // style copy carries grid props
    YGNodeRef m = YGNodeNew();
    YGNodeCopyStyle(m, n);
    CHECK(m->getStyle().gridTemplateColumns().size() == 3);
    CHECK(m->getStyle() == n->getStyle());

    // existing flexbox unchanged: row with two 50pt children in 200pt parent
    YGNodeRef root = YGNodeNew();
    YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
    YGNodeStyleSetJustifyContent(root, YGJustifySpaceBetween);
    YGNodeStyleSetWidth(root, 200);
    YGNodeStyleSetHeight(root, 100);
    YGNodeRef a = YGNodeNew(), b = YGNodeNew();
    YGNodeStyleSetWidth(a, 50); YGNodeStyleSetHeight(a, 50);
    YGNodeStyleSetWidth(b, 50); YGNodeStyleSetHeight(b, 50);
    YGNodeInsertChild(root, a, 0);
    YGNodeInsertChild(root, b, 1);
    YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);
    CHECK(YGNodeLayoutGetLeft(a) == 0.0f);
    CHECK(YGNodeLayoutGetLeft(b) == 150.0f);

    printf(failures ? "FAILED (%d)\n" : "ALL PASS\n", failures);
    return failures;
}
