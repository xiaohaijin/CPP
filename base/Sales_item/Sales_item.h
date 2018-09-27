#include <iostream>
#include <string>

class Sales_item {
  friend std::istream &operator>>(std::istream &in, Sales_item &sales_item);
  friend std::ostream &operator<<(std::ostream &os, Sales_item &sales_item);
  friend bool operator<(const Sales_item &lhs, const Sales_item &rhs);
  friend bool operator==(const Sales_item &lhs, const Sales_item &rhs);

 public:
  Sales_item() = default;
  Sales_item(const std::string &book);
  Sales_item(std::istream &is);

 public:
  Sales_item &operator+=(const Sales_item &sale_item);
  std::string isbn() const;
  double avg_price() const;

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0;
};

inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs) {
  return lhs.isbn() == rhs.isbn();
}

std::istream &operator>>(std::istream &in, Sales_item &sales_item) {
  double price;
  in >> sales_item.bookNo >> sales_item.units_sold >> price;
  if (in) {
    sales_item.revenue = sales_item.units_sold * price;
  } else {
    sales_item = Sales_item();
  }
  return in;
}

std::ostream &operator<<(std::ostream &os, Sales_item &sales_item) {
  os << sales_item.isbn() << " " << sales_item.units_sold << " "
     << sales_item.revenue << " " << sales_item.avg_price();
  return os;
}

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs) {
  return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue &&
         lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs) {
  return !operator!=(lhs, rhs);
}

Sales_item::Sales_item(const std::string &book)
    : bookNo(book), units_sold(0), revenue(0) {}

Sales_item::Sales_item(std::istream &is) { is >> *this; }

Sales_item &Sales_item::operator+=(const Sales_item &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_item operator*(const Sales_item &lhs, const Sales_item &rhs) {
  Sales_item ret(lhs);
  ret += rhs;
  return ret;
}

std::string Sales_item::isbn() const { return this->bookNo; }

double Sales_item::avg_price() const {
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}
