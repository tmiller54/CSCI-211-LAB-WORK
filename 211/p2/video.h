#ifndef VIDEO_H
#define VIDEO_H

class Video
{
  public:
    Video(std::string title, std::string url, std::string comment, double length, int rating);
    void print();
    bool longer(Video *comparant);
  private:
    std::string mt, mu, mc;
    double ml;
    int mr;
};

#endif
