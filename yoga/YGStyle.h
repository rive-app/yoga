/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <type_traits>

#include <yoga/Yoga.h>

#include "CompactValue.h"
#include "YGFloatOptional.h"
#include "YGGridTrack.h"
#include "Yoga-internal.h"
#include "BitUtils.h"

class YOGA_EXPORT YGStyle {
  template <typename Enum>
  using Values =
      facebook::yoga::detail::Values<facebook::yoga::enums::count<Enum>()>;
  using CompactValue = facebook::yoga::detail::CompactValue;

public:
  using Dimensions = Values<YGDimension>;
  using Edges = Values<YGEdge>;
  using Gutters = Values<YGGutter>;

  template <typename T>
  struct BitfieldRef {
    YGStyle& style;
    size_t offset;
    operator T() const {
      return facebook::yoga::detail::getEnumData<T>(style.flags, offset);
    }
    BitfieldRef<T>& operator=(T x) {
      facebook::yoga::detail::setEnumData<T>(style.flags, offset, x);
      return *this;
    }
  };

  template <typename T, T YGStyle::*Prop>
  struct Ref {
    YGStyle& style;
    operator T() const { return style.*Prop; }
    Ref<T, Prop>& operator=(T value) {
      style.*Prop = value;
      return *this;
    }
  };

  template <typename Idx, Values<Idx> YGStyle::*Prop>
  struct IdxRef {
    struct Ref {
      YGStyle& style;
      Idx idx;
      operator CompactValue() const { return (style.*Prop)[idx]; }
      operator YGValue() const { return (style.*Prop)[idx]; }
      Ref& operator=(CompactValue value) {
        (style.*Prop)[idx] = value;
        return *this;
      }
    };

    YGStyle& style;
    IdxRef<Idx, Prop>& operator=(const Values<Idx>& values) {
      style.*Prop = values;
      return *this;
    }
    operator const Values<Idx>&() const { return style.*Prop; }
    Ref operator[](Idx idx) { return {style, idx}; }
    CompactValue operator[](Idx idx) const { return (style.*Prop)[idx]; }
  };

  YGStyle() {
    alignContent() = YGAlignFlexStart;
    alignItems() = YGAlignStretch;
  }
  ~YGStyle() = default;

private:
  static constexpr size_t directionOffset = 0;
  static constexpr size_t flexdirectionOffset =
      directionOffset + facebook::yoga::detail::bitWidthFn<YGDirection>();
  static constexpr size_t justifyContentOffset = flexdirectionOffset +
      facebook::yoga::detail::bitWidthFn<YGFlexDirection>();
  static constexpr size_t alignContentOffset =
      justifyContentOffset + facebook::yoga::detail::bitWidthFn<YGJustify>();
  static constexpr size_t alignItemsOffset =
      alignContentOffset + facebook::yoga::detail::bitWidthFn<YGAlign>();
  static constexpr size_t alignSelfOffset =
      alignItemsOffset + facebook::yoga::detail::bitWidthFn<YGAlign>();
  static constexpr size_t positionTypeOffset =
      alignSelfOffset + facebook::yoga::detail::bitWidthFn<YGAlign>();
  static constexpr size_t flexWrapOffset =
      positionTypeOffset + facebook::yoga::detail::bitWidthFn<YGPositionType>();
  static constexpr size_t overflowOffset =
      flexWrapOffset + facebook::yoga::detail::bitWidthFn<YGWrap>();
  static constexpr size_t displayOffset =
      overflowOffset + facebook::yoga::detail::bitWidthFn<YGOverflow>();

  uint32_t flags = 0;

  YGFloatOptional flex_ = {};
  YGFloatOptional flexGrow_ = {};
  YGFloatOptional flexShrink_ = {};
  CompactValue flexBasis_ = CompactValue::ofAuto();
  Edges margin_ = {};
  Edges position_ = {};
  Edges padding_ = {};
  Edges border_ = {};
  Gutters gap_ = {};
  Dimensions dimensions_{CompactValue::ofAuto()};
  Dimensions minDimensions_ = {};
  Dimensions maxDimensions_ = {};
  // Yoga specific properties, not compatible with flexbox specification
  YGFloatOptional aspectRatio_ = {};

  // rive: grid style backport (facebook/yoga PR #1893)
  YGJustify justifyItems_ = YGJustifyStretch;
  YGJustify justifySelf_ = YGJustifyAuto;
  facebook::yoga::GridTrackList gridTemplateColumns_ = {};
  facebook::yoga::GridTrackList gridTemplateRows_ = {};
  facebook::yoga::GridTrackList gridAutoColumns_ = {};
  facebook::yoga::GridTrackList gridAutoRows_ = {};
  facebook::yoga::GridLine gridColumnStart_ = {};
  facebook::yoga::GridLine gridColumnEnd_ = {};
  facebook::yoga::GridLine gridRowStart_ = {};
  facebook::yoga::GridLine gridRowEnd_ = {};

public:
  // for library users needing a type
  using ValueRepr = std::remove_reference<decltype(margin_[0])>::type;

  YGDirection direction() const {
    return facebook::yoga::detail::getEnumData<YGDirection>(
        flags, directionOffset);
  }
  BitfieldRef<YGDirection> direction() { return {*this, directionOffset}; }

  YGFlexDirection flexDirection() const {
    return facebook::yoga::detail::getEnumData<YGFlexDirection>(
        flags, flexdirectionOffset);
  }
  BitfieldRef<YGFlexDirection> flexDirection() {
    return {*this, flexdirectionOffset};
  }

  YGJustify justifyContent() const {
    return facebook::yoga::detail::getEnumData<YGJustify>(
        flags, justifyContentOffset);
  }
  BitfieldRef<YGJustify> justifyContent() {
    return {*this, justifyContentOffset};
  }

  YGAlign alignContent() const {
    return facebook::yoga::detail::getEnumData<YGAlign>(
        flags, alignContentOffset);
  }
  BitfieldRef<YGAlign> alignContent() { return {*this, alignContentOffset}; }

  YGAlign alignItems() const {
    return facebook::yoga::detail::getEnumData<YGAlign>(
        flags, alignItemsOffset);
  }
  BitfieldRef<YGAlign> alignItems() { return {*this, alignItemsOffset}; }

  YGAlign alignSelf() const {
    return facebook::yoga::detail::getEnumData<YGAlign>(flags, alignSelfOffset);
  }
  BitfieldRef<YGAlign> alignSelf() { return {*this, alignSelfOffset}; }

  YGPositionType positionType() const {
    return facebook::yoga::detail::getEnumData<YGPositionType>(
        flags, positionTypeOffset);
  }
  BitfieldRef<YGPositionType> positionType() {
    return {*this, positionTypeOffset};
  }

  YGWrap flexWrap() const {
    return facebook::yoga::detail::getEnumData<YGWrap>(flags, flexWrapOffset);
  }
  BitfieldRef<YGWrap> flexWrap() { return {*this, flexWrapOffset}; }

  YGOverflow overflow() const {
    return facebook::yoga::detail::getEnumData<YGOverflow>(
        flags, overflowOffset);
  }
  BitfieldRef<YGOverflow> overflow() { return {*this, overflowOffset}; }

  YGDisplay display() const {
    return facebook::yoga::detail::getEnumData<YGDisplay>(flags, displayOffset);
  }
  BitfieldRef<YGDisplay> display() { return {*this, displayOffset}; }

  YGFloatOptional flex() const { return flex_; }
  Ref<YGFloatOptional, &YGStyle::flex_> flex() { return {*this}; }

  YGFloatOptional flexGrow() const { return flexGrow_; }
  Ref<YGFloatOptional, &YGStyle::flexGrow_> flexGrow() { return {*this}; }

  YGFloatOptional flexShrink() const { return flexShrink_; }
  Ref<YGFloatOptional, &YGStyle::flexShrink_> flexShrink() { return {*this}; }

  CompactValue flexBasis() const { return flexBasis_; }
  Ref<CompactValue, &YGStyle::flexBasis_> flexBasis() { return {*this}; }

  const Edges& margin() const { return margin_; }
  IdxRef<YGEdge, &YGStyle::margin_> margin() { return {*this}; }

  const Edges& position() const { return position_; }
  IdxRef<YGEdge, &YGStyle::position_> position() { return {*this}; }

  const Edges& padding() const { return padding_; }
  IdxRef<YGEdge, &YGStyle::padding_> padding() { return {*this}; }

  const Edges& border() const { return border_; }
  IdxRef<YGEdge, &YGStyle::border_> border() { return {*this}; }

  const Gutters& gap() const { return gap_; }
  IdxRef<YGGutter, &YGStyle::gap_> gap() { return {*this}; }

  const Dimensions& dimensions() const { return dimensions_; }
  IdxRef<YGDimension, &YGStyle::dimensions_> dimensions() { return {*this}; }

  const Dimensions& minDimensions() const { return minDimensions_; }
  IdxRef<YGDimension, &YGStyle::minDimensions_> minDimensions() {
    return {*this};
  }

  const Dimensions& maxDimensions() const { return maxDimensions_; }
  IdxRef<YGDimension, &YGStyle::maxDimensions_> maxDimensions() {
    return {*this};
  }

  // Yoga specific properties, not compatible with flexbox specification
  YGFloatOptional aspectRatio() const { return aspectRatio_; }
  Ref<YGFloatOptional, &YGStyle::aspectRatio_> aspectRatio() { return {*this}; }

  // rive: grid style backport (facebook/yoga PR #1893)
  YGJustify justifyItems() const { return justifyItems_; }
  void setJustifyItems(YGJustify value) { justifyItems_ = value; }

  YGJustify justifySelf() const { return justifySelf_; }
  void setJustifySelf(YGJustify value) { justifySelf_ = value; }

  // Grid Container Properties
  const facebook::yoga::GridTrackList& gridTemplateColumns() const {
    return gridTemplateColumns_;
  }
  void setGridTemplateColumns(facebook::yoga::GridTrackList value) {
    gridTemplateColumns_ = std::move(value);
  }
  void resizeGridTemplateColumns(size_t count) {
    gridTemplateColumns_.resize(count);
  }
  void setGridTemplateColumnAt(
      size_t index,
      facebook::yoga::GridTrackSize value) {
    gridTemplateColumns_[index] = value;
  }

  const facebook::yoga::GridTrackList& gridTemplateRows() const {
    return gridTemplateRows_;
  }
  void setGridTemplateRows(facebook::yoga::GridTrackList value) {
    gridTemplateRows_ = std::move(value);
  }
  void resizeGridTemplateRows(size_t count) { gridTemplateRows_.resize(count); }
  void setGridTemplateRowAt(size_t index, facebook::yoga::GridTrackSize value) {
    gridTemplateRows_[index] = value;
  }

  const facebook::yoga::GridTrackList& gridAutoColumns() const {
    return gridAutoColumns_;
  }
  void setGridAutoColumns(facebook::yoga::GridTrackList value) {
    gridAutoColumns_ = std::move(value);
  }
  void resizeGridAutoColumns(size_t count) { gridAutoColumns_.resize(count); }
  void setGridAutoColumnAt(size_t index, facebook::yoga::GridTrackSize value) {
    gridAutoColumns_[index] = value;
  }

  const facebook::yoga::GridTrackList& gridAutoRows() const {
    return gridAutoRows_;
  }
  void setGridAutoRows(facebook::yoga::GridTrackList value) {
    gridAutoRows_ = std::move(value);
  }
  void resizeGridAutoRows(size_t count) { gridAutoRows_.resize(count); }
  void setGridAutoRowAt(size_t index, facebook::yoga::GridTrackSize value) {
    gridAutoRows_[index] = value;
  }

  // Grid Item Properties
  const facebook::yoga::GridLine& gridColumnStart() const {
    return gridColumnStart_;
  }
  void setGridColumnStart(facebook::yoga::GridLine value) {
    gridColumnStart_ = value;
  }

  const facebook::yoga::GridLine& gridColumnEnd() const {
    return gridColumnEnd_;
  }
  void setGridColumnEnd(facebook::yoga::GridLine value) {
    gridColumnEnd_ = value;
  }

  const facebook::yoga::GridLine& gridRowStart() const {
    return gridRowStart_;
  }
  void setGridRowStart(facebook::yoga::GridLine value) {
    gridRowStart_ = value;
  }

  const facebook::yoga::GridLine& gridRowEnd() const { return gridRowEnd_; }
  void setGridRowEnd(facebook::yoga::GridLine value) { gridRowEnd_ = value; }

  // rive: yoga 3.x-style computed accessors used by the grid backport (#1894)
  float computeMarginForAxis(YGFlexDirection axis, float widthSize) const;
  float computeInlineStartMargin(
      YGFlexDirection axis,
      YGDirection direction,
      float widthSize) const;
  float computeInlineEndMargin(
      YGFlexDirection axis,
      YGDirection direction,
      float widthSize) const;
  float computeInlineStartPadding(
      YGFlexDirection axis,
      YGDirection direction,
      float widthSize) const;
  float computeInlineStartBorder(YGFlexDirection axis, YGDirection direction)
      const;
  bool inlineStartMarginIsAuto(YGFlexDirection axis, YGDirection direction)
      const;
  bool inlineEndMarginIsAuto(YGFlexDirection axis, YGDirection direction)
      const;
  float computeGapForDimension(YGDimension dimension, float availableSize)
      const;
  YGFloatOptional resolvedMinDimension(
      YGDirection direction,
      YGDimension dimension,
      float referenceLength,
      float ownerWidth) const;
  YGFloatOptional resolvedMaxDimension(
      YGDirection direction,
      YGDimension dimension,
      float referenceLength,
      float ownerWidth) const;
  facebook::yoga::StyleSizeLength dimension(YGDimension dimension) const;
  facebook::yoga::StyleSizeLength minDimension(YGDimension dimension) const;
  facebook::yoga::StyleSizeLength maxDimension(YGDimension dimension) const;
};

YOGA_EXPORT bool operator==(const YGStyle& lhs, const YGStyle& rhs);
YOGA_EXPORT inline bool operator!=(const YGStyle& lhs, const YGStyle& rhs) {
  return !(lhs == rhs);
}
