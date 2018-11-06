#ifndef COMPLEX_H
#define COMPLEX_H

class complex {
 public:
  complex(double r = 0, double i = 0) : re(r), im(i) {}

  double fuc(const complex &param) const;

 private:
  double re, im;
};

#endif  // COMPLEX_H
