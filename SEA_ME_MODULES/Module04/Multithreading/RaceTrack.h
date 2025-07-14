#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack {
private:
    int size;
    int finishLine;

public:
    explicit RaceTrack(int size, int finishLine);

    int getSize() const;
    int getFinishLine() const;

    void setTrackSize(int trk);
    void setFinishLine (int newFinishLine);
};

#endif // RACETRACK_H
