#include "Matrix-layer.hpp"
#include <stdexcept>

MatrixLayer::MatrixShape::MatrixShape(size_t row, const MatrixLayer* column) :
  row_(row),
  column_(column)
{
}
void MatrixLayer::resizeArray(size_t rows, size_t cols)
{
  std::unique_ptr<std::unique_ptr<Shape>[]> temp(new std::unique_ptr<Shape>[rows*cols]);
  for(size_t i = 0; i < filledRows_; i++)
  {
    for(size_t j = 0; j < rowSize_[i]; j++)
    {
      temp[i*cols + j] = std::move(arr_form[i*cols_ + j]);
    }
  }
  arr_form = std::move(temp);
}
void MatrixLayer::addRow()
{
  std::unique_ptr<size_t[]> temp(new size_t[rows_ + 1]);
  for(size_t i = 0; i < rows_; i++)
  {
    temp[i] = rowSize_[i];
  }
  temp[rows_] = 0;

  if(cols_ == 0)
  {
    resizeArray(rows_ + 1, cols_ + 1);
    cols_++;
  }
  else
  {
    resizeArray(rows_ + 1, cols_);
  }
  rowSize_ = std::move(temp);
  rows_++;
}
void MatrixLayer::addColumn()
{
  resizeArray(rows_, cols_ + 1);
  cols_++;
}
const Shape& MatrixLayer::MatrixShape::operator[](size_t col) const
{
  if(col >= column_->rowSize_[row_])
  {
    throw std::out_of_range("MatrixLayer column index out of range");
  }
  return *(column_->arr_form[row_*column_->cols_ + col]);
}
size_t MatrixLayer::MatrixShape::size() const noexcept
{
  return column_->rowSize_[row_];
}
MatrixLayer::MatrixLayer():
  filledRows_(0),
  rows_(0),
  cols_(0)
{
  arr_form = nullptr;
  rowSize_ = nullptr;
}
MatrixLayer::MatrixLayer(const MatrixLayer &matrix) :
  arr_form(nullptr),
  rowSize_(nullptr)
{
  *this = matrix;
}
MatrixLayer::MatrixLayer(MatrixLayer &&matrix) :
  arr_form(nullptr),
  rowSize_(nullptr)
{
  *this = std::move(matrix);
}
MatrixLayer& MatrixLayer::operator=(const MatrixLayer &other)
{
  if(this != &other)
  {
    std::unique_ptr<size_t[]>tempRowSize(new size_t[other.rows_]);
    for(size_t i = 0; i < other.rows_; i++)
    {
      tempRowSize[i] = other.rowSize_[i];
    }

    std::unique_ptr<std::unique_ptr<Shape>[]> tempArr(new std::unique_ptr<Shape>[other.rows_ * other.cols_]);
    for(size_t i = 0; i < other.size(); i++)
    {
      for(size_t j = 0; j < other[i].size(); j++)
      {
        tempArr[i*other.cols_ + j] = other[i][j].clone();
      }
    }

    arr_form = std::move(tempArr);
    rowSize_ = std::move(tempRowSize);
    filledRows_ = other.filledRows_;
    rows_ = other.rows_;
    cols_ = other.cols_;
  }
  return *this;
}
MatrixLayer& MatrixLayer::operator=(MatrixLayer &&other) 
{
  if(this != &other)
  {
    arr_form = std::move(other.arr_form);
    other.arr_form = nullptr;

    rowSize_ = std::move(other.rowSize_);
    other.rowSize_ = nullptr;

    filledRows_ = other.filledRows_;
    other.filledRows_ = 0;
    
    rows_ = other.rows_;
    other.rows_ = 0;

    cols_ = other.cols_;
    other.cols_ = 0;

  }
  return *this;
}
MatrixLayer::MatrixShape MatrixLayer::operator[](size_t row) const
{
  if(row >= filledRows_)
  {
    throw std::out_of_range("MatrixLayer row index out of range");
  }
  return MatrixShape(row, this);
}
size_t MatrixLayer::size() const 
{
  return filledRows_;
}

void MatrixLayer::addShape(const Shape &shape)
{
  std::unique_ptr<Shape> tempShape = shape.clone();
  bool addedToMatrix = false;
  for(size_t i = 0; i < rows_; i++)
  {
    bool overlapsLayer = false;

    if(!overlapsLayer)
    {
      if(rowSize_[i] == cols_)
      {
        addColumn();
      }
      arr_form[i*cols_ + rowSize_[i]] = std::move(tempShape);
      if(rowSize_[i] == 0)
      {
        filledRows_++;
      }
      rowSize_[i]++;
      addedToMatrix = true;
      break;
    }
  }
  if(!addedToMatrix)
  {
    addRow();
    arr_form[(rows_ - 1) * cols_] = std::move(tempShape);
    rowSize_[rows_ - 1] = 1;
    filledRows_++;
  }
}
void MatrixLayer::removeShape(size_t row, size_t col)
{
  if((row >= filledRows_) || (col >= rowSize_[row]))
  {
    throw std::out_of_range("MatrixShape index out of range");
  }
  for(size_t i = col + 1; i < rowSize_[row]; i++)
  {
    arr_form[row*cols_ + i - 1] = std::move(arr_form[row*cols_ + i]);
  }
  arr_form[row*cols_ + rowSize_[row] - 1].reset(nullptr);
  rowSize_[row]--;

  if(rowSize_[row] == 0)
  {
    for(size_t i = row + 1; i < filledRows_; i++)
    {
      for(size_t j = 0; j < rowSize_[i]; j++)
      {
        arr_form[(i - 1)*cols_ + j] = std::move(arr_form[i*cols_ + j]);
      }
      rowSize_[i - 1] = rowSize_[i];
    }
    rowSize_[filledRows_ - 1] = 0;
    filledRows_--;
  }
}
void MatrixLayer::addCompositeShapeElements(const CompositeShape &comp)
{
  MatrixLayer temp(*this);
  for(size_t i = 0; i < comp.size(); i++)
  {
    temp.addShape(comp[i]);
  }
  *this = std::move(temp);
}

void MatrixLayer::balance()
{
  MatrixLayer temp;
  for(size_t i = 0; i < filledRows_; i++)
  {
    for(size_t j = 0; j < rowSize_[i]; j++)
    {
      temp.addShape(*arr_form[i*cols_ + j]);
    }
  }
  *this = std::move(temp);

}
