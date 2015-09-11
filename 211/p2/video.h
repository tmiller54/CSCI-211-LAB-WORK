#ifndef VIDEO_H
#define VIDEO_H

class Video
{
  public:
    Video(std::string title, std::string url, std::string comment, double length, int rating);
    void print();
<<<<<<< HEAD
    bool longer(Video *comparant);
=======

    bool titleComp(Video *comparant);
    bool lengthComp(Video *comparant);
    bool rateComp(Video *comparant);
    
>>>>>>> bc55dc3a55c902b7ac8048a342076cb076fd4aa2
  private:
    std::string mt, mu, mc;
    double ml;
    int mr;
};

#endif
