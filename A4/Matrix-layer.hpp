#ifndef MATRIX_LAYER_H
#define MATRIX_LAYER_H
#include "shape.hpp"
#include "CompositeShape.hpp"
#include "base-types.hpp"

class MatrixLayer
{
public:
  class MatrixShape
  {
  public:
    MatrixShape(size_t row, const MatrixLayer* column);
    const Shape& operator[](size_t col) const;
    size_t size() const noexcept;
  private:
    size_t row_, size_;
    const MatrixLayer *column_;
  };

  MatrixLayer();
  MatrixLayer(const MatrixLayer &matrix);
  MatrixLayer(MatrixLayer &&matrix);
  ~MatrixLayer() = default;
  MatrixLayer& operator=(const MatrixLayer &other);
  MatrixLayer& operator=(MatrixLayer &&other) ;
  MatrixShape operator[](size_t row) const;
  size_t size() const ;

  void addCompositeShapeElements(const CompositeShape &comp);
  void addShape(const Shape &shape);
  void removeShape(size_t row, size_t col);
  void balance();

private:
  void addRow();
  void addColumn();
  std::unique_ptr<std::unique_ptr<Shape>[]> arr_form;
  std::unique_ptr < size_t[]> rowSize_;
  size_t filledRows_, rows_, cols_;
  void resizeArray(size_t rows, size_t cols);
};

#endif
