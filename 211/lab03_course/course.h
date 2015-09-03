#ifndef COURSE_H
#define COURSE_H

class Course
{
public:
  Course(std::string dept, int number, int time);
  void print();
private:
  std::string md;
  int mn, mt;
};

#endif
