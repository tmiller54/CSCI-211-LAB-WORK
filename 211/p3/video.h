//video.h
//Miller, Travis
//travis
#ifndef VIDEO_H
#define VIDEO_H

class Video
{
  public:
    Video(std::string title, std::string url, std::string comment, double length, int rating);
    void Print();

    bool TitleComp(Video *comparant);
    bool LengthComp(Video *comparant);
    bool RateComp(Video *comparant);
    std::string GetTitle();

  private:
    std::string mt, mu, mc;
    double ml;
    int mr;
};

#endif
